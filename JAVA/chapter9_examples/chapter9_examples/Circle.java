package chapter9_examples;

public class Circle {
	private double radius; // The radius
	private static int numberOfObjects = 0; // Number of objects created 
	
	// Construct a circle with radius 1
	public Circle() {
		this(1.0);
	}

	// Construct a circle with the specified radius
	public Circle(double radius) {
		this.radius = radius;
		numberOfObjects++;
	}
	
	// Return the radius
	public double getRadius() {
		return radius;
	}
	
	// Set a new radius
	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	// Return the number of objects created
	public static int getNumberOfObjects() {
		return numberOfObjects;
	}

	// Return the area
	public double getArea() {
		return radius * radius * Math.PI;
	}
	
	// Return a string representation
	public String toString() {
		return "radius = " + radius;
	}
}
