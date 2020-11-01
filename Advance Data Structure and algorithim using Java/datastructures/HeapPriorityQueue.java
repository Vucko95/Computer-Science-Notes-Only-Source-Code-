package net.datastructures;
import java.util.Comparator;

//begin#fragment HeapPriorityQueue
/** 
  * Realization of a priority queue by means of a heap.  A complete
  * binary tree realized by means of an array list is used to
  * represent the heap.
//end#fragment HeapPriorityQueue
  *
  * @author Roberto Tamassia, Michael Goodrich, Eric Zamore
//begin#fragment HeapPriorityQueue
  */
public class HeapPriorityQueue<K,V> implements PriorityQueue<K,V> {
  protected CompleteBinaryTree<Entry<K,V>> heap;	// underlying heap
  protected Comparator<K> comp;	// comparator for the keys
  /** Inner class for heap entries. */
  protected static class  MyEntry<K,V> implements Entry<K,V> {
    protected K key;
    protected V value;
    public MyEntry(K k, V v) { key = k; value = v; }
    public K getKey() { return key; }
    public V getValue() { return value; }
    public String toString() { return "(" + key  + "," + value + ")"; }
  }
  /** Creates an empty heap with the default comparator */ 
  public HeapPriorityQueue() {  
    heap = new ArrayListCompleteBinaryTree<Entry<K,V>>(); // use an array list
    comp = new DefaultComparator<K>();     // use the default comparator
  }
  /** Creates an empty heap with the given comparator */
  public HeapPriorityQueue(Comparator<K> c) {
    heap = new ArrayListCompleteBinaryTree<Entry<K,V>>();
    comp = c;
  }
//end#fragment HeapPriorityQueue
  /** Sets the comparator used for comparing items in the heap. 
   * @throws IllegalStateException if priority queue is not empty */
  public void setComparator(Comparator<K> c) throws IllegalStateException {
    if(!isEmpty())  // this is only allowed if the priority queue is empty
      throw new IllegalStateException("Priority queue is not empty");
    comp = c;
  }
//begin#fragment HeapPriorityQueue
  /** Returns the size of the heap */
  public int size() { return heap.size(); } 
  /** Returns whether the heap is empty */
  public boolean isEmpty() { return heap.size() == 0; }
  //end#fragment HeapPriorityQueue
  //begin#fragment mainMethods
  /** Returns but does not remove an entry with minimum key */
  public Entry<K,V> min() throws EmptyPriorityQueueException {
    if (isEmpty()) 
      throw new EmptyPriorityQueueException("Priority queue is empty");
    return heap.root().element();
  }
  /** Inserts a key-value pair and returns the entry created */
  public Entry<K,V> insert(K k, V x) throws InvalidKeyException {
    checkKey(k);  // may throw an InvalidKeyException
    Entry<K,V> entry = new MyEntry<K,V>(k,x);
    upHeap(heap.add(entry));
    return entry;
  }
  /** Removes and returns an entry with minimum key */
  public Entry<K,V> removeMin() throws EmptyPriorityQueueException {
    if (isEmpty()) 
      throw new EmptyPriorityQueueException("Priority queue is empty");
    Entry<K,V> min = heap.root().element();
    if (size() == 1)
      heap.remove();
    else {
      heap.replace(heap.root(), heap.remove());
      downHeap(heap.root());
    }
    return min;
  }
  /** Determines whether a given key is valid */
  protected void checkKey(K key) throws InvalidKeyException {
    try {
      comp.compare(key,key);
    }
    catch(Exception e) {
      throw new InvalidKeyException("Invalid key");
    }
  }
  //end#fragment mainMethods
  //begin#fragment auxiliary
   /** Performs up-heap bubbling */
  protected void upHeap(Position<Entry<K,V>> v) {
    Position<Entry<K,V>> u;
    while (!heap.isRoot(v)) {
      u = heap.parent(v);
      if (comp.compare(u.element().getKey(), v.element().getKey()) <= 0) break;
      swap(u, v);
      v = u;
    }
  }
  /** Performs down-heap bubbling */
  protected void downHeap(Position<Entry<K,V>> r) {
    while (heap.isInternal(r)) {
      Position<Entry<K,V>> s;		// the position of the smaller child
      if (!heap.hasRight(r))
	s = heap.left(r);
      else if (comp.compare(heap.left(r).element().getKey(), 
                            heap.right(r).element().getKey()) <=0)
	s = heap.left(r);
      else
	s = heap.right(r);
      if (comp.compare(s.element().getKey(), r.element().getKey()) < 0) {
	swap(r, s);
	r = s;
      }
      else 
	break;
    }
  }
  /** Swaps the entries of the two given positions */
  protected void swap(Position<Entry<K,V>> x, Position<Entry<K,V>> y) {
    Entry<K,V> temp = x.element();
    heap.replace(x, y.element());
    heap.replace(y, temp);
  }
  /** Text visualization for debugging purposes */
  public String toString() {
    return heap.toString();
  }
  //end#fragment auxiliary
}
