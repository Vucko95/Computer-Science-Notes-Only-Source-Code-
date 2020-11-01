 package net.datastructures;
/**
  * Interface for a queue: a collection of elements that are inserted
  * and removed according to the first-in first-out principle.
  *
  * @author Michael T. Goodrich
  * @author Natasha Gelfand
  * @author Mark Handy
  * @author Roberto Tamassia
  * @see EmptyQueueException
  */

//begin#fragment Queue
public interface Queue<E> {  
 /** 
  * Returns the number of elements in the queue.
  * @return number of elements in the queue.
  */
  public int size();  
 /** 
  * Returns whether the queue is empty.
  * @return true if the queue is empty, false otherwise.
  */
  public boolean isEmpty(); 
 /**
  * Inspects the element at the front of the queue.
  * @return element at the front of the queue.
  * @exception EmptyQueueException if the queue is empty.
  */
  public E front() throws EmptyQueueException; 
 /** 
  * Inserts an element at the rear of the queue.
  * @param element new element to be inserted.
  */
  public void enqueue (E element); 
 /** 
  * Removes the element at the front of the queue.
  * @return element removed.
  * @exception EmptyQueueException if the queue is empty.
  */
  public E dequeue() throws EmptyQueueException; 
}
//end#fragment Queue
