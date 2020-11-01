/*
 * Write a program that prompts the user to enter a year as an int value and checks if it is a leap year:
 * - A year is a leap year if it is divisible by 4 but not by 100, or it is divisible by 400
 */

package chapter3_examples;

import java.util.Scanner; 

public class LeapYear {
	public static void main(String args[]) {
		// Create a Scanner object
		Scanner input = new Scanner(System.in);
		
		// Prompt the user to enter a year
		System.out.println("Enter a year:");
		int year = input.nextInt();

		// Check if the year is a leap year 
		boolean isLeapYear = 
				(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

		// Display the result
		System.out.println("Is " + year + " a leap year? " + isLeapYear);   
	} 
}
