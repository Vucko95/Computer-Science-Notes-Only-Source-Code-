package chapter12_examples_2;

import java.io.File;
import java.io.IOException;
import java.util.Scanner; 

public class ReadData {
	public static void main(String[] args) {
		// Create a File instance
		File file = new File("chapter12/testFile.txt");

		// Declare a Scanner reference variable
		Scanner input = null;
		try {
			// Create a Scanner for the file
			input = new Scanner(file);

			// Read data from the file
			while (input.hasNext()) { // returns true if the scanner has more data to be read
				String line = input.nextLine();
				System.out.println(line);
			}
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			// Close the Scanner instance
			if (input != null)
				input.close();
		}

		System.out.println("\nFinished ...");
	}
}

