/*
 * An example program using array reference variables.
 */

package chapter7_examples;

public class ArrayReferenceTest {
	public static void main(String[] args) {
		int[] list1 = {1, 2, 3, 4, 5};
		int[] list2 = {10, 20, 30};

		System.out.println(list1 == list2);
		
		list2 = list1;
		
		System.out.println(list1 == list2);
		
		list1[0] = 100;
		list2[1] = 200;

		System.out.print("\nlist1: ");
		for (int i = 0; i < list1.length; i++)
			System.out.print(list1[i] + " " );
		System.out.println();
		
		System.out.print("\nlist2: ");
		for (int i = 0; i < list2.length; i++)
			System.out.print(list2[i] + " " );
	}
}
