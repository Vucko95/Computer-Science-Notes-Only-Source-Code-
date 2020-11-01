package bank;
import java.rmi.registry.LocateRegistry;
// any client can connect to this bank account with this port and all 
class Server {
	
	public static void main(String[] args) {
		Registry registry = LocateRegistry.createRegistry(1099); 
		BankAccount currentAccount = new CurrentAccount(); 
		// 0 = port number // proxy object you can // exposedObject.
		BankAccount exposedObject = (BankAccount) UnicastRemoteObject.exportObject(currentAccount, 0); 
		registry.bind("823928379", exposedObject); 
		System.out.println("bank accound exposed");
	}
}
