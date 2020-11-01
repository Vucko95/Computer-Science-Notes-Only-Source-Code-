package service.broker;

import java.rmi.*;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.*;
import java.util.LinkedList;
import java.util.List;
import service.core.BrokerService;
import service.core.ClientInfo;
import service.core.Quotation;
import service.core.QuotationService;
import service.registry.ServiceRegistry;

/** Implementation of the broker service that uses the Service Registry. @author Rem */

// sends off to all companies and every company does the math for each
// Making this class as a Remote Object for Server RMI

/* The Broker Service can handle all the requests Accepted by the QuotationService */
public class LocalBrokerService implements BrokerService { // implimented one of the bridges
	// this will get all of the quotes
	public List<Quotation> getQuotations(ClientInfo info) throws RemoteException {
		List<Quotation> quotations = new LinkedList<Quotation>();

		try {
			for (String name : ServiceRegistry.list()) {
				if (name.startsWith("qs-")) {
					QuotationService service = ServiceRegistry.lookup(name, QuotationService.class); // girl power and dog and all
					quotations.add(service.generateQuotation(info)); // adds to the service // calling generate quotation for every single one of them
				}
			}
		} catch (RemoteException e) { e.printStackTrace(); }

		return quotations;
	}
}

// extends UnicastRemoteObject