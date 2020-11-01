package practical6;

public class TestCircle {
	public static void main(String[] args) {
		// Create a new circle with radius 5 and center point (2, -1)
		Circle c1 = new Circle(5, 2, -1);
		// Display the string representation of c1
		System.out.println("c1: " + c1.toString());
		// Move c1 to (3, 4)
		c1.move(3, 4);
		// Set the radius of c1 to 10
		c1.setRadius(10);
		// Display the string representation of c1
		System.out.println("c1: " + c1.toString());
		
		// Create a new circle with radius 1 and center point (0, 0)
		Circle c2 = new Circle();
		// Display the string representation of c2
		System.out.println("c2: " + c2.toString());
		// Display the distance between the center points of c1 and c2		
		System.out.println("Distance between the center points of c1 and c2: " + c1.getDistance(c2));

		// Display the number of Circle objects created
		System.out.println("Number of Circle objects created: " + Circle.getNumberOfObjects());
	}
}
