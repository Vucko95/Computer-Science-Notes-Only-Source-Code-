/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rmiproject.clientside;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import rmiproject.RMIProject;

/**
 *
 * @author DisruptiveNL
 */
public class ClientRMI {
    
    public static void main(String args[]) throws RemoteException
    {
        ClientRMI c = new ClientRMI();
        c.connectRemote();
    }

    private void connectRemote() throws RemoteException {
        try
        {
            Registry reg = LocateRegistry.getRegistry("localhost",7777);
            RMIProject a = (RMIProject) reg.lookup("myserver");
            System.out.println("Hello "+a.getData("Greg"));
            
        }
        catch(NotBoundException e)
        {
            System.out.println("NotBoundException e"+e);
        }
    }
    
}
