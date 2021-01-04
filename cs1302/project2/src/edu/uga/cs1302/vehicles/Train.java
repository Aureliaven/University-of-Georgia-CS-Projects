package edu.uga.cs1302.vehicles;

class Train extends Vehicle {

    int numberOfCars;

    public Train() {
	super();
	this.numberOfCars = 0;
    } // default constructor

    public Train(int maxPassengers, int topSpeed, String name,
		 String manufacturer, int year, int numberOfCars) {
	super(maxPassengers, topSpeed, name, manufacturer, year);
	this.numberOfCars = numberOfCars;
    } // constructor

    int getNumberOfCars() {
	return this.numberOfCars;
    } // getNumberOfCars

    void setNumberOfCars(int numberOfCars) {
	this.numberOfCars = numberOfCars;
    } // setNumberOfCars

    void printDescription() {
	System.out.println("Type: Train");
	super.printDescription();
	System.out.println("Number of cars: " + this.numberOfCars);
    } // toString
    
} // class
