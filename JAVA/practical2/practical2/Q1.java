package practical2;

import java.util.Scanner;

public class Q1 {
	public static void main(String[] args) {
		// Read three lengths
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the lengths of the three sides of a triangle: ");
		double l1 = input.nextDouble();
		double l2 = input.nextDouble();
		double l3 = input.nextDouble();

		// Validate the inputs
		boolean isValid = l1 + l2 > l3 &&
				l1 + l3 > l2 && l2 + l3 > l1;

		// Display results
		if (isValid)
			System.out.println("The perimeter is " + (l1 + l2 + l3));
		else
			System.out.println("Input is invalid");
		
		// Close the Scanner
		input.close();
	} 
}
