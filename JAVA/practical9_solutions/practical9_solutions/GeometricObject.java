package practical9_solutions;

import java.util.Date;

public abstract class GeometricObject implements Comparable<GeometricObject>, Scalable {
	private String color; // The color
	private boolean filled; // Filled (true for yes)
	private Date dateCreated; // The date of creation

	// Default constructor
	protected GeometricObject() {
		this("white", false);
	}

	// Constructor with specified color and filled value
	protected GeometricObject(String color, boolean filled) {
		this.color = color;
		this.filled = filled;
		dateCreated = new Date();
	}

	// Return color
	public String getColor() {
		return color;
	}

	// Set a new color
	public void setColor(String color) {
		this.color = color;
	}

	// Return filled. Since filled is boolean,
	// the get method is named isFilled 
	public boolean isFilled() {
		return filled;
	}

	// Set a new filled
	public void setFilled(boolean filled) {
		this.filled = filled;
	}

	// Get dateCreated 
	public Date getDateCreated() {
		return dateCreated;
	}
	
	// Abstract method getArea
	public abstract double getArea();

	// Abstract method getPerimeter
	public abstract double getPerimeter();

	// Implement the compareTo method defined in Comparable
	@Override 
	public int compareTo(GeometricObject o) {
		if(getArea() > o.getArea()) 
			return 1;
		else if (getArea() < o.getArea()) 
			return -1;
		else 
			return 0;
	}
	
	// Return a string representation of this object
	@Override
	public String toString() {
		return "created: " + dateCreated + ", color: " + color + ", filled: " + filled;
	}
}
