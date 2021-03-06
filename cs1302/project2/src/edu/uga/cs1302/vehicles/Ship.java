package edu.uga.cs1302.vehicles;

class Ship extends Vehicle implements Floatable {

    int tonnage;

    String shippingLineOwner;

    public Ship() {
	super();
	this.tonnage = 0;
	this.shippingLineOwner = "Unknown";
    } // default constructor

    public Ship(int maxPassengers, int topSpeed, String name,
		String manufacturer, int year, int tonnage,
		String shippingLineOwner) {
	super(maxPassengers, topSpeed, name, manufacturer, year);
	this.tonnage = tonnage;
	this.shippingLineOwner = shippingLineOwner;
    } // constructor

    public int getTonnage() {
	return this.tonnage;
    } // getTonnage

    public void setTonnage(int tonnage) {
	this.tonnage = tonnage;
    } // setTonnage

    public String getShippingLineOwner() {
	return this.shippingLineOwner;
    } // getShippingLineOwner

    void setShippingLineOwner(String shippingLineOwner) {
	this.shippingLineOwner = shippingLineOwner;
    } // setShippingLineOwner

    void printDescription() {
	System.out.println("Type: Ship");
	super.printDescription();
	System.out.println("Tonnage: " + this.tonnage);
	System.out.println("Shipping Line: " + this.shippingLineOwner);
    } // toString
    
} // class
