package practical6;

public class RegularPolygon {
	private int n; // The number of sides in the polygon
	private double length; // The length of each side
	private double x; // The x-coordinate of the polygon's center point
	private double y; // The y-coordinate of the polygon's center point

	// A no-arg constructor that creates a polygon with default values
	public RegularPolygon() {
		this(3, 1, 0, 0);
	}

	// A constructor that creates a polygon with the specified number 
	// of sides and length of side, centered at (0, 0)
	public RegularPolygon(int n, double length) {
		this(n, length, 0, 0);		
	}

	// A constructor that creates a polygon with the specified number of 
	// sides, length of side, and x and y coordinates
	public RegularPolygon(int n, double length, double x, double y) {
		this.n = n;
		this.length = length;
		this.x = x;
		this.y = y;
	}

	// Return n
	public int getN() {
		return n;
	}
	
	// Return the side length
	public double getLength() {
		return length;
	}
	
	// Return the x coordinate 
	public double getX() {
		return x;
	}
	
	// Return the y coordinate 
	public double getY() {
		return y;
	}

	// Set a new n
	public void setN(int n) {
		this.n = n;
	}

	// Set a new side length
	public void setLength(double length) {
		this.length = length;
	}

	// Set a new x coordinate
	public void setX(double x) {
		this.x = x;
	}

	// Set a new y coordinate
	public void setY(double y) {
		this.y = y;
	}

	// Return the perimeter
	public double getPerimeter() {
		return n * length;
	}

	// Return the area
	public double getArea() {
		return n * Math.pow(length, 2) / (4 * Math.tan(Math.PI / n));
	} 

	// Return a String representation of the polygon
	public String toString() {
		return "number of sides = " + n + ", side length = " + length + ", center point = (" + x + ", " + y +")";
	}
}

