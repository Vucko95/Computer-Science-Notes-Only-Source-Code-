
package rmiproject;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;
import rmiproject.serverside.datamapper.ClientInfo;
import rmiproject.serverside.datamapper.Quotation;

public interface RMIBrokerServices extends Remote {
  public String getOnline(String question) throws RemoteException;
  public String getName() throws RemoteException;
  public void send(String msg) throws RemoteException;
  public void setClient(RMIBrokerServices c) throws RemoteException;
  public RMIBrokerServices getClient() throws RemoteException;
  public ClientInfo[] getClientList() throws RemoteException;
}
