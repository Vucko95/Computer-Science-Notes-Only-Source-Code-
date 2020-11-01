/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rmiproject;

import java.rmi.Remote;
import java.rmi.RemoteException;
import rmiproject.serverside.datamapper.ClientInfo;
import rmiproject.serverside.datamapper.Quotation;

public interface RMIProject extends Remote {

    public String getData(String text) throws RemoteException;
    
}
