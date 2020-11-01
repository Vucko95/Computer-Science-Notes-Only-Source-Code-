
 package client;
 import java.rmi.registry.LocateRegistry;
 import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
 import service.broker.LocalBrokerService;
 import service.core.BrokerService;
 
public class Server {
	// public static final String BROKER_SERVICE = "bs-BrokerService";
	// public static final String GIRL_POWER_SERVICE = "qs-GirlPowerService";
	// public static final String AULD_FELLAS_SERVICE = "qs-AuldFellasService";
	// public static final String DODGY_DRIVERS_SERVICE = "qs-DodgyDriversService";

	// static { // Create the services and bind them to the registry.
	// 	ServiceRegistry.bind(GIRL_POWER_SERVICE, new GPQService());
	// 	ServiceRegistry.bind(AULD_FELLAS_SERVICE, new AFQService());
	// 	ServiceRegistry.bind(DODGY_DRIVERS_SERVICE, new DDQService());
	// 	ServiceRegistry.bind(BROKER_SERVICE, new LocalBrokerService()); }

	// puts up the broker service - object which stores all the services - gives out the info 
	// puts it up on the registry with bind 

	public static void main(String[] args){
		

	// ===========================================================================
	// 1. create the registry on the right port 
	// 2. taking the localbrokerservice, hash: and setting it to the brokerervice 
	// 3. binding that to te registry BROKER_SERVICE STRING (preparing it for the lookup)
  // ===========================================================================

		while (true) {
			try {
				 Registry registry = LocateRegistry.createRegistry(1099); // this will create the regestry and store it on the regestry variable // BrokerService b = (BrokerService)registry.lookup("BROKER_SERVICE") // looking up when seperated. // the binds sends it to the regestry... cant bind an object to the regestry... stream of bytes 
			
				 BrokerService a = (BrokerService) UnicastRemoteObject.exportObject(new LocalBrokerService(), 0);
				 // needs to have this since rmi only understands moving information by hash
				 registry.bind("BROKER_SERVICE", a); // this will bind the regestry so that broker service and ultimitly read from it
				 System.out.println("RMI server on... ");
			Thread.sleep(10000);
			} catch (Exception e) {
			 e.printStackTrace();
		 }
	}
	}
}