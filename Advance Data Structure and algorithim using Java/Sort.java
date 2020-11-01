package net.datastructures;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Comparator;
import java.util.Random;
import java.util.Arrays;
/**
 * Class containing various sorting algorithms.
 *
 * @author Michael Goodrich, Roberto Tamassia, Eric Zamore
 */
public class Sort {
  //begin#fragment mergeSort
  /**
   * Sorts the elements of list in in nondecreasing order according
   * to comparator c, using the merge-sort algorithm.
   **/
  public static <E> void mergeSort (PositionList<E> in, Comparator<E> c) {
    int n = in.size();
    if (n < 2) 
      return;  // the in list is already sorted in this case
    // divide
    PositionList<E> in1 = new NodePositionList<E>(); 
    PositionList<E> in2 = new NodePositionList<E>(); 
    int i = 0;
    while (i < n/2) {
      in1.addLast(in.remove(in.first())); // move the first n/2 elements to in1
      i++;
    }
    while (!in.isEmpty())
      in2.addLast(in.remove(in.first())); // move the rest to in2
    // recur
    mergeSort(in1,c);
    mergeSort(in2,c);
    //conquer
    merge(in1,in2,c,in);
  }
  //end#fragment mergeSort
  
  //begin#fragment merge
  /**
   * Merges two sorted lists, in1 and in2, into a sorted list in.
   **/
  public static <E> void merge(PositionList<E> in1, PositionList<E> in2, 
         Comparator<E> c, PositionList<E> in) {
    while (!in1.isEmpty() && !in2.isEmpty())
      if (c.compare(in1.first().element(), in2.first().element()) <= 0)
        in.addLast(in1.remove(in1.first()));
      else
        in.addLast(in2.remove(in2.first()));
    while(!in1.isEmpty()) // move the remaining elements of in1
      in.addLast(in1.remove(in1.first()));
    while(!in2.isEmpty()) // move the remaining elements of in2
      in.addLast(in2.remove(in2.first()));
  }
  //end#fragment merge

  //begin#fragment mergeSort2
  /** Sorts an array with a comparator using nonrecursive merge sort.  */
  public static <E> void mergeSort(E[] orig, Comparator<E> c) { 
    E[] in = (E[]) new Object[orig.length]; // make a new temporary array
    System.arraycopy(orig,0,in,0,in.length); // copy the input
    E[] out = (E[]) new Object[in.length]; // output array
    E[] temp; // temp array reference used for swapping
    int n = in.length;
    for (int i=1; i < n; i*=2) { // each iteration sorts all length-2*i runs 
      for (int j=0; j < n; j+=2*i)  // each iteration merges two length-i pairs
        merge(in,out,c,j,i); // merge from in to out two length-i runs at j
      temp = in; in = out; out = temp; // swap arrays for next iteration
    }
    // the "in" array contains the sorted array, so re-copy it
    System.arraycopy(in,0,orig,0,in.length);
  }
  /** Merges two subarrays, specified by a start and increment. */
  protected static <E> void merge(E[] in, E[] out, Comparator<E> c, int start, 
      int inc) { // merge in[start..start+inc-1] and in[start+inc..start+2*inc-1]
    int x = start; // index into run #1
    int end1 = Math.min(start+inc, in.length); // boundary for run #1
    int end2 = Math.min(start+2*inc, in.length); // boundary for run #2
    int y = start+inc; // index into run #2 (could be beyond array boundary)
    int z = start; // index into the out array
    while ((x < end1) && (y < end2)) 
      if (c.compare(in[x],in[y]) <= 0) out[z++] = in[x++];
      else out[z++] = in[y++];
    if (x < end1) // first run didn't finish
      System.arraycopy(in, x, out, z, end1 - x);
    else if (y < end2) // second run didn't finish
      System.arraycopy(in, y, out, z, end2 - y);
  }
  //end#fragment mergeSort2
      
  /**
   * Sorts the elements of list in in nondecreasing order according to
   * comparator c, using a list-based implementation of the deterministic 
   * quicksort algorithm.
   **/
  public static <E> void quickSort(PositionList<E> in, Comparator<E> c) {
    if (in.size() <= 1) 
      return;
    E pivot = in.remove(in.last());
    PositionList<E> lesser = new NodePositionList<E>();
    PositionList<E> equal = new NodePositionList<E>();
    PositionList<E> greater = new NodePositionList<E>();
    E cur;
    while (!in.isEmpty()) {
      cur = in.remove(in.first());
      if (c.compare(cur,pivot) < 0)
	lesser.addFirst(cur);
      else if(c.compare(cur,pivot) == 0)
	equal.addFirst(cur);
      else
	greater.addFirst(cur);
    }
    quickSort(lesser,c);  // recur on lesser list
    quickSort(greater,c); // recur on greater list
    while(!lesser.isEmpty())
      in.addLast(lesser.remove(lesser.first()));
    while(!equal.isEmpty())
      in.addLast(equal.remove(equal.first()));
    in.addLast(pivot);
    while(!greater.isEmpty())
      in.addLast(greater.remove(greater.first()));
  }


  /**
   * Sorts the elements of array s in nondecreasing order according
   * to comparator c, using the quick-sort algorithm. Most of the work
   * is done by the auxiliary recursive method quickSortStep.
   **/
  //begin#fragment quickSort
  public static <E> void quickSort (E[] s, Comparator<E> c) {
    if (s.length < 2) return; // the array is already sorted in this case
    quickSortStep(s, c, 0, s.length-1); // recursive sort method
  }
  //end#fragment quickSort
  
  /**
   * Sorts in nondecreasing order the elements of sequence s between
   * ranks leftBound and rightBound, using a recursive, in-place,
   * implementation of the quick-sort algorithm.
   **/
  //begin#fragment quickSortStep
  private static <E> void quickSortStep (E[] s, Comparator<E> c,
                              int leftBound, int rightBound ) {
    if (leftBound >= rightBound) return; // the indices have crossed
    E temp;  // temp object used for swapping
    E pivot = s[rightBound];
    int leftInd = leftBound;     // will scan rightward
    int rightInd = rightBound-1; // will scan leftward
    while (leftInd <= rightInd) { // scan right until larger than the pivot
      while ( (leftInd <= rightInd) && (c.compare(s[leftInd], pivot)<=0) )
        leftInd++; 
      while ( (rightInd >= leftInd) && (c.compare(s[rightInd], pivot)>=0))
        rightInd--;
      if (leftInd < rightInd) { // both elements were found, so swap
        temp = s[rightInd]; s[rightInd] = s[leftInd]; s[leftInd] = temp;
      }
    } // the loop continues until the indices cross
    temp = s[rightBound]; // swap pivot with element at leftInd
    s[rightBound] = s[leftInd]; 
    s[leftInd] = temp; // the pivot is now at leftInd
    quickSortStep(s, c, leftBound, leftInd-1); // left recursive call
    quickSortStep(s, c, leftInd+1, rightBound); // right recursive call
  }
  //end#fragment quickSortStep
  
  public static void main (String[] argv) throws IOException {
    out("Start your engines...");
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    Random r = new Random();
    Comparator<Integer> c = new DefaultComparator<Integer>();
    out("Enter number of elements:");
    String num = in.readLine();
    int n = (new Integer(num)).intValue();
    String cont;
    Integer[] A = new Integer[n];
    Integer[] B = new Integer[n];
    float msin=0f,qsin=0f,msout=0f,qsout=0f;
    long t;
    do {
      PositionList<Integer> C = new NodePositionList<Integer>();
      PositionList<Integer> D = new NodePositionList<Integer>();
      for (int i = 0; i < n; i++) {
        int x = r.nextInt(100);
        A[i] = new Integer(x);
        B[i] = new Integer(x);
	C.addLast(new Integer(x));
	D.addLast(new Integer(x));
      }
      out("Array-Based Sorting");
      out("Before: " + Arrays.asList(A));

      //array-based mergesort
      t = System.currentTimeMillis();
      mergeSort(A, c);
      msin = (System.currentTimeMillis()-t)/1000f;
      out("MSort:  " + Arrays.asList(A));

      String correct = Arrays.asList(A).toString();

      //array-based quicksort
      t = System.currentTimeMillis();
      quickSort(B, c);
      qsin = (System.currentTimeMillis()-t)/1000f;
      out("QSort:  " + Arrays.asList(B));

      if(!correct.equals(Arrays.asList(B).toString())) {
	System.out.println("sorts produced different results!");
	System.exit(1);
      }

      out("List-Based Sorting");

      //list-based mergesort
      t = System.currentTimeMillis();
      mergeSort(C, c);
      out("MSort:  " + C);
      msout = (System.currentTimeMillis()-t)/1000f;

      if(!correct.equals(C.toString())) {
	System.out.println("sorts produced different results!");
	System.exit(1);
      }

      //list-based quicksort
      t = System.currentTimeMillis();
      quickSort(D, c);
      out("QSort:  " + D);
      qsout = (System.currentTimeMillis()-t)/1000f;

      if(!correct.equals(D.toString())) {
	System.out.println("sorts produced different results!");
	System.exit(1);
      }
      
      out("Times (in seconds)");
      out("Array-Based");
      out("MSort:  "+msin);
      out("QSort:  "+qsin);
      out("List-Based");
      out("MSort:  "+msout);
      out("QSort:  "+qsout);

      out("Type 'e' to end ...");
      cont = in.readLine();
    } while (cont.equals(""));
  } 
  
  private static void out (String s) {
    System.out.println(s);
  }
}
