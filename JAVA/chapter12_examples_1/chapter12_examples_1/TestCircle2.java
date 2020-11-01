package chapter12_examples_1;

import java.util.Scanner;

public class TestCircle2 {
	public static void main(String[] args) {
		// Create an instance of the Scanner class
		Scanner input = new Scanner(System.in);
		
		// Keep reading a radius from the standard input
		// until a valid radius (>= 0) is entered
		Circle circle;
		do {
			System.out.print("Enter the radius: ");
			double radius = input.nextDouble();
			circle = createCircle(radius);
		} while (circle == null); 

		// Display the radius of circle
		System.out.println("The radius is: " + circle.getRadius());
		
		// Display the number of Circle objects created
		System.out.println("Number of objects created: " +
				Circle.getNumberOfObjects());
		
		// Close the Scanner
		input.close();
	}
	
	// Returns a reference to a circle object or null
	// if an exception occurs
	public static Circle createCircle(double radius) {
		Circle c;
		
		try {
			c = new Circle(radius);
		}
		catch (IllegalArgumentException ex) {
			c = null;
			System.out.println(ex);
		}
		
		return c;
	}
}
