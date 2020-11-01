import java.util.Arrays;
import java.util.Scanner;

/**
   This program demonstrates the linear search algorithm.
*/
public class LinearSearchDemo
{  
   public static void main(String[] args)
   {  
      int[] a = ArrayUtil.randomIntArray(20, 100);
      System.out.println(Arrays.toString(a));
      LinearSearcher searcher = new LinearSearcher(a);

      Scanner in = new Scanner(System.in);

      boolean done = false;
      while (!done)
      {
         System.out.print("Enter number to search for, -1 to quit: ");
         int n = in.nextInt();
         if (n == -1) 
            done = true;
         else
         {
            int pos = searcher.search(n);
            System.out.println("Found in position " + pos);
         }
      }
   }
}
