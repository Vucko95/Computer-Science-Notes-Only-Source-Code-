package practical4;

import java.util.Scanner;

public class Q3 {
	public static void main(String[] args) {
		// Create a Scanner
		Scanner input = new Scanner(System.in);

		// Prompt the user to enter a string
		System.out.print("Enter a string: ");
		String s = input.nextLine();

		// Check if the string is a palindrome
		System.out.println("\"" + s + "\"" + (isPalindrome(s) ? " is" : " is not") + " a palindrome");

		// Close the scanner
		input.close();
	}

	// Return true if s is a palindrome; false otherwise
	public static boolean isPalindrome(String str) {
		int i = 0;
		while (i < str.length() / 2 && str.charAt(i) == str.charAt(str.length() - 1 - i))
			i++;

		return i == str.length() / 2; // if true, str is a palindrome
	}
}
