package net.datastructures;
import java.util.Iterator;
//begin#fragment FindCycleDFS
/** This class specializes DFS to find a cycle. */
//end#fragment FindCycleDFS
 /* @author Roberto Tamassia, Michael Goodrich, Eric Zamore
 */
//begin#fragment FindCycleDFS
public class FindCycleDFS<V, E> 
  extends DFS<V, E, Object, Iterable<Position>> {
  protected PositionList<Position> cycle; // sequence of edges of the cycle
  protected boolean done;
  protected Vertex<V> cycleStart;
//end#fragment FindCycleDFS
  /**
   * Executes the DFS algorithm.
   * @param info unused
   * @return {@link Iterable} collection containing the vertices and
   * edges of a cycle.
   */
//begin#fragment FindCycleDFS
  public void setup() { 
    cycle = new NodePositionList<Position>();
    done = false;
  }
  protected void startVisit(Vertex<V> v) { cycle.addLast(v); }
  protected void finishVisit(Vertex<V> v) {
    cycle.remove(cycle.last());	// remove v from cycle
    if (!cycle.isEmpty()) cycle.remove(cycle.last()); // remove edge into v from cycle
  }
  protected void traverseDiscovery(Edge<E> e, Vertex<V> from) { 
    cycle.addLast(e); 
  }
  protected void traverseBack(Edge<E> e, Vertex<V> from) {
    cycle.addLast(e);		// back edge e creates a cycle
    cycleStart = graph.opposite(from, e);
    cycle.addLast(cycleStart);	// first vertex completes the cycle
    done = true;
  }
  protected boolean isDone() {  return done; } 
  public Iterable<Position> finalResult(Iterable<Position> r) {
    // remove the vertices and edges from start to cycleStart
    if (!cycle.isEmpty()) {
      for (Position<Position> p: cycle.positions()) {
	if (p.element() == cycleStart)
	  break;
	cycle.remove(p);                     // remove vertex from cycle
      }
    }
    return cycle; // list of the vertices and edges of the cycle 
  }
}
//end#fragment FindCycleDFS

