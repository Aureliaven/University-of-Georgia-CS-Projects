package edu.uga.cs1302.vehicles;

class Automobile extends Vehicle {

    int horsepower;

    public Automobile() {
	super();
	this.horsepower = 0;
    } // default constructor

    public Automobile(int maxPassengers, int topSpeed, String name,
		      String manufacturer, int year, int horsepower) {
	super(maxPassengers, topSpeed, name, manufacturer, year);
	this.horsepower = horsepower;
    } // constructor

    int getHorsepower() {
	return this.horsepower;
    } // getHorsepower

    void setHorsepower(int horsepower) {
	this.horsepower = horsepower;
    } // setHorsepower

    void printDescription() {
	System.out.println("Type: Automobile");
	super.printDescription();
	System.out.println("Horsepower: " + this.horsepower);
    } // toString

} // class
