/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rmiproject.serverside;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import rmiproject.RMIProject;
import rmiproject.serverside.datamapper.ClientInfo;
import rmiproject.serverside.datamapper.Quotation;

/**
 *
 * @author bve22641
 */
public class ServerRMI extends UnicastRemoteObject implements RMIProject{
    
    public ServerRMI() throws RemoteException
    {
        super();
    }

    @Override
    public String getData(String text) throws RemoteException {
        return "Welkom "+text;
    }
    
    public static void main(String args[]) throws RemoteException
    {
        try
        {
            Registry reg = LocateRegistry.createRegistry(7777);
            reg.rebind("myserver", new ServerRMI());
            System.out.println("I am up as a server...");
        }catch(RemoteException e)
        {
            System.out.println("Exception e"+e);
        }
    }    
}
