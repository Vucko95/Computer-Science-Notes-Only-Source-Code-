/**
 * A class to represent a movie case
 */

package alg.cb.cases;

import java.util.HashSet;
import java.util.Set;

public class MovieCase {
	private int id; // the movie id
	private String title; // the movie title
	private Set<String> genres; // the movie genres
	private Set<String> directors; // the movie directors
	private Set<String> actors; // the lead actors
	
	/**
	 * constructor - creates a new MovieCase object
	 * @param id - the case id
	 */
	public MovieCase(int id) {
		this.id = id;
		title = null;
		genres = new HashSet<>();
		directors = new HashSet<>();
		actors = new HashSet<>();
	}
	
	/**
	 * constructor - creates a new MovieCase object
	 * @param id - the case id
	 * @param title - the movie title
	 * @param genres - the movie genres
	 * @param directors - the movie directors
	 * @param actors - the actors
	 */
	public MovieCase(int id, String title, Set<String> genres, Set<String> directors, Set<String> actors) {
		this.id = id;
		this.title = title;
		this.genres = genres;
		this.directors = directors;
		this.actors = actors;
	}
	
	/**
	 * @return the case id
	 */
	public int getId() {
		return id;
	}
	
	/**
	 * @return the movie title
	 */
	public String getTitle() {
		return title;
	}
	
	/**
	 * @return the movie genres
	 */
	public Set<String> getGenres() {
		return genres;
	}
	
	/**
	 * @return the movie directors
	 */
	public Set<String> getDirectors() {
		return directors;
	}
	
	/**
	 * @return the actors
	 */
	public Set<String> getActors() {
		return actors;
	}
	
	/**
	 * @return a string representation of the MovieCase object
	 */
	@Override
	public String toString() {;
		return id + " " + title + " " + genres.toString() + " " + directors.toString() + " " + actors.toString();
	}
}
