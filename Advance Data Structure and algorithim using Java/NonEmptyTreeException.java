package net.datastructures;
/**
 * Runtime exception thrown when one tries to create the root of a
 * tree that is not empty.
 */

public class NonEmptyTreeException extends RuntimeException {  
  public NonEmptyTreeException(String err) {
    super(err);
  }
}
