import java.util.Arrays;


public class ReverseArray {


    /** A nonrecursive generic method for reversing an array */
    public static <E> void reverse(E[] a) {
      Stack<E> S = new ArrayStack<E>(a.length);
      for (int i=0; i < a.length; i++)
        S.push(a[i]);
      for (int i=0; i < a.length; i++)
        a[i] = S.pop();
    }


    /** Tester routine for reversing arrays */
    public static void main(String args[]) {
      Integer[] a = {4, 8, 15, 16, 23, 42};  // autoboxing allows this
      String[] s = {"Jack", "Kate", "Hurley", "Jin", "Boone"};
      System.out.println("a = " + Arrays.toString(a));
      System.out.println("s = " + Arrays.toString(s));
      System.out.println("Reversing...");
      reverse(a);
      reverse(s);
      System.out.println("a = " + Arrays.toString(a));
      System.out.println("s = " + Arrays.toString(s));
    }

}
