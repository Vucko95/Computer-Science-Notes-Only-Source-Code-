package chapter13_examples_2;

import java.util.Arrays;

public class SortRectangles {
	public static void main(String[] args) {
		// Create an array containing four comparable rectangles
		ComparableRectangle[] arr = {
				new ComparableRectangle(3.4, 5.4), 
				new ComparableRectangle(13.24, 55.4),
				new ComparableRectangle(7.4, 35.4),
				new ComparableRectangle(1.4, 25.4)
		};

		// Sort the array
		Arrays.sort(arr);

		// Display the comparable rectangles
		for (ComparableRectangle r: arr) 
			System.out.printf("%s\narea: %.2f\n\n", r.toString(), r.getArea()); 
	}
}
