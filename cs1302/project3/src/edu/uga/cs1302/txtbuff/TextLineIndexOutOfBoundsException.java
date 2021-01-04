package edu.uga.cs1302.txtbuff;

public class TextLineIndexOutOfBoundsException extends
						   IndexOutOfBoundsException {

    TextLineIndexOutOfBoundsException() {
	super();
    } // default constructor

    TextLineIndexOutOfBoundsException(String errMsg) {
	super(errMsg);
    } // constructor

    TextLineIndexOutOfBoundsException(int index) {
	super("TextLine index out of range: " + index);
    } // constructor
    
} // class
