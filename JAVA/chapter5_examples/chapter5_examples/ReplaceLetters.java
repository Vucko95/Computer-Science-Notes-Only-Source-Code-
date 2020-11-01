/*
 * A program that reads a line of text from the console and replaces
 * (1) every lowercase letter in the input text with its uppercase 
 * equivalent and (2) every uppercase letter in the input text with 
 * its lowercase equivalent.
 */

package chapter5_examples;

import java.util.Scanner;

public class ReplaceLetters {
	public static void main(String[] args) {
		// Read a line of text
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a line of text: ");
		String s1 = input.nextLine();
		
		// Iterate over the characters in the string
		String s2 = "";
		for (int i = 0; i < s1.length(); i++) { 
			char ch = s1.charAt(i);
			
			if (Character.isLowerCase(ch))
				s2 += Character.toUpperCase(ch);
			else if (Character.isUpperCase(ch))
				s2 += Character.toLowerCase(ch);
			else
				s2 += ch;
		}
		
		// Display result
		System.out.println("The modified line of text is: " + s2);
		
		// Close the Scanner
		input.close();
	}
}
