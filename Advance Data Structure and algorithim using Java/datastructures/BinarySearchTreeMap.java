package net.datastructures;
import java.util.Comparator;
import java.util.Iterator;

/**
  * Realization of a map by means of a binary search tree.
  * @author Michael Goodrich, Eric Zamore
  */ 

//begin#fragment BinarySearchTree
// Realization of a map by means of a binary search tree
public class BinarySearchTreeMap<K,V> 
  extends LinkedBinaryTree<Entry<K,V>> implements Map<K,V> {
//end#fragment BinarySearchTree
  // Instance variables:
//begin#fragment BinarySearchTree
  protected Comparator<K> C;	// comparator
  protected Position<Entry<K,V>> 
              actionPos; // insert node or removed node's parent
  protected int numEntries = 0;	// number of entries
  /** Creates a BinarySearchTree with a default comparator. */
  public BinarySearchTreeMap()  { 
    C = new DefaultComparator<K>(); 
    addRoot(null);
  }
//end#fragment BinarySearchTree
  /** Creates a BinarySearchTree with the given comparator. */
//begin#fragment BinarySearchTree
  public BinarySearchTreeMap(Comparator<K> c)  { 
    C = c; 
    addRoot(null);
  }
  /** Nested class for location-aware binary search tree entries */
  protected static class BSTEntry<K,V> implements Entry<K,V> {
    protected K key;
    protected V value;
    protected Position<Entry<K,V>> pos;
    BSTEntry() { /* default constructor */ }
    BSTEntry(K k, V v, Position<Entry<K,V>> p) { 
      key = k; value = v; pos = p;
    }
    public K getKey() { return key; }
    public V getValue() { return value; }
    public Position<Entry<K,V>> position() { return pos; }
  }
//end#fragment BinarySearchTree
  // Auxiliary methods:
//begin#fragment BinarySearchTree
  /** Extracts the key of the entry at a given node of the tree. */
  protected K key(Position<Entry<K,V>> position)  {
    return position.element().getKey();
  }
  /** Extracts the value of the entry at a given node of the tree. */  
  protected V value(Position<Entry<K,V>> position)  { 
    return position.element().getValue(); 
  }
  /** Extracts the entry at a given node of the tree. */  
  protected Entry<K,V> entry(Position<Entry<K,V>> position)  { 
    return position.element();
  }
//end#fragment BinarySearchTree
//begin#fragment BinarySearchTree2
/** Replaces an entry with a new entry (and reset the entry's location) */
protected V replaceEntry(Position <Entry<K,V>> pos, Entry<K,V> ent) {
  ((BSTEntry<K,V>) ent).pos = pos;
  return replace(pos, ent).getValue();
}
/** Checks whether a given key is valid. */  
protected void checkKey(K key) throws InvalidKeyException {
  if(key == null)  // just a simple test for now
    throw new InvalidKeyException("null key");
}
/** Checks whether a given entry is valid. */
protected void checkEntry(Entry<K,V> ent) throws InvalidEntryException {
  if(ent == null || !(ent instanceof BSTEntry))
    throw new InvalidEntryException("invalid entry");
}
/** Auxiliary method for inserting an entry at an external node */
protected Entry<K,V> insertAtExternal(Position<Entry<K,V>> v, Entry<K,V> e) {
  expandExternal(v,null,null);
  replace(v, e);
  numEntries++;
  return e;
}
/** Auxiliary method for removing an external node and its parent */
protected void removeExternal(Position<Entry<K,V>> v) {
  removeAboveExternal(v);
  numEntries--;
}
/** Auxiliary method used by find, insert, and remove. */
protected Position<Entry<K,V>> treeSearch(K key, Position<Entry<K,V>> pos) {
  if (isExternal(pos)) return pos; // key not found; return external node
  else {
    K curKey = key(pos);
    int comp = C.compare(key, curKey);
    if (comp < 0) 
      return treeSearch(key, left(pos));	// search left subtree
    else if (comp > 0)
      return treeSearch(key, right(pos));	// search right subtree
    return pos;		// return internal node where key is found
  }
}
//end#fragment BinarySearchTree2
/** Adds to L all entries in the subtree rooted at v having keys
 * equal to k. */
//begin#fragment BinarySearchTree3
  // methods of the map ADT
//end#fragment BinarySearchTree3
  /** Returns the number of entries in the tree. */
//begin#fragment BinarySearchTree3
  public int size() { return numEntries; }
//end#fragment BinarySearchTree3
  /** Returns whether the tree is empty. */
//begin#fragment BinarySearchTree3
  public boolean isEmpty() { return size() == 0; }
//end#fragment BinarySearchTree3
  /** Returns an entry containing the given key.  Returns null if no
    * such entry exists. */
//begin#fragment BinarySearchTree3
  public V get(K key) throws InvalidKeyException {
    checkKey(key);		// may throw an InvalidKeyException
    Position<Entry<K,V>> curPos = treeSearch(key, root());
    actionPos = curPos;		// node where the search ended
    if (isInternal(curPos)) return value(curPos);
    return null;
  }
//end#fragment BinarySearchTree3
  /** Inserts an entry into the tree and returns the newly created entry. */
//begin#fragment BinarySearchTree3
  public V put(K k, V x) throws InvalidKeyException {
    checkKey(k);	// may throw an InvalidKeyException
    Position<Entry<K,V>> insPos = treeSearch(k, root());
    BSTEntry<K,V> e = new BSTEntry<K,V>(k, x, insPos);
    actionPos = insPos;	// node where the entry is being inserted
    if (isExternal(insPos)) { // we need a new node, key is new
      return insertAtExternal(insPos, e).getValue();
    }
    return replaceEntry(insPos, e);  // key already exists
  }
//end#fragment BinarySearchTree3
  /** Removes and returns a given entry. */
//begin#fragment BinarySearchTree3
  public V remove(K k) throws InvalidKeyException  {
    checkKey(k);            // may throw an InvalidKeyException
    Position<Entry<K,V>> remPos = treeSearch(k, root());
    if (isExternal(remPos)) return null; // key not found
    Entry<K,V> toReturn = entry(remPos);	// old entry 
    if (isExternal(left(remPos))) remPos = left(remPos);  // left easy case
    else if (isExternal(right(remPos))) remPos = right(remPos); // right easy case
    else {			//  entry is at a node with internal children
      Position<Entry<K,V>> swapPos = remPos;	// find node for moving entry
      remPos = right(swapPos);
      do
	remPos = left(remPos);
      while (isInternal(remPos));
      replaceEntry(swapPos, (Entry<K,V>) parent(remPos).element());
    }
    actionPos = sibling(remPos);	// sibling of the leaf to be removed
    removeExternal(remPos);
    return toReturn.getValue();
  }
//end#fragment BinarySearchTree3
  /** Returns an iterable collection containing all keys in the tree. */
  public Iterable<K> keySet() {
    PositionList<K> keys = new NodePositionList<K>();
    Iterable<Position<Entry<K,V>>> positer = positions();
    for (Position<Entry<K,V>> cur: positer)
      if (isInternal(cur))
	keys.addLast(key(cur));
    return keys;
  }
  /** Returns an iterable collection containing all entries in the tree. */
  public Iterable<V> values() {
    PositionList<V> vals = new NodePositionList<V>();
    Iterable<Position<Entry<K,V>>> positer = positions();
    for (Position<Entry<K,V>> cur: positer)
      if (isInternal(cur))
	vals.addLast(value(cur));
    return vals;
  }
  /** Returns an iterable collection containing all entries in the tree. */
  public Iterable<Entry<K,V>> entrySet() {
    PositionList<Entry<K,V>> entries = new NodePositionList<Entry<K,V>>();
    Iterable<Position<Entry<K,V>>> positer = positions();
    for (Position<Entry<K,V>> cur: positer)
      if (isInternal(cur))
	entries.addLast(cur.element());
    return entries;
  }
  /** 
   * Performs a tri-node restructuring.  Assumes the nodes are in one
   * of following configurations:
   *
   * <pre>
   *          z=c       z=c        z=a         z=a
   *         /  \      /  \       /  \        /  \
   *       y=b  t4   y=a  t4    t1  y=c     t1  y=b
   *      /  \      /  \           /  \         /  \
   *    x=a  t3    t1 x=b        x=b  t4       t2 x=c
   *   /  \          /  \       /  \             /  \
   *  t1  t2        t2  t3     t2  t3           t3  t4
   * </pre>
   * @return the new root of the restructured subtree
   */
  protected Position<Entry<K,V>> restructure(Position<Entry<K,V>> x) { 
    BTPosition<Entry<K,V>> a, b, c, t1, t2, t3, t4;
    Position<Entry<K,V>> y = parent(x);	// assumes x has a parent
    Position<Entry<K,V>> z = parent(y);	// assumes y has a parent
    boolean xLeft = (x == left(y));
    boolean yLeft = (y == left(z));
    BTPosition<Entry<K,V>> xx = (BTPosition<Entry<K,V>>)x, 
      yy = (BTPosition<Entry<K,V>>)y, zz = (BTPosition<Entry<K,V>>)z;
    if (xLeft && yLeft) { 
      a = xx; b = yy; c = zz; 
      t1 = a.getLeft(); t2 = a.getRight(); t3 = b.getRight(); t4 = c.getRight();
    }
    else if (!xLeft && yLeft) { 
      a = yy; b = xx; c = zz; 
      t1 = a.getLeft(); t2 = b.getLeft(); t3 = b.getRight(); t4 = c.getRight();
    }
    else if (xLeft && !yLeft) { 
      a = zz; b = xx; c = yy; 
      t1 = a.getLeft(); t2 = b.getLeft(); t3 = b.getRight(); t4 = c.getRight();
    }
    else { // right-right 
      a = zz; b = yy; c = xx; 
      t1 = a.getLeft(); t2 = b.getLeft(); t3 = c.getLeft(); t4 = c.getRight();
    }
    // put b at z's place 
    if (isRoot(z)) {
      root = b;
      b.setParent(null);
    }
    else {
      BTPosition<Entry<K,V>> zParent = (BTPosition<Entry<K,V>>)parent(z);
      if (z == left(zParent)) {
	b.setParent(zParent);
	zParent.setLeft(b);
      }
      else { // z was a right child
	b.setParent(zParent);
	zParent.setRight(b);
      }
    }
    // place the rest of the nodes and their children
    b.setLeft(a);
    a.setParent(b);
    b.setRight(c);
    c.setParent(b);
    a.setLeft(t1);
    t1.setParent(a);
    a.setRight(t2);
    t2.setParent(a);
    c.setLeft(t3);
    t3.setParent(c);
    c.setRight(t4);
    t4.setParent(c);
    // Reset the location-aware entries
    ((BSTEntry<K,V>) a.element()).pos = a;
    ((BSTEntry<K,V>) b.element()).pos = b;
    ((BSTEntry<K,V>) c.element()).pos = c;
    return b; // the new root of this subtree
  }
//begin#fragment BinarySearchTree3
} 	
//end#fragment BinarySearchTree3
