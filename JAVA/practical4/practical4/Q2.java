package practical4;

public class Q2 {
	public static void main(String[] args) {
		// Iterate over positive integers until the first four 
		// perfect numbers are found
		int n = 0;
		int counter = 0;
		do {
			// Check if the current number is a perfect number; 
			// if so, print it and increment count
			if (isPerfectNumber(n)) {
				System.out.println(n);
				counter++;
			}
			n++; // Increment n
		}
		while (counter < 4);	
	}

	// Return true if number is a perfect number; false otherwise
	public static boolean isPerfectNumber(int number) {
		// Return false if number <= 0
		if (number <= 0)
			return false;
		
		// Find all the positive divisors of number and 
		// calculate the sum
		int sum = 0;
		int divisor = number - 1; // Exclude the number itself
		while (divisor >= 1) {
			if (number % divisor == 0)
				sum += divisor;

			divisor--;
		}

		// Return true if sum is equal to number; false otherwise
		return number == sum;
	}
}
