package net.datastructures;
/**
 * Thrown when a position is determined to be invalid.
 * @author Roberto Tamassia, Michael Goodrich
 */
//begin#fragment InvalidPositionException
// A run-time exception for invalid positions
public class InvalidPositionException extends RuntimeException {  
  public InvalidPositionException(String err) {
    super(err);
  }
//end#fragment InvalidPositionException
  public InvalidPositionException() {
    /* default constructor */
  }
//begin#fragment InvalidPositionException
}
//end#fragment InvalidPositionException
