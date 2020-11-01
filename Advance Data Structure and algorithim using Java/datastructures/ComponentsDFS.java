package net.datastructures;
import java.util.Iterator;

//begin#fragment CC
/** This class extends DFS to compute the connected components of a graph. */
public class ComponentsDFS<V, E> extends DFS<V, E, Object, Integer> {
  protected Integer compNumber; // Connected component number
  protected Object COMPONENT = new Object(); // Connected comp. selector
  protected void setup() { compNumber = 1; }
  protected void startVisit(Vertex<V> v) { v.put(COMPONENT, compNumber);}
  protected Integer finalResult(Integer dfsResult) { 
    for (Vertex<V> v : graph.vertices()) // check for any unvisited vertices
      if (v.get(STATUS) == UNVISITED) { 
        compNumber += 1;  // we have found another connected component
	dfsTraversal(v);  // visit all the vertices of this component
      }
    return compNumber;
  }
}
//end#fragment CC
