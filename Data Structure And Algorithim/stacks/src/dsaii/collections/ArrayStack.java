package dsaii.collections;

import java.lang.reflect.Array;

public class ArrayStack<T> implements Stack<T> {
    private T[] array;
    private int top;

    public ArrayStack() {
        this(10);
    }
    public ArrayStack(int capacity) {
        array = (T[]) new Object[capacity];
        top = 0;
    }

    @Override
    public void push(T object) {
        if (top == array.length) throw new StackFullException();
        array[top] = object;
        top++;
    }

    @Override
    public T pop() {
        if (isEmpty()) throw new StackEmptyException();
        T temp = array[top-1];
        array[top-1] = null;
        top--;
        return temp;
    }

    @Override
    public T peek() {
        if (isEmpty()) throw new StackEmptyException();

        return array[top-1];
    }

    @Override
    public int size() {
        return top;
    }

    @Override
    public boolean isEmpty() {
        return top == 0;
    }
}
