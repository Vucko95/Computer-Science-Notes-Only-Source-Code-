package chapter11_examples;

import java.util.Date;

public class GeometricObject {
	private String color; // The color
	private boolean filled; // Filled (true or false)
	private Date dateCreated; // The date of creation

	// Construct a default geometric object
	public GeometricObject() {
		this("white", false);
	}

	// Construct a geometric object with the specified color 
	//  and filled value 
	public GeometricObject(String color, boolean filled) {
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

	// Return filled. (Since filled is boolean, 
    // its get method is named isFilled)
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

	// Return a string representation of this object
	public String toString() {
		  return "created: " + dateCreated +
		  "\n color: " + color + 
		  "\n filled: " + filled;
	}
}
