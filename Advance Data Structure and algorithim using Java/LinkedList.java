
public class LinkedList<T> implements List<T> {
	private class Node implements Position<T> {
		T element;
		Node next, prev;
		
		public Node(T element) {
			this.element = element;
		}

		@Override
		public T element() {
			return element;
		}
	}
	
	Node front, rear;
	int size = 0;
	
	@Override
	public int size() {
		return size;
	}

	@Override
	public boolean isEmpty() {
		return size == 0;
	}

	@Override
	public Position<T> first() {
		if (front == null) throw new ListEmptyException();
		return front;
	}

	@Override
	public Position<T> last() {
		if (rear == null) throw new ListEmptyException();
		return rear;
	}

	@Override
	public Position<T> prev(Position<T> p) {
		return ((Node) p).prev;
	}

	@Override
	public Position<T> next(Position<T> p) {
		return ((Node) p).next;
	}

	@Override
	public Position<T> insertFirst(T e) {
		Node n = new Node(e);
		if (front == null) {
			rear = n;
		} else {
			n.next = front;
			front.prev = n;
		}
		front = n;
		size++;
		return n;
	}

	@Override
	public Position<T> insertLast(T e) {
		Node n = new Node(e);
		if (rear == null) {
			front = n;
		} else {
			n.prev = rear;
			rear.next = n;
		}
		rear = n;
		size++;
		return n;
	}

	@Override
	public Position<T> insertBefore(Position<T> p, T e) {
		if (p == front) return insertFirst(e);
		
		Node node = (Node) p;
		
		Node n = new Node(e);
		n.prev = node.prev;
		n.next = node;
		node.prev.next = n;
		node.prev = n;
		size++;
		return n;
	}

	@Override
	public Position<T> insertAfter(Position<T> p, T e) {
		if (p == rear) return insertLast(e);
		
		Node node = (Node) p;
		
		Node n = new Node(e);
		n.next = node.next;
		n.prev = node;
		node.next.prev = n;
		node.next = n;
		size++;
		return n;
	}

	@Override
	public T replace(Position<T> p, T e) {
		T temp = p.element();
		((Node) p).element = e;
		return temp;
	}

	@Override
	public T remove(Position<T> p) {
		Node node = (Node) p;
		if (node == front) front = front.next;
		else node.prev.next = node.next;

		if (node == rear) rear = rear.prev;
		else node.next.prev = node.prev;

		size--;
		return node.element;
	}

	public String toString() {
		if (size == 0) return "";
		
		String output = "[" + size + "]";
		Node c = front;
		while (c != null) {
			output += " " + c.element;
			c = c.next;
		}
		return output;
	}

	@Override
	public Iterator<T> iterator() {
		return new Iterator<T>() {
			private Position<T> current;

			@Override
			public boolean hasNext() {
				if (isEmpty()) return false;
				if (current == null) return true;
				return !current.equals(last());
			}

			@Override
			public T next() {
				if (current == null) {
					current = first();
				} else {
					// The line below has a problem because next() is defined in both the
					// outer class and the inner class.  To overcome situations like this
					// java allows you to specify which method you mean (it defaults to
					// the method in the inner class).  To access the method in the outer
					// class, you use <class-name>.this.<method> (<classname.this refers
					// to the outer class instance).
					current = LinkedList.this.next(current);
				}
				return current.element();
			}
		};
	}
}
