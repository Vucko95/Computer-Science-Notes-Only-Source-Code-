package net.datastructures;
//begin#fragment Sequence
/**
 * An interface for a sequence, a data structure supporting all
 * operations of a deque, indexed list and position list.
//end#fragment Sequence
 * @author Roberto Tamassia, Michael Goodrich
//begin#fragment Sequence
 */
public interface Sequence<E> 
     extends Deque<E>, IndexList<E>, PositionList<E> {
  /** Returns the position containing the element at the given index. */
  public Position<E> atIndex(int r) throws BoundaryViolationException;
  /** Returns the index of the element stored at the given position. */
  public int indexOf(Position<E> p) throws InvalidPositionException;
}
//end#fragment Sequence
