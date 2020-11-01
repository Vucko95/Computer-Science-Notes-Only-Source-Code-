package net.datastructures;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.lang.UnsupportedOperationException;

/**
 *  A simple iterator class for lists.  The elements of a list are
 *  returned by this iterator.  No copy of the list is made, so any
 *  changes to the list are reflected in the iterator.
 *
 *  @author Michael Goodrich, Eric Zamore, Roberto Tamassia
 */
//begin#fragment Iterator
public class ElementIterator<E> implements Iterator<E> {
  protected PositionList<E> list; // the underlying list
  protected Position<E> cursor; // the next position
  /** Creates an element iterator over the given list. */
  public ElementIterator(PositionList<E> L) {
    list = L;
    cursor = (list.isEmpty())? null : list.first();
  }
//end#fragment Iterator
  /** Returns whether the iterator has a next object. */
//begin#fragment Iterator
  public boolean hasNext() { return (cursor != null);  }
//end#fragment Iterator
  /** Returns the next object in the iterator. */
//begin#fragment Iterator
  public E next() throws NoSuchElementException {
    if (cursor == null)
      throw new NoSuchElementException("No next element");
    E toReturn = cursor.element();
    cursor = (cursor == list.last())? null : list.next(cursor);
    return toReturn;
  }
//end#fragment Iterator
  /** Throws an {@link UnsupportedOperationException} in all cases,
   * because removal is not a supported operation in this iterator.
   */
  public void remove() throws UnsupportedOperationException {
    throw new UnsupportedOperationException("remove");
  }
//begin#fragment Iterator
}
//end#fragment Iterator
