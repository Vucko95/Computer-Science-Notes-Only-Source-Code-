package practical9_code;

public class Rectangle extends GeometricObject implements Rotatable {
	private double width;  // The width of a rectangle
	private double height;  // The height of a rectangle
	private static int numberOfObjects = 0; // Number of the objects created 

	// Construct a default rectangle object
	public Rectangle() {
		this(1.0, 1.0);
	}

	// Construct a rectangle object with the specified width and height
	public Rectangle(double width, double height) {
		this.width = width;
		this.height = height;
		numberOfObjects++;
	}

	// Construct a rectangle object with the specified width, height, color 
	// and filled value 
	public Rectangle(double width, double height, String color, boolean filled) {
		super(color, filled);
		this.width = width;
		this.height = height;
		numberOfObjects++;
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

	// Return the number of objects created
	public static int getNumberOfObjects() {
		return numberOfObjects;
	}

	// Return area 
	@Override 
	public double getArea() {
		return width * height;
	}

	// Return perimeter 
	@Override 
	public double getPerimeter() {
		return 2 * (width + height);
	}

	// Implement the scale method defined in Scalable
	@Override 
	public void scale(double factor) {
		if (factor > 0) {
			width *= factor;
			height *= factor;
		} 
	}

	// Implement the rotate method defined in Rotatable
	@Override 
	public void rotate() {
		double temp = width;
		width = height;
		height = temp;
	}

	// Return a string representation of this object
	@Override
	public String toString() {
		return super.toString() + ", width: " + width + ", height: " + height;
	}
}
