import java.util.Arrays;

public class QuickSortDemo
{  
   public static void main(String[] args)
   {  
      int[] a = ArrayUtil.randomIntArray(20, 100);
      System.out.println(Arrays.toString(a));

      QuickSorter sorter = new QuickSorter(a);
      sorter.sort();
      System.out.println(Arrays.toString(a));
   }
}

