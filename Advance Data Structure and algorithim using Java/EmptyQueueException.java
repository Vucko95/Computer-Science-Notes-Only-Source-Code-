package net.datastructures;

/**
 * Runtime exception thrown when one tries to perform operation front
 * or dequeue on an empty queue.
 * @author Natasha Gelfand
 * @author Michael T. Goodrich
 * @author Roberto Tamassia
 */

public class EmptyQueueException extends RuntimeException {  
    public EmptyQueueException(String err) {
    super(err);
  }
}
