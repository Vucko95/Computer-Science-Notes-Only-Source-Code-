package bank;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface BankAccount extends Remote {
	public void deposit(double amount) throws RemoteException;
	public boolean withdraw(double amount) throws RemoteException;
	public double balance() throws RemoteException;
}
