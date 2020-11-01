package chapter12_examples_1;

public class Divide1 { 

	public static int divide(int n1, int n2) {
		return n1 / n2;
	}

	public static void main(String[] args) {
		int x = 1;
		int y = 0;

		int result = divide(x, y);
		System.out.println("result: " + result);
	}
}
