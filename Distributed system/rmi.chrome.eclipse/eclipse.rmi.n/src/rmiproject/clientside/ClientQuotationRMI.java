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
import rmiproject.RMIQuotationServices;
import rmiproject.serverside.datamapper.ClientInfo;

public class ClientQuotationRMI {
    
    static RMIQuotationServices qs = null;
    
    public static void main(String args[]) throws RemoteException
    {
        ClientQuotationRMI c = new ClientQuotationRMI();
        c.connectRemote();
    }
    
    public static void startClientQs() throws RemoteException
    {
        ClientQuotationRMI c = new ClientQuotationRMI();
        c.connectRemote();
    }

    private void connectRemote() throws RemoteException {
        try
        {
            Registry reg = LocateRegistry.getRegistry("localhost",7778);
            qs = (RMIQuotationServices) reg.lookup("myquotationserver");
            System.out.println("Are you up? "+qs.getOnline("Are you up?"));
            System.out.println("***************************************");          
            
        }
        catch(NotBoundException e)
        {
            System.out.println("NotBoundException e"+e);
        }
    }
    
    public static RMIQuotationServices getQs()
    {
        return qs;
    }
    
}
