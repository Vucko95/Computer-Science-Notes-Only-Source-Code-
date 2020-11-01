package stack;

public class StackMain {
   public static void main( String[] args ) {
      LinkedIntegerStack stack = new LinkedIntegerStack();
      //IntegerStack stack = new IntegerStack();
      
      stack.push( 17 );
      System.out.println( stack );

      stack.push( 11 );
      System.out.println( stack );

      stack.push( 12 );
      System.out.println( stack );

      stack.push( 23 );
      System.out.println( stack );

      stack.push( 26 );
      System.out.println( stack );

      stack.push( 51 );
      System.out.println( stack );

      while( stack.size() > -1 ) {
         System.out.println( stack.pop() );
         System.out.println( stack );
      }
      
   }
}
