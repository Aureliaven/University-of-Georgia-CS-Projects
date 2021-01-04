package edu.uga.cs1302.test;
import edu.uga.cs1302.txtbuff.*;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.After;
import org.junit.Test;

public class EditableTextLineTest {

    // EditableTextLines to be tested
    private EditableTextLine line;

    // Set up for test case with default EditableTextLine
    @Before
    public void setUp() {
	line = new EditableTextLine("My name is Darren");
    } // setUp

    // Reset the EditableTextLine to null
    @After
    public void tearDown() {
	line = null;
    } // tearDown

    // Test the creation of a TextLine with <80 length
    @Test
    public void testInstantiateDefault() {
	assertEquals(line.length(), 17);
	assertEquals(line.capacity(), 80);
	assertEquals(line.toString(), "My name is Darren"));
    } // testInstantiateDefault

    // Test the creation of a TextLine with >80 length
    @Test
    public void testInstantiateLonger() {
	line = new EditableTextLine("My name is AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	assertEquals(line.length(), 100);
	assertEquals(line.capacity(), 160);
	assertEquals(line.toString(), "My name is AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    } // testInstantiateLonger

    // Test the append method that would cause the buffer size to increase
    @Test
    public void testAppend() {
	line.append("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	assertEquals(line.length(), 99);
	assertEquals(line.capacity(), 160);
	assertEquals(line.toString(), "My name is DarrenAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    } // testAppend

    // Test the insert method at index 0 that would cause the buffer size
    // to increase
    @Test
    public void testInsertAtStart() {
	line.insert(0, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	assertEquals(line.length(), 99);
	assertEquals(line.capacity(), 160);
	assertEquals(line.toString(), "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMy name is Darren");
    } // testInsertAtStart

    // Test the insert method at the index line.length() that would cause
    // the buffer size to increase
    @Test
    public void testInsertAtEnd() {
	line.insert(line.length(), "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	assertEquals(line.length(), 99);
	assertEquals(line.capacity(), 160);
	assertEquals(line.toString(), "My name is DarrenAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    } // testInsertAtEnd

    // Test the replace method, replacing the String "name," that would cause
    // the buffer size to increase
    @Test
    public void testReplaceName() {
	line.replace(3, 7, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	assertEquals(line.length(), 95);
	assertEquals(line.capacity(), 160);
	assertEquals(line.toString(), "My AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA is Darren");
    } // testReplaceName

    // Test the replace method, replacing the String "My," that would cause
    // the buffer size to increase
    @Test
    public void testReplaceMy() {
	line.replace(0, 2, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	assertEquals(line.length(), 97);
	assertEquals(line.capacity(), 160);
	assertEquals(line.toString(), "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA name is Darren");
    } // testReplaceMy

    // Test the replace method, replacing the String "Darren," that would cause
    // the buffer size to increase
    @Test
    public void testReplaceDarren() {
	line.replace(11, 17, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	assertEquals(line.length(), 93);
	assertEquals(line.capacity(), 160);
	assertEquals(line.toString(), "My name is AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    } // testReplaceDarren

    // Test an illegal index with the insert method
    @Test(expected = edu.uga.cs1302.txtbuff.TextLineIndexOutOfBoundsException.class)
    public void testIllegalIndex() {
	line.insert(-1, "illegal index");
    } // testIllegalIndex

    // Test an illegal index with the insert method
    @Test(expected = edu.uga.cs1302.txtbuff.TextLineIndexOutOfBoundsException.class)
    public void testIllegalIndex2() {
	line.insert(20, "illegal index");
    } // testIllegalIndex2
    
} // class
