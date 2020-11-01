package net.datastructures;
//begin#fragment TPos
/**
 * Interface for a node of a binary tree. It maintains an element, a
 * parent node, a left node, and a right node.
//end#fragment TPos
 *
 *  @author Michael Goodrich
//begin#fragment TPos
 */
public interface TreePosition<E> extends Position<E> { 	// inherits element()
  public void setElement(E o);
  public PositionList<Position<E>> getChildren(); 
  public void setChildren(PositionList<Position<E>> c);
  public TreePosition<E> getParent(); 
  public void setParent(TreePosition<E> v);
}
//end#fragment TPos
