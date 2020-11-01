/**
 * This class stores case objects
 */

package alg.cb.casebase;

import java.util.ArrayList;
import java.util.List;

import alg.cb.cases.MovieCase;

public class Casebase {
	private List<MovieCase> cb; // stores case objects
	
	/**
	 * constructor - creates a new Casebase object
	 */
	public Casebase() {
		cb = new ArrayList<>();
	}
	
	/**
	 * adds a case to the casebase
	 * @param c - the case object
	 */
	public void addCase(MovieCase c) {
		cb.add(c);
	}
	
	/**
	 * @param index - the case index
	 * @return the case object at the specified index
	 */
	public MovieCase getCase(int index) {
		return cb.get(index);
	}
	
	/**
	 * @return all cases in the casebase
	 */
	public List<MovieCase> getCases() {
		return cb;
	}
	
	/**
	 * @return the number of cases in the casebase
	 */
	public int getSize() {
		return cb.size();
	}
}
