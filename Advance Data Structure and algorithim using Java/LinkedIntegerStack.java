package stack;

public class LinkedIntegerStack {

   private Node top = null;
   private int size = 0;
   
   public int size() {
      return size;
   }

   public boolean isEmpty() {
      return size == 0;
   }

   public void push( int value ) {
      Node n = new Node( value );
      n.next = top;
      
      top = n;
      size++;
   }

   public int top() {
      if ( isEmpty() ) {
         throw new StackEmptyException();
      }
      return top.element;
   }

   public int pop() {
      if ( isEmpty() ) {
         throw new StackEmptyException();
      }
      int toReturn = top.element;
      
      top = top.next;
      size--;
      
      return toReturn;
   }
   
   private class Node {
      int element;
      Node next;
      
      public Node( int value ) {
         element = value;
      }
   }
   
   public String toString() {
       
      String out = "[" + size + " element(s)]: ";
      Node n = top;
      while ( n != null ) {
         out += "[" + n.element + "|-]-> ";
         n = n.next;
      }
      return out;
   }
}