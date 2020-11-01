package test.calc;

import java.rmi.AlreadyBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class Server {
	public static void main(String[] args) throws RemoteException, AlreadyBoundException {
		// create an RMI registry on the standard port...
		Registry registry = LocateRegistry.createRegistry(1099);
		Calculator calc = (Calculator) UnicastRemoteObject.exportObject(new CalculatorImpl(), 0);
		registry.bind("mycalc", calc);
	}
}
