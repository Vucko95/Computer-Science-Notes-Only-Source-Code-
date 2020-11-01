// Dealing with invalid input using a Scanner object.
// Version 2 - using methods in the Scanner class.

package chapter12_examples_1;

import java.util.Scanner;

public class ReadNumber2 {
	public static void main(String[] args) {
		// Create an instance of the Scanner class
		Scanner input = new Scanner(System.in);

		// Read an integer
		int num = readInt(input);
		System.out.println("The integer is: " + num);

		// Close the Scanner
		input.close();
	}

	public static int readInt(Scanner s) {
		int n;

		do {
			System.out.print("Enter an integer: ");
			if (s.hasNextInt()) {
				n = s.nextInt();
				break;
			} else
				// The scanner does not advance past the 
				// token if hasNextInt if false; invoke
				// nextLine to advance beyond the token.
				s.nextLine();
		} while(true);

		return n;
	}
}
