public class LinkedStack {
	private class Node {
		Object element;
		Node next;

		public Node(Object value) {
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

	public void push(Object value) {
		Node n = new Node(value);
		n.next = top;

		top = n;
		size++;
	}

	public Object top() {
		if (isEmpty()) {
			throw new StackEmptyException();
		}
		return top.element;
	}

	public Object pop() {
		if (isEmpty()) {
			throw new StackEmptyException();
		}
		Object toReturn = top.element;

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