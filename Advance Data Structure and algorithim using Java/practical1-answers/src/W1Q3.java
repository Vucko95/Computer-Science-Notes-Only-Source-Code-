

import java.util.Scanner;

public class W1Q3 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("enter a number: ");
		int x = input.nextInt();
		System.out.print("enter a number: ");
		int y = input.nextInt();
		
		
		System.out.print("result: ");
		if (x > y) System.out.println(y + "," + x);
		else if (x < y) System.out.println(x + "," + y);
		else System.out.println(x + "," + y);
	}
}
