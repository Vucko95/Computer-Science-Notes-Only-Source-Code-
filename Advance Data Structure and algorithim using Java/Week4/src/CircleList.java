
import java.util.Random;

    /** Circulary linked list with nodes of type Node storing strings. */
    public class CircleList {
      protected Node cursor;	// the current cursor 
      protected int size;	        // the number of nodes in the list
      /** Constructor that creates and empty list */
      public CircleList() { cursor = null; size = 0; }
      /** Returns the current size */
      public int size() { return size; }
      /** Returns the cursor */
      public Node getCursor() { return cursor; }
      /** Moves the cursor forward */
      public void advance() { cursor = cursor.getNext(); }
      /** Adds a node after the cursor  */
      public void add(Node newNode) {
        if (cursor == null) {    // list is empty
          newNode.setNext(newNode);
          cursor = newNode;
        }
        else {
          newNode.setNext(cursor.getNext());
          cursor.setNext(newNode);
        }
        size++;
      }
      /** Removes the node after the cursor */
      public Node remove() {
        Node oldNode = cursor.getNext();	// the node being removed
        if (oldNode == cursor) 
          cursor = null; // list is becoming empty
        else {
          cursor.setNext(oldNode.getNext());	// link out the old node 
          oldNode.setNext(null); 
        }
        size--;
        return oldNode;
      }
      /** Returns a string representation of the list, starting from the cursor */
      public String toString() {
        if (cursor == null) return "[]";
        String s = "[..." + cursor.getElement();
        Node oldCursor = cursor;
        for (advance(); oldCursor != cursor; advance()) 
          s += ", " + cursor.getElement();
        return s + "...]";
      }      

      /** Simulation of Duck, Duck, Goose with a circularly linked list. */
      public static void main(String[] args) {
        CircleList C = new CircleList();
        int N = 3; // number of iterations of the game
        Node it;	// the player who is "it"
        Node goose;	// the goose
        Random rand = new Random();
        rand.setSeed(System.currentTimeMillis()); // use current time as seed
        // The players...
        String[] names = {"Bob","Jen","Pam","Tom","Ron","Vic","Sue","Joe"};
        for (int i = 0; i< names.length; i++) {
          C.add(new Node(names[i], null));
          C.advance();
        }
        for (int i = 0; i < N; i++) {	// play Duck, Duck, Goose N times
          System.out.println("Playing Duck, Duck, Goose for " + C.toString());
          it = C.remove();
          System.out.println(it.getElement() + " is it.");
          while (rand.nextBoolean() || rand.nextBoolean()) { // march around circle
    	C.advance(); // advance with probability 3/4
    	System.out.println(C.getCursor().getElement() + " is a duck.");
          }
          goose = C.remove();
          System.out.println(goose.getElement() + " is the goose!");
          if (rand.nextBoolean()) { 
    	System.out.println("The goose won!");
            C.add(goose); // add the goose back in its old place
    	C.advance();  // now the cursor is on the goose
    	C.add(it);    // The "it" person will be it again in next round
          }
          else {
    	System.out.println("The goose lost!");
    	C.add(it);     // add who's "it" back at the goose's place
    	C.advance(); // now the cursor is on the "it" person
            C.add(goose);  // The goose will be "it" in the next round
          }
        }
        System.out.println("Final circle is " + C.toString());
      }

 
    }

