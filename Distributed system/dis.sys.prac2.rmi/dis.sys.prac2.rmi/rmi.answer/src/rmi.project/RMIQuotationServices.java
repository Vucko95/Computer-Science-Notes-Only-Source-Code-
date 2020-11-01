
package rmiproject;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;
import rmiproject.registry.Service;
import rmiproject.serverside.datamapper.ClientInfo;
import rmiproject.serverside.datamapper.Quotation;

/*
this is where all of the quotation services are called. you need to make sure
to have service and remote and import their appropriate libraries.
 */

public interface RMIQuotationServices extends Service, Remote {
  public String getOnline(String question) throws RemoteException;
  public RMIBrokerServices getClient() throws RemoteException;
  public RMIBrokerServices getQuotation() throws RemoteException;
  public void displayQuotation(Quotation quotation) throws RemoteException;
  public Quotation generateQuotation(ClientInfo info) throws RemoteException;
  public List<Quotation> getQuotations(ClientInfo info) throws RemoteException;
}
