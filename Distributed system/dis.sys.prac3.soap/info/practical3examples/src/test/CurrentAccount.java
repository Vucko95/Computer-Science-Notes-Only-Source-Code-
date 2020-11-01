package test;

import java.rmi.RemoteException;

public class CurrentAccount implements BankAccount {
	private double balance;
	
	public CurrentAccount() {
		balance = 0;
	}
	
	@Override
	public void deposit(double amount) throws RemoteException {
		balance += amount;
	}

	@Override
	public boolean withdraw(double amount) throws RemoteException {
		if (balance > amount) {
			balance -= amount;
			return true;
		}
		return false;
	}

	@Override
	public double balance() throws RemoteException {
		return balance;
	}

}
