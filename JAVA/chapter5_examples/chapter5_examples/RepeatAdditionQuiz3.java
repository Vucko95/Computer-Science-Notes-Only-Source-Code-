/*
 * A program that prompts the user to add two (randomly-generated) single digit 
 * integers. Using a loop, the user repeatedly enters an answer until it is correct.
 * 
 * Solution using a do-while loop and the break keyword.
 */

package chapter5_examples;

import java.util.Scanner;

public class RepeatAdditionQuiz3 {
	public static void main(String[] args) {
		// Create a Scanner
		Scanner input = new Scanner(System.in);

		// Generate two random numbers 
		int number1 = (int)(Math.random() * 10);
		int number2 = (int)(Math.random() * 10);
		
		// Loop until the user enters the correct answer
		do {
			// Prompt the user for an answer
			System.out.print("What is " + number1 + " + " + number2 + "? ");
			int answer = input.nextInt();
			
			if (number1 + number2 != answer) 
				System.out.print("Wrong answer. Try again. ");
			else 
				break;
		} while (true);

		System.out.println("You got it!");
		
		// Close the Scanner
		input.close();
	}
}
