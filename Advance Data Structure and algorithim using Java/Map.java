package net.datastructures;
/**
 * An interface for a map which binds a key uniquely to a value.
 * @author Michael Goodrich
 */
//begin#fragment Map
// A simple Map interface
public interface Map<K,V> {
  /** Returns the number of items in the map. */ 
  public int size();
  /** Returns whether the map is empty. */
  public boolean isEmpty();
  /** Puts a given key-value pair in the map, replacing a previous
    * one, if any, and returns the old value. */
  public V put(K key, V value) throws InvalidKeyException;
  /** Returns the value associated with a key. */
  public V get(K key) throws InvalidKeyException;
  /** Removes the key-value pair with a given key. */
  public V remove(K key) throws InvalidKeyException;
  /** Returns an iterable object containing all the keys in the map. */
  public Iterable<K> keySet();
  /** Returns an iterable object containing all the values in the map. */
  public Iterable<V> values();
  /** Returns an iterable object containing all the entries in the map. */
  public Iterable<Entry<K,V>> entrySet();  
}
//end#fragment Map
