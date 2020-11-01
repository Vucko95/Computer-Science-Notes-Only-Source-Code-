/**
 * Used as a way to collect a number of objects (each of which is associated with some kind of score) 
 * and then inspect the set sorted by the scores
 * Note: sorts in DESCENDING order
 */

package alg.cb.util;

public class ScoredThingDsc implements Comparable<Object> {
	private double score; // the score associated with the object
	private Object thing; // the object to be sorted

	public ScoredThingDsc(double s, Object t) {
		score = s;
		thing = t;
	}

	public double getScore() {
		return score;
	}

	public Object getThing() {
		return thing;
	}

	@Override
	public int compareTo(Object o) {
		ScoredThingDsc st = (ScoredThingDsc) o;
		return (score > st.score) ? -1 : +1;
	}

	@Override
	public String toString() {
		return "(" + score + ", " + thing + ")";
	}
}
