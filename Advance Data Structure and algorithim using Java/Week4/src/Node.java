

    /** Node of a singly linked list of strings. */
    public class Node {
      private String element;	// we assume elements are character strings
      private Node next;
      /** Creates a node with the given element and next node. */
      public Node(String s, Node n) {
        element = s;
        next = n;
      }
      /** Returns the element of this node. */
      public String getElement() { return element; }
      /** Returns the next node of this node. */
      public Node getNext() { return next; }
      // Modifier methods:
      /** Sets the element of this node. */
      public void setElement(String newElem) { element = newElem; }
      /** Sets the next node of this node. */
      public void setNext(Node newNext) { next = newNext; }
    }

