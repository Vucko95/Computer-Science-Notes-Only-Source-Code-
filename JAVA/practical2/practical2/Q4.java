package practical2;

import java.util.Scanner;

public class Q4 {
	public static void main(String[] args) {
		// Read a number
		Scanner input = new Scanner(System.in);
		System.out.print("Enter an integer value (0 to 15): ");
		int number = input.nextInt();

		// Check if number is valid
		if (number < 0 || number > 15)
			System.out.println(number + " is an invalid input");
		else if (number < 10) // If number < 10, display number
			System.out.println("The hex value is " + number);
		else { // If number >= 10, display corresponding letter
			char hex = (char)('A' + number - 10);
			System.out.println("The hex value is " + hex);
		}
		
		// Close the Scanner
		input.close();
	}
}
