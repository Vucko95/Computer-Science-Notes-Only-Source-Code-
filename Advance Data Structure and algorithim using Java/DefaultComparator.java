package net.datastructures;
import java.util.Comparator;
import java.io.Serializable;
/** Comparator based on the natural ordering
  *
  *  @author Michael Goodrich
  */
//begin#fragment DefaultComparator
public class DefaultComparator<E> implements Comparator<E> {
//end#fragment DefaultComparator
  /** Compares two given elements
    *
    * @return a negative integer if <tt>a</tt> is less than <tt>b</tt>,
    * zero if <tt>a</tt> equals <tt>b</tt>, or a positive integer if
    * <tt>a</tt> is greater than <tt>b</tt>
    */
//begin#fragment DefaultComparator
  public int compare(E a, E b) throws ClassCastException { 
    return ((Comparable<E>) a).compareTo(b);
  }
}
//end#fragment DefaultComparator
