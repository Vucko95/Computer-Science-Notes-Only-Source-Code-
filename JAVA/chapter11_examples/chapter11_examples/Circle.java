package chapter11_examples;

public class Circle extends GeometricObject {
	private double radius; // The radius of a circle

	// Construct a default circle object
	public Circle() {
		this(1.0);
	}

	// Construct a circle object with the specified radius
	public Circle(double radius) {
		this.radius = radius;
	}

	// Construct a circle object with the specified radius, color 
	// and filled value 
	public Circle(double radius, String color, boolean filled) {
		this.radius = radius;
		setColor(color);
		setFilled(filled);
	}

	// Return radius
	public double getRadius() {
		return radius;
	}

	// Set a new radius
	public void setRadius(double radius) {
		this.radius = radius;
	}

	// Return area
	public double getArea() {
		return radius * radius * Math.PI;
	}

	// Return diameter
	public double getDiameter() {
		return 2 * radius;
	}

	// Return perimeter
	public double getPerimeter() {
		return 2 * radius * Math.PI;
	}

	// Print the circle info
	public void printCircle() {
		  System.out.println("created: " + getDateCreated() +
		  "\n color: " + getColor() + 
		  "\n filled: " + isFilled() + 
		  "\n radius: " + radius);
	}
}

