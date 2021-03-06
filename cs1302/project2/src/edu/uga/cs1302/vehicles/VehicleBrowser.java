package edu.uga.cs1302.vehicles;

import java.util.Scanner;

/** Contains the main method for browsing the
 * vehicle objects that have been created
 */

public class VehicleBrowser {

    public static void main(String[] args) {

	// create 3 examples of each vehicle type
	Automobile audiA4 = new Automobile(5, 150, "A4", "Audi", 2016, 160);
	Automobile jeepWrangler = new Automobile(5, 120, "Wrangler",
						 "Jeep", 2018, 285);
	Automobile cadillacXT6 = new Automobile(7, 120, "XT6", "Cadillac",
						2019, 300);

	Airplane boeing737 = new Airplane(250, 550, "737", "Boeing", 2010,
					  40000, 8400, 4);
	Airplane airbusA320 = new Airplane(200, 500, "A320", "Airbus", 2008,
					   38000, 8200, 4);
	Airplane boeing747 = new Airplane(500, 640, "747", "Boeing", 2015,
					  45000, 9000, 4);

	Ship harmonyOfTheSeas = new Ship(5500, 35, "Harmony of the Seas",
					 "Chantiers de l'Atlantique", 2016,
					 226963, "Royal Caribbean");
	Ship carnivalVista = new Ship(4000, 35, "Carnival Vista",
				      "Fincantieri", 2016, 133500, "Carnival");
	Ship norwegianEscape = new Ship(4200, 35, "Norwegian Escape",
					"Meyer Werft", 2012, 150320,
					"Norwegian");

	Train goldenEagle = new Train(1000, 80, "Golden Eagle", "Kolomna",
				      2007, 10);
	Train orientExpress = new Train(2000, 100, "Orient Express", "Venezia",
					2002, 22);
	Train cyberBullet = new Train(3000, 150, "Cyber Bullet", "CD Projekt",
				      2050, 30);

	FlyingShip nightHawk = new FlyingShip(1000, 500, "Night Hawk",
					      "Nightingale", 2030, 40000,
					      5000, 200000, 5);
	FlyingShip sailsOfTheSky = new FlyingShip(2000, 550, "Sails of the" +
						  " Sky", "Royal Transport",
						  2025, 42000, 4500, 250000,
						  8);
	FlyingShip avatarOfHeaven = new FlyingShip(800, 650, "Avatar of " +
						   "Heaven", "Monastery",
						   2040, 50000, 7000, 150000,
						   3);

	//create array of vehicles
	Vehicle[] vehicles = new Vehicle[15];
        vehicles[0] = audiA4;
	vehicles[1] = jeepWrangler;
	vehicles[2] = cadillacXT6;
	vehicles[3] = boeing737;
	vehicles[4] = airbusA320;
	vehicles[5] = boeing747;
	vehicles[6] = harmonyOfTheSeas;
	vehicles[7] = carnivalVista;
	vehicles[8] = norwegianEscape;
	vehicles[9] = goldenEagle;
	vehicles[10] = orientExpress;
	vehicles[11] = cyberBullet;
	vehicles[12] = nightHawk;
	vehicles[13] = sailsOfTheSky;
	vehicles[14] = avatarOfHeaven;

	Scanner scan = new Scanner(System.in);
	String input = "";

	while(!input.equalsIgnoreCase("q")) {
	    System.out.println("Enter an option: (1-6, 'h' (help), or " +
			       "'q' (quit))");
	    input = scan.nextLine();
	    switch(input) {
	    case "1" :
		System.out.println("Number of vehicles in system: " +
				   Vehicle.getNumberOfVehicles());
		break;

	    case "2" :
		int counter = 1;
		String type = "";
		for (Vehicle v : vehicles) {
		    if (v instanceof Automobile) {
			type = "Automobile";
		    } // if
		    else if (v instanceof Airplane) {
			type = "Airplane";
		    }
		    else if (v instanceof Ship) {
			type = "Ship";
		    }
		    else if (v instanceof Train) {
			type = "Train";
		    }
		    else if (v instanceof FlyingShip) {
			type = "Flying Ship";
		    }
		    System.out.println(counter + ". " + v.getName() + " - " +
				       type);
		    counter++;
		} // for each
		break;
	    case "3" :
		System.out.println("Vehicles that can fly: ");
		for (Vehicle v : vehicles) {
		    if (v instanceof Flyable) {
			System.out.println(v.getManufacturer() + " " +
					   v.getName());
		    } // if
		} // for each
		break;
	    case "4" :
		System.out.println("Vehicles that can float: ");
		for (Vehicle v : vehicles) {
		    if (v instanceof Floatable) {
			System.out.println(v.getManufacturer() + " " +
					   v.getName());
		    } // if
		} // for each
		break;
	    case "5" :
		System.out.println("Vehicles that can fly and float: ");
		for (Vehicle v : vehicles) {
		    if (v instanceof Flyable && v instanceof Floatable) {
			System.out.println(v.getManufacturer() + " " +
					   v.getName());
		    } // if
		} // for each
		break;
	    case "6" :
		System.out.println("Vehicle Descriptions: ");
		for (Vehicle v : vehicles) {
		    System.out.println();
		    v.printDescription();
		} // for each
		break;
	    case "h" :
		System.out.println("Press 1 to see how many vehicles are " +
				   "in the system");
		System.out.println("Press 2 to see the name and type of " +
				   "each vehicle");
		System.out.println("Press 3 to see which vehicles can " +
				   "fly");
		System.out.println("Press 4 to see which vehicles can " +
				   "float");
		System.out.println("Press 5 to see which vehicles can " +
				   "fly and float");
		System.out.println("Press 6 to see a description of each " +
				   "vehicle in the system");
		System.out.println("Press h to see help information for " +
				   "the system");
		System.out.println("Press q to quit this program");
		break;
	    case "q" :
		System.exit(0);
		break;
	    default:
		System.out.println("Invalid option");
	    } // switch
	} // while
	scan.close();
	
    } // main
    
} // class
