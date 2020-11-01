// Dealing with invalid input using a Scanner object.
// Version 1 - using exception handling.


package chapter12_examples_1;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ReadNumber1 {
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
			try {
				System.out.print("Enter an integer: ");
				n = s.nextInt();
				break;
			}
			catch (InputMismatchException ex) {
				// When a scanner throws an InputMismatchException, 
				// the scanner will not pass the token that caused 
				// the exception; invoke nextLine to advance beyond
				// the token. 
				s.nextLine();
			}
		} while(true);
		
		return n;
	}
}
