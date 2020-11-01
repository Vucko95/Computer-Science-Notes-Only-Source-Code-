package chapter13_examples_1;

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
		super(color, filled);
		this.radius = radius;
	}

	// Return radius 
	public double getRadius() {
		return radius;
	}

	// Set a new radius 
	public void setRadius(double radius) {
		this.radius = radius;
	}

	// Return diameter 
	public double getDiameter() {
		return 2 * radius;
	}
	
	// Return area 
	@Override 
	public double getArea() {
		return radius * radius * Math.PI;
	}

	// Return perimeter 
	@Override 
	public double getPerimeter() {
		return 2 * radius * Math.PI;
	}

	// Return a string representation of this object
	@Override
	public String toString() {
		return super.toString() + ", radius: " + radius;
	}
}
