package client;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.text.NumberFormat;

import service.core.BrokerService;
import service.core.ClientInfo;
import service.core.Quotation;
//import service.auldfellas.AFQService;
//import service.broker.LocalBrokerService;
//import service.dodgydrivers.DDQService;
//import service.girlpower.GPQService;
//import service.registry.ServiceRegistry;

public class Client {
	// public static final String BROKER_SERVICE = "bs-BrokerService";
	// public static final String GIRL_POWER_SERVICE = "qs-GirlPowerService";
	// public static final String AULD_FELLAS_SERVICE = "qs-AuldFellasService";
	// public static final String DODGY_DRIVERS_SERVICE = "qs-DodgyDriversService";

	// static { // Create the services and bind them to the registry.
	// 	ServiceRegistry.bind(GIRL_POWER_SERVICE, new GPQService());
	// 	ServiceRegistry.bind(AULD_FELLAS_SERVICE, new AFQService());
	// 	ServiceRegistry.bind(DODGY_DRIVERS_SERVICE, new DDQService());
	// 	ServiceRegistry.bind(BROKER_SERVICE, new LocalBrokerService()); }

	/**
	 * This is the starting point for the application. Here, we must
	 * get a reference to the Broker Service and then invoke the
	 * getQuotations() method on that service.
	 * Finally, you should print out all quotations returned
	 * by the service.
	 * @param args
	 */

	public static void main(String[] args) throws Exception { // BrokerService brokerService = ServiceRegistry.lookup(BROKER_SERVICE, BrokerService.class);

		try {
			Registry registry = LocateRegistry.getRegistry(1099); // get registry with port 
			BrokerService brokerService = (BrokerService) registry.lookup("BROKER_SERVICE");
			// gets the information from BROKER_SERVICE by the last step 
			// cast it in brokerService (interface - cable) and give it a variable 
			// this will create the regestry and store it on the regestry variable // BrokerService b = (BrokerService)registry.lookup("BROKER_SERVICE") // looking up when seperated. // the binds sends it to the regestry... cant bind an object to the regestry... stream of bytes 
			// 	BrokerService b = (BrokerService) UnicastRemoteObject.exportObject(new LocalBrokerService(), 0);
			// 	registry.bind("BROKER_SERVICE", b); // this will bind the regestry so that broker service and ultimitly read from it
			// 	System.out.println("rmi server on... ");

// =============================================================================
// 1. running though every client from clientInfo file 
// 2. running through all quotations from brokerService lookup -> interface which gathers QUOTATIONS
// =============================================================================

			for (ClientInfo info : clients) {
				displayProfile(info);
				// Create the broker and run the test data
				// all clients get quote from ever client 
				for (Quotation quotation : brokerService.getQuotations(info)) { 
					// Retrieve quotations from the broker and display them...
					// for every client get quote from company
					displayQuotation(quotation); // Print a couple of lines between each client
				}
				System.out.println("\n");
			}
		} catch (RemoteException e) {
			e.printStackTrace();
		}
	}


	// =============================================================================
	// these are the clients and their variables : new clients 
	// =============================================================================

	public static final ClientInfo[] clients = {
		// from client info class -- String name, char sex, int age, int points, int noClaims, String licenseNumber
		new ClientInfo("Niki Collier", ClientInfo.FEMALE, 43, 0, 5, "PQR254/1"),
		new ClientInfo("Old Geeza", ClientInfo.MALE, 65, 0, 2, "ABC123/4"),
		new ClientInfo("Hannah Montana", ClientInfo.FEMALE, 16, 10, 0, "HMA304/9"),
		new ClientInfo("Rem Collier", ClientInfo.MALE, 44, 5, 3, "COL123/3"),
		new ClientInfo("Jim Quinn", ClientInfo.MALE, 55, 4, 7, "QUN987/4"),
		new ClientInfo("Donald Duck", ClientInfo.MALE, 35, 5, 2, "XYZ567/9") 
	};
	
	
	// ============================================================================
 	// statements : Display after process 
 	// ============================================================================

	public static void displayProfile(ClientInfo info) {
		System.out.println(
				"|=================================================================================================================|");
		System.out.println(
				"|                                     |                                     |                                     |");
		System.out.println("| Name: " + String.format("%1$-29s", info.name) + " | Gender: "
				+ String.format("%1$-27s", (info.gender == ClientInfo.MALE ? "Male" : "Female")) + " | Age: "
				+ String.format("%1$-30s", info.age) + " |");
		System.out.println("| License Number: " + String.format("%1$-19s", info.licenseNumber) + " | No Claims: "
				+ String.format("%1$-24s", info.noClaims + " years") + " | Penalty Points: "
				+ String.format("%1$-19s", info.points) + " |");
		System.out.println(
				"|                                     |                                     |                                     |");
		System.out.println(
				"|=================================================================================================================|");
	}

	/**
	 * Display a quotation nicely - note that the assumption is that the quotation will follow
	 * immediately after the profile (so the top of the quotation box is missing).
	 * @param quotation
	 */

	public static void displayQuotation(Quotation quotation) {
		System.out.println("| Company: " + String.format("%1$-26s", quotation.company) + " | Reference: "
				+ String.format("%1$-24s", quotation.reference) + " | Price: "
				+ String.format("%1$-28s", NumberFormat.getCurrencyInstance().format(quotation.price)) + " |");
		System.out.println(
				"|=================================================================================================================|");
	}

}
