package practical5;

import java.util.Scanner;

public class Q1 {
	public static void main(String[] args) {
		// Prompt the user to enter how many numbers should be read
		Scanner input = new Scanner(System.in);
		System.out.print("Enter how many numbers to read: ");
		int count = input.nextInt();
		
		// Declare and create an array of size count 
		double[] numbers = new double[count];

		// Prompt the user to enter the numbers
		System.out.print("Enter " + numbers.length + " numbers: ");
		for (int i = 0; i < numbers.length; i++) 
			numbers[i] = input.nextDouble();

		// Calculate and display the mean and standard deviation
		double mean = mean(numbers);
		double deviation = stdev(numbers, mean);
		System.out.println("The mean is " + mean);
		System.out.println("The standard deviation is " + deviation);
		
		// Close the Scanner
		input.close();
	}

	// Returns the mean of double values
	public static double mean(double[] x) {
		double sum = 0;

		for (int i = 0; i < x.length; i++)
			sum += x[i];

		return (x.length > 0) ? sum / x.length : 0;
	}

	// Returns the standard deviation of double values
	public static double stdev(double[] x, double mean) {
		double squareSum = 0;

		for (int i = 0; i < x.length; i++)
			squareSum += Math.pow(x[i] - mean, 2);

		return (x.length > 1) ? Math.sqrt(squareSum / (x.length - 1)) : 0;
	}
}
