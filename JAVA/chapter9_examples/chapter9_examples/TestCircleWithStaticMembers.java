package chapter9_examples;

public class TestCircleWithStaticMembers {
	// Main method
	public static void main(String[] args) {
		// Display the number of objects created
		System.out.println("Number of objects created: " +
				CircleWithStaticMembers.getNumberOfObjects() + "\n");	

		// Create c1
		CircleWithStaticMembers c1 = new CircleWithStaticMembers();
		System.out.println("c1: radius = " + c1.radius + "\n");

		// Create c2
		CircleWithStaticMembers c2 = new CircleWithStaticMembers(5);
		System.out.println("c2: radius = " + c2.radius + "\n");

		// Update radius of c2
		c2.radius = 100;
		System.out.println("c2: radius = " + c2.radius + "\n");

		// Display the number of objects created
		System.out.println("Number of objects created: " +
				CircleWithStaticMembers.getNumberOfObjects());	
	}
}
