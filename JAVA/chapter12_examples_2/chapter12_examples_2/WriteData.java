package chapter12_examples_2;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class WriteData {
	public static void main(String[] args) {
		// Create a File instance
		File file = new File("chapter12/testFile.txt");

		// Declare a PrintWriter reference variable
		PrintWriter output = null;
		try {
			// Create a PrintWriter object 
			output = new PrintWriter(new FileWriter(file, true)); // true to append; false to overwrite

			// Write output to the file
			output.println("Hello World!");
			output.println("And hello again...");
		}
		catch (IOException ex) {
			ex.printStackTrace();
		}
		finally {
			// Close the PrintWriter instance
			if (output != null)
				output.close();
		}

		System.out.println("Finished ...");
	}
}
