/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rmiproject;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;
import rmiproject.serverside.datamapper.ClientInfo;
import rmiproject.serverside.datamapper.Quotation;

/**
 * The broker services handle all the information which are related to:
 * - clientinfo (broker data)
 * - quotations related to the client(s)
 * 
 * @author 
 */
public interface RMIBrokerServices extends Remote {
 
    public String getOnline(String question) throws RemoteException;
    
    public String getName() throws RemoteException;
    public void send(String msg) throws RemoteException;
    public void setClient(RMIBrokerServices c) throws RemoteException;
    public RMIBrokerServices getClient() throws RemoteException;
    public ClientInfo[] getClientList() throws RemoteException;
    
}
