/******************************************************************************
 *  Compilation:  javac Knuth.java
 *  Execution:    java Knuth < list.txt
 *  Dependencies: StdIn.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/11model/cards.txt
 *                https://algs4.cs.princeton.edu/11model/cardsUnicode.txt
 *  
 *  Reads in a list of strings and prints them in random order.
 *  The Knuth (or Fisher-Yates) shuffling algorithm guarantees
 *  to rearrange the elements in uniformly random order, under
 *  the assumption that Math.random() generates independent and
 *  uniformly distributed numbers between 0 and 1.
 *
 *  % more cards.txt
 *  2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC AC
 *  2D 3D 4D 5D 6D 7D 8D 9D 10D JD QD KD AD
 *  2H 3H 4H 5H 6H 7H 8H 9H 10H JH QH KH AH
 *  2S 3S 4S 5S 6S 7S 8S 9S 10S JS QS KS AS
 *
 *  % java Knuth < cards.txt
 *  6H
 *  9C
 *  8H
 *  7C
 *  JS
 *  ...
 *  KH
 *
 *  % more cardsUnicode.txt
 *  2♣ 3♣ 4♣ 5♣ 6♣ 7♣ 8♣ 9♣ 10♣ J♣ Q♣ K♣ A♣ 
 *  2♦ 3♦ 4♦ 5♦ 6♦ 7♦ 8♦ 9♦ 10♦ J♦ Q♦ K♦ A♦ 
 *  2♥ 3♥ 4♥ 5♥ 6♥ 7♥ 8♥ 9♥ 10♥ J♥ Q♥ K♥ A♥ 
 *  2♠ 3♠ 4♠ 5♠ 6♠ 7♠ 8♠ 9♠ 10♠ J♠ Q♠ K♠ A♠ 
 * 
 *  % java Knuth < cardsUnicode.txt
 *  2♠
 *  K♥
 *  6♥
 *  5♣
 *  J♣
 *  ...
 *  A♦
 *
 ******************************************************************************/

/**
 *  The {@code Knuth} class provides a client for reading in a 
 *  sequence of strings and <em>shuffling</em> them using the Knuth (or Fisher-Yates)
 *  shuffling algorithm. This algorithm guarantees to rearrange the
 *  elements in uniformly random order, under
 *  the assumption that Math.random() generates independent and
 *  uniformly distributed numbers between 0 and 1.
 *  <p>
 *  For additional documentation,
 *  see <a href="https://algs4.cs.princeton.edu/11model">Section 1.1</a> of
 *  <i>Algorithms, 4th Edition</i> by Robert Sedgewick and Kevin Wayne.
 *  See {@link StdRandom} for versions that shuffle arrays and
 *  subarrays of objects, doubles, and ints.
 *
 *  @author Robert Sedgewick
 *  @author Kevin Wayne
 */


public class KnuthShuffle { 

    // this class should not be instantiated
    private KnuthShuffle() { }

    /**
     * Rearranges an array of objects in uniformly random order
     * (under the assumption that {@code Math.random()} generates independent
     * and uniformly distributed numbers between 0 and 1).
     * @param a the array to be shuffled
     */
    public static void shuffle(Object[] a) {
        int n = a.length;
        for (int i = 0; i < n; i++) {
            // choose index uniformly in [0, i]
            int r = (int) (Math.random() * (i + 1));
            Object swap = a[r];
            a[r] = a[i];
            a[i] = swap;
        }
    }

    /**
     * Rearranges an array of objects in uniformly random order
     * (under the assumption that {@code Math.random()} generates independent
     * and uniformly distributed numbers between 0 and 1).
     * @param a the array to be shuffled
     */
    public static void shuffleAlternate(Object[] a) {
        int n = a.length;
        for (int i = 0; i < n; i++) {
            // choose index uniformly in [i, n-1]
            int r = i + (int) (Math.random() * (n - i));
            Object swap = a[r];
            a[r] = a[i];
            a[i] = swap;
        }
    }

    /**
     * Reads in a sequence of strings from standard input, shuffles
     * them, and prints out the results.
     *
     * @param args the command-line arguments
     */
    public static void main(String[] args) {

        // read in the data
        String[] a = StdIn.readAllStrings();
        System.out.println(a); 

        // shuffle the array
        KnuthShuffle.shuffle(a);

        // print results.
        for (int i = 0; i < a.length; i++)
            StdOut.println(a[i]);
    }
}