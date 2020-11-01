package net.datastructures;

/**
 * Signals that the boundaries of a data structure have been illegally
 * traversed (e.g. past the end of a list).
 * @author Roberto Tamassia
 */

public class BoundaryViolationException  extends RuntimeException {
  public BoundaryViolationException (String message) {
    super (message);
  }
}
