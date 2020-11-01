 /**
  * Implementation of the Deque interface by means of a doubly linked
  * list.  This class uses class DLNode, which implements a node of
  * the list.
  *   
  * @author Natasha Gelfand
  * @author Roberto Tamassia
  */

//begin#fragment NodeDeque
public class NodeDeque<E> implements Deque<E> {
  protected DLNode<E> header, trailer;  // sentinels
  protected int size;    // number of elements
//end#fragment NodeDeque
  /** Creates an empty deque. */
//begin#fragment NodeDeque
  public NodeDeque() {  // initialize an empty deque
    header = new DLNode<E>();
    trailer = new DLNode<E>();
    header.setNext(trailer);  // make header point to trailer
    trailer.setPrev(header);  // make trailer point to header
    size = 0;
  }
  //end#fragment NodeDeque
    
/** 
 * Return the size of the deque, that is the number of elements it has. 
 * @return  Number of elements in the deque
 */
 //begin#fragment size
  public int size() {   
    return size;
  }
  //end#fragment size
    
/** 
 * This function returns true if and only if the deque is empty 
 * @return  true if the deque is empty, false otherwise
 */
 //begin#fragment isEmpty
  public boolean isEmpty() {    
    if (size == 0)
      return true;
    return false;
  }
 //end#fragment isEmpty

/** 
 * Inspect the first element without modifying the deque.
 * @return The first element in the sequence
 */    
 //begin#fragment first
  public E getFirst() throws EmptyDequeException {  
    if (isEmpty())
      throw new EmptyDequeException("Deque is empty.");
    return header.getNext().getElement();
  }
 //end#fragment first
 
  public E getLast() throws EmptyDequeException { 
    if (isEmpty())
      throw new EmptyDequeException("Deque is empty.");
    return trailer.getPrev().getElement();
  }

  //begin#fragment addFirst
  public void addFirst(E o) {  
    DLNode<E> second = header.getNext();
    DLNode<E> first = new DLNode<E>(o, header, second);
    second.setPrev(first);
    header.setNext(first);
    size++;
  }
  //end#fragment addFirst

  public void addLast(E o) {  
    DLNode<E> secondtolast = trailer.getPrev();
    DLNode<E> last = new DLNode<E>(o, secondtolast, trailer);
    secondtolast.setNext(last);
    trailer.setPrev(last);
    size++;
  }

  public E removeFirst() throws EmptyDequeException {
    if (isEmpty())
      throw new EmptyDequeException("Deque is empty.");
    DLNode<E> first = header.getNext();
    E o = first.getElement();
    DLNode<E> second = first.getNext();
    header.setNext(second);
    second.setPrev(header);
    size--;
    return o;
   }

  //begin#fragment removeLast
  public E removeLast() throws EmptyDequeException {
    if (isEmpty())
      throw new EmptyDequeException("Deque is empty.");
    DLNode<E> last = trailer.getPrev();
    E o = last.getElement();
    DLNode<E> secondtolast = last.getPrev();
    trailer.setPrev(secondtolast);
    secondtolast.setNext(trailer);
    size--; 
    return o;
  }
  //end#fragment removeLast

//begin#fragment tail
}
//end#fragment tail
