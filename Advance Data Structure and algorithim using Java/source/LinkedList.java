/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author rem
 */
public class LinkedList implements List {
    private class Node implements Position {
        Node previous;
        Node next;
        Object element;

        public Node(Object element) {
            this.element = element;
        }

        public Object element() {
            return element;
        }
    }

    private int size;
    private Node first;
    private Node last;

    public LinkedList() {
        size = 0;
        first = last = null;
    }
    
    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public Position first() throws ListEmptyException {
        if (first == null) throw new ListEmptyException();

        return first;
    }

    public Position last() throws ListEmptyException {
        if (last == null) throw new ListEmptyException();

        return last;
    }

    public Position prev(Position p) throws BoundaryViolationException {
        return null;
    }

    public Position next(Position p) throws BoundaryViolationException {
        // Implement this method based on pseudo code from the CLASS
        return null;
    }

    public Position insertFirst(Object e) {
        Node node = new Node(e);
        if (first == null) {
            last = node;
        } else {
            first.previous = node;
        }
        node.next = first;
        first = node;
        size++;
        return node;
    }

    public Position insertLast(Object e) {
        // Implement this method based on pseudo code from the CLASS
        return null;
    }

    public Position insertBefore(Position p, Object e) {
        // Implement this method based on YOUR pseudo code
        return null;
    }

    public Position insertAfter(Position p, Object e) {
        Node n = (Node) p;

        if (p == last) return insertLast(e);

        Node node = new Node(e);
        node.next = n.next;
        node.previous = n;
        n.next.previous = node;
        n.next = node;
        size++;
        return node;
    }

    public Object replace(Position p, Object e) {
        // Implement this method based on YOUR pseudo code
        return null;
    }

    public Object remove(Position p) {
        // Implement this method based on pseudo code from the CLASS
        return null;
    }
}
