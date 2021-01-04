// Greatly simplified, but similar to the LinkedList class in OpenJDK.

package edu.uga.cs1302.util;
import java.lang.UnsupportedOperationException;
import java.util.NoSuchElementException;
import java.util.ConcurrentModificationException;
import java.util.ListIterator;



/**
 * This class provides a simple generic list implmented as a doubly linked list. 
 * It is similar to the LinkedList class included in the java.util package.
 *
 * The elements on the list are ordered, and the first element of the list 
 * is at position 0 and the last element is at position list.size() - 1.
 */
public class SimpleLinkedList<E> 
    implements SimpleList<E>
{
    private Node<E> first;        // first node of the list
    private Node<E> last;         // last node of the list
    private int     count;	  // number of list elements
    private int     modCount;     // the total number of modifications 
    			          // (add and remove calls)

    /**
     * Creates an empty SimpleLinkedList.
     */
    public SimpleLinkedList()
    {
	first = null;
	last = null;
	count = 0;
	modCount = 0;
    }

    /**
     * Checks if this SimpleLinkedList is empty.
     * @return true if and only if the list is empty
     */
    public boolean isEmpty()
    {
	return count == 0;
    }

    /**
     * Returns the number of elements in this SimpleLinkedList.
     * @return the number of elements in this list
     */
    public int size()
    {
	return count;
    }

    /**
     * Adds an element at the end of this list.
     * @param e the element to be added to the end of this list
     * @return true
     */
    public boolean add( E e )
    {
	Node<E> node = new Node<E>( e, last, null );

	if( last == null )  // list is empty
	    first = node;
	else
	    last.next = node;
	last = node;
	count++;
	modCount++;     // increase modification count; element added
	return true;
    }

    /**
     * Adds an element to the linked list at the given index
     * @param index - the index at which the element will be added
     * @param e - the element to be added to the linked list
     * @return true
     */
    public boolean add( int index, E e )
    {
	ListIterator<E> iterator = listIterator(index);
	if (iterator.nextIndex() == count) {
	    return add(e);
	} // if
	Node<E> node = new Node(e, null, null);
	Node<E> curr = first;
	for (int i = 0; i < index; i++) {
	    curr = curr.next;
	} // for
	if (iterator.hasPrevious()) {
	    node.prev = curr.prev;
	    curr.prev.next = node;
	} // if
	node.next = curr;
	curr.prev = node;
	if (!iterator.hasPrevious()) {
	    first = node;
	} // if
	if (iterator.nextIndex() == count) {
	    last = node;
	} // if
	count++;
	modCount++;
	return true;
    }

    /**
     * Returns the element of the list at the indicated position.
     * @param index the position of the list element to return
     * @return the element at position index
     * @throws IndexOutOfBoundsException if the index is < 0 or >= size()
     */
    public E get( int index )
    { 
	validateIndex( index, count-1 ); // must be an index of an existing element
	Node<E> node = getNodeAt( index );
	return node.elem;
    }
	    
    /**
     * Removes the element at the given index from the linked list, and
     * shifts the elements to accomodate
     * @param index - the index of the element to be removed
     * @return the element at the index being removed
     */
    public E remove( int index ) 
    {
	validateIndex(index, count - 1);
	ListIterator<E> iterator = listIterator(index);
	Node<E> curr = first;
	for (int i = 0; i < index; i++) {
	    curr = curr.next;
	} // for
	if (!iterator.hasPrevious() && curr.next == null) {
	    first = null;
	    last = null;
	    count = 0;
	    modCount++;
	    return curr.elem;
	} // if
	if (!iterator.hasPrevious() && iterator.hasNext()) {
	    first = curr.next;
	    count--;
	    modCount++;
	    return curr.elem;
	} // if
	if (curr.next == null && iterator.hasPrevious()) {
	    last = curr.prev;
	    curr.prev.next = null;
	    count--;
	    modCount++;
	    return curr.elem;
	} // if
	curr.prev.next = curr.next;
	curr.next.prev = curr.prev;
	count--;
	modCount++;
	return curr.elem;
    }

    /**
     * Returns the index of the first occurrence of the given element
     * @param e - the element to compare each element with
     * @return the index of the first occurrence of the given element, -1 otherwise
     */
    public int indexOf( E e )
    {
        ListIterator iterator = listIterator(0);
	while (iterator.hasNext()) {
	    if (iterator.next().equals(e)) {
		return iterator.previousIndex();
	    } // if
	} // while
	return -1;
    }

    /**
     * Returns a ListIterator of the list elements, starting at the given position in this list.
     * @param index the position of the first element on the list to be returned from the iterator
     * @return the created ListIterator
     * throws IndexOutOfBoundsException if the index is < 0 or >= the size of the list
     */
    public ListIterator<E> listIterator( int index ) 
    {
	validateIndex( index, count ); // must be possible to insert after the last element
        return new SimpleLinkedListIterator( index );
    }

    // The methods and inner classes below are private, and are intended for internal use only.

    // Return the node at a given index.
    // The argument, index, must be verified to be a legal index into this list.
    private Node<E> getNodeAt( int index )
    {
	Node<E> curr = first;
	for( int i = 0; i < index; i++ )
	    curr = curr.next;
	return curr;
    }

    // Verify that a given index is within bounds 0 through end.
    // The second argument, end, should be either count-1, if the given index must
    // be a valid index of an existing element, or count, if an insert is to be at 
    // the end of a list, or an iterator starting at the right end of the list.
    private void validateIndex( int index, int end )
    {
	if( index < 0 || index > end )
	    throw new IndexOutOfBoundsException( "Illegal list index: " + index );
    }

    // This is a private inner class implementing a doubly-linked list node.
    // It makes sense for this class to be private, as it is only useful internally to
    // the SimpleLinnkedList class.
    // Because this class is private, so it is accessible only to the host class SimpleLinkedList,
    // therefore, there is no need to define the variables as private.
    private static class Node<E> {
        E       elem;
        Node<E> next;
        Node<E> prev;

        Node( E elem, Node<E> prev, Node<E> next ) {
            this.elem = elem;
            this.next = next;
            this.prev = prev;
        }
    }

    /**
     * This class provides an iterator for the SimpleLinkedList.
     * Some methods have not been implemented intentaionlly;  you 
     * are not expected to implement them.
     */
    private class SimpleLinkedListIterator
	implements ListIterator<E>
    {
	private Node<E> currNode;
	private Node<E> previouslyReturned;
	private int     currPos; // index of the element to be returned next
        private int     expectedModCount; // the count of modifications at the time of this iteractor creation

	// Creates a new iterator starting at position index.
	// javadoc comment needed
	public SimpleLinkedListIterator( int index )
	{
	    validateIndex( index, count ); // verify the staring index;  may be equal to count
	    expectedModCount = modCount;
	    previouslyReturned = null;
	    if( count == 0 )
		currNode = null;
	    else
		currNode = getNodeAt( index );
	    currPos = index;
	}
	    
	// Returns true if this list iterator has more elements when traversing the list forward.
	// javadoc comment needed
	public boolean hasNext() 
	{
	    return currPos < count;
	}

	// Returns true if this list iterator has more elements when traversing the list in the reverse direction.
	// javadoc comment needed
	public boolean hasPrevious()
	{
	    return currPos > 0;
	}

	// Returns the next element on the list.
	// May throw NoSuchElementException if the next element does not exist.
	public E next() 
	{
	    checkForComodification();
	    if( currPos >= count || currNode == null )
		throw new NoSuchElementException();
	    previouslyReturned = currNode;
	    currPos++;
	    currNode = currNode.next;
	    return previouslyReturned.elem;
	}

	// Returns the index of the element that would be returned by a call to next.
	// javadoc comment needed
	public int nextIndex() 
	{
	    return currPos;
	}

	// Returns the previous element in the list.
	// javadoc comment needed
	public E previous() 
	{
	    checkForComodification();
	    if( currPos <= 0 )
		throw new NoSuchElementException();
	    currPos--;
	    if( currNode == null ) {
		currNode = last;
		previouslyReturned = last;
		return previouslyReturned.elem;
	    }
	    else {
		currNode = currNode.prev;
		previouslyReturned = currNode;
		return previouslyReturned.elem;
	    }
	}

	// Returns the index of the element that would be returned by a call to previous.
	// javadoc comment needed
	public int previousIndex() 
	{
	    return currPos - 1;
	}

	// The following are optional operations which are not supported in the 
	// SimpleLinkedList implementation.

	// Adds a new element
	// not implemented here
	public void add(Object e)
	{
	    throw new UnsupportedOperationException( "add called while iterating is not available" );
	}

	// Removes from the list the last element that was returned by next or previous (optional operation).
	// not implemented here
	public void remove() 
	{
	    throw new UnsupportedOperationException( "remove called while iterating is not available" );
	}

	// Replaces the last element returned by next or previous with the specified element (optional operation).
	// not implemented here
	public void set(Object e)
	{
	    throw new UnsupportedOperationException( "set called while iterating is not available" );
	}

	// check if there was a concurrent modification of the list contents.
	// if yes, throw a ConcurrentModificationException exception
	private final void checkForComodification() 
	{
	    if( expectedModCount != SimpleLinkedList.this.modCount )
		throw new ConcurrentModificationException( "list modified while iterator is in progress" );
	}
    }
}
