package worksheet5;

import worksheet3.StackEmptyException;
import worksheet3.StackFullException;


public class ArrayStack<T> implements Stack<T> {
	private T[] array = null;
	private int top = 0;
	
	public ArrayStack() {
		this(20);
	}
	
	@SuppressWarnings("unchecked")
	public ArrayStack(int capacity) {
		array = (T[]) new Object[capacity];
	}
	
	public int size() {
		return top;
	}
	
	public boolean isEmpty() {
		return top == 0;
	}
	
	public void push(T value) {
		if (top == array.length) throw new StackFullException();
		array[top++] = value;
	}
	
	public T top() {
		if (top == 0) throw new StackEmptyException(); 
		return array[top-1];
	}

	public T pop() {
		if (top == 0) throw new StackEmptyException();
		
		T temp = array[--top];
		array[top] = null;
		return temp;
	}
	
	public String toString() {
		String out = "[" + top + " / " + array.length + "]";
		for (int i=0;i<array.length; i++) {
			out += " " + array[i];
		}
		return out;
	}
}
