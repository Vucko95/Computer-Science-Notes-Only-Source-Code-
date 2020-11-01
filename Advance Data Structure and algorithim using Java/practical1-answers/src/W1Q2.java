

import java.util.Scanner;

public class W1Q2 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("enter a number: ");
		int num = input.nextInt();
		if (num < 10000) System.out.print("0");
		if (num < 1000) System.out.print("0");
		if (num < 100) System.out.print("0");
		if (num < 10) System.out.print("0");
		System.out.println(num);
	}
}
