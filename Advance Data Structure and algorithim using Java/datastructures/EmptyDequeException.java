package net.datastructures;

/**
 * Runtime exception thrown when one tries to perform an access or
 * removal operation on an empty deque.
 *
 * @author Natasha Gelfand
 * @author Michael T. Goodrich
 * @author Roberto Tamassia
 */

public class EmptyDequeException extends RuntimeException {
  public EmptyDequeException(String err) {
    super(err);
  }
}
