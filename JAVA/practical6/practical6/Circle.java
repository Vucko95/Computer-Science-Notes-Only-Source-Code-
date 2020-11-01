package practical6;

public class Circle {
	private double radius; // The radius of a circle
	private double x; // The x coordinate of the center point
	private double y; // The y coordinate of the center point
	
	private static int numberOfObjects = 0; // The number of objects created

	// Construct a circle with radius 1 and center point (0, 0) 
	public Circle() {
		this(1, 0, 0);
	}

	// Construct a circle with the specified radius and center point
	public Circle(double radius, double x, double y) {
		this.radius = radius;
		this.x = x;
		this.y = y;
		numberOfObjects++;
	}

	// Return the radius
	public double getRadius() {
		return radius;
	}

	// Return the x coordinate of the center point
	public double getX() {
		return x;
	}

	// Return the y coordinate of the center point
	public double getY() {
		return y;
	}

	// Return numberOfObjects
	public static int getNumberOfObjects() {
		return numberOfObjects;
	}

	// Set a new radius
	public void setRadius(double radius) {
		this.radius = radius;
	}

	// Move the circle (i.e. set a new center point)
	public void move(double x, double y) {
		this.x = x;
		this.y = y;
	}

	// Return the area
	public double getArea() {
		return radius * radius * Math.PI;
	}

	// Return the perimeter
	public double getPerimeter() {
		return 2 * radius * Math.PI;
	}

	// Return the distance between the center point of this circle and another Circle object
	public double getDistance(Circle c) {
		return Math.sqrt( Math.pow(x - c.getX(), 2) + Math.pow(y - c.getY(), 2) );
	}

	// Return a String representation 
	public String toString() {
		return "radius = " + radius + ", center point = (" + x + ", " + y +")";
	}
}
