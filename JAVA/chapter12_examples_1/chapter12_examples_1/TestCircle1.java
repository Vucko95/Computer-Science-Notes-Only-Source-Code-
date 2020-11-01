package chapter12_examples_1;

public class TestCircle1 {
	public static void main(String[] args) {
		// Try creating some Circle objects
		try {
			Circle c1 = new Circle(5);
			System.out.println("radius of c1: " + c1.getRadius());
			
			Circle c2 = new Circle(-5);
			System.out.println("radius of c2: " + c2.getRadius());
			
			Circle c3 = new Circle(0);
			System.out.println("radius of c3: " + c3.getRadius());
		}
		catch (IllegalArgumentException ex) {
			System.out.println(ex);
		}

		// Display the number of Circle objects created
		System.out.println("Number of objects created: " +
				Circle.getNumberOfObjects());
	}
}
