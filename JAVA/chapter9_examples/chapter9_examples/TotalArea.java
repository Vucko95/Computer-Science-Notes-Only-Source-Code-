package chapter9_examples;

public class TotalArea {
	// Main method
	public static void main(String[] args) {
		// Declare and create an array of Circle objects
		Circle[] circleArray = createCircleArray();

		// Print the areas of the circles in the array
		printAreas(circleArray);
		
		// Display the sum of circle areas
		System.out.printf("total area = %.2f", getSum(circleArray));
	}

	// Create an array of Circle objects 
	public static Circle[] createCircleArray() {
		// Declare and create an array of Circle objects
		Circle[] arr = new Circle[5];

		// Create Circle objects
		for (int i = 0; i < arr.length; i++) 
			arr[i] = new Circle(Math.random() * 5);

		return arr;
	}

	// Print the areas of the circles in the array
	public static void printAreas(Circle[] arr) {
		for (int i = 0; i < arr.length; i++) 
			System.out.printf("area = %.2f\n", arr[i].getArea());
		
		// Using foreach loop...
		// for (Circle c: arr) 
		//	System.out.printf("area = %.2f\n", c.getArea());
	}

	// Compute the sum of the areas of all circles in the array
	public static double getSum(Circle[] arr) {
		// Initialize sum
		double sum = 0;

		// Add areas to sum
		for (int i = 0; i < arr.length; i++)
			sum += arr[i].getArea();
		
		return sum;
	}
}
