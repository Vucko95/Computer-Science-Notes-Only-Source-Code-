package practical3;

import java.util.Scanner;

public class Q5b {
	public static void main(String[] args) {
		// Prompt the user to enter the pattern size
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the pattern size: ");
		int n = input.nextInt();

		// Print Pattern B 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n + 1 - i; j++)
				System.out.print(j + " ");
			System.out.println();
		}
		
		// Close the Scanner
		input.close();
	}
}
