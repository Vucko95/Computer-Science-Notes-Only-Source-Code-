package net.datastructures;
/** 
  * Interface for an adaptable priority queue.
  */

public interface AdaptablePriorityQueue<K,V> extends PriorityQueue<K,V> {
  /** Removes and returns an entry from the priority queue. */
  public Entry<K,V> remove(Entry<K,V> e);
  /** Replaces the key of an entry and returns the old key. */
  public K replaceKey(Entry<K,V> e, K key) throws InvalidKeyException;
  /** Replaces the value of an entry and returns the old value. */
  public V replaceValue(Entry<K,V> e, V value);
}
