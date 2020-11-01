package net.datastructures;
import java.util.ArrayList;
import java.util.Iterator;
/**
  * A speedy implementation of the CompleteBinaryTree interface using
  * a vector.  Within the vector, there is a null element at rank 0,
  * the root of the tree at rank 1, and the rest of the tree is
  * contained as follows.  If node <code>n</code> has rank <i>i</i>,
  * then the left child of <code>n</code> will have rank 2*<i>i</i>,
  * and the right child of <code>n</code> will have rank 2*<i>i</i> +
  * 1.  Traversing the contents of the vector in order of increasing
  * rank yields a level-order traversal
  *
  * @author Michael Goodrich, Eric Zamore
  * @see BinaryTree
  * @see CompleteBinaryTree
  */

//begin#fragment VectorHeap
public class ArrayListCompleteBinaryTree<E> 
    implements CompleteBinaryTree<E>  {
  protected ArrayList<BTPos<E>> T;  // indexed list of tree positions
  /** Nested class for a index list-based complete binary tree node. */
  protected static class BTPos<E> implements Position<E> {
    E element; // element stored at this position
    int index;      // index of this position in the array list
    public BTPos(E elt, int i) { 
      element = elt;
      index = i; 
    }
    public E element() { return element; }
    public int index() { return index; }
    public E setElement(E elt) {
      E temp = element;
      element = elt;
      return temp;
    }
//end#fragment VectorHeap
    public String toString() {
      return("[" + element + "," + index + "]");
    }
//begin#fragment VectorHeap
  }
  /** default constructor */
  public ArrayListCompleteBinaryTree() { 
    T = new ArrayList<BTPos<E>>();
    T.add(0, null); // the location at rank 0 is deliberately empty
  }
  /** Returns the number of (internal and external) nodes. */
  public int size() { return T.size() - 1; } 
  /** Returns whether the tree is empty. */ 
  public boolean isEmpty() { return (size() == 0); } 
//end#fragment VectorHeap
//begin#fragment VectorHeap2
  /** Returns whether v is an internal node. */
  public boolean isInternal(Position<E> v) throws InvalidPositionException {
    return hasLeft(v);  // if v has a right child it will have a left child
  }
  /** Returns whether v is an external node. */
  public boolean isExternal(Position<E> v) throws InvalidPositionException {
    return !isInternal(v);
  }
  /** Returns whether v is the root node. */
  public boolean isRoot(Position<E> v) throws InvalidPositionException { 
    BTPos<E> vv = checkPosition(v);
    return vv.index() == 1;
  }
  /** Returns whether v has a left child. */
  public boolean hasLeft(Position<E> v) throws InvalidPositionException { 
    BTPos<E> vv = checkPosition(v);
    return 2*vv.index() <= size();
  }
  /** Returns whether v has a right child. */
  public boolean hasRight(Position<E> v) throws InvalidPositionException { 
    BTPos<E> vv = checkPosition(v);
    return 2*vv.index() + 1 <= size();
  }
  /** Returns the root of the tree. */
  public Position<E> root() throws EmptyTreeException {
    if (isEmpty()) throw new EmptyTreeException("Tree is empty");
    return T.get(1);
  } 
  /** Returns the left child of v. */
  public Position<E> left(Position<E> v) 
    throws InvalidPositionException, BoundaryViolationException { 
    if (!hasLeft(v)) throw new BoundaryViolationException("No left child");
    BTPos<E> vv = checkPosition(v);
    return T.get(2*vv.index());
  }
  /** Returns the right child of v. */ 
  public Position<E> right(Position<E> v) 
    throws InvalidPositionException { 
    if (!hasRight(v)) throw new BoundaryViolationException("No right child");
    BTPos<E> vv = checkPosition(v);
    return T.get(2*vv.index() + 1);
  }
//end#fragment VectorHeap2
//begin#fragment VectorHeap3
  /** Returns the parent of v. */
  public Position<E> parent(Position<E> v) 
    throws InvalidPositionException, BoundaryViolationException { 
    if (isRoot(v)) throw new BoundaryViolationException("No parent");
    BTPos<E> vv = checkPosition(v);
    return T.get(vv.index()/2);
  }
//end#fragment VectorHeap3
  /** Returns an iterable collection of the children of v. */ 
  public Iterable<Position<E>> children(Position<E> v) throws InvalidPositionException { 
    PositionList<Position<E>> children = new NodePositionList<Position<E>>();
    if (hasLeft(v))
      children.addLast(left(v));
    if (hasRight(v))
      children.addLast(right(v));
    return children;
  }
  /** Returns an iterable collection of all the nodes in the tree. */
  public Iterable<Position<E>> positions() {
    ArrayList<Position<E>> P = new ArrayList<Position<E>>();
    Iterator<BTPos<E>> iter = T.iterator();
    iter.next(); // skip the first position
    while (iter.hasNext())
      P.add(iter.next());
    return P;
  }
//begin#fragment VectorHeap3
  /** Replaces the element at v. */
  public E replace(Position<E> v, E o) throws InvalidPositionException {
    BTPos<E> vv = checkPosition(v);
    return vv.setElement(o);
  }
  /** Adds an element just after the last node (in a level numbering). */
  public Position<E> add(E e) {
    int i = size() + 1;
    BTPos<E> p = new BTPos<E>(e,i);
    T.add(i, p);
    return p;
  }
  /** Removes and returns the element at the last node. */
  public E remove() throws EmptyTreeException {
    if(isEmpty()) throw new EmptyTreeException("Tree is empty");
    return T.remove(size()).element(); 
  }
  /** Determines whether the given position is a valid node. */
  protected BTPos<E> checkPosition(Position<E> v) 
    throws InvalidPositionException 
  {
    if (v == null || !(v instanceof BTPos))
      throw new InvalidPositionException("Position is invalid");
    return (BTPos<E>) v;
  }
//end#fragment VectorHeap3
  // Additional Methods
  /** Returns the sibling of v. */ 
  public Position<E> sibling(Position<E> v) 
    throws InvalidPositionException, BoundaryViolationException {
    try {
      Position<E> p = parent(v);
      Position<E> lc = left(p);
      if (v == lc)
	return right(p);
      else
	return lc;
    }
    catch(BoundaryViolationException e) {
      throw new BoundaryViolationException("Node has no sibling");
    }
  }
  /** Swaps the elements at two nodes. */
  public void swapElements(Position<E> v, Position<E> w)
    throws InvalidPositionException {
    BTPos<E> vv = checkPosition(v);
    BTPos<E> ww = checkPosition(w);
    E temp = vv.element();
    vv.setElement(ww.element());
    ww.setElement(temp);
  }
//begin#fragment VectorHeap3
  /** Returns an iterator of the elements stored at all nodes in the tree. */
  public Iterator<E> iterator() { 
    ArrayList<E> list = new ArrayList<E>();
    Iterator<BTPos<E>> iter = T.iterator();
    iter.next(); // skip the first element
    while (iter.hasNext())
      list.add(iter.next().element());
    return list.iterator();
  } 
//end#fragment VectorHeap3
  /** Returns a String representing this complete binary tree. */
  public String toString() { return T.toString(); }
//begin#fragment VectorHeap3
} 
//end#fragment VectorHeap3
