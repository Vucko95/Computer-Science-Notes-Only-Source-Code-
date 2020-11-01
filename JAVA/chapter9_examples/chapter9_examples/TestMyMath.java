/*
 * A program that uses the MyMath class to perform mathematical operations.
 */

package chapter9_examples;

public class TestMyMath {

	public static void main(String[] args) {
		double n1 = 2.5, n2 = -1.5, n3 = 3.5;
		
		// test the MyMath.abs(double) method
		System.out.println(MyMath.abs(n1));
		System.out.println(MyMath.abs(n2) + "\n");
		
		// test the MyMath.max(double, double) and
		// MyMath.max(double, double, double) methods
		System.out.println(MyMath.max(n1, n2));
		System.out.println(MyMath.max(n1, n2, n3) + "\n");
		
		// test the MyMath.min(double, double) and
		// MyMath.min(double, double, double) methods
		System.out.println(MyMath.min(n1, n2));
		System.out.println(MyMath.min(n1, n2, n3));	
		
		
		// cannot create an instance of MyMath - constructor is private
		// MyMath m = new MyMath(); 
	}
}
