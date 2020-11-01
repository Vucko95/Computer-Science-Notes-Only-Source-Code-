/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rmiproject;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import rmiproject.serverside.ServerRMIBroker;
import rmiproject.serverside.ServerRMIQuotation;
import rmiproject.serverside.icompany.DDQService;
import rmiproject.serverside.icompany.GPQService;

public class StartingProject {
    
    /**
     * Start this first and then run: ClientBrokerRMI
     * The project is lacking comments, but that takes time ;-)
     */

    public static void main(String args[]) throws RemoteException
    {
        Registry regqs = LocateRegistry.createRegistry(7778);
        regqs.rebind("myquotationserver", new ServerRMIQuotation());
        System.out.println("QS server started...");
        
        Registry regbs = LocateRegistry.createRegistry(7780);
        regbs.rebind("mybrokerserver", new ServerRMIBroker());
        System.out.println("BS server started...");
        
        DDQService ddqs = new DDQService();
        GPQService gpqs = new GPQService();
    }
}
