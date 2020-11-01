import java.rmi.RemoteException;

public interface Calculator extends java.rmi.Remote {
	public long add(long a, long b) throws RemoteException;
	public long sub(long a, long b) throws RemoteException;
	public long mul(long a, long b) throws RemoteException;
	public long div(long a, long b) throws RemoteException;
}
