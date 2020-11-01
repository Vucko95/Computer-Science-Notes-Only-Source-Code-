/**
 * A class to read in and store movie metadata.
 */

package alg.cb.util;

import java.io.File;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

import alg.cb.casebase.Casebase;
import alg.cb.cases.MovieCase;

public class DatasetReader {
	private Casebase cb; // stores case objects
	
	/** 
	 * constructor - creates a new DatasetReader object
 	 * @param movieFile - the path and filename of the file containing movie metadata
	 */
	public DatasetReader(String movieFile) {
		readCasebase(movieFile);
	}
		
	/**
	 * @return the casebase
	 */
	public Casebase getCasebase() {
		return cb;
	}
	
	/** 
	 * creates the casebase
	 * @param filename - the path and filename of the file containing the movie metadata
 	 */
	private void readCasebase(String filename) {
		// Initialise the Casebase data field
		cb = new Casebase();
		
		// Create a File object
		File file = new File(filename);

		// Declare a Scanner reference variable
		Scanner input = null;
		
		try {
			// Create a Scanner for the file
			input = new Scanner(file);
			
			while (input.hasNext()) { // returns true if the scanner has more data to be read
				String line = input.nextLine();
				StringTokenizer st = new StringTokenizer(line, "\t");
				if(st.countTokens() != 5) {
					System.out.println("Error reading from file \"" + filename + "\"");
					System.exit(1);
				}
				
				int id = Integer.parseInt(st.nextToken());
				String title = st.nextToken().trim();
				Set<String> genres = tokenizeString(st.nextToken());
				Set<String> directors = tokenizeString(st.nextToken());
				Set<String> actors = tokenizeString(st.nextToken());
			
				MovieCase movie = new MovieCase(id, title, genres, directors, actors);
				cb.addCase(movie);
			}
		} catch(IOException e) {
			e.printStackTrace();
			System.exit(0);
		} finally {
			// Close the Scanner
			if (input != null)
				input.close();
		}
	}
	
	/** 
	 * @param str - the string to be tokenized; ',' is the delimiter character
 	 * @return a set of string tokens
	 */
	private Set<String> tokenizeString(String str) {
		Set<String> s = new HashSet<>();
		
		StringTokenizer st = new StringTokenizer(str, ",");
		while (st.hasMoreTokens())
			s.add(st.nextToken().trim()); 
		
		return s;
	}
}
