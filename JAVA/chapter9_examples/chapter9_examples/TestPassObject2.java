package chapter9_examples;

public class TestPassObject2 {
	public static void main(String[] args) {
		int x = 1; // An integer with value 1
		Circle circle = new Circle(5); // A circle with radius 5

		// Display x and the radius of circle
		System.out.println("x = " + x);
		System.out.println("radius = " + circle.getRadius());

		// Invoke method test
		test(x, circle);

		// Display x and the radius of circle
		System.out.println("x = " + x);
		System.out.println("radius = " + circle.getRadius());
	}

	public static void test(int n, Circle c) {
		n = 10;
		c = new Circle(50);
		
		// Display n and the radius of circle
		System.out.println("\n\t Inside method:");
		System.out.println("\t n = " + n);
		System.out.println("\t radius = " + c.getRadius() + "\n");
	}
}

