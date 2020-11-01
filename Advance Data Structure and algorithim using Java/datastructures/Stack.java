package net.datastructures;
//begin#fragment Stack
 /** 
  * Interface for a stack: a collection of objects that are inserted
  * and removed according to the last-in first-out principle.  This
  * interface includes the main methods of java.util.Stack.
  * 
  * @author Roberto Tamassia
  * @author Michael Goodrich
  * @see EmptyStackException
  */

public interface Stack<E> {
 /**
  * Return the number of elements in the stack.
  * @return number of elements in the stack. 
  */
  public int size();
 /** 
  * Return whether the stack is empty.
  * @return true if the stack is empty, false otherwise. 
  */
  public boolean isEmpty();
 /** 
  * Inspect the element at the top of the stack.
  * @return top element in the stack.  
  * @exception EmptyStackException if the stack is empty. 
  */
  public E top() 
    throws EmptyStackException;  
 /**
  * Insert an element at the top of the stack.
  * @param element to be inserted.
  */
  public void push (E element); 
 /** 
  * Remove the top element from the stack.
  * @return element removed.
  * @exception EmptyStackException if the stack is empty.
  */
  public E pop()
    throws EmptyStackException; 
}
//end#fragment Stack
