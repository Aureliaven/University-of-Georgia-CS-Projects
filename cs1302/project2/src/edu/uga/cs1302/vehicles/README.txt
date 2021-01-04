README.txt by Darren Yu (811009973)

Instructions for compiling and executing the project2 folder

Compile the files in this order:
1. Transporter.java
2. Flyable.java
3. Floatable.java
4. Vehicle.java
5. Automobile.java
6. Airplane.java
7. Ship.java
8. Train.java
9. FlyingShip.java
10. VehicleBrowser.java

Make sure you are in the project2 directory, and execute this command for
each .java file:

     javac -d bin -cp bin src/edu/uga/cs1302/vehicles/[FILENAME].java

To execute, run VehicleBrowser.java with the following command:

     java -cp bin edu.uga.cs1302.vehicles.VehicleBrowser
