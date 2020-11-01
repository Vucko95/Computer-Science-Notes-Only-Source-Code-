/**
 * A class to compute the case similarity between objects of type MovieCase.
 * Case similarity is given by a weighted sum of the genre, director, and 
 * actor feature similarities.
 */

package alg.cb.similarity.cases;

import alg.cb.cases.MovieCase;
import alg.cb.similarity.features.FeatureSimilarity;

public class WeightedJaccardSimilarity implements CaseSimilarity {
	private double genreWeight; // the weight for feature genres
	private double directorWeight; // the weight for feature directors
	private double actorWeight; // the weight for feature actors
	
	/**
	 * constructor - creates a new WeightedJaccardSimilarity object
	 */
	public WeightedJaccardSimilarity() {
		this(1, 1, 1);
	}
	
	/**
	 * constructor - creates a new WeightedSimilarity object
	 * @param genreWeight - the weight assigned to the genre feature
	 * @param directorWeight - the weight assigned to the director feature
	 * @param actorWeight - the weight assigned to the actor feature
	 */
	public WeightedJaccardSimilarity(double genreWeight, double directorWeight, double actorWeight) {
		this.genreWeight = genreWeight;
		this.directorWeight = directorWeight;
		this.actorWeight = actorWeight;
	}
	
	/**
	 * computes the similarity between two cases
	 * @param c1 - the first case
	 * @param c2 - the second case
	 * @return the similarity between case c1 and case c2
	 */
	@Override
	public double getSimilarity(MovieCase c1, MovieCase c2) {
		double above = genreWeight * FeatureSimilarity.Jaccard(c1.getGenres(), c2.getGenres()) + 
				directorWeight * FeatureSimilarity.Jaccard(c1.getDirectors(), c2.getDirectors()) + 
				actorWeight * FeatureSimilarity.Jaccard(c1.getActors(), c2.getActors());
		
		double below = genreWeight + directorWeight + actorWeight;
		
		return (below > 0) ? above / below : 0;
	}
}
