/*
 * Write a program to calculate the area of a circle: 
 * - Prompt the user to enter the radius from the keyboard
 * - If the radius is >= 0; calculate the area and print the output
 * - If the radius is negative, display a suitable message to the user
 */

package chapter3_examples;

import java.util.Scanner; // Scanner is in the java.util package

public class ComputeArea {
	public static void main(String[] args) {
		// Create a Scanner object
		Scanner input = new Scanner(System.in);

		// Prompt the user to enter a radius
		System.out.println("Enter a number for radius:");
		double radius = input.nextDouble();

		// If radius is >= 0, then calculate the area and display the result
		if (radius >= 0) {
			double area = Math.pow(radius, 2) * Math.PI;
			System.out.println("The area is " + area);
		} 
		else // Otherwise, display message
			System.out.println("The radius must be >= 0");		
	}
}
