package practical4;

public class Q1 {
	public static void main(String args[]) {
		// Iterate over all integers starting from 0, and 
		// print the first 10 prime numbers
		int number = 0;
		int counter = 0;
		while (counter < 10) {
			// If number is prime, print it and increment 
			// counter by 1
			if (isPrime(number)) { 
				System.out.println(number); 
				counter++; 
			}

			// Increment number by 1, and go to the next 
			// iteration of the loop
			number++; 
		}
	}

	// Return true if number is prime; false otherwise
	public static boolean isPrime(int number) {
		// Return false if number <= 1
		if (number <= 1)
			return false;

		for (int divisor = 2; divisor <= number / 2; divisor++)
			if (number % divisor == 0) // If true, number is not prime
				return false;

		// If this point is reached, number is prime
		return true; 
	}
}

