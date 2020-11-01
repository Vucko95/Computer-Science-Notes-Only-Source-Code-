package practical5;

public class Q3 {
	public static void main(String[] args) {
		// Declare array reference variable and invoke method getPoints
		double[][] points = getPoints();
		
		// Display array points
		displayPoints(points);
		
		// declare array reference variable and invoke method getDistances
		double[][] distances = getDistances(points);
		
		// Display array distances
		displayDistances(distances);
	}
	
	// Create and return a 2-D array. Each row of the array 
	// contains the x and y coordinates of a point.
	public static double[][] getPoints() {
		double[][] p = {
				{1.5, -1.5}, // x and y coordinates of the first point
				{-0.5, 2.5}, // x and y coordinates of the second point
				{3.5, 4.5},  // ...
				{0, 0},
				{0, 4}
		};
		
		return p;
	}
	
	// Displays the points
	public static void displayPoints(double[][] p) {
		System.out.println("Points:");
		for (int i = 0; i < p.length; i++) 
			System.out.println("point " + (i + 1) + ": (" + p[i][0] + ", " + p[i][1] + ")");
		
		System.out.println();
	}
	
	// Returns the distance between two points
	public static double calculateDistance(double x1, double y1, double x2, double y2) {
		return Math.sqrt( Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2) );
	}
	
	// Create and return a 2-D array where d[i][j] contains the 
	// distance between points i and j 
	public static double[][] getDistances(double[][] p) {
		double[][] d = new double[p.length][p.length];
		
		for (int i = 0; i < p.length; i++)
			for (int j = i + 1; j < p.length; j++) {
				double dist = calculateDistance(p[i][0], p[i][1], p[j][0], p[j][1]);
				d[i][j] = dist;
				d[j][i] = dist; // distance is symmetric
			}
				
		return d;
	}
	
	// Displays a 2-D array
	public static void displayDistances(double[][] arr) {
		System.out.println("Distances:");
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++) 
				System.out.printf("%5.2f ", arr[i][j]);
			
			System.out.println();
		}
	}
}
