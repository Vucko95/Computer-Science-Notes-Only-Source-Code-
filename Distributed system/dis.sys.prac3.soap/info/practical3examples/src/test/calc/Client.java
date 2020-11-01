package test.calc;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
	public static void main(String[] args) throws RemoteException, NotBoundException {
		Registry registry = LocateRegistry.getRegistry("localhost", 1099);
		Calculator calc = (Calculator) registry.lookup("mycalc");
		System.out.println("Test: " + calc.add(2, 4));
	}
}
