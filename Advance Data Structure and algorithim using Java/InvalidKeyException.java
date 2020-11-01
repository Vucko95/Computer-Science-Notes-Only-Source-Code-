package net.datastructures;
/**
 * Thrown when a key is determined to be invalid.
 * @author Roberto Tamassia
 */
public class InvalidKeyException  extends RuntimeException {
  public InvalidKeyException (String message) {
    super (message);
  }
  public static final long serialVersionUID = 424242L;
}
