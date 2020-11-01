package net.datastructures;
import java.util.Iterator;
import java.lang.reflect.Field;

/** 
 * Dijkstra's algorithm for the single-source shortest path problem in
 * an undirected graph whose edges have integer weights.  
 *
 * <p>To execute the algorithm, use the {@link
 * #execute(Graph,Vertex,Object) execute} method, and then make
 * subsequent calls to the {@link #getDist(Vertex) getDist} method to
 * obtain the shortest distance from the start to any given vertex.
 *
 * @author Roberto Tamassia, Michael Goodrich, Eric Zamore
 */

//begin#fragment execute
/* Dijkstra's algorithm for the single-source shortest path problem
 * in an undirected graph whose edges have non-negative integer weights.  */
public class Dijkstra<V, E> {
  /** Infinity value. */
  protected static final Integer INFINITE = Integer.MAX_VALUE;
  /** Input graph. */
  protected Graph<V, E> graph;
  /** Decoration key for edge weights */
  protected Object WEIGHT;
  /** Decoration key for vertex distances  */
  protected Object DIST = new Object();
  /** Decoration key for entries in the priority queue */
  protected Object ENTRY = new Object();
  /** Auxiliary priority queue. */
  protected AdaptablePriorityQueue<Integer, Vertex<V>> Q;
  /** Executes Dijkstra's algorithm.
    * @param g Input graph
    * @param s Source vertex
    * @param w Weight decoration object */
  public void execute(Graph<V, E> g, Vertex<V> s, Object w) {
    graph = g;
    WEIGHT = w;
    DefaultComparator dc = new DefaultComparator();
    Q = new HeapAdaptablePriorityQueue<Integer, Vertex<V>>(dc);
    dijkstraVisit(s);
  }
  /** Get the distance of a vertex from the source vertex.
//end#fragment execute
   * This method returns the length of a shortest path from the source
   * to <tt>u</tt> after {@link #execute(Graph,Vertex,Object) execute}
   * has been called.
//begin#fragment execute
   * @param u Start vertex for the shortest path tree */
  public int getDist(Vertex<V> u) {
    return (Integer) u.get(DIST);
  }
//end#fragment execute

  //begin#fragment dijkstraVisit
  /** The actual execution of Dijkstra's algorithm.
    * @param v source vertex.  
    */
  protected void dijkstraVisit (Vertex<V> v) {
    // store all the vertices in priority queue Q
    for (Vertex<V> u: graph.vertices()) {
      int u_dist;
      if (u==v)
	u_dist = 0;
      else
	u_dist = INFINITE;
      Entry<Integer, Vertex<V>> u_entry = Q.insert(u_dist, u);	// autoboxing
      u.put(ENTRY, u_entry);
    }
    // grow the cloud, one vertex at a time
    while (!Q.isEmpty()) {
      // remove from Q and insert into cloud a vertex with minimum distance
      Entry<Integer, Vertex<V>> u_entry = Q.min();
      Vertex<V> u = u_entry.getValue();
      int u_dist = u_entry.getKey();
      Q.remove(u_entry); // remove u from the priority queue
      u.put(DIST,u_dist); // the distance of u is final
      u.remove(ENTRY); // remove the entry decoration of u
      if (u_dist == INFINITE)
	continue; // unreachable vertices are not processed
      // examine all the neighbors of u and update their distances
      for (Edge<E> e: graph.incidentEdges(u)) {
	Vertex<V> z = graph.opposite(u,e);
	Entry<Integer, Vertex<V>> z_entry 
	                          = (Entry<Integer, Vertex<V>>) z.get(ENTRY);
	if (z_entry != null) { // check that z is in Q, i.e., not in the cloud
	  int e_weight = (Integer) e.get(WEIGHT);
	  int z_dist = z_entry.getKey();
	  if ( u_dist + e_weight < z_dist ) // relaxation of edge e = (u,z)
	    Q.replaceKey(z_entry, u_dist + e_weight);
	}
      }
    }
  }
  //end#fragment dijkstraVisit
} // end of Dijkstra class
