

import java.util.Scanner;


public class W1Q7 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		int num = 0;
		int A = 0;
		int j = 0;
		while (num != -1) {
			num = input.nextInt();
			if (num != -1) {
				A = A + num;
				j++;
			}
		}
		System.out.println(j + " numbers entered with result: " + (A/j));
	}
}