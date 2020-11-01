package service.core;

import java.rmi.*;
import service.registry.Service;

/** Interface to define the behaviour of a quotation service. @author Rem */

// other part of the bridge which uses remote
public interface QuotationService extends Service, Remote { // at this stage service does not serve as anything

	public Quotation generateQuotation(ClientInfo info) throws RemoteException;
}
