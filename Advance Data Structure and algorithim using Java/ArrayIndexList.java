package net.datastructures;
//begin#fragment vector
/** Realization of an indexed list by means of an array, which is doubled 
  * when the size of the indexed list exceeds the capacity of the array.  
//end#fragment vector
  *
  * @author Roberto Tamassia, Michael Goodrich
//begin#fragment vector
  */
public class ArrayIndexList<E> implements IndexList<E> {
  private E[] A;	      // array storing the elements of the indexed list
  private int capacity = 16;  // initial length of array A
  private int size = 0;	      // number of elements stored in the indexed list
  /** Creates the indexed list with initial capacity 16. */
  public ArrayIndexList() { 
    A = (E[]) new Object[capacity]; // the compiler may warn, but this is ok
  }
//end#fragment vector
  /** Returns the number of elements in the indexed list. */
  public int size() {
    return size;
  }
  /** Returns whether the indexed list is empty. */
  public boolean isEmpty() {
    return size() == 0; 
  }
  /** Returns the element stored at the given index. */
  public E get(int r) 
    throws IndexOutOfBoundsException {
    checkIndex(r, size());
    return A[r]; 
  }
  /** Replaces the element stored at the given index. */
  public E set(int r, E e) 
    throws IndexOutOfBoundsException {
    checkIndex(r, size());
    E temp = A[r];
    A[r] = e;
    return temp;
  }
//begin#fragment vector list
  /** Inserts an element at the given index. */
  public void add(int r, E e) 
    throws IndexOutOfBoundsException {
    checkIndex(r, size() + 1);
    if (size == capacity) {		// an overflow
      capacity *= 2;
      E[] B =(E[]) new Object[capacity];
      for (int i=0; i<size; i++) 
	B[i] = A[i];
      A = B;
    }
    for (int i=size-1; i>=r; i--)	// shift elements up
      A[i+1] = A[i];
    A[r] = e;
    size++;
  }
  /** Removes the element stored at the given index. */
  public E remove(int r) 
    throws IndexOutOfBoundsException {
    checkIndex(r, size());
    E temp = A[r];
    for (int i=r; i<size-1; i++)	// shift elements down
      A[i] = A[i+1];
    size--;
    return temp;
  }
//end#fragment vector
  /** Checks whether the given index is in the range [0, n - 1] */
  protected void checkIndex(int r, int n) // 
    throws IndexOutOfBoundsException {	// 
    if (r < 0 || r >= n)
      throw new IndexOutOfBoundsException("Illegal index: " + r);
  }
}
