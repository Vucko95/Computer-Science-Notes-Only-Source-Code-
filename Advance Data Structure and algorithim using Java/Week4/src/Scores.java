/** Class for storing high scores in an array in non-decreasing order. */
public class Scores {
  public static final int maxEntries = 10; // number of high scores we keep
  protected int numEntries;          // number of actual entries
  protected GameEntry[] entries;     // array of game entries (names & scores)
  /** Default constructor */
  public Scores() { 
    entries = new GameEntry[maxEntries];
    numEntries = 0;
  }
  /** Returns a string representation of the high scores list */
  public String toString() {
    String s = "[";
    for (int i = 0; i < numEntries; i++) {
      if (i > 0) s  += ", "; // separate entries by commas
      s += entries[i];
    }
    return s + "]";
  }
  // ... methods for updating the set of high scores go here ...
  /** Attempt to add a new score to the collection (if it is high enough) */
  public void add(GameEntry e) {
    int newScore = e.getScore();
    // is the new entry e really a high score?
    if (numEntries == maxEntries) { // the array is full
      if (newScore <= entries[numEntries-1].getScore())
	return;  // the new entry, e, is not a high score in this case
    }
    else // the array is not full
      numEntries++;
    // Locate the place that the new (high score) entry e belongs
    int i = numEntries-1; 
    for ( ; (i >= 1) && (newScore > entries[i-1].getScore()); i--)
      entries[i] = entries[i - 1]; 	  // move entry i one to the right
    entries[i] = e; 			  // add the new score to entries
  }
  /** Remove and return the high score at index i */
  public GameEntry remove(int i) throws IndexOutOfBoundsException {
    if ((i < 0) || (i >= numEntries))
      throw new IndexOutOfBoundsException("Invalid index: " + i);
    GameEntry temp = entries[i];   // temporarily save the object to be removed
    for (int j = i; j < numEntries - 1; j++)   // count up from i (not down)
      entries[j] = entries[j+1];       // move one cell to the left
    entries[numEntries -1 ] = null;        // null out the old last score 
    numEntries--;
    return temp;                // return the removed object
  }

}
