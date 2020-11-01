package chapter11_examples;

public class PolymorphismAndCastingDemo2 {
	// Main method 
	public static void main(String[] args) {
		// Create a circle with specified radius, color, and filled value
		GeometricObject c = new Circle(5, "red", false);

		// Create a rectangle with specified width, height, color, and filled value
		GeometricObject r = new Rectangle(2, 4, "blue", true);
		
		// Display the properties of c and r
		display(c);
		System.out.println("------");
		display(r);
	}

	// Display the properties of o. 
	// Note: an instance of a subclass can always 
	// be passed to a parameter of its superclass type.
	public static void display(GeometricObject o) {
		System.out.println("Color: " + o.getColor()); 
		System.out.println("Is filled: " + o.isFilled());
		
		if (o instanceof Circle) {
			System.out.println("The circle area is " + ((Circle)o).getArea());
			System.out.println("The circle diameter is " + ((Circle)o).getDiameter());
		}
		else if (o instanceof Rectangle) {
			System.out.println("The rectangle area is " + ((Rectangle)o).getArea());
			System.out.println("The rectangle perimeter is " + ((Rectangle)o).getPerimeter());
		}
	}
}
