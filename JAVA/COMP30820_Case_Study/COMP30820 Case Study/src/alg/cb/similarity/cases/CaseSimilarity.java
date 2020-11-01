/**
 * An interface to compute the similarity between cases
 */

package alg.cb.similarity.cases;

import alg.cb.cases.MovieCase;

public interface CaseSimilarity {
	/**
	 * computes the similarity between two cases
	 * @param c1 - the first case
	 * @param c2 - the second case
	 * @return the similarity between case c1 and case c2
	 */
	public double getSimilarity(MovieCase c1, MovieCase c2);
}
