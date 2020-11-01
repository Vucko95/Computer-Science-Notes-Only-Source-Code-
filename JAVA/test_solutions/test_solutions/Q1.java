package test_solutions;

public class Q1 {
	public static void main(String[] args) {
		// test cases
		
		// should return: 0
		System.out.println("test case 1: " + getSumDigits(""));

		// should return: 0
		System.out.println("test case 2: " + getSumDigits("hello"));
		
		// should return: 5
		System.out.println("test case 3: " + getSumDigits("a2b3"));
	}

	public static int getSumDigits(String str) {
		int sum = 0;

		for (int i = 0; i < str.length(); i++)
			if (Character.isDigit(str.charAt(i)))
				sum += str.charAt(i) - '0';

		return sum;
	}
}
