package worksheet5;
import worksheet3.StackEmptyException;

public class LinkedStack<T> implements Stack<T> {
	private class Node {
		T element;
		Node next;

		public Node(T value) {
			element = value;
		}
	}

	private Node top = null;
	private int size = 0;

	public int size() {
		return size;
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public void push(T value) {
		Node n = new Node(value);
		n.next = top;

		top = n;
		size++;
	}

	public T top() {
		if (isEmpty()) {
			throw new StackEmptyException();
		}
		return top.element;
	}

	public T pop() {
		if (isEmpty()) {
			throw new StackEmptyException();
		}
		T toReturn = top.element;

		top = top.next;
		size--;

		return toReturn;
	}

	public String toString() {
		String out = "[" + size + " element(s)]: ";
		Node n = top;
		while (n != null) {
			out += "[" + n.element + "|-]-> ";
			n = n.next;
		}
		return out;
	}
}