// Q6 solution using an if-else statement

package practical2;

import java.util.Scanner;

public class Q6b {
	public static void main(String[] args) {
		// Read year and month
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a year: ");
		int year = input.nextInt();
		System.out.print("Enter a month (e.g. Jan, Feb, etc.): ");
		String month = input.next();

		// Perform tests
		if (month.equals("Jan") || month.equals("Mar") || month.equals("May")
				|| month.equals("Jul") || month.equals("Aug") || month.equals("Oct") || month.equals("Dec"))
			System.out.println(month + " " + year + " has 31 days");
		else if (month.equals("Apr") || month.equals("Jun") || month.equals("Sep") || month.equals("Nov"))
			System.out.println(month + " " + year + " has 30 days");
		else if (month.equals("Feb")) // Check if year is a leap year
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				System.out.println(month + " " + year + " has 29 days");
			else
				System.out.println(month + " " + year + " has 28 days");
		else
			System.out.println(month + " is not a correct month name ");
		
		// Close the Scanner
		input.close();
	}
}
