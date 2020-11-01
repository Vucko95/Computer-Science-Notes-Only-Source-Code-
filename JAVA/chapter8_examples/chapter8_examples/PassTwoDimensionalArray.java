/*
 * An example program showing how to: 
 * - Pass a two-dimensional array to a method 
 * - Return a two-dimensional array from a method
 */

package chapter8_examples;

public class PassTwoDimensionalArray {
	public static void main(String[] args) {
		// Declare array and invoke method to create 
		// and return an array filled with random values
		int nrows = 3;
		int ncols = 2;
		int[][] m = createArray(nrows, ncols);
		
		// Display the array
		displayArray(m);
		System.out.println();

		// Get the sum of all elements and display the result
		int sum = getSum(m);
		System.out.println("The sum of all elements is: " + sum);
	}

	// Returns the reference to a 2-D array with elements set to
	// random values between 0 and 9, inclusive
	public static int[][] createArray(int nrows, int ncols) {
		int[][] arr = new int[nrows][ncols];

		// Fill arr with random values
		for (int i = 0; i < arr.length; i++)
			for (int j = 0; j < arr[i].length; j++) 
				arr[i][j] = (int)(Math.random() * 10);

		return arr;
	}

	// Displays a 2-D array
	public static void displayArray(int[][] arr) {
	
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++) 
				System.out.print(arr[i][j] + " ");
			
			System.out.println();
		}
	}

	// Returns the sum of all elements in a 2-D array
	public static int getSum(int[][] arr) {
		int sum = 0;

		for (int i = 0; i < arr.length; i++)
			for (int j = 0; j < arr[i].length; j++) 
				sum += arr[i][j];

		return sum;
	}
}
