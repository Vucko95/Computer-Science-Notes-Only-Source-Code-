package practical9_code;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Test {
	// Main method 
	public static void main(String[] args) {
		// Create File instances for the input and log files
		File inputFile = new File("practical9/object_data.txt");
		File logFile = new File("practical9/log.txt");

		// Create a list of geometric objects
		List<GeometricObject> list = readGeometricObjects(inputFile, logFile);

		// Display the number of Circle and Rectangle objects created
		System.out.println("Number of Circle objects created: " + Circle.getNumberOfObjects());
		System.out.println("Number of Rectangle objects created: " + Rectangle.getNumberOfObjects());

		System.out.println("\n********************\n");

		// Display the objects in the list
		displayGeometricObjects(list);

		System.out.println("\n********************\n");

		// Scale the first two geometric objects in the list by a factor of 3
		for (int i = 0; i < list.size() && i < 2; i++)
			if (list.get(i) instanceof Scalable)
				((Scalable) list.get(i)).scale(3);

		// Rotate all Rotatable geometric objects in the list
		for (GeometricObject o: list)
			if (o instanceof Rotatable)
				((Rotatable) o).rotate();

		// Display the objects in the list
		displayGeometricObjects(list);


	}

	// Returns a list of geometric objects. The input file specifies the properties of the
	// geometric objects to be created. Each line in the file contains either a single double
	// value -- the radius of a circle -- or two double values -- the width and height of a 
	// rectangle. If the specified values are not valid, an object is not created and an 
	// error message is written to the log file.
	public static List<GeometricObject> readGeometricObjects(File inputFile, File logFile) {
		// Create an ArrayList instance to store geometric objects
		List<GeometricObject> list = new ArrayList<>();

		// Declare a Scanner reference variable
		Scanner input = null;
		// Declare a PrintWriter reference variable
		PrintWriter log = null;

		try {
			// Create a Scanner object for the input file
			input = new Scanner(inputFile);

			// Create a PrintWriter object for the log file 
			log = new PrintWriter(new FileWriter(logFile, false)); // true to append; false to overwrite

			// Read data from the file
			while (input.hasNext()) { // returns true if the scanner has more data to be read
				String line = input.nextLine();
				StringTokenizer st = new StringTokenizer(line, ",");

				try {
					GeometricObject obj = null;
					if(st.countTokens() == 1) {
						double radius = Double.parseDouble(st.nextToken());
						obj = new Circle(radius);
					} else if (st.countTokens() == 2) {
						double width = Double.parseDouble(st.nextToken());
						double height = Double.parseDouble(st.nextToken());
						obj = new Rectangle(width, height);
					} else {
						System.out.println("Error reading from file");
						System.exit(1);
					}

					list.add(obj);
				} catch (IllegalArgumentException ex) {
					log.println("Invalid object data: " + line);
				}
			}
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			// Close the Scanner instance
			if (input != null)
				input.close();

			// Close the PrintWriter instance
			if (log != null)
				log.close();
		}

		return list;
	}

	// Display the objects in the list
	public static void displayGeometricObjects(List<GeometricObject> l) {
		for (GeometricObject o: l)
			System.out.printf("%s, area: %.2f\n", o.toString(), o.getArea());	
	}
}
