package chapter11_examples;

public class PolymorphismAndCastingDemo1 {
	// Main method 
	public static void main(String[] args) {
		// Create and initialize three objects
		GeometricObject g = new GeometricObject();
		GeometricObject c = new Circle(5.0);
		GeometricObject r = new Rectangle(2.0, 3.0);

		// Invoke method test
		test(g);
		System.out.println("------");
		test(c);
		System.out.println("------");
		test(r);
	}

	// Note: an instance of a subclass can always 
	// be passed to a parameter of its superclass type.
	public static void test(GeometricObject o) {
		if (o instanceof Object) 
			System.out.println("object");
		
		if (o instanceof GeometricObject) 
			System.out.println("geometric object");
		
		if (o instanceof Circle)
			System.out.println("circle");
		
		if (o instanceof Rectangle) 
			System.out.println("rectangle");
	}
}
