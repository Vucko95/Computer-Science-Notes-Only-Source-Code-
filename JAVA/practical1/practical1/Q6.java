package practical1;

import java.util.Scanner;

public class Q6 {
	public static void main(String[] args) {
		// Read a number
		Scanner input = new Scanner(System.in);
		System.out.print("Enter an integer between 0 and 999 (inclusive): ");
		int number = input.nextInt();

		// Find all digits in number
		int lastDigit = number % 10;
		int remainingNumber = number / 10;
		int secondLastDigit = remainingNumber % 10;
		remainingNumber = remainingNumber / 10;
		int thirdLastDigit = remainingNumber % 10;

		// Obtain the sum of all digits
		int sum = lastDigit + secondLastDigit + thirdLastDigit;

		// Display results
		System.out.println("The sum of all digits in " + number + " is " + sum);
	}
}