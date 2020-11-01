package net.datastructures;

/**
 * An interface for a position that can be marked with an arbitrary
 * number of decorations.
 *
 * @author Roberto Tamassia, Michael Goodrich
 */
//begin#fragment Decorable
public interface DecorablePosition<E> 
       extends Position<E>, Map<Object,Object> {
} // no new methods needed -- this is a mixture of Position and Map.
//end#fragment Decorable
