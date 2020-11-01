
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

/* in this file we will need to create a CLIENT BROKER RMI, and a way to connect to the
remote, where we need to locate the registry, cast the server, and
grab the list of all of our client information  */

public class ClientBrokerRMI {
  public static void main(String args[]) throws RemoteException {
    ClientBrokerRMI c = new ClientBrokerRMI();
    c.connectRemote();
  }

  private void connectRemote() throws RemoteException {
    try {
      Registry reg = LocateRegistry.getRegistry(7780);
      RMIBrokerServices bs = (RMIBrokerServices)reg.lookup("mybrokerserver");
      System.out.println("Are you up? " + bs.getOnline("Are you up?"));
      System.out.println("***************************************");
      ClientInfo[] cinfo = bs.getClientList();
      for (int i = 0; i < cinfo.length; ++i) {
        System.out.println("" + cinfo[i].name);
      }
    } catch (NotBoundException e) {
      System.out.println("NotBoundException e" + e);
    }
  }
}
