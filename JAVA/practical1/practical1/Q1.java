package practical1;

import java.util.Scanner;

public class Q1 {
	public static void main(String[] args) {
		// Read radius and length
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the radius and length of a cylinder: ");
		double radius = input.nextDouble();
		double length = input.nextDouble();

		// Perform calculations
		double area = Math.PI * Math.pow(radius, 2);
		double volume = area * length;

		// Display results
		System.out.println("The area is " + area);
		System.out.println("The volume of the cylinder is " + volume);
	}
}
