/*
 * Write a program that reads in a number and checks whether the number is:
 * - Divisible by both 2 and 3
 * - Divisible by 2 or 3 or both
 * - Divisible by 2 or 3 but not both
 */

package chapter3_examples;

import java.util.Scanner;

public class TestBooleanOperators {
	public static void main(String[] args) {
		// Create a Scanner Object
		Scanner input = new Scanner(System.in);

		// Prompt the user to enter a number
		System.out.println("Enter an integer: ");
		int number = input.nextInt();

		// Check if number is divisible by both 2 and 3
		boolean and = (number % 2 == 0) && (number % 3 == 0);
		System.out.println("Is " + number + " divisible by both 2 and 3? " + and);
		
		// Check if number is divisible by 2 or 3 or both
		boolean or = (number % 2 == 0) || (number % 3 == 0);
		System.out.println("Is " + number + " divisible by 2 or 3 or both? " + or);

		// Check if number is divisible by 2 or 3 but not both
		boolean xor = (number % 2 == 0) ^ (number % 3 == 0);		
		System.out.println("Is " + number + " divisible by 2 or 3 but not both? " + xor); 
	}
}
