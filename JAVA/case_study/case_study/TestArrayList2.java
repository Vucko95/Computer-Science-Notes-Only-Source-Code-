package case_study;

import java.util.ArrayList;
import java.util.List;

public class TestArrayList2 {
	public static void main(String[] args) {
		// Create a list to store integers
		List<Integer> list = new ArrayList<>();
		list.add(1);
		list.add(2);
		
		// Display the integer at index 1
		int n = list.get(1);
		System.out.println(n);
		
		// Display the contents in the list
		System.out.println(list.toString());
		
		// Display the elements in the hash set using a foreach loop
		for (int i: list)
			System.out.print(i + " ");
		System.out.println();
	}
}
