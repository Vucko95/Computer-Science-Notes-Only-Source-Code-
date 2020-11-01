package net.datastructures;
import java.util.Comparator;
/** 
  * Realization of a priority queue by means of a sorted node list in
  * nondecreasing order.
  * @author Roberto Tamassia, Michael Goodrich, Eric Zamore
  */
//begin#fragment SortedListPriorityQueue1
public class SortedListPriorityQueue<K,V> implements PriorityQueue<K,V> {
  protected PositionList<Entry<K,V>> entries;
  protected Comparator<K> c;
  protected Position<Entry<K,V>> actionPos; // variable used by subclasses
  /** Inner class for entries */
  protected static class MyEntry<K,V> implements Entry<K,V> {
    protected K k; // key
    protected V v; // value
    public MyEntry(K key, V value) {
      k = key;
      v = value;
    }
    // methods of the Entry interface
    public K getKey() { return k; }
    public V getValue() { return v; }
//end#fragment SortedListPriorityQueue1
    // overrides toString, useful for debugging
    public String toString() { return "(" + k  + "," + v + ")"; }
//begin#fragment SortedListPriorityQueue1
  }
  /** Creates the priority queue with the default comparator. */
  public SortedListPriorityQueue () {
    entries = new NodePositionList<Entry<K,V>>();
    c = new DefaultComparator<K>();
  }
  /** Creates the priority queue with the given comparator. */
  public SortedListPriorityQueue (Comparator<K> comp) {
    entries = new NodePositionList<Entry<K,V>>();
    c = comp;
  }
  //end#fragment SortedListPriorityQueue1
  /** Creates the priority queue with the given comparator and list.
   * The list is assumed to be sorted in nondecreasing order.*/
  public SortedListPriorityQueue (PositionList<Entry<K,V>> list, Comparator<K> comp) { 
    entries = list;
    c = comp;
  }
  /** Sets the comparator for this priority queue.
   * @throws IllegalStateException if priority queue is not empty */
  public void setComparator(Comparator<K> comp) throws IllegalStateException {
    if(!isEmpty())  // this is only allowed if the priority queue is empty
      throw new IllegalStateException("Priority queue is not empty");
    c = comp;
  }
  /** Returns the number of elements in the priority queue. */
  public int size () {return entries.size(); }
  /** Returns whether the priority queue is empty. */
  public boolean isEmpty () { return entries.isEmpty(); }
  //begin#fragment SortedListPriorityQueue2
  /** Returns but does not remove an entry with minimum key. */
  public Entry<K,V> min () throws EmptyPriorityQueueException {
    if (entries.isEmpty())
      throw new EmptyPriorityQueueException("priority queue is empty");
    else
      return entries.first().element();
  }
  /** Inserts a key-value pair and return the entry created. */
  public Entry<K,V> insert (K k, V v) throws InvalidKeyException {
    checkKey(k); // auxiliary key-checking method (could throw exception)
    Entry<K,V> entry = new MyEntry<K,V>(k, v);
    insertEntry(entry);               // auxiliary insertion method
    return entry;
  }
  /** Auxiliary method used for insertion. */
  protected void insertEntry(Entry<K,V> e) {
    if (entries.isEmpty()) {
      entries.addFirst(e);            // insert into empty list
      actionPos = entries.first();    // insertion position 
    }
    else if (c.compare(e.getKey(), entries.last().element().getKey()) > 0) {
      entries.addLast(e);             // insert at the end of the list
      actionPos = entries.last();     // insertion position
    }
    else {
      Position<Entry<K,V>> curr = entries.first();
      while (c.compare(e.getKey(), curr.element().getKey())> 0) {
	curr = entries.next(curr);    // advance toward insertion position
      }
      entries.addBefore(curr, e); 
      actionPos = entries.prev(curr); // insertion position
    }
  }
  /** Removes and returns an entry with minimum key. */
  public Entry<K,V> removeMin() throws EmptyPriorityQueueException {
    if (entries.isEmpty())
      throw new EmptyPriorityQueueException("priority queue is empty");
    else
      return entries.remove(entries.first());
  }
//end#fragment SortedListPriorityQueue2

//begin#fragment SortedListPriorityQueue3
  /** Determines whether a key is valid. */
  protected boolean checkKey(K key) throws InvalidKeyException {
    boolean result;
    try {		// check if the key can be compared to itself
      result = (c.compare(key,key)==0);
    } catch (ClassCastException e)
      {	throw new InvalidKeyException("key cannot be compared"); }
    return result;
  }
  // overrides toString, useful for debugging
  public String toString() {
    return entries.toString(); 
  }
//end#fragment SortedListPriorityQueue3
//begin#fragment tail
}
//end#fragment tail
