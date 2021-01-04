package edu.uga.cs1302.vehicles;

abstract class Vehicle implements Transporter {

    private int maxPassengers;
    private int topSpeed;
    
    private String name;
    private String manufacturer;
    private int year;
    private static int numberOfVehicles;

    public Vehicle() {
	this.maxPassengers = 0;
	this.topSpeed = 0;
	this.name = "Unknown";
	this.manufacturer = "Unknown";
	this.year = 0;
	numberOfVehicles += 1;
    } // default constructor

    public Vehicle(int maxPassengers, int topSpeed, String name,
		   String manufacturer, int year) {
	this.maxPassengers = maxPassengers;
	this.topSpeed = topSpeed;
	this.name = name;
	this.manufacturer = manufacturer;
	this.year = year;
	numberOfVehicles += 1;
    } // constructor
    
    public int getMaxPassengers() {
	return this.maxPassengers;
    } // getMaxPassengers

    public void setMaxPassengers(int maxPassengers) {
	this.maxPassengers = maxPassengers;
    } // setMaxPassengers

    public int getTopSpeed() {
	return this.topSpeed;
    } // getTopSpeed

    public void setTopSpeed(int topSpeed) {
	this.topSpeed = topSpeed;
    } // setTopSpeed

    public String getName() {
	return this.name;
    } // getName

    public void setName(String name) {
	this.name = name;
    } // setName

    public String getManufacturer() {
	return this.manufacturer;
    } // getManufacturer

    public void setManufacturer(String manufacturer) {
	this.manufacturer = manufacturer;
    } // setManufacturer

    public int getYear() {
	return this.year;
    } // getYear

    public void setYear(int year) {
	this.year = year;
    } // setYear

    public static int getNumberOfVehicles() {
	return numberOfVehicles;
    } // getNumberOfVehicles

    void printDescription() {
	System.out.println("Name: " + this.name);
	System.out.println("Manufacturer: " + this.manufacturer);
	System.out.println("Manufacture year: " + this.year);
	System.out.println("Maximum passengers: " + this.maxPassengers);
	System.out.println("Top speed: " + this.topSpeed + " mph");
    } // toString

} // class
