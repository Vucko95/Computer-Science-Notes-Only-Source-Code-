package practical5;

import java.util.Scanner;

public class Q2 {
	public static void main (String[] args) {
		// Create an instance of the Scanner class
		Scanner input = new Scanner(System.in);

		// Prompt the user to enter the number of integers
		System.out.println("Enter the number of integers: ");
		int size = input.nextInt();

		if (size <= 0) 
			System.out.println("The array does not contain four consecutive integers");
		else {
			// Declare and create an array
			int[] list = new int[size];

			// Prompt the user to enter the integers
			System.out.println("Enter the integers: ");
			for (int i = 0; i < list.length; i++)
				list[i] = input.nextInt();

			// Check if the list has four consecutive numbers with the same value
			if (isConsecutiveFour(list))
				System.out.println("The array contains four consecutive integers");
			else
				System.out.println("The array does not contain four consecutive integers");
		}
		
		// Close the Scanner
		input.close();
	}

	// Returns true if the array has (at least one instance of) four consecutive integers with the same value
	public static boolean isConsecutiveFour(int[] values) {    
		for (int i = 0; i < values.length; i++) { // The current element value is given by values[i] 
			boolean isEqual = true; // Assume the next three element values are equal to the current element value

			for (int j = i + 1; j < i + 4; j++) { // Iterate over the next three element values
				if (j >= values.length) // Return false if j exceeds the bounds of the array
					return false;

				if (values[i] != values[j]) { // If values are not equal, set isEqual to false and break out of the inner for loop 
					isEqual = false; 
					break;
				}
			}

			if (isEqual) // Return true if isEqual is still equal to true
				return true; 
		}

		return false; // If this point is reached, there are no consecutive fours, return false 
	}
}

