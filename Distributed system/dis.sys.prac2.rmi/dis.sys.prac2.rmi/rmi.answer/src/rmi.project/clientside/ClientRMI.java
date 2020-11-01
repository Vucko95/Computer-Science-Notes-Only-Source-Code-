
package rmiproject.clientside;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import rmiproject.RMIProject;


/* in this file we will need to create a CLIENT RMI, and a way to connect to the
remote, where we need to locate the registry, cast the server, and
grab the list of all of our client information  */

public class ClientRMI {

  public static void main(String args[]) throws RemoteException {
    ClientRMI c = new ClientRMI();
    c.connectRemote();
  }

  private void connectRemote() throws RemoteException {
    try {
      Registry reg = LocateRegistry.getRegistry(7777);
      RMIProject a = (RMIProject)reg.lookup("myserver");
      System.out.println("Hello " + a.getData("Greg"));
    } catch (NotBoundException e) {
      System.out.println("NotBoundException e" + e);
    }
  }
}
