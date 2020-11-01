package net.datastructures;
import java.util.Iterator;
/**  
 * Realization of a PositionList using a doubly-linked list of nodes.
 *   
 * @author Michael Goodrich, Natasha Gelfand, Roberto Tamassia, Eric Zamore
 */
//begin#fragment Header
public class NodePositionList<E> implements PositionList<E> {
//end#fragment Header
//begin#fragment Listvars
  protected int numElts;            	// Number of elements in the list
  protected DNode<E> header, trailer;	// Special sentinels
//end#fragment Listvars
//begin#fragment checkPosition
  /** Constructor that creates an empty list; O(1) time */
  public NodePositionList() {
    numElts = 0;
    header = new DNode<E>(null, null, null);	// create header
    trailer = new DNode<E>(header, null, null);	// create trailer
    header.setNext(trailer);	// make header and trailer point to each other
  }
  /** Checks if position is valid for this list and converts it to
    *  DNode if it is valid; O(1) time */
  protected DNode<E> checkPosition(Position<E> p)
    throws InvalidPositionException {
    if (p == null)
      throw new InvalidPositionException
	("Null position passed to NodeList");
    if (p == header)
	throw new InvalidPositionException
	  ("The header node is not a valid position");
    if (p == trailer)
	throw new InvalidPositionException
	  ("The trailer node is not a valid position");
    try {
      DNode<E> temp = (DNode<E>) p;
      if ((temp.getPrev() == null) || (temp.getNext() == null))
	throw new InvalidPositionException
	  ("Position does not belong to a valid NodeList");
      return temp;
    } catch (ClassCastException e) {
      throw new InvalidPositionException
	("Position is of wrong type for this list");
    }
  }
  //end#fragment checkPosition
  //begin#fragment first
  /** Returns the number of elements in the list;  O(1) time */
  public int size() { return numElts; }
  /** Returns whether the list is empty;  O(1) time  */
  public boolean isEmpty() { return (numElts == 0); }
  /** Returns the first position in the list; O(1) time */
  public Position<E> first()
      throws EmptyListException {
    if (isEmpty())
      throw new EmptyListException("List is empty");
    return header.getNext();
  }
  //end#fragment first
  /** Returns the last position in the list; O(1) time */
  public Position<E> last()
      throws EmptyListException {
    if (isEmpty())
      throw new EmptyListException("List is empty");
    return trailer.getPrev();
  }
  //begin#fragment first
  /** Returns the position before the given one; O(1) time */
  public Position<E> prev(Position<E> p)
      throws InvalidPositionException, BoundaryViolationException {
    DNode<E> v = checkPosition(p);
    DNode<E> prev = v.getPrev();
    if (prev == header)
      throw new BoundaryViolationException
	("Cannot advance past the beginning of the list");
    return prev;
  }
  //end#fragment first
  /** Returns the position after the given one; O(1) time */
  public Position<E> next(Position<E> p)
      throws InvalidPositionException, BoundaryViolationException {
    DNode<E> v = checkPosition(p);
    DNode<E> next = v.getNext();
    if (next == trailer)
      throw new BoundaryViolationException
	("Cannot advance past the end of the list");
    return next;
  }
  //begin#fragment first
  /** Insert the given element before the given position;
    * O(1) time  */
  public void addBefore(Position<E> p, E element) 
      throws InvalidPositionException {
    DNode<E> v = checkPosition(p);
    numElts++;
    DNode<E> newNode = new DNode<E>(v.getPrev(), v, element);
    v.getPrev().setNext(newNode);
    v.setPrev(newNode);
  }
  //end#fragment first
  /** Insert the given element after the given position;
    * O(1) time  */
  public void addAfter(Position<E> p, E element) 
      throws InvalidPositionException {
    DNode<E> v = checkPosition(p);
    numElts++;
    DNode<E> newNode = new DNode<E>(v, v.getNext(), element);
    v.getNext().setPrev(newNode);
    v.setNext(newNode);
  }
  //begin#fragment remove
  /** Insert the given element at the beginning of the list, returning
    * the new position; O(1) time  */
  public void addFirst(E element) {
    numElts++;
    DNode<E> newNode = new DNode<E>(header, header.getNext(), element);
    header.getNext().setPrev(newNode);
    header.setNext(newNode);
  }
  //end#fragment remove
  /** Insert the given element at the end of the list, returning
    * the new position; O(1) time  */
  public void addLast(E element) {
    numElts++;
    DNode<E> oldLast = trailer.getPrev();
    DNode<E> newNode = new DNode<E>(oldLast, trailer, element);
    oldLast.setNext(newNode);
    trailer.setPrev(newNode);
  }
  //begin#fragment remove
  /**Remove the given position from the list; O(1) time */
  public E remove(Position<E> p)
      throws InvalidPositionException {
    DNode<E> v = checkPosition(p);
    numElts--;
    DNode<E> vPrev = v.getPrev();
    DNode<E> vNext = v.getNext();
    vPrev.setNext(vNext);
    vNext.setPrev(vPrev);
    E vElem = v.element();
    // unlink the position from the list and make it invalid
    v.setNext(null);
    v.setPrev(null);
    return vElem;
  }
  /** Replace the element at the given position with the new element
    * and return the old element; O(1) time  */
  public E set(Position<E> p, E element)
      throws InvalidPositionException {
    DNode<E> v = checkPosition(p);
    E oldElt = v.element();
    v.setElement(element);
    return oldElt;
  }
  //end#fragment remove

//begin#fragment Iterator
  /** Returns an iterator of all the elements in the list. */
  public Iterator<E> iterator() { return new ElementIterator<E>(this); }
//end#fragment Iterator
//begin#fragment PIterator
  /** Returns an iterable collection of all the nodes in the list. */
  public Iterable<Position<E>> positions() {     // create a list of posiitons
    PositionList<Position<E>> P = new NodePositionList<Position<E>>();
    if (!isEmpty()) {
      Position<E> p = first();
      while (true) {
	P.addLast(p); // add position p as the last element of list P
	if (p == last())
	  break;
	p = next(p);
      }
    }
    return P; // return P as our Iterable object
  }
//end#fragment PIterator

  // Convenience methods
  /** Returns whether a position is the first one;  O(1) time */
  public boolean isFirst(Position<E> p)
    throws InvalidPositionException {  
    DNode<E> v = checkPosition(p);
    return v.getPrev() == header;
  }
  /** Returns whether a position is the last one;  O(1) time */
  public boolean isLast(Position<E> p)
      throws InvalidPositionException {  
    DNode<E> v = checkPosition(p);
    return v.getNext() == trailer;
  }
  /** Swap the elements of two give positions;  O(1) time */ 
  public void swapElements(Position<E> a, Position<E> b) 
      throws InvalidPositionException {
    DNode<E> pA = checkPosition(a);
    DNode<E> pB = checkPosition(b);
    E temp = pA.element();
    pA.setElement(pB.element());
    pB.setElement(temp);
  }
  /** Returns a textual representation of a given node list using for-each */
  public static <E> String forEachToString(PositionList<E> L) {
    String s = "[";
    int i = L.size();
    for (E elem: L) {
      s += elem; // implicit cast of the element to String
      i--;
      if (i > 0)
	s += ", "; // separate elements with a comma
    }
    s += "]";
    return s;
  }
//begin#fragment toString
  /** Returns a textual representation of a given node list */
  public static <E> String toString(PositionList<E> l) {
    Iterator<E> it = l.iterator();
    String s = "[";
    while (it.hasNext()) {
      s += it.next();	// implicit cast of the next element to String
      if (it.hasNext())
	s += ", ";
      }
    s += "]";
    return s;
  }
//end#fragment toString
  /** Returns a textual representation of the list */
  public String toString() {
    return toString(this);
  }
}
