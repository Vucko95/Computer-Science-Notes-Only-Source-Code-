/**
 * Runtime exception thrown when one tries to perform operation top or
 * pop on an empty Queue.
 */

public class EmptyDequeException extends RuntimeException {  
  public EmptyDequeException(String err) {
    super(err);
  }
}
