package chapter12_examples_1;

public class Divide2 { 

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
			System.out.println("Exception: integer division by zero");
		}

		System.out.println("\nExecution continues ...");
	}
}
