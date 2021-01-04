package edu.uga.cs1302.vehicles;

class Airplane extends Vehicle implements Flyable {

    int maxAltitude;
    int maxRange;

    int numberOfEngines;

    public Airplane() {
	super();
	this.maxAltitude = 0;
	this.maxRange = 0;
	this.numberOfEngines = 0;
    } // default constructor

    public Airplane(int maxPassengers, int topSpeed, String name,
		    String manufacturer, int year, int maxAltitude,
		    int maxRange, int numberOfEngines) {
	super(maxPassengers, topSpeed, name, manufacturer, year);
	this.maxAltitude = maxAltitude;
	this.maxRange = maxRange;
	this.numberOfEngines = numberOfEngines;
    } // constructor

    public int getMaxAltitude() {
	return this.maxAltitude;
    } // getMaxAltitude

    public void setMaxAltitude(int maxAltitude) {
	this.maxAltitude = maxAltitude;
    } // setMaxAltitude

    public int getMaxRange() {
	return this.maxRange;
    } // getMaxRange

    public void setMaxRange(int maxRange) {
	this.maxRange = maxRange;
    } // setMaxRange

    public int getNumberOfEngines() {
	return this.numberOfEngines;
    } // getNumberOfEngines

    public void setNumberOfEngines(int numberOfEngines) {
	this.numberOfEngines = numberOfEngines;
    } // setNumberOfEngines

    void printDescription() {
	System.out.println("Type: Airplane");
	super.toString();
	System.out.println("Max altitude: " + this.maxAltitude + " ft");
	System.out.println("Max range: " + this.maxRange + " mi");
	System.out.println("Number of engines: " + this.numberOfEngines);
    } // toString
    
} // class
