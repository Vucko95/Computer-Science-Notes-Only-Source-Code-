import java.util.Scanner;

/**
   This program measures how long it takes to sort an
   array of a user-specified size with the merge
   sort algorithm.
*/
public class MergeSortTimer
{  
   public static void main(String[] args)
   {  
      Scanner in = new Scanner(System.in);
      System.out.print("Enter array size: ");
      int n = in.nextInt();

      // Construct random array
   
      int[] a = ArrayUtil.randomIntArray(n, 100);
      MergeSorter sorter = new MergeSorter(a);
      
      // Use stopwatch to time merge sort

      StopWatch timer = new StopWatch();

      timer.start();
      sorter.sort();
      timer.stop();

      System.out.println("Elapsed time: " 
            + timer.getElapsedTime() + " milliseconds");
   }
}

   
