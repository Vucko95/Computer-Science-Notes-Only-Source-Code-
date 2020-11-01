package alg.cb.similarity.cases;

import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

import alg.cb.cases.MovieCase;
import alg.cb.similarity.features.FeatureSimilarity;

public class TitleSimilarity implements CaseSimilarity {
	Set<String> stopWords; // stores stop words

	/**
	 * constructor - creates a new TitleSimilarity object
	 */
	public TitleSimilarity() {
		initialiseStopWords(); // initialise the set of stop words
	}

	/**
	 * computes the similarity between two cases
	 * @param c1 - the first case
	 * @param c2 - the second case
	 * @return the similarity between case c1 and case c2
	 */
	@Override
	public double getSimilarity(MovieCase c1, MovieCase c2) {
		return FeatureSimilarity.Jaccard(tokenizeTitle(c1.getTitle()), tokenizeTitle(c2.getTitle()));
	}

	/** 
	 * @param str - the string to be tokenized; ' ' is the delimiter character
	 * @return a set of string tokens
	 */
	private Set<String> tokenizeTitle(String str)
	{
		Set<String> s = new HashSet<>();

		StringTokenizer st = new StringTokenizer(str, " ");
		while (st.hasMoreTokens()) {
			String token = st.nextToken().toLowerCase().trim();
			if(!stopWords.contains(token))
				s.add(token); 
		}

		return s;
	}

	/** 
	 * initialises the set of stop words
	 */
	private void initialiseStopWords() {
		// add stop words to this array
		String[] list = {"a", "and", "at", "by", "in", "of", "on", "the", "this", "with", "&"}; 

		stopWords = new HashSet<>();
		for (String s: list)
			stopWords.add(s);		
	}
}
