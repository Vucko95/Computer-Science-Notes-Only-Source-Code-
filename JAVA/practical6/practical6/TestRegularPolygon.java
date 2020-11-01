package practical6;

public class TestRegularPolygon {
	public static void main(String[] args) {
		// Declare and create an array of polygons
		RegularPolygon[] arr = new RegularPolygon[5];
		arr[0] = new RegularPolygon(3, 10, 2.5, 8.0);
		arr[1] = new RegularPolygon(6, 4);
		arr[2] = new RegularPolygon();
		arr[3] = new RegularPolygon(10, 5);
		arr[4] = new RegularPolygon(4, 6, 3.0, 6.8);
		
		// Display all polygons
		for (int i = 0; i < arr.length; i++) {
			System.out.printf("Polygon %d: %s\n", (i + 1), arr[i].toString());
			System.out.printf("\tPerimeter: %.2f\n", arr[i].getPerimeter());
			System.out.printf("\tArea: %.2f\n\n", arr[i].getArea());
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

