package practical3;

import java.util.Scanner;

public class Q2 {
	public static void main(String[] args) {
		// Prompt the user to enter a string
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a string: ");
		String str = input.nextLine();

		// Reverse the string and display the result
		String reverse = "";
		
		// Iterate over the characters in the string in reverse order
		for (int i = str.length() - 1; i >= 0; i--) 
			reverse += str.charAt(i);
		
		System.out.println("The reversed string is: " + reverse);
		
		// Close the Scanner
		input.close();
	}
}
