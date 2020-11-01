/*
 * Write a program to teach a first grade child how to learn subtractions: 
 * - Prompt the user to enter two integers, n1 and n2
 * - To avoid dealing with negative numbers, if n1 < n2 then swap the numbers
 * - Prompt the user to answer the question: What is n1 – n2 ?
 * - Display whether the answer is correct
 */

package chapter3_examples;

import java.util.Scanner;

public class SubtractionTest {
	public static void main(String[] args) {
		// Create a Scanner object
		Scanner input = new Scanner(System.in);

		// Prompt the user to enter two integers
		System.out.println("Enter two integers:");
		int n1 = input.nextInt();
		int n2 = input.nextInt();

		// If n1 < n2 then swap the numbers
		if (n1 < n2) {
			int temp = n1;
			n1 = n2;
			n2 = temp;
		}

		// Prompt the student to answer the question: What is n1 - n2 ?
		System.out.println("What is " + n1 + " - " + n2 + "?");
		int answer = input.nextInt();

		// Display whether the answer is correct
		if (n1 - n2 == answer)
			System.out.println("Your answer is correct");
		else
			System.out.println("Your answer is wrong");
	}
}
