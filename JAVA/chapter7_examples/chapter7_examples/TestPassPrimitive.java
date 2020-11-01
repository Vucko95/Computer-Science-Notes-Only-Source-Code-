/*
 * A program to demonstrate passing primitive data type 
 * variables to methods.
 */

package chapter7_examples;

public class TestPassPrimitive {
	public static void main(String[] args) {
		int i = 5;

		System.out.println("Before method call:");
		System.out.println("i is: " + i);
		
		foo(i); // invoke method foo
		
		System.out.println("\nAfter method call:");
		System.out.println("i is: " + i);
	}
	
	public static void foo(int n) {
		n *= 10;
		System.out.println("\nInside method:");
		System.out.println("n is: " + n + "\n");
	}
}
