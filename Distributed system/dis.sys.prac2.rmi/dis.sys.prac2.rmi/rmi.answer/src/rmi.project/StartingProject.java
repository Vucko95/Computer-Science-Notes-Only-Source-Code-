
package rmiproject;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import rmiproject.serverside.ServerRMIBroker;
import rmiproject.serverside.ServerRMIQuotation;
import rmiproject.serverside.icompany.DDQService;
import rmiproject.serverside.icompany.GPQService;

public class StartingProject {

/* START THIS FIRST AND THEN RUN CLIENT BROKER RMI !!! */
public static void main(String args[]) throws RemoteException {

    // you will need to create the registry and assign it to a port 
    Registry regqs = LocateRegistry.createRegistry(7778); // port 7778
    // then rebind the server RMIquotation to the quotation server  
    regqs.rebind("myquotationserver", new ServerRMIQuotation());
    System.out.println("QS server started...");

    // this will create the second registry/ server to rebind everything for the broker. 
    Registry regbs = LocateRegistry.createRegistry(7780); // port 7780
    regbs.rebind("mybrokerserver", new ServerRMIBroker());
    System.out.println("BS server started...");

    // creating the objects with the appropriate services 
    DDQService ddqs = new DDQService();
    GPQService gpqs = new GPQService();
  }
}
