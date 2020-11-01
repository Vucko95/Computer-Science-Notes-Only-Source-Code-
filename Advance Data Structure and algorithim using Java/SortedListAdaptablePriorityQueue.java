package net.datastructures;
import java.util.Comparator;
/**
 * Realization of an adaptable priority queue by means of a sorted
 * linked-list in nondecreasing order. Much functionality is
 * inherited.
 * @see SortedListPriorityQueue
 * @author Roberto Tamassia, Eric Zamore, Michael Goodrich
 */
//begin#fragment SortedListAdaptablePriorityQueue
/** Implementation of an adaptable priority queue by means of a sorted list. */
public class SortedListAdaptablePriorityQueue<K,V>
    extends SortedListPriorityQueue<K,V> 
    implements AdaptablePriorityQueue<K,V> {
  /** Creates the priority queue with the default comparator */
  public SortedListAdaptablePriorityQueue() { 
    super();
  }
  /** Creates the priority queue with the given comparator */
  public SortedListAdaptablePriorityQueue(Comparator<K> comp) { 
    super(comp);
  }
//end#fragment SortedListAdaptablePriorityQueue
  /** Creates the priority queue with the given comparator and list.
    * The list is assumed to be sorted in nondecreasing order */
  public SortedListAdaptablePriorityQueue(PositionList<Entry<K,V>> list, Comparator<K> comp) { 
    super(list, comp);
  }
//begin#fragment SortedListAdaptablePriorityQueue
  /** Inserts a key-value pair and returns the entry created */
  public Entry<K,V> insert (K k, V v) throws InvalidKeyException {
    checkKey(k);
    LocationAwareEntry<K,V> entry = new LocationAwareEntry<K,V>(k,v);
    insertEntry(entry);
    entry.setLocation(actionPos);	// position of the new entry
    return entry;
  }
  /** Removes and returns the given entry */
  public Entry<K,V> remove(Entry<K,V> entry) {
    checkEntry(entry);
    LocationAwareEntry<K,V> e = (LocationAwareEntry<K,V>) entry;
    Position<Entry<K,V>> p = e.location();
    entries.remove(p);
    e.setLocation(null);
    return e;
  }
  /** Replaces the key of the given entry */
  public K replaceKey(Entry<K,V> entry, K k) {
    checkKey(k);
    checkEntry(entry);
    LocationAwareEntry<K,V> e = (LocationAwareEntry<K,V>) remove(entry);
    K oldKey = e.setKey(k);
    insertEntry(e);
    e.setLocation(actionPos); // position of new entry
    return oldKey;
  }
  //end#fragment SortedListAdaptablePriorityQueue
  //begin#fragment LocationAwareEntry
  /** Replaces the value of the given entry */
  public V replaceValue(Entry<K,V> e, V value) {
    checkEntry(e);
    V oldValue = ((LocationAwareEntry<K,V>) e).setValue(value);
    return oldValue;
  }
  /** Determines whether a given entry is valid */
  protected void checkEntry(Entry ent) throws InvalidEntryException {
    if(ent == null || !(ent instanceof LocationAwareEntry))
      throw new InvalidEntryException("invalid entry");
  }
  /** Inner class for a location-aware entry */
  protected static class LocationAwareEntry<K,V>
    extends MyEntry<K,V> implements Entry<K,V> {
    /** Position where the entry is stored. */
    private Position<Entry<K,V>> loc;
    public LocationAwareEntry(K key, V value) {
      super(key, value);
    }
    public LocationAwareEntry(K key, V value, Position<Entry<K,V>> pos) {
      super(key, value);
      loc = pos;
    }
    protected Position<Entry<K,V>> location() {
      return loc;
    }
    protected Position<Entry<K,V>> setLocation(Position<Entry<K,V>> pos) {
      Position<Entry<K,V>> oldPosition = location();
      loc = pos;
      return oldPosition;
    }
    protected K setKey(K key) {
      K oldKey = getKey();
      k = key;
      return oldKey;
    }
    protected V setValue(V value) {
      V oldValue = getValue();
      v = value;
      return oldValue;
    }
  }
  //end#fragment LocationAwareEntry
}





