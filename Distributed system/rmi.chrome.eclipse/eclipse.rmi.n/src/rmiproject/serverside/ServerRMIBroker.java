/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rmiproject.serverside;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.text.NumberFormat;
import java.util.LinkedList;
import java.util.List;
import rmiproject.RMIBrokerServices;
import rmiproject.RMIProject;
import rmiproject.RMIQuotationServices;
import rmiproject.clientside.ClientQuotationRMI;
import rmiproject.registry.ServiceRegistry;
import rmiproject.serverside.datamapper.ClientInfo;
import rmiproject.serverside.datamapper.Quotation;

/**
 *
 * @author bve22641
 */
public class ServerRMIBroker extends UnicastRemoteObject implements RMIBrokerServices {
    
    public ServerRMIBroker() throws RemoteException
    {
        super();
        ClientQuotationRMI.startClientQs();
    }
    
    /* Some data ... could also be a Database Service */
    public static final ClientInfo[] clients = { 
			new ClientInfo("Niki Collier", ClientInfo.FEMALE, 43, 0, 5, "PQR254/1"),
			new ClientInfo("Old Geeza", ClientInfo.MALE, 65, 0, 2, "ABC123/4"),
			new ClientInfo("Hannah Montana", ClientInfo.FEMALE, 16, 10, 0, "HMA304/9"),
			new ClientInfo("Rem Collier", ClientInfo.MALE, 44, 5, 3, "COL123/3"),
			new ClientInfo("Jim Quinn", ClientInfo.MALE, 55, 4, 7, "QUN987/4"),
			new ClientInfo("Donald Duck", ClientInfo.MALE, 35, 5, 2, "XYZ567/9") 
		};
    
    public static void displayProfile(ClientInfo info) {
			System.out.println("|=================================================================================================================|");
			System.out.println("|                                     |                                     |                                     |");
			System.out.println("| Name: " + String.format("%1$-29s", info.name) + " | Gender: "
					+ String.format("%1$-27s", (info.gender == ClientInfo.MALE ? "Male" : "Female")) + " | Age: "
					+ String.format("%1$-30s", info.age) + " |");
			System.out.println("| License Number: " + String.format("%1$-19s", info.licenseNumber) + " | No Claims: "
					+ String.format("%1$-24s", info.noClaims + " years") + " | Penalty Points: "
					+ String.format("%1$-19s", info.points) + " |");
			System.out.println("|                                     |                                     |                                     |");
			System.out.println("|=================================================================================================================|");
		}
    
 
    public static void main(String args[]) throws RemoteException, UnknownHostException
    {
        
        /* C:\Program Files\Java\jdk1.8.0_181\bin>rmiregistry.exe 1100 */
        try
        {
            //System.setProperty("java.rmi.server.hostname", "myrmiserver");
            //System.setProperty("sun.rmi.log.debug", "true");
            //System.setProperty("java.rmi.useLocalHostName","true");
            
            //ServerRMIBroker srmib = new ServerRMIBroker();
            //ServerRMIBroker stub = (ServerRMIBroker)UnicastRemoteObject.exportObject(srmib, 0);
            //Registry reg = LocateRegistry.getRegistry("myrmiserver", 1100);
            Registry reg = LocateRegistry.createRegistry(7778);
            //reg.rebind("mybrokerserver", stub);
            reg.rebind("mybrokerserver", new ServerRMIBroker());
            System.out.println("I am up as a broker server...");
        }catch(RemoteException e)
        {
            System.out.println("Exception e"+e.getMessage());
            System.err.println("Got an error: " + e);
        }
    }    

    @Override
    public String getName() throws RemoteException {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void send(String msg) throws RemoteException {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void setClient(RMIBrokerServices c) throws RemoteException {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public RMIBrokerServices getClient() throws RemoteException {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public ClientInfo[] getClientList() throws RemoteException {
        for (ClientInfo info : clients) { // Create the broker and run the test data
			displayProfile(info); // all clients get quote from ever client 
                        System.out.println("***[ Quotations ]***");
			for (Quotation quotation : ClientQuotationRMI.getQs().getQuotations(info)) { // Retrieve quotations from the broker and display them...
				// for every client get quote from company
                                System.out.println("***[ "+info.name+" ]***");
				ClientQuotationRMI.getQs().displayQuotation(quotation); // Print a couple of lines between each client
                                System.out.println("***");
			}
			System.out.println("\n");
		}
        return clients;
    }

    @Override
    public String getOnline(String question) throws RemoteException {
       return "yes";
    }


}
