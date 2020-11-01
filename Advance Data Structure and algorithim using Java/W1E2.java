

import java.util.Scanner;

public class W1E2 {

	public static void main(String[] args) {
		// User scanner class to read user input
		Scanner input = new Scanner(System.in);;
		
		System.out.print("enter number: ");
		int num = input.nextInt();
		System.out.print("you entered " + num);

		// Shutdown the scanner (being a good boy)
		input.close();
	}

}
