/**
 * A class containing various feature similarity metric implementations
 */

package alg.cb.similarity.features;

import java.util.Set;

public class FeatureSimilarity {
	/**
	 * private constructor - prevent instantiation of class
	 */
	private FeatureSimilarity() {
	}
	
	/**
	 * computes exact match similarity between string feature values
	 * @param s1 - the first feature value
	 * @param s2 - the second feature value
	 * @return the similarity between string feature values
	 */
	public static double exact(String s1, String s2) {
		return s1.equals(s2) ? 1 : 0;
	}

	/**
	 * computes exact match similarity (ignoring case) between string feature values
	 * @param s1 - the first feature value
	 * @param s2 - the second feature value
	 * @return the similarity between string feature values
	 */
	public static double exactIgnoreCase(String s1, String s2) {
		return s1.equalsIgnoreCase(s2) ? 1 : 0;
	}
	
	/**
	 * computes overlap similarity between two sets of strings
	 * @param s1 - the first set of strings
	 * @param s2 - the second set of strings
	 * @return the similarity between two sets of strings
	 */
	public static double overlap(Set<String> s1, Set<String> s2) {
		int intersection = 0;
		
		for(String str: s1)
			if(s2.contains(str))
				intersection++;
		
		int min = (s1.size() < s2.size()) ? s1.size() : s2.size();		
		return (min > 0) ? intersection * 1.0 / min : 0;
	}
	
	/**
	 * computes Jaccard similarity between two sets of strings
	 * @param s1 - the first set of strings
	 * @param s2 - the second set of strings
	 * @return the similarity between two sets of strings
	 */	
	public static double Jaccard(Set<String> s1, Set<String> s2) {
		int intersection = 0;
		
		for(String str: s1)
			if(s2.contains(str))
				intersection++;
		
		int union = s1.size() + s2.size() - intersection;		
		return (union > 0) ? intersection * 1.0 / union : 0;
	}
}
