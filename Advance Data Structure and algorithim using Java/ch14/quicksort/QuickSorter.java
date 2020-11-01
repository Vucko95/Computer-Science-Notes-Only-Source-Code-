public class QuickSorter
{
   private int[] a;

   public QuickSorter(int[] anArray)
   {
      a = anArray;
   }   

   /**
      Sorts the array managed by this merge sorter
   */
   public void sort()
   {  
      sort(0, a.length - 1);
   }

   public void sort(int from, int to)
   {
      if (from >= to) return;
      int p = partition(from, to);
      sort(from, p);
      sort(p + 1, to);
   }

   private int partition(int from, int to)
   {
      int pivot = a[from];
      int i = from - 1;
      int j = to + 1;
      while (i < j)
      {
         i++; while (a[i] < pivot) i++;
         j--; while (a[j] > pivot) j--;
         if (i < j) swap(i, j); 
      }
      return j;
   }

   /**
      Swaps two entries of the array.
      @param i the first position to swap
      @param j the second position to swap
   */
   private void swap(int i, int j)
   {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
   }
}
