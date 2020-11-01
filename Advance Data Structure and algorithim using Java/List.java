public interface List<T> extends Iterable<T> {
    public int size();
    public boolean isEmpty();
    public Position<T> first();
    public Position<T> last();
    public Position<T> prev(Position<T> p);
    public Position<T> next(Position<T> p);
    public Position<T> insertFirst(T e);
    public Position<T> insertLast(T e);
    public Position<T> insertBefore(Position<T> p, T e);
    public Position<T> insertAfter(Position<T> p, T e);
    public T replace(Position<T> p, T e);
    public T remove(Position<T> p);
}
