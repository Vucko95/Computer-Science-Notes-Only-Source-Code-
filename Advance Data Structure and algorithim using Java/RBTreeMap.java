package net.datastructures;
import java.util.Comparator;

/** 
 * Realization of a red-black Tree by extending a binary search tree.
 *
 * @author Michael Goodrich, Roberto Tamassia, Eric Zamore
 */

//begin#fragment RBTree
/** Realization of a dictionary by means of a red-black tree. */
public class RBTreeMap<K,V>
  extends BinarySearchTreeMap<K,V> implements Map<K,V> {
  public RBTreeMap() { super(); }
  public RBTreeMap(Comparator<K> C) { super(C); }
  /** Nested class for the nodes of a red-black tree */
  protected static class RBNode<K,V> extends BTNode<Entry<K,V>> {
    protected boolean isRed;  // we add a color field to a BTNode
    RBNode() {/* default constructor */}
    /** Preferred constructor */
    RBNode(Entry<K,V> element, BTPosition<Entry<K,V>> parent,
	   BTPosition<Entry<K,V>> left, BTPosition<Entry<K,V>> right) {
      super(element, parent, left, right);
      isRed = false;
    } 
    public boolean isRed()  {return isRed;}
    public void makeRed()  {isRed = true;}
    public void makeBlack()  {isRed = false;}
    public void setColor(boolean color)  {isRed = color;}
  }
  //end#fragment RBTree
  //begin#fragment insertItem
  /** Creates a new tree node. */
  protected BTPosition<Entry<K,V>> createNode(Entry<K,V> element, 
      BTPosition<Entry<K,V>> parent, BTPosition<Entry<K,V>> left, 
      BTPosition<Entry<K,V>> right) {
    return new RBNode<K,V>(element,parent,left,right); // a red-black node
  }
  //end#fragment insertItem
  /** Inserts an item into the dictionary and returns the newly
   * created entry. */
  //begin#fragment insertItem
  public V put(K k, V x) throws InvalidKeyException  {
    V toReturn = super.put(k, x); 
    Position<Entry<K,V>> posZ = actionPos; // start at the insertion position
    setRed(posZ);
    if (isRoot(posZ))
      setBlack(posZ);
    else
      remedyDoubleRed(posZ); // fix a double-red color violation 
    return toReturn;
  }
  //end#fragment insertItem
  /** Remedies a double red violation at a given node caused by insertion. */
  //begin#fragment insertItem
  protected void remedyDoubleRed(Position<Entry<K,V>> posZ)  {
    Position<Entry<K,V>> posV = parent(posZ);
    if (isRoot(posV))
      return;
    if (!isPosRed(posV))
      return;
    // we have a double red: posZ and posV
    if (!isPosRed(sibling(posV)))  { // Case 1: trinode restructuring
      posV = restructure(posZ);
      setBlack(posV);
      setRed(left(posV));
      setRed(right(posV));
    }  
    else  { // Case 2: recoloring
      setBlack(posV);
      setBlack(sibling(posV));
      Position<Entry<K,V>> posU = parent(posV);
      if (isRoot(posU))
        return;
      setRed(posU);
      remedyDoubleRed(posU);
    }
  }
  //end#fragment insertItem
  /** Removes and returns the given entry from the dictionary. */
  //begin#fragment remedyDoubleBlack
  public V remove(K k) throws InvalidKeyException {
    V toReturn = super.remove(k);
    Position<Entry<K,V>> posR = actionPos;
    if (toReturn != null) {	
      if (wasParentRed(posR) || isRoot(posR) || isPosRed(posR))
	setBlack(posR);
      else
	remedyDoubleBlack(posR);
    }
    return toReturn;
  }
  //end#fragment remedyDoubleBlack
  /** Remedies a double black violation at a given node caused by removal. */
  //begin#fragment remedyDoubleBlack
  protected void remedyDoubleBlack(Position<Entry<K,V>> posR) {
    Position<Entry<K,V>> posX, posY, posZ;
    boolean oldColor;
    posX = parent(posR);
    posY = sibling(posR);
    if (!isPosRed(posY))  {
      posZ = redChild(posY);
      if (hasRedChild(posY))  { // Case 1: trinode restructuring
      	oldColor = isPosRed(posX);
	posZ = restructure(posZ);
      	setColor(posZ, oldColor);
	setBlack(posR);
      	setBlack(left(posZ));
      	setBlack(right(posZ));
	return;
      }
      setBlack(posR);
      setRed(posY);
      if (!isPosRed(posX))  { // Case 2: recoloring
        if (!isRoot(posX))
	  remedyDoubleBlack(posX);
	return;
      }
      setBlack(posX);
      return;
    } // Case 3: adjustment
    if (posY == right(posX)) posZ = right(posY);
    else posZ = left(posY);
    restructure(posZ);
    setBlack(posY);
    setRed(posX);
    remedyDoubleBlack(posR);
  }
  //end#fragment remedyDoubleBlack

  /** Returns whether a node is red. */
  protected boolean isPosRed(Position<Entry<K,V>> position)  {
    return ((RBNode) position).isRed();
  }

  /** Returns whether the former parent of a node was red. */
  private boolean wasParentRed(Position<Entry<K,V>> position){
    if (!isRoot(position)) {
      if(!isPosRed(position) && !isPosRed(parent(position))) {
	if (isExternal(sibling(position)) ||
	    (hasTwoExternalChildren(sibling(position)) &&
	     isPosRed(sibling(position))))
	  return true;  //then position's old parent was red
      }
    }
    return false;
  }
    
  /** Returns whether an internal node has two external children. */
  private boolean hasTwoExternalChildren(Position<Entry<K,V>> position){
    if (isExternal(left(position)) 
	&& isExternal(right(position)))
      return true;
    else 
      return false;
  }

  /** Colors a node red. */
  protected void setRed(Position<Entry<K,V>> position)  {
    ((RBNode) position).makeRed();
  }
    
  /** Colors a node black. */
  protected void setBlack(Position<Entry<K,V>> position)  {
    ((RBNode) position).makeBlack();
  }

  /** Sets the color of a node. 
   * @param color <tt>true</tt> to color the node red, <tt>false</tt>
   * to color the node black*/
  protected void setColor(Position<Entry<K,V>> position, boolean color)  {
    ((RBNode) position).setColor(color);
  }

  /** Returns a red child of a node. */
  protected Position<Entry<K,V>> redChild(Position<Entry<K,V>> position)  {
    Position<Entry<K,V>> child = left(position);
    if (isPosRed(child))
      return child;
    child = right(position);
    if (isPosRed(child))
      return child;
    return null;
  }

  /** Returns whether a node has a red child. */
  protected boolean hasRedChild(Position<Entry<K,V>> position){
    if (isPosRed(left(position)) || isPosRed(right(position)))
      return true;
    else
      return false;
  }

  /** 
   * Swaps the colors of <tt>a</tt> and <tt>b</tt> if they are
   * different and returns whether <tt>a</tt> was red.
   */
  protected boolean swapColor(Position<Entry<K,V>> a, Position<Entry<K,V>> b){
    boolean wasRed = false;
    if (isPosRed(a) && !isPosRed(b)){
      wasRed = true;
      setBlack(a);
      setRed(b);
    }
    else if (!isPosRed(a) && isPosRed(b)){
      setBlack(b);
      setRed(a);
    }
    return wasRed;
  }

  /** Swaps the colors and elements at the two nodes. */
  protected void swap(Position<Entry<K,V>> swapPos, Position<Entry<K,V>> remPos){
    swapColor(remPos, swapPos);
    swapElements(swapPos, remPos);
  }
}
