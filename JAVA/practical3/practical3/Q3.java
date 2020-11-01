package practical3;

import java.util.Scanner;

public class Q3 {
	public static void main(String[] args) {
		// Read a line of text
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a string: ");
		String str = input.nextLine();
		
		// Declare a String variable to hold the cypher
		String cypher = ""; 
				
		// Create the cypher - iterate over the the characters in the string
		for (int i = 0; i < str.length(); i++) { 
			char ch = str.charAt(i);
			
			// Check if ch is a lowercase letter
			if (Character.isLowerCase(ch)) { 
				if (ch == 'z') // If ch is 'z', replace with 'a'
					cypher += 'a';
				else 
					cypher += (char)(ch + 1); // Otherwise, replace ch with next character in alphabet
			}
			else
				cypher += ch; // If not a lowercase letter, add ch to string
		}
		
		// Display the result
		System.out.println("The cypher is: " + cypher);
		
		// Close the Scanner
		input.close();
	}
}
