package test.calc;

import java.rmi.RemoteException;

public class CalculatorImpl implements Calculator {

	@Override
	public long add(long a, long b) throws RemoteException {
		return a+b;
	}

	@Override
	public long subtract(long a, long b) throws RemoteException {
		return a-b;
	}

	@Override
	public long multiply(long a, long b) throws RemoteException {
		return a*b;
	}

	@Override
	public long divide(long a, long b) throws RemoteException {
		return a/b;
	}

	@Override
	public long modulo(long a, long b) throws RemoteException {
		return a % b;
	}

}
