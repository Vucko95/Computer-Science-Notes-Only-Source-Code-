public class NodeQueue<E> implements Queue<E> {
	private Node<E> head;
	private Node<E> tail;
	private int size;
	
/**default constructor*/	
	public NodeQueue(){
		head=null;
		tail=null;
		size=0;
	}
	public E dequeue() throws EmptyQueueException {
		if (size==0)
			throw new EmptyQueueException("Queue is empty");
		E tmp=head.getElement();
		head=head.getNext();
		size--;
		if (size==0)
			tail=null; //the queue is now empty
		return tmp;
	}

	public void enqueue(E element) {
		Node<E> node = new Node<E>();
		node.setElement(element);
		node.setNext(null); //node will be new tail node
		if (size==0)
			head=node; //special case of a previously empty queue
		else
			tail.setNext(node); //add node at the tail of the list
		tail=node; //update the reference to the tail node
		size++;

	}

	public E front() throws EmptyQueueException {
		if (size==0)
			throw new EmptyQueueException("Queue is empty");
		else return head.getElement();
	}

	public boolean isEmpty() {
		return (size==0);
	}

	public int size() {
		return size;
	}
	
	public String toString(){
		Node<E> temp=head;
		String s="";
		while(temp!=null){
			s+=temp.getElement()+"\n";
			temp=temp.getNext();
		}
		return s;
		
	}

}
