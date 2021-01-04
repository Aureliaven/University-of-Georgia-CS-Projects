Compile the .java files in the src/edu/uga/cs1302/txtbuff folder in this order:
1. TextLineIndexOutOfBoundsException.java
2. Editable.java
3. TextLine.java
4. EditableTextLine.java

To compile, use the command from the project4 directory:
javac -d bin -cp bin src/edu/uga/cs1302/txtbuff/[FileName].java

To compile the test class in the src/edu/uga/cs1302/test folder, use:
javac -d bin -cp bin:lib/*.jar src/edu/uga/cs1302/test/EditableTextLineTest.java

To run the test, use the command:
java -cp bin:lib/*.jar org.junit.runner.JUnitCore edu.uga.cs1302.test.EditableTextLineTest.java
