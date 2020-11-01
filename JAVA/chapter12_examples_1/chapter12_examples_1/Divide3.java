package chapter12_examples_1;

public class Divide3 { 

	public static int divide(int n1, int n2) throws ArithmeticException {
		if (n2 == 0)
			throw new ArithmeticException("Divisor cannot be zero");

		return n1 / n2;
	}

	public static void main(String[] args) {
		int x = 1;
		int y = 0;

		try {
			int result = divide(x, y);
			System.out.println("result: " + result);
		}
		catch (ArithmeticException ex) { 
			ex.printStackTrace();
		}

		System.out.println("\nExecution continues ...");
	}
}
