package edu.uga.cs1302.txtbuff;

/** This interface represents an object type that can have its
 * string literal value modified
 */
public interface Editable {

    /** Appends the given string {@code fragment} at the end of a
     * {@code TextLine}
     * @param fragment - the string to be appended
     */
    void append(String fragment);

    /** Inserts the given string {@code fragment} at the specified index of
     * a {@code TextLine}.
     * @param index - the index at which the string will be inserted
     * @param fragment - the string to be inserted
     * @throws TextLineIndexOutOfBoundsException - when index is out of bounds
     */
    void insert(int index, String fragment)
	throws TextLineIndexOutOfBoundsException;

    /** Replaces the characters between {@code start} (inclusive) and
     * {@code end} (exclusive) in this {@code TextLine} with characters
     * in the specified string {@code fragment}.
     * @param start - the starting index of replacement (inclusive)
     * @param end - the end index of replacement (exclusive)
     * @param fragment - the string to replace the characters with
     * @throws TextLineIndexOutOfBoundsException - when index is out of bounds
     */
    void replace(int start, int end, String fragment)
	throws TextLineIndexOutOfBoundsException;
    
} // interface
