package net.datastructures;

/**
 * A simple node class for a doubly-linked list.  Each node has a
 * reference to a stored element, a previous node, and a next node.
 * This class differs from the <code>DNode</code> class in that it
 * does not implement the <code>Position</code> interface, for
 * simplification purposes.
 *
 * @author Roberto Tamassia
 * @see DNode
 * @see Position
 */

//begin#fragment DLNode
public class DLNode<E> {
  private E element;
  private DLNode<E> next, prev;
  DLNode() { this(null, null, null); }
  DLNode(E e, DLNode<E> p, DLNode<E> n) {
    element = e;
    next = n;
    prev = p;
  }
  public void setElement(E newElem) { element = newElem; }
  public void setNext(DLNode<E> newNext) { next = newNext; }
  public void setPrev(DLNode<E> newPrev) { prev = newPrev; }
  public E getElement() { return element; }
  public DLNode<E> getNext() { return next; }
  public DLNode<E> getPrev() { return prev; }
}
//end#fragment DLNode
