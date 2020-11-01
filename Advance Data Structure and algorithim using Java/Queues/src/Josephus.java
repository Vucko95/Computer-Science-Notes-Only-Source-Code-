

  //  import net.datastructures.*;
    public class Josephus {
      /** Solution of the Josephus problem using a queue. */
      public static <E> E Josephus(Queue<E> Q, int k) {
        if (Q.isEmpty()) return null;
        while (Q.size() > 1) {
          System.out.println("  Queue: " + Q + "  k = " + k);
          for (int i=0; i < k; i++) 
            Q.enqueue(Q.dequeue());  // move the front element to the end
          E e = Q.dequeue(); // remove the front element from the collection 
          System.out.println("    " + e + " is out");      
          }
        return Q.dequeue();  // the winner
      }
      /** Build a queue from an array of objects */
      public static <E> Queue<E> buildQueue(E a[]) {
        Queue<E> Q = new NodeQueue<E>();
        for (int i=0; i<a.length; i++)
          Q.enqueue(a[i]);
        return Q;
      }
      /** Tester method */
      public static void main(String[] args) {
        String[] a1 = {"Alice", "Bob", "Cindy", "Doug", "Ed", "Fred"};
        String[] a2 = {"Gene", "Hope", "Irene", "Jack", "Kim", "Lance"};
        String[] a3 = {"Mike", "Roberto"};
        System.out.println("First winner is " + Josephus(buildQueue(a1), 3));
        System.out.println("Second winner is " + Josephus(buildQueue(a2), 10));
        System.out.println("Third winner is " + Josephus(buildQueue(a3), 7));
      }
    }

