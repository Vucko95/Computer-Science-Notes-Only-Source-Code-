package practical1;

import java.util.Scanner;

public class Q3 {
	public static void main(String[] args) {
		// Enter the first point with two double values
		Scanner input = new Scanner(System.in);
		System.out.print("Enter x1 and y1: ");
		double x1 = input.nextDouble();
		double y1 = input.nextDouble();

		// Enter the second point with two double values
		System.out.print("Enter x2 and y2: ");
		double x2 = input.nextDouble();
		double y2 = input.nextDouble();

		// Compute the distance
		double distance = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));

		// Display results
		System.out.println("The distance of the two points is " + distance);
	}
}
