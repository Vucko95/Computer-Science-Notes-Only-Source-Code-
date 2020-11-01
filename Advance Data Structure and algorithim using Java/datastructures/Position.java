package net.datastructures;
/**
 * An interface for a position, which is a holder object storing a
 * single element.
 * @author Roberto Tamassia, Michael Goodrich
 */
//begin#fragment All
public interface Position<E> {
  /** Return the element stored at this position. */
  E element();
}
//end#fragment All
