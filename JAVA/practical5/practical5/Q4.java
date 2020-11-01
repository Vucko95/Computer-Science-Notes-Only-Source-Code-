/**
 * A program to play a game of Hangman
 */

package practical5;

import java.util.Scanner;

public class Q4 {
	public static void main(String[] args) {
		// Create an instance of the Scanner class
		Scanner input = new Scanner(System.in);

		// Use an array of strings to hold the dictionary words
		String[] words = {"hello", "world", "hello world", "hangman"};

		// Each game is one iteration around this do-while loop
		do { 
			// Randomly select the target word from the dictionary
			int index = (int) (Math.random() * words.length);
			String word = words[index].toLowerCase();

			// Create a char array to hold the user's guesses
			// Initialise all elements to '*'
			char[] guesses = createArray(word.length());

			// Keep a count of the number of letters correctly guessed
			int numberHits = 0; 

			// Keep a count of the number of incorrect guesses 
			int numberMisses = 0;

			// Iterate until the user has guessed all letters in the word
			while (numberHits < word.length()) {
				// Prompt the user to enter a letter
				System.out.print("Guess a letter [" + new String(guesses) + "] > ");
				char letter = input.nextLine().toLowerCase().charAt(0); // Convert to lowercase

				// Check if the letter has already been guessed correctly
				if (alreadyGuessed(guesses, letter)) { 
					System.out.println("\t'" + letter + "' is already in the word");
				} else if (word.indexOf(letter) < 0) { // Check if the letter is not in the word
					System.out.println("\t'" + letter + "' is not in the word");
					numberMisses++;
				} else { // The letter is in the word
					for (int i = 0; i < word.length(); i++) 
						if (word.charAt(i) == letter) {
							guesses[i] = letter; // Replace '*' with letter
							numberHits++; // Increment number of correct guesses
						}
				}
			}

			// The current game is over - display message to the user
			System.out.println("\t You win! The word is [" + word + "]. You missed "
					+ numberMisses + ((numberMisses == 1) ? " time" : " times") + ".\n");

			// Prompt the user to enter 'y' or 'Y' to play again
			System.out.print("Enter 'y' to play again or any other character to exit > ");
			if (input.nextLine().toLowerCase().charAt(0) != 'y')
				break; // The user does not wish to play again, quit
		} while (true);

		// Display a final message
		System.out.println("Goodbye");

		// Close the Scanner
		input.close();
	}

	// Returns a char array with all elements initialised to '*'
	public static char[] createArray(int size) {
		char[] arr = new char[size];

		for (int i = 0; i < arr.length; i++)
			arr[i] = '*';

		return arr;
	}

	// Returns true if char ch is present in the array
	public static boolean alreadyGuessed(char[] arr, char ch) {
		boolean present = false;

		for (int i = 0; i < arr.length; i++)
			if (arr[i] == ch) {
				present = true;
				break;
			}

		return present;
	}
}
