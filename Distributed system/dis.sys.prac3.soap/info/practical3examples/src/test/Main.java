package test;

import java.rmi.RemoteException;

public class Main {

	public static void main(String[] args) throws RemoteException {
		BankAccount account = new CurrentAccount();
		account.deposit(100);
		System.out.println("Balance: " + account.balance());
	}

}
