package practical3;

import java.util.Scanner;

public class Q4 {
	public static void main(String[] args) {
		// Prompt the user to enter two strings
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the first string: ");
		String s1 = input.nextLine();
		System.out.print("Enter the second string: ");
		String s2 = input.nextLine();

		// Get the largest common prefix - iterate over the strings and exit
		// the loop when the corresponding characters in the strings differ
		String prefix = "";
		int i = 0;
		while (i < s1.length() && i < s2.length() && s1.charAt(i) == s2.charAt(i))
			prefix += s1.charAt(i++);
		
		// Display results
		if (prefix.length() > 0)
			System.out.println("The common prefix is: " + prefix);
		else
			System.out.println(s1 + " and " + s2 + " have no common prefix");
		
		// Close the Scanner
		input.close();
	}
}
