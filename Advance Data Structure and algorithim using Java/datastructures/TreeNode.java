package net.datastructures;
//begin#fragment TNode
/**
 * Class implementing a node of a binary tree by storing references to
 * an element, a parent node, a left node, and a right node.
//end#fragment TNode
 *
 *  @author Luca Vismara, Roberto Tamassia, Michael Goodrich
//begin#fragment TNode
 */
public class TreeNode<E> implements TreePosition<E> {
  private E element;  // element stored at this node
  private TreePosition<E> parent;  // adjacent node
  private PositionList<Position<E>> children;  // children nodes
//end#fragment TNode
  /** Default constructor */
  public TreeNode() { }
//begin#fragment TNode
  /** Main constructor */
  public TreeNode(E element, TreePosition<E> parent, 
		PositionList<Position<E>> children) { 
    setElement(element);
    setParent(parent);
    setChildren(children);
  }
  /** Returns the element stored at this position */
  public E element() { return element; }
  /** Sets the element stored at this position */
  public void setElement(E o) { element=o; }
  /** Returns the children of this position */
  public PositionList<Position<E>> getChildren() { return children; }
  /** Sets the right child of this position */
  public void setChildren(PositionList<Position<E>> c) { children=c; }
  /** Returns the parent of this position */
  public TreePosition<E> getParent() { return parent; }
  /** Sets the parent of this position */
  public void setParent(TreePosition<E> v) { parent=v; }
}
//end#fragment TNode
