/*
 * A program that reads and calculates the sum of an unspecified number of integers. 
 * The input 0 (the sentinel value) signifies the end of the input. 
 */

package chapter5_examples;

import java.util.Scanner; 

public class SentinelValue {
	public static void main(String[] args) {
		// Create a Scanner
		Scanner input = new Scanner(System.in);

		// Read an initial number
		System.out.print("Enter an int value (0 to exit): ");
		int number = input.nextInt();

		// Compute the sum - keep reading numbers until the input is 0
		int sum = 0;
		while (number != 0) {
			sum += number;

			// Read the next number
			System.out.print("Enter an int value (0 to exit): ");
			number = input.nextInt();
		}  // End of loop

		System.out.println("The sum is " + sum);
		
		// Close the Scanner
		input.close();
	}
}
