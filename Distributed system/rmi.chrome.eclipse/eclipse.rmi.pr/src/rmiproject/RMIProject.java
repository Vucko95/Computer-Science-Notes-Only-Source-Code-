package rmiproject;

import java.rmi.Remote;
import java.rmi.RemoteException;
import rmiproject.serverside.datamapper.ClientInfo;
import rmiproject.serverside.datamapper.Quotation;

public interface RMIProject extends Remote {
    public String getData(String text) throws RemoteException;  
}
