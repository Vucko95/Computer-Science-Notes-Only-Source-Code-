/*
 * A program that converts a hexadecimal digit into a decimal value.
 */

package chapter4_examples;

import java.util.Scanner;

public class HexDigit2Dec {
	public static void main(String[] args) {
		// Create a Scanner object
		Scanner input = new Scanner(System.in);
		
		// Prompt the user to enter a hex digit
		System.out.print("Enter a hex digit: ");
		char ch = input.next().charAt(0);
		
		// Obtain the decimal value for the hex digit
		int value;
		if (Character.isDigit(ch))
			value = ch - '0'; // Unicode decimal value for '0' is 48
		else if (ch >= 'A' && ch <= 'F')
			value = ch - 'A' + 10; // Unicode decimal value for 'A' is 65
		else
			value = -1;
		
		// Display result
		if (value != -1)
			System.out.println("The decimal value for " + ch + " is " + value);
		else
			System.out.println(ch + " is not a valid hex digit");
		
		// Close the Scanner
		input.close();
	}
}
