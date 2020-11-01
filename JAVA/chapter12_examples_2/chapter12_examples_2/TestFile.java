package chapter12_examples_2;

import java.io.File;
import java.util.Date;

public class TestFile {
	public static void main(String[] args) {
		File file = new File("chapter12/testFile.txt");

		System.out.println("Does it exist? " + file.exists());
		System.out.println("The file has " + file.length() + " bytes\n");

		System.out.println("Can it be read? " + file.canRead());
		System.out.println("Can it be written? " + file.canWrite() + "\n");

		System.out.println("Is it a file? " + file.isFile());
		System.out.println("Is it a directory? " + file.isDirectory());
		System.out.println("Is it hidden? " + file.isHidden() + "\n");

		System.out.println("Is it absolute? " + file.isAbsolute());
		System.out.println("Absolute path is " + file.getAbsolutePath() + "\n");

		System.out.println("Last modified on " + new Date(file.lastModified()));
	}
}
