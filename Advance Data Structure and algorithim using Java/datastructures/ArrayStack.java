package net.datastructures;
//begin#fragment ArrayStack
 /**
  * Implementation of the stack ADT using a fixed-length array.  An
  * exception is thrown if a push operation is attempted when the size
  * of the stack is equal to the length of the array.  This class
  * includes the main methods of the built-in class java.util.Stack.
//end#fragment ArrayStack
  * 
  * @author Natasha Gelfand
  * @author Roberto Tamassia
  * @see FullStackException
//begin#fragment ArrayStack
  */
//begin#fragment ArrayStack
public class ArrayStack<E> implements Stack<E> {
//end#fragment ArrayStack
 /**
  * Length of the array used to implement the stack.
  */
//begin#fragment ArrayStack
  protected int capacity; 	// The actual capacity of the stack array
//end#fragment ArrayStack
 /**
  * Default array capacity.
  */
//begin#fragment ArrayStack
  public static final int CAPACITY = 1000;	// default array capacity
//end#fragment ArrayStack
 /**
  * Array used to implement the stack.
  */
//begin#fragment ArrayStack
  protected E S[];		// Generic array used to implement the stack 
//end#fragment ArrayStack
 /**
  * Index of the top element of the stack in the array.
  */
//begin#fragment ArrayStack
  protected int top = -1;	// index for the top of the stack
//end#fragment ArrayStack
 /**
  * Initializes the stack to use an array of default length.
  */
//begin#fragment ArrayStack
  public ArrayStack() {
    this(CAPACITY); // default capacity 
  }
//end#fragment ArrayStack
 /**
  * Initializes the stack to use an array of given length.
  * @param cap length of the array.
  */
//begin#fragment ArrayStack
  public ArrayStack(int cap) {
    capacity = cap;
    S = (E[]) new Object[capacity]; // compiler may give warning, but this is ok
  }
//end#fragment ArrayStack
 /**
  * Returns the number of elements in the stack.
  * This method runs in O(1) time.
  * @return number of elements in the stack. 
  */
//begin#fragment ArrayStack
  public int size() { 
    return (top + 1);
  }
//end#fragment ArrayStack
 /**
  * Testes whether the stack is empty.
  * This method runs in O(1) time.
  * @return true if the stack is empty, false otherwise.
  */
//begin#fragment ArrayStack
  public boolean isEmpty() {
    return (top < 0);
  }
//end#fragment ArrayStack
 /**
  * Inserts an element at the top of the stack.
  * This method runs in O(1) time.
  * @return element inserted.
  * @param element element to be inserted.
  * @exception FullStackException if the array storing the elements is full.
  */
//begin#fragment ArrayStack
  public void push(E element) throws FullStackException {
    if (size() == capacity)
      throw new FullStackException("Stack is full.");
    S[++top] = element;
  }
//end#fragment ArrayStack
 /**
  * Inspects the element at the top of the stack.
  * This method runs in O(1) time.
  * @return top element in the stack.  
  * @exception EmptyStackException if the stack is empty. 
  */
//begin#fragment ArrayStack
  public E top() throws EmptyStackException {
    if (isEmpty())
      throw new EmptyStackException("Stack is empty.");
    return S[top];
    }
//end#fragment ArrayStack
 /**
  * Removes the top element from the stack.
  * This method runs in O(1) time.
  * @return element removed.
  * @exception EmptyStackException if the stack is empty.
  */
//begin#fragment ArrayStack
  public E pop() throws EmptyStackException {
    E element;
    if (isEmpty())
      throw new EmptyStackException("Stack is empty.");
    element = S[top];
    S[top--] = null; // dereference S[top] for garbage collection.
    return element;
  }
//end#fragment ArrayStack

 /**
  * Returns a string representation of the stack as a list of elements,
  * with the top element at the end: [ ... , prev, top ].
  * This method runs in O(n) time, where n is the size of the stack.
  * @return textual representation of the stack.
  */
//begin#fragment ArrayStack2
  public String toString() {
    String s;
    s = "[";
    if (size() > 0) s+= S[0];
    if (size() > 1)
      for (int i = 1; i <= size()-1; i++) {
	s += ", " + S[i];
      }
    return s + "]";
  }
//end#fragment ArrayStack2
 /**
  * Prints status information about a recent operation and the stack.
  * @param op operation performed
  * @param element element returned by the operation
  * @return information about the operation performed, the element
  * returned by the operation and the content of the stack after 
  * the operation.
  */ 
//begin#fragment ArrayStack2
//  Prints status information about a recent operation and the stack.
  public void status(String op, Object element) {
    System.out.print("------> " + op);   // print this operation
    System.out.println(", returns " + element); // what was returned
    System.out.print("result: size = " + size() + ", isEmpty = " + isEmpty());
    System.out.println(", stack: " + this);       // contents of the stack
  }
//end#fragment ArrayStack2
//begin#fragment ArrayStack2
 /**
  * Test our program by performing a series of operations on stacks,
  * printing the operations performed, the returned elements and the
  * contents of the stack involved, after each operation.
  */
  public static void main(String[] args) {
    Object o;
    ArrayStack<Integer> A = new ArrayStack<Integer>();
    A.status("new ArrayStack<Integer> A", null);
    A.push(7);
    A.status("A.push(7)", null);
    o = A.pop();
    A.status("A.pop()", o);
    A.push(9);
    A.status("A.push(9)", null);
    o = A.pop();
    A.status("A.pop()", o);
    ArrayStack<String> B = new ArrayStack<String>();
    B.status("new ArrayStack<String> B", null);
    B.push("Bob");
    B.status("B.push(\"Bob\")", null);
    B.push("Alice");
    B.status("B.push(\"Alice\")", null);
    o = B.pop();
    B.status("B.pop()", o);
    B.push("Eve");
    B.status("B.push(\"Eve\")", null);
  }
}
//end#fragment ArrayStack2
