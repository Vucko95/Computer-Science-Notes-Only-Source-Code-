/*
 * A program to demonstrate stepwise refinement using method stubs.
 * In particular, the program determines whether or not a credit card number is valid.
 */

package chapter6_examples;

import java.util.Scanner;

public class ValidateCCStubs {
	// main method
	public static void main(String[] args) {
		// Prompt the user to enter a credit card number
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a credit card number: ");
		String number = input.nextLine().trim();

		// Display result
		System.out.println(number + (isValidNumber(number) ? " is valid" : " is invalid"));
		
		// Close the Scanner
		input.close();
	}

	// Return true if the card number is valid
	public static boolean isValidNumber(String number) {
		return false; 
	}

	// Return true if the card number has between 13 and 16 digits 
	public static boolean hasValidLength(String number) {
		return false;
	}

	// Return true if the card number has a valid prefix
	public static boolean hasValidPrefix(String number) {
		return false;
	}
	
	// Return true if the Mod 10 check is satisfied
	public static boolean satisfiesMod10Check(String number) {
		return false;
	}
	
	// Double every second digit from right to left and return sum
	public static int sumOfDoubleEvenPlace(String number) {
		return 0;
	}

	// Return sum of digits in odd places from right to left 
	public static int sumOfOddPlace(String number) {
		return 0;
	}

	// Return this number if it is a single digit; 
	// otherwise return the sum of the two digits 
	public static int getSumDigits(int number) {
		return 0;
	}
}
