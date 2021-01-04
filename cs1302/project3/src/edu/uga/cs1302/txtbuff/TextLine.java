package edu.uga.cs1302.txtbuff;

/** Represents a String in the form of a {@code char[]} array.
 * Has a default size (a {@code final} integer) of 80 and a length
 * which contains the length of the String in the array.
 */
public class TextLine {

    public final int DEFAULT_SIZE = 80;
    /** Array containing the characters of the represented String
     * Set to protected to allow derived classes to access the indices of
     * the array.
     */
    protected char[] array;
    protected int length;

    /** Default constructor which creates an empty {@code TextLine} object
     * Has an array with capacity of {@code DEFAULT_SIZE} and length of 0.
     */
    public TextLine() {
	this.array = new char[DEFAULT_SIZE];
	this.length = 0;
    } // default constructor

    /** Constructor, creates a {@code TextLine} object that contains the
     * given String. Has an array with capacity of a multiple of 
     * {@code DEFAULT_SIZE} sufficient to contain the given String and
     * length equal to the length of the given String.
     */
    public TextLine(String line) {
        this.array = new char[DEFAULT_SIZE + DEFAULT_SIZE *
			      (line.length() / DEFAULT_SIZE)];
	this.length = line.length();
	for (int i = 0; i < this.length; i++) {
	    this.array[i] = line.charAt(i);
	} // for
    } // constructor

    /** Returns the index of the first occurrence of a character sequence
     * matching the given String
     * @return the index of the first occurrence
     * @param the String of which the index will be returned
     */
    public int indexOf(String fragment) {
        return this.indexOf(fragment, 0);
    } // indexOf

    /** Returns the index of the first occurrence of a character sequence
     * matching the given String, starting from the given index
     * @return the index of the first occurrence from the given index
     * @param the String of which the index will be returned
     * @param the index from which to begin searching for the given String
     */
    public int indexOf(String fragment, int fromIndex)
	throws TextLineIndexOutOfBoundsException {
	if (fromIndex < 0  || fromIndex >= this.length) {
	    throw new TextLineIndexOutOfBoundsException(fromIndex);
	} // if
	if (fragment.length() <= 0) {
	    return -1;
	} // if
	if (fragment.length() >= this.length - fromIndex) {
	    return -1;
	} // if
	int count;
	for (int i = fromIndex; i < this.length; i++) {
	    count = 0;
	    if (this.array[i] == fragment.charAt(0)) {
		if (fragment.length() == 1) {
		    return i;
		} // if
		count++;
		for (int j = i + 1; j < i + fragment.length(); j++) {
		    if (this.array[j] == fragment.charAt(j - i)) {
			count++;
			if (count == fragment.length()) {
			    return i;
			} // if
		    } // if
		} // for
	    } // if
	} // for
	return -1;
    } // indexOf from index

    /** Returns the length of the String in the {@code TextLine} object
     * @return the length of the contained String
     */
    public int length() {
	return this.length;
    } // length

    /** Returns the size of the array in the {@code TextLine} object
     * @return the size of the array
     */
    public int capacity() {
	return this.array.length;
    } // capacity

    /** Returns true if the calling object contains the same content as
     * the given object, false otherwise
     * @return true if the object equals the given object, false otherwise
     */
    public boolean equals(Object anObject) {
	if (anObject instanceof String) {
	    String string = (String)anObject;
	    if (string.length() == this.length) {
		boolean isEqual = true;
		for (int i = 0; i < this.length; i++) {
		    if (this.array[i] != string.charAt(0)) {
			isEqual = false;
		    } // if
		} // for
		return isEqual;
	    } // if
	} // if
	if (anObject instanceof char[]) {
	    char[] otherArray = (char[])anObject;
	    if (otherArray.length == this.length) {
		boolean isEqual = true;
		for (int i = 0; i < this.length; i++) {
		    if (this.array[i] != otherArray[i]) {
			isEqual = false;
		    } // if
		} // for
		return isEqual;
	    } // if
	} // if
	if (anObject instanceof TextLine) {
	    TextLine textline = (TextLine)anObject;
	    if (textline.length() == this.length) {
		boolean isEqual = true;
		for (int i = 0; i < this.length; i++) {
		    if (this.array[i] != textline.array[i]) {
			isEqual = false;
		    } // if
		} // for
		return isEqual;
	    } // if
	} // if
	return false;
    } // equals

    /** Returns a String representation of the {@code TextLine}
     * @return String of the {@code TextLine}
     */
    public String toString() {
	return new String(this.array);
    } // toString
    
} // class
