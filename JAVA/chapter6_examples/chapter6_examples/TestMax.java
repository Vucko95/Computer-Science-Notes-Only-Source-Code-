/*
 * Demonstrates defining and calling a method max to return the largest of two int values
 */

package chapter6_examples;

public class TestMax {
	// main method	
	public static void main(String[] args) {
		int i = 5;
		int j = 2;
		int k = max(i, j); // Invoke method max

		System.out.println("The max is " + k);
	}

	// A method that returns the max value of two integers
	public static int max(int num1, int num2) {
		int result; 

		if (num1 > num2)
			result = num1;
		else
			result = num2;

		return result;
	}
}
