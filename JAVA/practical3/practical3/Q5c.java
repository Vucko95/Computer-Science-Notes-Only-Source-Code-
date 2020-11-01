package practical3;

import java.util.Scanner;

public class Q5c {
	public static void main(String[] args) {
		// Prompt the user to enter the pattern size
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the pattern size: ");
		int n = input.nextInt();

		// Print Pattern C 
		for (int i = 1; i <= n; i++) {
			for (int j = n; j >= 1; j--)
				System.out.print(j <= i ? j + " " : "  ");
			System.out.println();
		}
		
		// Close the Scanner
		input.close();
	}
}
