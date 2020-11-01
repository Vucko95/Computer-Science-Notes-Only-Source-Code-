package practical2;

import java.util.Scanner;

public class Q5 {
	public static void main(String[] args) {
		// Read a character
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a lowercase or uppercase letter: ");
		char ch = input.next().charAt(0);

		// Check if ch is either a lowercase or uppercase letter
		if (Character.isLowerCase(ch) || Character.isUpperCase(ch)) {
			// First convert ch to lowercase and then check if it is a vowel 
			char lower = Character.toLowerCase(ch);
			boolean isVowel = lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
			
			// Display results
			System.out.println(ch + " is a " + (isVowel ? "vowel" : "consonant"));
		} else // Invalid input entered 
			System.out.println(ch + " is an invalid input");
		
		// Close the Scanner
		input.close();
	}
}
