package edu.uga.cs1302.vehicles;

class FlyingShip extends Vehicle implements Flyable, Floatable {

    int maxAltitude;
    int maxRange;

    int tonnage;
    
    // how long it takes for the vehicle to
    // transform from an aircraft into a ship
    int conversionTime;

    public FlyingShip() {
	super();
	this.maxAltitude = 0;
	this.maxRange = 0;
	this.tonnage = 0;
	this.conversionTime = 0;
    } // default constructor

    public FlyingShip(int maxPassengers, int topSpeed, String name,
		      String manufacturer, int year, int maxAltitude,
		      int maxRange, int tonnage, int conversionTime) {
	super(maxPassengers, topSpeed, name, manufacturer, year);
	this.maxAltitude = maxAltitude;
	this.maxRange = maxRange;
	this.tonnage = tonnage;
	this.conversionTime = conversionTime;
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

    public int getTonnage() {
	return this.tonnage;
    } // getTonnage

    public void setTonnage(int tonnage) {
	this.tonnage = tonnage;
    } // setTonnage

    public int getConversionTime() {
	return this.conversionTime;
    } // getConversionTime

    public void setConversionTime(int conversionTime) {
	this.conversionTime = conversionTime;
    } // setConversionTime

    void printDescription() {
	System.out.println("Type: Flying Ship");
	super.printDescription();
	System.out.println("Max altitude: " + this.maxAltitude + " ft");
	System.out.println("Max range: " + this.maxRange + " mi");
	System.out.println("Tonnage: " + this.tonnage);
	System.out.println("Conversion time: " + this.conversionTime + " min");
    } // toString
    
} // class
