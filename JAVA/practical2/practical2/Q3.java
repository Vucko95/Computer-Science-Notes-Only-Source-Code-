package practical2;

import java.util.Scanner;

public class Q3 {
	public static void main(String[] args) {
		// Read coordinates
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the x and y coordinates of a point: ");
		double x = input.nextDouble();
		double y = input.nextDouble();

		// Perform tests and display results
		if (Math.abs(x) <= 5 && Math.abs(y) <= 2.5)
			System.out.println("Point (" + x + ", " + y + ") is in the rectangle");
		else
			System.out.println("Point (" + x + ", " + y + ") is not in the rectangle");
		
		// Close the Scanner
		input.close();
	}
}
