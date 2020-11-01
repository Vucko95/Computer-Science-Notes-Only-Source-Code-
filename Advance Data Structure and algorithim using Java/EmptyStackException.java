package net.datastructures;
//begin#fragment EmptyStackException
/**
 * Runtime exception thrown when one tries to perform operation top or
 * pop on an empty stack.
//end#fragment EmptyStackException
 * @author Roberto Tamassia
//begin#fragment EmptyStackException
 */

public class EmptyStackException extends RuntimeException {  
  public EmptyStackException(String err) {
    super(err);
  }
}
//end#fragment EmptyStackException
