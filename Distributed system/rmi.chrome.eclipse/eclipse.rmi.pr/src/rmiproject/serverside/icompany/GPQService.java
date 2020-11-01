
package rmiproject.serverside.icompany;

import java.rmi.RemoteException;
import java.util.List;
import rmiproject.RMIAbstractQuotationService;
import rmiproject.RMIBrokerServices;
import rmiproject.RMIQuotationServices;
import rmiproject.registry.Service;
import rmiproject.registry.ServiceRegistry;
import rmiproject.serverside.datamapper.ClientInfo;
import rmiproject.serverside.datamapper.Quotation;

// All references are to be prefixed with an DD (e.g. DD001000)
public class GPQService extends RMIAbstractQuotationService implements RMIQuotationServices { 
	public static final String PREFIX = "GP";
	public static final String COMPANY = "Girl Power Inc.";
        
        public GPQService()
        {
            ServiceRegistry.bind("qs-gps", (Service) this);
        }

	/**
	 * Quote generation:
	 * 50% discount for being female
	 * 20% discount for no penalty points
	 * 15% discount for < 3 penalty points
	 * no discount for 3-5 penalty points
	 * 100% penalty for > 5 penalty points
	 * 5% discount per year no claims
	 */

	@Override
	public Quotation generateQuotation(ClientInfo info) {        // Create an initial quotation between 600 and 1000
		double price = generatePrice(600, 400);                  // Automatic 50% discount for being female
		int discount = (info.gender == ClientInfo.FEMALE) ? 50:0;// Add a points discount
		discount += getPointsDiscount(info);                     // Add a no claims discount
		discount += getNoClaimsDiscount(info);                   // Generate the quotation and send it back
		return new Quotation(COMPANY, generateReference(PREFIX), (price * (100-discount)) / 100);
	}

	private int getNoClaimsDiscount(ClientInfo info) {
		return 5*info.noClaims;
	}
	
	private int getPointsDiscount(ClientInfo info) {
		if (info.points == 0) return 20;
		if (info.points < 3) return 15;
		if (info.points < 6) return 0;
		return -100;
	}


	 //To change body of generated methods, choose Tools | Templates.
	@Override
    public RMIBrokerServices getClient() throws RemoteException {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    @Override
    public RMIBrokerServices getQuotation() throws RemoteException {
        throw new UnsupportedOperationException("Not supported yet."); 
    }
    @Override
    public void displayQuotation(Quotation quotation) throws RemoteException {
        throw new UnsupportedOperationException("Not supported yet."); 
    }
    @Override
    public String getOnline(String question) throws RemoteException {
        throw new UnsupportedOperationException("Not supported yet."); 
    }
    @Override
    public List<Quotation> getQuotations(ClientInfo info) throws RemoteException {
        throw new UnsupportedOperationException("Not supported yet."); 
    }
}
