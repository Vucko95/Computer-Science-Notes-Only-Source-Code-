/**
 *
 * @author rem
 */
public interface List {
    public int size();
    public boolean isEmpty();
    public Position first() throws ListEmptyException;
    public Position last() throws ListEmptyException;
    public Position prev(Position p) throws BoundaryViolationException;
    public Position next(Position p) throws BoundaryViolationException;
    public Position insertFirst(Object e);
    public Position insertLast(Object e);
    public Position insertBefore(Position p, Object e);
    public Position insertAfter(Position p, Object e);
    public Object replace(Position p, Object e);
    public Object remove(Position p);
}
