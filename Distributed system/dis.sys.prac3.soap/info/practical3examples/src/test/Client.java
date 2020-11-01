package test;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
	public static void main(String[] args) throws RemoteException, NotBoundException {
		// 1. get reference to existing RMI registry
		Registry registry = LocateRegistry.getRegistry("localhost", 1099);
		
		// 2. create a proxy to interact with the remote object
		BankAccount account = (BankAccount) registry.lookup("71728672");
		
		// 3. interact with it...
		account.deposit(100);
		System.out.println("Balance: " + account.balance());
	}
}
