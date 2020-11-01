package bank;

import java.rmi.registry.LocateRegistry;

// any client can connect to this bank account with this port and all 
class Server {
	public static void main(String[] args) {
		Registry registry = LocateRegistry,createRegistry(1099); 
		BankAccount currentAccount = new CurrentAccount(); 
		BankAccount exposedObject = (BankAccount) UnicastRemoteObject.exportObject(currentAccount, 0); // 0 = port number // proxy object you ccan 		// exposedObject.
		registry.bind("823928379", exposedObject); 
		System.out.println("bank accound exposed");
	}
}


