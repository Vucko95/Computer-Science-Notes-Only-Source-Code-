/*
 * Compare this class to PolymorphismAndCastingDemo2.java (chapter11_examples)
 */

package chapter13_examples_1;

public class TestGeometricObject {
	// Main method 
	public static void main(String[] args) {
		// Create a circle with specified radius, color, and filled value
		GeometricObject c = new Circle(5, "red", false);
		display(c);
		
		// Create a rectangle with specified width, height, color, and filled value
		GeometricObject r = new Rectangle(2, 4, "blue", true);
		display(r);	
	}

	// Display geometric object properties - an instance of a subclass can always 
	// be passed to a parameter of its superclass type.
	public static void display(GeometricObject o) {
		System.out.println(
				"color: " + o.getColor() + 
				"\nis filled? " + o.isFilled() + 
				"\narea: " + o.getArea() + 
				"\nperimeter: " + o.getPerimeter() + "\n");	
	}
}
