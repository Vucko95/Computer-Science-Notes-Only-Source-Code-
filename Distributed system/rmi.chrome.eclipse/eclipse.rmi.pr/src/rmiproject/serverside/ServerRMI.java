
package rmiproject.serverside;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import rmiproject.RMIProject;
import rmiproject.serverside.datamapper.ClientInfo;
import rmiproject.serverside.datamapper.Quotation;

public class ServerRMI extends UnicastRemoteObject implements RMIProject {

  public ServerRMI() throws RemoteException { 
      super(); 
    }

  @Override
  public String getData(String text) throws RemoteException {
    return "welcome " + text;
  }

  public static void main(String args[]) throws RemoteException {
    try {
      Registry reg = LocateRegistry.createRegistry(7777); // port 7777
      reg.rebind("myserver", new ServerRMI());
      System.out.println("I am up as a server...");
    } catch (RemoteException e) {
      System.out.println("Exception e" + e);
    }
  }
}
