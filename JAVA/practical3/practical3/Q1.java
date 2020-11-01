package practical3;

import java.util.Scanner;

public class Q1 {
	public static void main(String[] args) {
		// Read a line of text
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a string: ");
		String str = input.nextLine(); 
		
		// Count the number of vowels and consonants in the text
		int numVowels = 0;
		int numConsonants = 0;
		String vowels = "aeiou";
		
		// Iterate over the characters in the string
		for (int i = 0; i < str.length(); i++) { 
			// Obtain the character and convert to lowercase
			char ch = Character.toLowerCase(str.charAt(i)); 
			
			// Check if the character is a vowel
			if (vowels.indexOf(ch) != -1) 
				numVowels++;
			// If not a vowel, check if the character is a letter
			else if (Character.isLetter(ch)) 
				numConsonants++;
		}
		
		// Display the result
		System.out.println("Number of vowels: " + numVowels);
		System.out.println("Number of consonants: " + numConsonants);
		
		// Close the Scanner
		input.close();
	}
}
