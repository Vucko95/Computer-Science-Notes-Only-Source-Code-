import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class CalculatorServer {
	public static void main(String args[]) {
		try {
			Registry registry = LocateRegistry.createRegistry(1099);
			Calculator c = (Calculator) UnicastRemoteObject.exportObject(new CalculatorImpl(), 0);
			registry.bind("CalculatorService", c);
			System.out.println("RMI Server running on port: 1099");
		} catch (Exception e) {
			System.out.println("Trouble: " + e);
		}
	}
}
