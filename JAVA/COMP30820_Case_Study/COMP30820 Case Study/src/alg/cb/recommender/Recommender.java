/**
 * An abstract class to define a case-based recommender
 */

package alg.cb.recommender;

import java.util.List;

import alg.cb.util.Matrix;
import alg.cb.casebase.Casebase;
import alg.cb.similarity.cases.CaseSimilarity;

public abstract class Recommender {
	private Matrix matrix; // a Matrix object to store case similarities
	private Casebase cb; // the case base

	/**
	 * constructor - creates a new Recommender object
	 * @param caseSimilarity - the case similarity metric
	 * @param cb - the case base
	 */
	public Recommender(CaseSimilarity caseSimilarity, Casebase cb) {
		this.cb = cb;
		matrix = new Matrix(cb.getSize(), cb.getSize());
		
		// compute all case similarities and store in a Matrix object
		for (int i = 0; i < cb.getSize(); i++)
			for (int j = i + 1; j < cb.getSize(); j++) {
				double sim = caseSimilarity.getSimilarity(cb.getCase(i), cb.getCase(j));
				if(sim > 0) {
					matrix.addValue(i, j, sim);
					matrix.addValue(j, i, sim);
				}
			}
	}
	
	/**
	 * returns the case base
	 * @return the case base
	 */
	public Casebase getCasebase() {
		return cb;
	}

	/**
	 * returns the case similarity between two cases
	 * @param id1 - the id of the first case
	 * @param id2 - the id of the second case
	 * @return the case similarity or -1 if the Matrix object does not contain the case similarity
	 */
	public double getCaseSimilarity(int id1, int id2) {
		return matrix.getValue(id1, id2);
	}

	/**
	 * returns a ranked list of recommended case ids
	 * @param targetIds - a list of target case ids
	 * @return the ranked list of recommended case ids
	 */
	public abstract List<Integer> getRecommendations(List<Integer> targetIds);
}
