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
import java.util.Arrays;
import java.util.Iterator;
import rmiproject.RMIBrokerServices;
import rmiproject.RMIProject;
import rmiproject.serverside.datamapper.ClientInfo;

/**
 *
 * @author DisruptiveNL
 */
public class ClientBrokerRMI {
    
    public static void main(String args[]) throws RemoteException
    {
        ClientBrokerRMI c = new ClientBrokerRMI();
        c.connectRemote();
    }

    private void connectRemote() throws RemoteException {
        try
        {
            Registry reg = LocateRegistry.getRegistry("localhost",7780);
            RMIBrokerServices bs = (RMIBrokerServices) reg.lookup("mybrokerserver");
            System.out.println("Are you up? "+bs.getOnline("Are you up?"));
            System.out.println("***************************************");
            ClientInfo[] cinfo = bs.getClientList();
            for (int i=0; i < cinfo.length; ++i){
                System.out.println(""+cinfo[i].name);
            }
            
            
        }
        catch(NotBoundException e)
        {
            System.out.println("NotBoundException e"+e);
        }
    }
    
}
