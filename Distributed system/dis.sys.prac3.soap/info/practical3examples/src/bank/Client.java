package bank;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {

	public static void main(String[] args) throws RemoteException, NotBoundException {
		Registry registry = LocateRegistry.getRegistry("localhost", 1099);
		BankAccount account = (BankAccount) registry.lookup("71728623");
		
		account.deposit(100);
		System.out.println("Balance="+account.balance());
	}

}
