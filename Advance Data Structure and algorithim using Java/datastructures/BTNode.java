package net.datastructures;
//begin#fragment BTNode
/**
 * Class implementing a node of a binary tree by storing references to
 * an element, a parent node, a left node, and a right node.
//end#fragment BTNode
 *
 *  @author Luca Vismara, Roberto Tamassia, Michael Goodrich
//begin#fragment BTNode
 */
public class BTNode<E> implements BTPosition<E> {
  private E element;  // element stored at this node
  private BTPosition<E> left, right, parent;  // adjacent nodes
//end#fragment BTNode
  /** Default constructor */
  public BTNode() { }
//begin#fragment BTNode
  /** Main constructor */
  public BTNode(E element, BTPosition<E> parent, 
		BTPosition<E> left, BTPosition<E> right) { 
    setElement(element);
    setParent(parent);
    setLeft(left);
    setRight(right);
  }
  /** Returns the element stored at this position */
  public E element() { return element; }
  /** Sets the element stored at this position */
  public void setElement(E o) { element=o; }
  /** Returns the left child of this position */
  public BTPosition<E> getLeft() { return left; }
  /** Sets the left child of this position */
  public void setLeft(BTPosition<E> v) { left=v; }
  /** Returns the right child of this position */
  public BTPosition<E> getRight() { return right; }
  /** Sets the right child of this position */
  public void setRight(BTPosition<E> v) { right=v; }
  /** Returns the parent of this position */
  public BTPosition<E> getParent() { return parent; }
  /** Sets the parent of this position */
  public void setParent(BTPosition<E> v) { parent=v; }
}
//end#fragment BTNode
