/*
 *  A program that reads an integer n (where n is the pattern size) from the 
 *  console and displays the pattern as shown below.
 *  
 *  1
 *  1 2
 *  1 2 3
 *  
 *  (pattern for n = 3)
 *  
 *  1
 *  1 2
 *  1 2 3
 *  1 2 3 4
 *  
 *  (pattern for n = 4)
 */

package chapter5_examples;

import java.util.Scanner;

public class DisplayPattern {
	public static void main(String[] args) {
		// Create a Scanner
		Scanner input = new Scanner(System.in);

		// Prompt the user to enter the pattern size (n)
		System.out.print("Enter the pattern size: ");
		int n = input.nextInt();
		
		// Display the pattern
		for (int i = 1; i <= n; i++) { // outer loop - i denotes rows
			for (int j = 1; j <= i; j++) // inner loop - j denotes columns
				System.out.print(j + " ");
			
			System.out.println();
		}
		
		// Close the Scanner
		input.close();
	}
}
