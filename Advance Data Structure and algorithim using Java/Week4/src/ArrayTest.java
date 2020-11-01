import java.util.Arrays;
import java.util.Random;
/** Program showing some array uses. */
public class ArrayTest {
	
	/** Insertion sort of an array of characters into non-decreasing order */
	  public static void insertionSort(char[] a) { 
	    int n = a.length;
	    for (int i = 1; i < n; i++) {	// index from the second character in a
	      char cur = a[i];			// the current character to be inserted
	      int j = i - 1;			// start comparing with cell left of i
	      while ((j >= 0) && (a[j] > cur))	// while a[j] is out of order with cur
		a[j + 1] = a[j--];		// move a[j] right and decrement j
	      a[j + 1]=cur;			// this is the proper place for cur
	    }
	  }
	public static void main(String[] args) {
    int num[] = new int[10];
    Random rand = new Random();  // a pseudo-random number generator
    rand.setSeed(System.currentTimeMillis()); // use current time as a seed
    // fill the num array with pseudo-random numbers from 0 to 99, inclusive
    for (int i = 0; i < num.length; i++)
      num[i] = rand.nextInt(100); // the next pseudo-random number
    int[] old = (int[]) num.clone();	  // cloning the num array
    System.out.println("arrays equal before sort: " + Arrays.equals(old,num));
    Arrays.sort(num); // sorting the num array (old is unchanged)
    System.out.println("arrays equal after sort: " + Arrays.equals(old,num));
    System.out.println("old = " + Arrays.toString(old));
    System.out.println("num = " + Arrays.toString(num));
  }
}
