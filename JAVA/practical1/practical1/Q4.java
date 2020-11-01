package practical1;

import java.util.Scanner;

public class Q4 {
	public static void main(String[] args) {
		// Enter the temperature in Fahrenheit
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the temperature in Fahrenheit between -58 F and 41 F: ");
		double fahrenheit = input.nextDouble();

		// Enter the wind speed miles per hour
		System.out.print("Enter the wind speed miles per hour " + 
				"(must be greater than or equal to 2) : ");
		double speed = input.nextDouble();

		// Compute wind chill index
		double windChillIndex = 35.74 + 0.6215 * fahrenheit - 35.75 *
				Math.pow(speed, 0.16) + 0.4275 * fahrenheit * 
				Math.pow(speed, 0.16);

		// Display results
		System.out.println("The wind chill index is " + windChillIndex);
	}
}
