package test;

import java.rmi.AlreadyBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class Server {

	public static void main(String[] args) throws RemoteException, AlreadyBoundException {
		// 1. Create an RMI Registry
		Registry registry = LocateRegistry.createRegistry(1099);
		
		// 2. Create and Export an Object
		BankAccount currentAccount = new CurrentAccount();
		BankAccount exposedAccount = (BankAccount) UnicastRemoteObject.exportObject(currentAccount, 0);
		
		// 3. Advertise the Object in the RMI registry
		registry.bind("71728672", exposedAccount);
		
		System.out.println("Bank Account created...");
	}

}
