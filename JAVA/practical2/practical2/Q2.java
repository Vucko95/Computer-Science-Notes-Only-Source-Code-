package practical2;

import java.util.Scanner;

public class Q2 {
	public static void main(String[] args) {   
		// Read input
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the length from the center to a vertex: ");
		double r = input.nextDouble();

		if (r > 0) { // Validate input
			// Perform calculations and display result
			double s = 2 * r * Math.sin(Math.PI / 5);
			double area = 5 * Math.pow(s, 2) / (4 * Math.tan(Math.PI / 5));
			System.out.println("The area of the pentagon is " + area);
		} else
			System.out.println("The length must be > 0");
		
		// Close the Scanner
		input.close();
	}
}