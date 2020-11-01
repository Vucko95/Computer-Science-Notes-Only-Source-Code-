package dsaii.collections;

public interface Stack<T> {
    void push(T object);
    T pop();
    T peek();
    int size();
    boolean isEmpty();
}
