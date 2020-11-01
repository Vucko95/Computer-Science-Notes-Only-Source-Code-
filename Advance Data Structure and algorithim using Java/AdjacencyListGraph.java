package net.datastructures;
import java.util.Iterator;

/**
  * An realization of a graph according to adjacency list structure.
  *
  * @author Roberto Tamassia, Eric Zamore
  */

public class AdjacencyListGraph<V,E> implements Graph<V,E> {

  protected NodePositionList<Vertex<V>> VList;	// container for vertices
  protected NodePositionList<Edge<E>> EList;	// container for edges
  /** Default constructor that creates an empty graph */
  public AdjacencyListGraph() {
    VList = new NodePositionList<Vertex<V>>();
    EList = new NodePositionList<Edge<E>>();
  }
  /** Return an iterator over the vertices of the graph */
  public Iterable<Vertex<V>> vertices() {
    return VList;
  }
  /** Return an iterator over the edges of the graph */
  public Iterable<Edge<E>> edges() {
    return EList;
  }
  /** Replace the element a given position (vertex or edge) with a new
      element and return the old element */
  public Object replace(Position p, Object o)
    throws InvalidPositionException {
    MyPosition pp = checkPosition(p);
    Object temp = p.element();
    pp.setElement(o);
    return temp;
  }
  /** Return an iterator over the edges incident on a vertex */
  public Iterable<Edge<E>> incidentEdges(Vertex<V> v)
    throws InvalidPositionException {
    MyVertex<V> vv = checkVertex(v);
    return vv.incidentEdges();

  }
  /** Return the endvertices of a edge in an array of length 2 */
  public Vertex<V>[] endVertices(Edge<E> e)
    throws InvalidPositionException {
    MyEdge<E> ee = checkEdge(e);
    return ee.endVertices();
  }
  /** Return the other endvertex of an incident edge */
  public Vertex<V> opposite(Vertex<V> v, Edge<E> e)
    throws InvalidPositionException {
    checkVertex(v);
    MyEdge<E> ee = checkEdge(e);
    Vertex<V>[] endv = ee.endVertices();
    if (v == endv[0])
      return endv[1];
    else if (v == endv[1])
      return endv[0];
    else
      throw new InvalidPositionException("No such vertex exists");
  }
  /** Test whether two vertices are adjacent */
  public boolean areAdjacent(Vertex<V> u, Vertex<V> v)
    throws InvalidPositionException {
    // search the incidence list of the vertex with smaller degree
    Iterable<Edge<E>> iterToSearch;
    if (degree(u) < degree(v)) {
      iterToSearch = incidentEdges(u);
    }
    else {
      iterToSearch = incidentEdges(v);
    }
    for (Edge<E> e: iterToSearch ) {
      Vertex<V>[] endV = endVertices(e);
      // if there exists an edge whose endpoints are u and v
      if ((endV[0] == u && endV[1] == v) || (endV[0] == v && endV[1] == u))
        return true;
    }
    return false;
  }
  /** Insert and return a new vertex with a given element */
  public Vertex<V> insertVertex(V o) {
    MyVertex<V> vv =  new MyVertex<V>(o);
    VList.addLast(vv);
    Position<Vertex<V>> p = VList.last();
    vv.setLocation(p);
    return vv;
  }
  /** Insert and return a new edge with a given element between two
      vertices */
  public Edge<E> insertEdge(Vertex<V> v, Vertex<V> w, E o)
    throws InvalidPositionException {
    MyVertex<V> vv = checkVertex(v);
    MyVertex<V> ww = checkVertex(w);
    MyEdge<E> ee = new MyEdge<E>(v, w, o);
    Position<Edge<E>> pv = vv.insertIncidence(ee);
    Position<Edge<E>> pw = ww.insertIncidence(ee);
    ee.setIncidences(pv, pw);
    EList.addLast(ee);
    Position<Edge<E>> pe = EList.last();
    ee.setLocation(pe);
    return ee;
  }
  /** Remove a vertex and all its incident edges and return the
      element stored at the removed vertex */
  public V removeVertex(Vertex<V> v)
    throws InvalidPositionException {
    MyVertex<V> vv = checkVertex(v);
    Iterator<Edge<E>> inc = incidentEdges(v).iterator();
    while (inc.hasNext()) {
      MyEdge<E> e = (MyEdge<E>) inc.next();
      if (e.location() != null) // if the edge has not been marked invalid
        removeEdge(e);
    }
    VList.remove(vv.location());
    return v.element();
  }
  /** Remove an edge and return its element */
  public E removeEdge(Edge<E> e)
    throws InvalidPositionException {
    MyEdge<E> ee = checkEdge(e);
    MyVertex<V>[] endv = ee.endVertices();
    Position<Edge<E>>[] inc = ee.incidences();
    endv[0].removeIncidence(inc[0]);
    endv[1].removeIncidence(inc[1]);
    EList.remove(ee.location());
    ee.setLocation(null);	// invalidating this edge
    return e.element();
  }

  // Auxiliary methods

  /** Return the degree of a given vertex */
  public int degree(Vertex<V> v) {
    MyVertex<V> vv = checkVertex(v);
    return vv.degree();
  }

  /** Determines whether a given position is valid. */
  protected MyPosition checkPosition(Position p)
    throws InvalidPositionException {
    if (p == null || !(p instanceof MyPosition))
      throw new InvalidPositionException("Position is invalid");
    return (MyPosition) p;
  }

  /** Determines whether a given vertex is valid. */
  protected MyVertex<V> checkVertex(Vertex<V> v)
    throws InvalidPositionException {
    if (v == null || !(v instanceof MyVertex))
      throw new InvalidPositionException("Vertex is invalid");
    return (MyVertex<V>) v;
  }

  /** Determines whether a given edge is valid. */
  protected MyEdge<E> checkEdge(Edge<E> e)
    throws InvalidPositionException {
    if (e == null || !(e instanceof MyEdge))
      throw new InvalidPositionException("Edge is invalid");
    return (MyEdge<E>) e;
  }

  /** Implementation of a decorable position by means of a hash
   * table. */
  protected static class MyPosition<T>
    extends HashTableMap<Object,Object> implements DecorablePosition<T> {
    /** The element stored at this position. */
    protected T elem;
    /** Returns the element stored at this position. */
    public T element() {
      return elem;
    }
    /** Sets the element stored at this position. */
    public void setElement(T o) {
      elem = o;
    }
  }

  /** Returns a string representation of the vertex and edge lists,
   * separated by a newline. */
  public String toString() {
    return VList.toString() + "\n" +  EList.toString();
  }

  public int numVertices() {
    return VList.size();
  }

  public int numEdges() {
    return EList.size();
  }

  public V replace(Vertex<V> p, V o) throws InvalidPositionException {
    V temp = p.element();
    MyVertex<V> vv = checkVertex(p);
    vv.setElement(o);
    return temp;
  }

  public E replace(Edge<E> p, E o) throws InvalidPositionException {
    E temp = p.element();
    MyEdge<E> ee = checkEdge(p);
    ee.setElement(o);
    return temp;
  }

  /** Implementation of a vertex for an undirected adjacency list
   * graph.  Each vertex stores its incidence container and position
   * in the vertex container of the graph. */
  protected  class MyVertex<V> 
    extends MyPosition<V> implements Vertex<V> {
    /** Incidence container of the vertex. */
    protected PositionList<Edge<E>> incEdges;
    /** Position of the vertex in the vertex container of the graph. */
    protected Position<Vertex<V>> loc;
    /** Constructs the vertex with the given element. */
    MyVertex(V o) {
      elem = o;
      incEdges = new NodePositionList<Edge<E>>();
    }
    /** Return the degree of a given vertex */
    public int degree() {
      return incEdges.size();
    }
    /** Returns the incident edges on this vertex. */
    public Iterable<Edge<E>> incidentEdges() {
      return incEdges;
    }
    /** Inserts an edge into the incidence container of this vertex. */
    public Position<Edge<E>> insertIncidence(Edge<E> e) {
      incEdges.addLast(e);
      return incEdges.last();
    }
    /** Removes an edge from the incidence container of this vertex. */
    public void removeIncidence(Position<Edge<E>> p) {
      incEdges.remove(p);
    }
    /** Returns the position of this vertex in the vertex container of
     * the graph. */
    public Position<Vertex<V>> location() {
      return loc;
    }
    /** Sets the position of this vertex in the vertex container of
     * the graph. */
    public void setLocation(Position<Vertex<V>> p) {
      loc = p;
    }
    /** Returns a string representation of the element stored at this
     * vertex. */
    public String toString() {
      return elem.toString();
    }
  }

  /** Implementation of an edge for an undirected adjacency list
   * graph.  Each edge stores its endpoints (end vertices), its
   * positions within the incidence containers of its endpoints, and
   * position in the edge container of the graph. */
  protected class MyEdge<E> extends MyPosition<E> implements Edge<E> {

    /** The end vertices of the edge. */
    protected MyVertex<V>[] endVertices;
    /** The positions of the entries for the edge in the incidence
     * containers of the end vertices. */
    protected Position<Edge<E>>[] Inc;
    /** The position of the edge in the edge container of the
     * graph. */
    protected Position<Edge<E>> loc;

    /** Constructs an edge with the given endpoints and elements. */
    MyEdge (Vertex<V> v, Vertex<V> w, E o) {
      elem = o;
      endVertices = (MyVertex<V>[]) new MyVertex[2];
      endVertices[0] = (MyVertex<V>)v;
      endVertices[1] = (MyVertex<V>)w;
      Inc = (Position<Edge<E>>[]) new Position[2];
    }
    /** Returns the end vertices of the edge. There are always two
     * elements in the returned array. */
    public MyVertex<V>[] endVertices() {
      return endVertices;
    }
    /** Returns the positions of the edge in the incidence containers
     * of its end vertices.  The returned array always contains two
     * elements. */
    public Position<Edge<E>>[] incidences() {
      return Inc;
    }
    /** Sets the positions of the edge in the incidence containers of
     * its end vertices. */
    public void setIncidences(Position<Edge<E>> pv, Position<Edge<E>> pw) {
      Inc[0] = pv;
      Inc[1] = pw;
    }
    /** Returns the position of the edge in the edge container of the
     * graph. */
    public Position<Edge<E>> location() {
      return loc;
    }
    /** Sets the position of the edge in the edge container of the
     * graph. */
    public void setLocation(Position<Edge<E>> p) {
      loc = p;
    }
    /** Returns a string representation of the edge via a tuple of
     * vertices. */
    public String toString() {
      return element() + "(" + endVertices[0].toString() +
	"," + endVertices[1].toString() + ")";
    }
  }
}


