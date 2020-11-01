package case_study;

import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;

public class TestHashSet {
	public static void main(String[] args) {
		// Create a hash set
		Set<Integer> set = new HashSet<>();

		// Add integers to the set
		set.add(0);
		set.add(11);
		set.add(1);
		set.add(0);

		// Display the number of elements in the set
		System.out.println("set size: " + set.size()); 

		// Check if an element is in the set
		System.out.println("Is the integer 1 in the set? " +
				set.contains(1)); 

		// Display the elements in the hash set 
		System.out.println(set.toString());
		
		// Display the elements in the hash set using a foreach loop
		for (int i: set)
			System.out.print(i + " ");
		System.out.println();
		
		// Display the elements in the hash set using an iterator
		for(Iterator<Integer> it = set.iterator(); it.hasNext(); ) {
			int i = it.next();
			System.out.print(i + " ");
		}
	}
}
