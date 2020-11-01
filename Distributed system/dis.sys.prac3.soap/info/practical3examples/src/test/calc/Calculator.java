package test.calc;

public interface Calculator extends java.rmi.Remote {
	public long add(long a, long b) throws java.rmi.RemoteException;
	public long subtract(long a, long b) throws java.rmi.RemoteException;
	public long multiply(long a, long b) throws java.rmi.RemoteException;
	public long divide(long a, long b) throws java.rmi.RemoteException;
	public long modulo(long a, long b) throws java.rmi.RemoteException;

}
