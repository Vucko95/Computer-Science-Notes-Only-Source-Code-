package net.datastructures;
/**
 * An interface for a complete binary tree.  A binary tree with height
 * <tt>h</tt> is <b>complete</b> if the levels 0,1,2,...,<tt>h</tt> -
 * 1 have the maximum number of nodes possible (that is, level
 * <tt>i</tt> has 2<sup>i</sup> nodes, for 0 <= <tt>i</tt> <=
 * <tt>h</tt> - 1) and in level <tt>h</tt> - 1 all the internal nodes
 * are to the left of the external nodes.
 *
 * @author Michael Goodrich
 */
//begin#fragment HeapTree
public interface CompleteBinaryTree<E> extends BinaryTree<E> {
//end#fragment HeapTree
  /** Adds an element to the tree just after the last node. Returns
   * the newly created position. */
//begin#fragment HeapTree
  public Position<E> add(E elem);
//end#fragment HeapTree
  /** Removes and returns the element stored in the last node of the
   * tree. */
//begin#fragment HeapTree
  public E remove();
}
//end#fragment HeapTree
