// Alternative version showing how to (1) declare, create, and 
// initialise an array of objects and (2) use a foreach loop 
// to iterate over an array of objects.

package practical6;

public class TestRegularPolygon2 {
	public static void main(String[] args) {
		// Declare, create and initialise an array of polygons
		RegularPolygon[] arr = {
				new RegularPolygon(3, 10, 2.5, 8.0),
				new RegularPolygon(6, 4),
				new RegularPolygon(),
				new RegularPolygon(10, 5),
				new RegularPolygon(4, 6, 3.0, 6.8)
		};

		// Display all polygons
		int i = 0;
		for (RegularPolygon p: arr) {
			System.out.printf("Polygon %d: %s\n", ++i, p.toString());
			System.out.printf("\tPerimeter: %.2f\n", p.getPerimeter());
			System.out.printf("\tArea: %.2f\n\n", p.getArea());
		}

		// Find and print the polygon with the smallest perimeter
		System.out.println("The polygon with the smallest perimeter: " + 
				getSmallestPerimenter(arr).toString() + "\n");

		// Find and print the polygon with the largest area
		System.out.println("The polygon with the largest area: " + 
				getLargestArea(arr).toString() + "\n");		
	}

	// Return a reference to the polygon in the array with the smallest perimeter
	public static RegularPolygon getSmallestPerimenter(RegularPolygon[] arr) {
		int index = 0;
		for (int i = 1; i < arr.length; i++)
			if (arr[i].getPerimeter() < arr[index].getPerimeter())
				index = i;

		return arr[index];
	}

	// Return a reference to the polygon in the array with the largest area
	public static RegularPolygon getLargestArea(RegularPolygon[] arr) {
		int index = 0;
		for (int i = 1; i < arr.length; i++)
			if (arr[i].getArea() > arr[index].getArea())
				index = i;

		return arr[index];
	}
}

