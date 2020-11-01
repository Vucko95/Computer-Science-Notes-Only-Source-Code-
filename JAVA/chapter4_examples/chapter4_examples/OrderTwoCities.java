/*
 * A program that reads the names of two cities from the console and displays
 * the cities in alphabetical order.
 */

package chapter4_examples;

import java.util.Scanner;

public class OrderTwoCities {
	public static void main(String[] args) {
		// Create a Scanner object
		Scanner input = new Scanner(System.in);

		// Prompt the user to enter two cities
		System.out.print("Enter the first city: ");
		String city1 = input.nextLine();
		System.out.print("Enter the second city: ");
		String city2 = input.nextLine();

		// Display the cities in alphabetical order 
		System.out.println("The cities in alphabetical order are:");
		
		if (city1.compareTo(city2) < 0)
			System.out.println(city1 + "\n" + city2);
		else
			System.out.println(city2 + "\n" + city1);
		
		// Close the Scanner
		input.close();
	}
}