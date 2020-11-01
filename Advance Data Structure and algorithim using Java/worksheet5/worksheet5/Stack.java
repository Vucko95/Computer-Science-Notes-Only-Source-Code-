package worksheet5;

public interface Stack<T> {
	public int size();
	public boolean isEmpty();
	public T pop();
	public void push(T object);
	public T top();
}
