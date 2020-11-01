package chapter11_examples;

public class Rectangle extends GeometricObject {
	private double width; // The width of a rectangle
	private double height; // The height of a rectangle

	// Construct a default rectangle object
	public Rectangle() {
		this(1.0, 1.0);
	}

	// Construct a rectangle object with the specified width and height
	public Rectangle(double width, double height) {
		this.width = width;
		this.height = height;
	}

	// Construct a rectangle object with the specified width, height, color 
	// and filled value 
	public Rectangle(double width, double height, String color, boolean filled) {
		this.width = width;
		this.height = height;
		setColor(color);
		setFilled(filled);
	}

	// Return width
	public double getWidth() {
		return width;
	}

	// Set a new width
	public void setWidth(double width) {
		this.width = width;
	}

	// Return height
	public double getHeight() {
		return height;
	}

	// Set a new height
	public void setHeight(double height) {
		this.height = height;
	}

	// Return area
	public double getArea() {
		return width * height;
	}

	// Return perimeter
	public double getPerimeter() {
		return 2 * (width + height);
	}
}
