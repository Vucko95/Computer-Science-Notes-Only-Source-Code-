package bank;

import java.rmi.AlreadyBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class Server {

	public static void main(String[] args) throws RemoteException, AlreadyBoundException {
		// 1. Create an RMI Registry
		Registry registry = LocateRegistry.createRegistry(1099);
		// 2. Create an object and expose it
		BankAccount currentAccount = new CurrentAccount();
		BankAccount exposedObject = (BankAccount) UnicastRemoteObject.exportObject(currentAccount, 0);
		
		registry.bind("71728623", exposedObject);
		
		System.out.println("Bank Account exposed...");
	}

}
