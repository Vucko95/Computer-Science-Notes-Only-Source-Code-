package net.datastructures;
import java.util.Iterator;
/**
 * An interface for array lists.
 * @author Roberto Tamassia, Michael Goodrich
 */
//begin#fragment Header
public interface IndexList<E> {
//end#fragment Header
//begin#fragment Iterator
  // ... the other List methods ...
//end#fragment Iterator
//begin#fragment List
  /** Returns the number of elements in this list. */
  public int size();
  /** Returns whether the list is empty. */
  public boolean isEmpty();
  /** Inserts an element e to be at index i, shifting all elements after this. */
  public void add(int i, E e) 
    throws IndexOutOfBoundsException;
  /** Returns the element at index i, without removing it. */
  public E get(int i) 
    throws IndexOutOfBoundsException;
  /** Removes and returns the element at index i, shifting the elements after this. */
  public E remove(int i)
    throws IndexOutOfBoundsException;
  /** Replaces the element at index i with e, returning the previous element at i. */
  public E set(int i, E e)
    throws IndexOutOfBoundsException;
//end#fragment List
//begin#fragment Tail
}
//end#fragment Tail
