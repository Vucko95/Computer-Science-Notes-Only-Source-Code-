import java.util.Arrays;

/**
   This program demonstrates the selection sort algorithm by
   sorting an array that is filled with random numbers.
*/
public class SelectionSortDemo
{  
   public static void main(String[] args)
   {  
      int[] a = ArrayUtil.randomIntArray(20, 100);
      System.out.println(Arrays.toString(a));

      SelectionSorter sorter = new SelectionSorter(a);
      sorter.sort();

      System.out.println(Arrays.toString(a));
   }
}

   
