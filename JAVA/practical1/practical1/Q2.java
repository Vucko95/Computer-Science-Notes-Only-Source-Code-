package practical1;

import java.util.Scanner;

public class Q2 {
	public static void main(String[] args) {
		// Read number of years
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the number of years: ");
		int numberYears = input.nextInt();

		// Perform calculations
		double numberBirthsPerYear = 365 * 24 * 60 * 60 / 7.0;
		double numberDeathsPerYear = 365 * 24 * 60 * 60 / 13.0;
		double numberImmigrantsPerYear = 365 * 24 * 60 * 60 / 45.0;
		
		double population = 312032486 + numberYears * 
				(numberBirthsPerYear - numberDeathsPerYear + numberImmigrantsPerYear);

		// Display results
		System.out.println("The population in " + numberYears + " years is " + population);
	}
}
