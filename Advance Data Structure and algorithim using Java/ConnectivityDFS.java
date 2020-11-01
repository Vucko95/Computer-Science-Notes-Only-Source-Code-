package net.datastructures;
import java.util.Iterator;
import java.lang.Boolean;

//begin#fragment ConnectivityTesterDFS
/** This class specializes DFS to determine whether the graph is connected. */
public class ConnectivityDFS<V, E> extends DFS <V, E, Object, Boolean> {
  protected int reached;
//end#fragment ConnectivityTesterDFS
  /** Executes the DFS algorithm. 
   * @param graph Input graph
   * @param start Start vertex
   * @param info unused
   * @return {@link Boolean} with value <tt>true</tt> if the graph is
   * connected, <tt>false</tt> otherwise
   */
//begin#fragment ConnectivityTesterDFS
  protected void setup() { reached = 0; }
  protected void startVisit(Vertex<V> v) { reached++; }
  protected Boolean finalResult(Boolean dfsResult) { 
    return new Boolean(reached == graph.numVertices());
  }
}
//end#fragment ConnectivityTesterDFS
