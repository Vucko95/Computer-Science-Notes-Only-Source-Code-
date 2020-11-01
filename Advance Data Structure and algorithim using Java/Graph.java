package net.datastructures;
import java.util.Iterator;
/**
 * An interface for a graph.
 * @author Roberto Tamassia
 */
//begin#fragment Graph
public interface Graph<V, E> {
  /** Returns the number of vertices of the graph */
  public int numVertices();
  /** Returns the number of edges of the graph */
  public int numEdges();
  /** Returns the vertices of the graph as an iterable collection */
  public Iterable<Vertex<V>> vertices();
  /** Returns the edges of the graph as an iterable collection */
  public Iterable<Edge<E>> edges();
  /** Replaces the element of a given vertex with a new element and
      returns the old element */
  public V replace(Vertex<V> p, V o) throws InvalidPositionException;
  /** Replaces the element of a given edge with a new element and
      returns the old element */
  public E replace(Edge<E> p, E o) throws InvalidPositionException;
  /** Returns the edges incident on a vertex as an iterable collection */
  public Iterable<Edge<E>> incidentEdges(Vertex<V> v)
    throws InvalidPositionException;
  /** Returns the endvertices of a vertex as an array of length 2 */
  public Vertex[] endVertices(Edge<E> e) throws InvalidPositionException;
  /** Returns the other endvertex of an incident edge */
  public Vertex<V> opposite(Vertex<V> v, Edge<E> e)
    throws InvalidPositionException;
  /** Tests whether two vertices are adjacent */
  public boolean areAdjacent(Vertex<V> u, Vertex<V> v)
    throws InvalidPositionException;
  /** Inserts and return a new vertex with a given element */
  public Vertex<V> insertVertex(V o);
  /** Inserts and return a new edge with a given element between two
      vertices */
  public Edge<E> insertEdge(Vertex<V> u, Vertex<V> v, E o)
    throws InvalidPositionException;
  /** Removes a vertex and all its incident edges and returns the
      element stored at the removed vertex */
  public V removeVertex(Vertex<V> v) throws InvalidPositionException;
  /** Removes an edge and return its element */
  public E removeEdge(Edge<E> e) throws InvalidPositionException;
}
//end#fragment Graph

