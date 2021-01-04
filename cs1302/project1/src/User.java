/** This program prints a single line declaring the user's username
 * and the operating system they are running.
 */

public class User {
    
    public static void main (String[] args) {
	
	System.out.println("I am " + UserIdentifier.getUserName() +
			   " on " + UserIdentifier.getOSName());

    } // main
    
} // class
