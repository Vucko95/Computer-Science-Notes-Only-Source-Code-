/*
 * A program to illustrate that arguments are passed by value to methods.
 */

package chapter6_examples;

public class TestPassByValue {
	// main method
	public static void main(String[] args) {
		int x = 1;
		System.out.println("Before the call, x is " + x);
		foo(x); // Invoke method foo
		System.out.println("After the call, x is " + x);
	}

	public static void foo(int n) {
		System.out.println("\t Inside the method, n is " + n);
		n *= 10;
		System.out.println("\t Inside the method, n is " + n);
	}
}
