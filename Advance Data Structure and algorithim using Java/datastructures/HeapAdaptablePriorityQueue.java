package net.datastructures;
import java.util.Comparator;

/**
  * Realization of an adaptable priority queue by means of a heap.
  * Much functionality is inherited.
  *
  * @author Eric Zamore
  * @see HeapPriorityQueue
  */

public class HeapAdaptablePriorityQueue<K,V>
  extends HeapPriorityQueue<K,V>
  implements AdaptablePriorityQueue<K,V> {
  /** Creates an empty heap with a default comparator. */ 
  public HeapAdaptablePriorityQueue() { 
    super();
  }
  /** Creates an empty heap with the given comparator. */ 
  public HeapAdaptablePriorityQueue(Comparator comp) { 
    super(comp);
  }
  /** Inserts a key-value pair and returns the entry created. */
  public Entry<K,V> insert (K k, V v) throws InvalidKeyException {
    checkKey(k);
    LocationAwareEntry<K,V> entry = new LocationAwareEntry<K,V>(k,v);
    Position z = heap.add(entry);	// add entry to the tree
    entry.setLocation(z);	// make this entry location-aware
    upHeap(z);			// perform up-heap bubbling
    return entry;
  }
  /** Removes and returns the given entry from the heap. */
  public Entry<K,V> remove(Entry<K,V> entry) throws InvalidEntryException {
    LocationAwareEntry<K,V> ee = checkEntry(entry);
    Position p = ee.location();
    if(size() == 1)
      return (Entry<K,V>) heap.remove();
    replaceEntry(p,(LocationAwareEntry<K,V>) heap.remove());
    upHeap(p);
    downHeap(p);
    ee.setLocation(null);
    return ee;
  }
  /** Replaces the key of the given entry. */
  public K replaceKey(Entry<K,V> entry, K k) 
    throws InvalidEntryException 
  {
    checkKey(k);
    LocationAwareEntry<K,V> ee = checkEntry(entry);
    K oldKey = ee.setKey(k);
    upHeap(ee.location());
    downHeap(ee.location());
    return oldKey;
  }
  /** Replaces the value of the given entry. */
  public V replaceValue(Entry<K,V> e, V value) 
    throws InvalidEntryException
  {
    LocationAwareEntry<K,V> ee = checkEntry(e);
    return ee.setValue(value);
  }
  /** Swaps the elements of the two positions.  This method is called
   * when up-heaping and down-heaping. */
  protected void swap(Position<Entry<K,V>> u, Position<Entry<K,V>> v) {
    super.swap(u,v);	// swap the entries held by the positions
    getEntry(u).setLocation(u);	// swap the position references
    getEntry(v).setLocation(v);
  }

  /** Replaces the element of the given position with the given
   * location-aware entry. */
  protected Position replaceEntry(Position v, LocationAwareEntry<K,V> e) {
    heap.replace(v,e);		// replace the entry in the tree
    return e.setLocation(v);	// make the new entry aware of its position
  }
  /** Returns the entry stored at a heap node. */
  protected LocationAwareEntry<K,V> getEntry (Position p) { 
    return (LocationAwareEntry<K,V>) p.element(); 
  }
  
  /** Check whether a given entry is valid. */
  protected LocationAwareEntry<K,V> checkEntry(Entry<K,V> ent) 
    throws InvalidEntryException 
  {
    if(ent == null || !(ent instanceof LocationAwareEntry))
      throw new InvalidEntryException("Invalid entry");
    return (LocationAwareEntry)ent;
  }

  /** Inner class for a location-aware entry. */
  protected static class LocationAwareEntry<K,V>
    extends MyEntry<K,V> implements Entry<K,V> {
    protected Position loc;
    public LocationAwareEntry(K k, V v) {
      super(k, v);
    }
    public LocationAwareEntry(K k, V v, Position pos) {
      super(k, v);
      loc = pos;
    }
    protected Position location() {
      return loc;
    }
    protected Position setLocation(Position pos) {
      Position oldPosition = location();
      loc = pos;
      return oldPosition;
    }
    protected K setKey(K k) {
      K oldKey = getKey();
      key = k;
      return oldKey;
    }
    protected V setValue(V v) {
      V oldValue = getValue();
      value = v;
      return oldValue;
    }
  }
}

