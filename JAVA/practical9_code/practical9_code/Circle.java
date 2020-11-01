package practical9_code;

public class Circle extends GeometricObject {
	private double radius; // The radius of a circle
	private static int numberOfObjects = 0; // Number of the objects created 
	
	// Construct a default circle object
	public Circle() {
		this(1.0);
	}

	// Construct a circle object with the specified radius
	public Circle(double radius) {
		setRadius(radius);
		numberOfObjects++;
	}

	// Construct a circle object with the specified radius, color 
	// and filled value 
	public Circle(double radius, String color, boolean filled) {
		super(color, filled);
		setRadius(radius);
		numberOfObjects++;
	}

	// Return radius 
	public double getRadius() {
		return radius;
	}

	// Set a new radius 
	public void setRadius(double radius) throws IllegalArgumentException {
		if (radius >= 0)
			this.radius = radius;
		else
			throw new IllegalArgumentException("Radius cannot be negative");
	}
	
	// Return the number of objects created
	public static int getNumberOfObjects() {
		return numberOfObjects;
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

	// Implement the scale method defined in Scalable
	@Override 
	public void scale(double factor) {
		if (factor > 0)
			radius *= factor;
	}
	
	// Return a string representation of this object
	@Override
	public String toString() {
		return super.toString() + ", radius: " + radius;
	}
}
