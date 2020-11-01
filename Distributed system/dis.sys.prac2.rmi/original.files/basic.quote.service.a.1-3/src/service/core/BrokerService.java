package service.core;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;
import service.registry.Service;

/**
 * Interface for defining the behaviours of the broker service
 * @author Rem
 */

/* this is interface declaration of any method college - > asks you to fill a 
form and submit the form and csomeone tyoes it on the computer to save the data 
form that has set of rules -> answer those things in the rules cannot putaddress 
on the form... declaring soemething as a prototype, you will define what will 
happenn in that method. 
*/ 

public interface BrokerService extends Service, Remote { // we call remote -> it makes a bridge from client to server (the other part are the other intefaces)
	public List<Quotation> getQuotations(ClientInfo info) throws RemoteException; 	// this is a function which accepts //...getQuotations(); profile method 
}
