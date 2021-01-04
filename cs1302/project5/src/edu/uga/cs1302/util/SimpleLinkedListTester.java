package edu.uga.cs1302.util;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.After;
import org.junit.Test;

public class SimpleLinkedListTester {

    // SimpleLinkedList to be tested
    private SimpleLinkedList<String> list;

    // Set up for test case with default list
    @Before
    public void setUp() {
	list = new SimpleLinkedList<String>();
	list.add("First element");
	list.add("Second element");
	list.add("Third element");
	list.add("Fourth element");
	list.add("Fifth element");
    } // setUp

    // Reset the list to empty
    @After
    public void tearDown() {
	list = null;
    } // tearDown

    // Test the remove() method on the first element
    @Test
    public void testRemoveFirst() {
	assertEquals("First element", list.remove(0));
	assertEquals("Second element", list.get(0));
    } // testRemoveFirst

    // Test the remove() method on the third element
    @Test
    public void testRemoveThird() {
	assertEquals("Third element", list.remove(2));
	assertEquals("Second element", list.get(1));
	assertEquals("Fourth element", list.get(2));
    } // testRemoveThird

    // Test the remove() method on the last element
    @Test
    public void testRemoveLast(){
	assertEquals("Fifth element", list.remove(4));
    } // testRemoveLast

    // Test the remove() method on the whole list
    @Test
    public void testRemoveList() {
	assertEquals("First element", list.remove(0));
	assertEquals("Second element", list.remove(0));
	assertEquals("Third element", list.remove(0));
	assertEquals("Fourth element", list.remove(0));
	assertEquals("Fifth element", list.remove(0));
    } // testRemoveList

    // Test to see if an illegal index would throw an exception
    @Test (expected = IndexOutOfBoundsException.class)
    public void testIllegalIndex() {
	list.remove(5);
    } // testIllegalIndex
    
} // class
