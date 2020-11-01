

    public class PersonPairDirectory {
      // ... instance variables would go here ...
      public PersonPairDirectory() {/* default constructor goes here */}
      public void insert (Person person, Person other) {/* insert code goes here */}
      public Person findOther (Person person) { return null; } // stub for find
      public void remove (Person person, Person other) {/* remove code goes here */}

 //Student cute_one = myDirectory.findOther(smart_one);	// wrong!

      // The statement above causes an "explicit cast required" compilation error.
      //The problem here is that we are trying to perform a narrowing conversion without
      //an explicit cast. Namely, the value returned by method findOther is of type Person
      //while the variable cute_one, to which it is assigned, is of the narrower
      //type Student, a class implementing interface Person, Thus, we use a cast to convert
      //type Person to type Student, as follows:
 
      
//Student cute_one = (Student) myDirectory.findOther(smart_one);

      //Casting the value of type Person returned by method findOther to type Student
      //works fine as long as we are sure that the call to myDirectory.findOther is
      //really giving us a Student object. In general, interfaces can be a valuable 
      //tool for the design of general data structures, which can then be specialised
      //by other programmers through the use of casting.
      
    }

