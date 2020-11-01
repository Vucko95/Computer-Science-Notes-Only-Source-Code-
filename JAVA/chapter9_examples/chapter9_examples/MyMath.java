/*
 * A class that implements some mathematical functions.
 */

package chapter9_examples;

public class MyMath {
	// constructor is private - cannot create an
	// instance of this class
	private MyMath() {
	}
	
	// returns the absolute value of a double value
	public static double abs(double a) {
		return (a < 0) ? -a : a;
	}
	
	// returns the maximum of two double values
	public static double max(double a1, double a2) {
		return (a1 > a2) ? a1 : a2;
	}
	
	// returns the maximum of three double values
	public static double max(double a1, double a2, double a3) {
		return max(max(a1, a2), a3);
	}
	
	// returns the minimum of two double values
	public static double min(double a1, double a2) {
		return (a1 < a2) ? a1: a2;
	}
	
	// returns the minimum of three double values
	public static double min(double a1, double a2, double a3) {
		return min(min(a1, a2), a3);
	}
}
