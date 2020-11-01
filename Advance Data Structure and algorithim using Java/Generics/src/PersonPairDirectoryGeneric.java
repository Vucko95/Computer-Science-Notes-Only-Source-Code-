

    public class PersonPairDirectoryGeneric<P extends Person> {
      // ... instance variables would go here ...
      public PersonPairDirectoryGeneric() { /* default constructor goes here */ }
      public void insert (P person, P other) { /* insert code goes here */ }
      public P findOther (P person) { return null; } // stub for find
      public void remove (P person, P other) { /* remove code goes here */ }

      public static void main(String[] args) {
        Pair<String,Integer>[] a = new Pair[10]; // right, but gives a warning
        //Pair<String,Integer>[] b = new Pair<String,Integer>[10]; // wrong!!
        a[0] = new Pair<String,Integer>();  // this is completely right
        a[0].set("Dog",10);		// this and the next statement are right too
        System.out.println("First pair is "+a[0].getKey()+", "+a[0].getValue());
      }

    }

