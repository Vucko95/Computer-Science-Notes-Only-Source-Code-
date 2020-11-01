package practical1;

import java.util.Scanner;

public class Q5 {
	public static void main(String args[]) {
		// Read driving distance
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the driving distance: ");
		double distance = input.nextDouble();

		// Read miles per gallon
		System.out.print("Enter miles per gallon: ");
		double milesPerGallon = input.nextDouble();

		// Read price per gallon
		System.out.print("Enter price per gallon: ");
		double pricePerGallon = input.nextDouble();

		// Perform calculation
		double cost = (distance / milesPerGallon) * pricePerGallon;

		// Display results
		System.out.println("The cost of driving is $" + cost);
	}
}
