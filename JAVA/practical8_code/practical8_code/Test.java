package practical8_code;

public class Test {
	// Main method 
	public static void main(String[] args) {
		// Create an array of geometric objects
		GeometricObject[] shapes = {
				new Circle(5), 
				new Rectangle(3, 1),
				new Circle(),
				new Circle(15),
				new Rectangle(1, 2)
		};

		// Scale all Scalable geometric objects by a factor of 2.0
		scaleGeometricObjects(shapes, 2.0);

		// Rotate the first Rotable geometric object found in the array
		rotateFirstGeometricObject(shapes);

		// Display the array elements
		displayGeometricObjects(shapes);

		System.out.println("\n********************\n");

		// Sort the array and display its elements
		java.util.Arrays.sort(shapes);
		displayGeometricObjects(shapes);
	}

	// Scales all Scalable geometric objects by the specified factor
	public static void scaleGeometricObjects(GeometricObject[] arr, double factor) {
		for (GeometricObject o: arr)
			if (o instanceof Scalable)
				((Scalable) o).scale(factor);
	}

	// Rotates the first Rotable geometric object found in the array
	public static void rotateFirstGeometricObject(GeometricObject[] arr) {
		for (GeometricObject o: arr)
			if (o instanceof Rotatable) {
				((Rotatable) o).rotate();
				break;
			}
	}

	// Display the array
	public static void displayGeometricObjects(GeometricObject[] arr) {
		for (GeometricObject o: arr)
			System.out.printf("%s, area: %.2f\n", o.toString(), o.getArea());	
	}
}
