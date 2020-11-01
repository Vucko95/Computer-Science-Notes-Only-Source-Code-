/*
 * Randomly generate 20 lowercase letters and assign to an array of characters.
 * Count the occurrence of each letter in the array and display the result. 
 */

package chapter7_examples;


public class CountLettersInArray {
	// Main method
	public static void main(String[] args) {
		// Declare array and invoke method createArray
		char[] randomChars = createArray(20);

		// Display the array
		System.out.println("The lowercase letters are:");
		displayArray(randomChars);

		// Count the occurrences of each letter
		int[] charCounts = countLetters(randomChars);

		// Display the occurrences of each letter
		System.out.println("\nThe occurrences of each letter are:");
		displayArray(charCounts);
	}

	// Create an array of randomly generated lowercase letters
	public static char[] createArray(int numberChars) {
		// Declare an create an array of characters
		char[] chars = new char[numberChars];

		// Randomly generate lowercase letters and assign them to the array
		for (int i = 0; i < chars.length; i++) 
			chars[i] = (char)('a' + Math.random() * ('z' - 'a' + 1));
		
		// Return the array
		return chars;
	}

	// Count the occurrences of each letter
	public static int[] countLetters(char[] chars) {
		// Declare and create an array of 26 integers
		// counts[0] gives the occurrences of 'a'
		int[] counts = new int[26]; // Default element values are 0

		// Count the occurrence of each lowercase letter in array chars
		for (int i = 0; i < chars.length; i++)
			counts[chars[i] - 'a']++;

		return counts;
	}

	// Display an array of characters
	public static void displayArray(char[] chars) {
		// Display the characters in the array
		for (char c: chars) 
			System.out.print(c + " ");
		System.out.println();
	}

	// Display counts
	public static void displayArray(int[] counts) {
		// Display the character counts
		for (int i = 0; i < counts.length; i++)
			System.out.println((char)(i + 'a') + ": " + counts[i]);
	}
}
