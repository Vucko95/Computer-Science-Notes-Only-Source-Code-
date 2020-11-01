/*
 * A program to demonstrate passing array variables to methods.
 */

package chapter7_examples;

public class TestPassArray1 {
	public static void main(String[] args) {
		int[] y = new int[3]; // Declare and create an array of int values
		
		System.out.println("Before method call:");
		System.out.println("y[0] is " + y[0]);
		
		foo(y); // Invoke method foo 

		System.out.println("\nAfter method call:");
		System.out.println("y[0] is " + y[0]);
	}
	
	public static void foo(int[] arr) {
		arr[0] = 5555; // Assign a new value to arr[0]
		
		System.out.println("\nInside method:");
		System.out.println("arr[0] is " + arr[0]);
	}
}

