// Q6 solution using a switch statement

package practical2;

import java.util.Scanner;

public class Q6a {
	public static void main(String[] args) {
		// Read year and month
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a year: ");
		int year = input.nextInt();
		System.out.print("Enter a month (e.g. Jan, Feb, etc.): ");
		String month = input.next();

		// Perform tests
		switch(month) {
		case "Jan":
		case "Mar":
		case "May":
		case "Jul":
		case "Aug":
		case "Oct":
		case "Dec": System.out.println(month + " " + year + " has 31 days"); break;
		case "Apr":
		case "Jun":
		case "Sep":
		case "Nov": System.out.println(month + " " + year + " has 30 days"); break;
		case "Feb": // Check if year is a leap year
			int numDays = 28;
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				numDays++;

			System.out.println(month + " " + year + " has " + numDays + " days");
			break;
		default: System.out.println(month + " is not a correct month name ");
		}
		
		// Close the Scanner
		input.close();
	}
}