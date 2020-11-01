/**
 * A class to define a case-based recommender.
 * The scoring function used to rank recommendation candidates is the maximum similarity over the target cases.
 */

package alg.cb.recommender;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.SortedSet;
import java.util.TreeSet;

import alg.cb.util.ScoredThingDsc;
import alg.cb.casebase.Casebase;
import alg.cb.similarity.cases.CaseSimilarity;

public class MaxRecommender extends Recommender {
	/**
	 * constructor - creates a new MaxRecommender object
	 * @param caseSimilarity - the case similarity metric
	 * @param cb - the case base
	 */
	public MaxRecommender(CaseSimilarity caseSimilarity, Casebase cb) {
		super(caseSimilarity, cb);
	}

	/**
	 * returns a ranked list of recommended case ids
	 * @param targetIds - a list of target case ids
	 * @return the ranked list of recommended case ids
	 */
	public List<Integer> getRecommendations(List<Integer> targetIds) {
		SortedSet<ScoredThingDsc> ss = new TreeSet<>(); 

		// compute a score for all candidate recommendation cases
		for (int i = 0; i < getCasebase().getSize(); i++) {
			double score  = 0;

			// compute the score between the current candidate and the target cases
			for (int j = 0; j < targetIds.size(); j++) 

				// check that the current candidate is not contained in target list
				if (i != targetIds.get(j)) {
					double sim = getCaseSimilarity(i, targetIds.get(j));
					if (sim > score)
						score = sim;
				} else { // the current candidate is contained in target list - set score to 0
					score = 0; 
					break;
				}

			// add the score for the current candidate to the set
			if(score > 0)
				ss.add(new ScoredThingDsc(score, i)); 
		}

		// sort the candidate recommendation cases by score (in descending order) and return as recommendations 
		List<Integer> recIds = new ArrayList<>();

		for(Iterator<ScoredThingDsc> it = ss.iterator(); it.hasNext(); ) {
			ScoredThingDsc st = it.next();
			recIds.add((Integer)st.getThing());
		}

		return recIds;
	}
}
