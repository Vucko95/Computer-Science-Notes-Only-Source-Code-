package ws.calc;
import javax.jws.WebMethod;
import javax.jws.WebService;

@WebService
public interface Calculator extends java.rmi.Remote {
	@WebMethod public long add(long a, long b) throws java.rmi.RemoteException;
	@WebMethod public long subtract(long a, long b) throws java.rmi.RemoteException;
	@WebMethod public long multiply(long a, long b) throws java.rmi.RemoteException;
	@WebMethod public long divide(long a, long b) throws java.rmi.RemoteException;
	@WebMethod public long modulo(long a, long b) throws java.rmi.RemoteException;
}


