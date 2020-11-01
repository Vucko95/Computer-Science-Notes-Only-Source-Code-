package net.datastructures;

/**
 * Realization of a queue by means of a singly-linked list of nodes.
 * All operations are performed in constant time.
 *
 * @author Roberto Tamassia
 */

public class NodeQueue<E> implements Queue<E> {

  protected Node<E> head, tail;  // the head and tail nodes
  protected int size;         // Keeps track of number of elements in queue

  /** Creates an empty queue. */
  public NodeQueue() {
    head = null;
    tail = null;
    size = 0;
  }
  
  public int size() {       //# Return the current queue size
    return size;
  }
  
  public boolean isEmpty() {      //# Returns true iff queue is empty
    if ( (head==null) && (tail==null) )
      return true;
    return false;
  }

  //begin#fragment enqueue
  public void enqueue(E elem) {
    Node<E> node = new Node<E>();
    node.setElement(elem);
    node.setNext(null); // node will be new tail node
    if (size == 0)
      head = node; // special case of a previously empty queue
    else
      tail.setNext(node); // add node at the tail of the list
    tail = node; // update the reference to the tail node
    size++;
  }
  //end#fragment enqueue

  public E front()     //# Return the first queue element
    throws EmptyQueueException {
    if (size == 0)
      throw new EmptyQueueException("Queue is empty.");
    return head.getElement();
  }
  
  //begin#fragment dequeue
  public E dequeue() throws EmptyQueueException {
    if (size == 0)
      throw new EmptyQueueException("Queue is empty.");
    E tmp = head.getElement();
    head = head.getNext();
    size--;
    if (size == 0)
      tail = null; // the queue is now empty
    return tmp;
  }
  //end#fragment dequeue

  public String toString() {
    String s = "";
    s += "(";
    if (!isEmpty()) {
      Node p = head;
      do {
	s += p.getElement() ;
	if (p != tail)
	  s += ", ";
	p = p.getNext();
      } while (p != null); 
    }
    s += ")";
    return s;
  }

 /**
  * Prints information about an operation and the queue.
  * @param op operation performed
  * @param element element returned by the operation
  * @return information about the operation performed, the element
  * returned by the operation and the content of the stack after 
  * the operation.
  */ 
  public static void status(Queue Q, String op, Object element) {
    System.out.println("---------------------------------");
    System.out.println(op);
    System.out.println("Returned: " + element);
    String emptyStatus;
    if (Q.isEmpty())
      emptyStatus = "empty";
    else
      emptyStatus = "not empty";
    System.out.println("size = " + Q.size() + ", " + emptyStatus);
    System.out.println("Queue: " + Q);
  }

 /**
  * Test program that performs a series of operations on on a queue and
  * prints the operation performed, the returned element and the
  * content of the stack after each operation.
  */
  public static void main(String[] args) {
    Object o;
    Queue<Integer> A = new NodeQueue<Integer>();
    status (A, "New empty queue", null);
    A.enqueue(5);
    status (A, "enqueue(5)", null);
    A.enqueue(3);
    status (A, "enqueue(3)", null);
    A.enqueue(7);
    status (A, "enqueue(7)", null);
    o = A.dequeue();
    status (A, "dequeue()", o);
    A.enqueue(9);
    status (A, "enqueue(9)", null);
    o = A.dequeue();
    status (A, "dequeue()", o);
    o = o = A.front();
    status (A, "front()", o);
  }
  
}
