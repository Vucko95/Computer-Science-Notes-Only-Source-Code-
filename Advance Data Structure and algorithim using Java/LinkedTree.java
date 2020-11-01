package net.datastructures;
import java.util.Iterator;
import net.datastructures.*;

//begin#fragment Tree
/**
 * A linked class for a tree where nodes have an arbitrary number of children.
//end#fragment Tree
 * @author Luca Vismara, Roberto Tamassia, Michael Goodrich, Eric Zamore
//begin#fragment Tree
 */
public class LinkedTree<E> implements Tree<E> {
  protected TreePosition<E> root; // reference to the root
  protected int size;		  // number of nodes
  /**  Creates an empty tree. */
  public LinkedTree() { 		    
    root = null;  // start with an empty tree
    size = 0;
  }
  /** Returns the number of nodes in the tree. */
  public int size() {
    return size; 
  } 
//end#fragment LinkedTree
  /** Returns whether the tree is empty. */
  public boolean isEmpty() {
    return (size == 0); 
  } 
//begin#fragment LinkedTree
  /** Returns whether a node is internal. */
  public boolean isInternal(Position<E> v) throws InvalidPositionException {
    return !isExternal(v);
  }
//end#fragment LinkedTree
  /** Returns whether a node is external. */
  public boolean isExternal(Position<E> v) throws InvalidPositionException {
    TreePosition<E> vv = checkPosition(v);	// auxiliary method
    return (vv.getChildren() == null) || vv.getChildren().isEmpty();
  }
//begin#fragment LinkedTree
  /** Returns whether a node is the root. */
  public boolean isRoot(Position<E> v) throws InvalidPositionException { 
    checkPosition(v);
    return (v == root()); 
  }
//begin#fragment LinkedTree
  /** Returns the root of the tree. */
  public Position<E> root() throws EmptyTreeException {
    if (root == null)
      throw new EmptyTreeException("The tree is empty");
    return root;
  } 
//end#fragment LinkedTree
//begin#fragment LinkedTree2
  /** Returns the parent of a node. */
  public Position<E> parent(Position<E> v) 
    throws InvalidPositionException, BoundaryViolationException { 
    TreePosition<E> vv = checkPosition(v);
    Position<E> parentPos = vv.getParent();
    if (parentPos == null)
      throw new BoundaryViolationException("No parent");
    return parentPos; 
  }
  /** Returns an iterable collection of the children of a node. */
  public Iterable<Position<E>> children(Position<E> v) 
    throws InvalidPositionException { 
    TreePosition<E> vv = checkPosition(v);
    if (isExternal(v))
      throw new InvalidPositionException("External nodes have no children"); 
    return vv.getChildren();
  }
  /** Returns an iterable collection of the tree nodes. */
  public Iterable<Position<E>> positions() {
   PositionList<Position<E>> positions = new NodePositionList<Position<E>>();
    if(size != 0)
      preorderPositions(root(), positions);  // assign positions in preorder
    return positions;
  } 
 /** Returns an iterator of the elements stored at the nodes */
  public Iterator<E> iterator() {
    Iterable<Position<E>> positions = positions();
   PositionList<E> elements = new NodePositionList<E>();
   for (Position<E> pos: positions) 
     elements.addLast(pos.element());
    return elements.iterator();  // An iterator of elements
  }
  /** Replaces the element at a node. */
  public E replace(Position<E> v, E o) 
    throws InvalidPositionException {
    TreePosition<E> vv = checkPosition(v);
    E temp = v.element();
    vv.setElement(o);
    return temp;
  }
//end#fragment LinkedTree2
//begin#fragment LinkedTree3
  // Additional update methods
  /** Adds a root node to an empty tree */
  public Position<E> addRoot(E e) throws NonEmptyTreeException {
    if(!isEmpty())
      throw new NonEmptyTreeException("Tree already has a root");
    size = 1;
    root = createNode(e,null,null);
    return root;
  }
  /** Swap the elements at two nodes */
  public void swapElements(Position<E> v, Position<E> w)
    throws InvalidPositionException {
    TreePosition<E> vv = checkPosition(v);
    TreePosition<E> ww = checkPosition(w);
    E temp = w.element();
    ww.setElement(v.element());
    vv.setElement(temp);	
  }
  // Auxiliary methods
//begin#fragment LinkedTree5
  /** If v is a good tree node, cast to TreePosition, else throw exception */
  protected TreePosition<E> checkPosition(Position<E> v) 
    throws InvalidPositionException {
    if (v == null || !(v instanceof TreePosition))
      throw new InvalidPositionException("The position is invalid");
    return (TreePosition<E>) v;
  }
  /** Creates a new tree node */
  protected TreePosition<E> createNode(E element, TreePosition<E> parent, 
				  PositionList<Position<E>> children) {
    return new TreeNode<E>(element,parent,children); 
  }
  /** Creates a list storing the the nodes in the subtree of a node,
    * ordered according to the preorder traversal of the subtree. */
  protected void preorderPositions(Position<E> v, PositionList<Position<E>> pos)
      throws InvalidPositionException {
    pos.addLast(v);
    for (Position<E> w : children(v))
      preorderPositions(w, pos);	// recurse on each child
  }
}
//end#fragment LinkedTree5
