import java.util.Arrays;

/**
   This program demonstrates the insertion sort algorithm.
*/
public class InsertionSortDemo
{  
   public static void main(String[] args)
   {  
      int[] a = ArrayUtil.randomIntArray(20, 100);
      System.out.println(Arrays.toString(a));

      InsertionSorter sorter = new InsertionSorter(a);
      sorter.sort();
      System.out.println(Arrays.toString(a));
   }
}
