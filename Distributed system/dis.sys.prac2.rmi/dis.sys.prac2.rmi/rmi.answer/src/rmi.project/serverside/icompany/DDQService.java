
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
public class DDQService extends RMIAbstractQuotationService implements RMIQuotationServices { 
	public static final String PREFIX = "DD";
	public static final String COMPANY = "Dodgy Drivers Corp.";
        
        public DDQService()
        {
            ServiceRegistry.bind("qs-ddq", (Service) this);
        }

	/**
	 * Quote generation:
	 * 5% discount per penalty point (3 points required for qualification)
	 * 50% penalty for <= 3 penalty points
	 * 10% discount per year no claims
	 */
	
	@Override
	public Quotation generateQuotation(ClientInfo info) {     // Create an initial quotation between 800 and 1000
		double price = generatePrice(800, 200);               // 5% discount per penalty point (3 points required for qualification)
		int discount = (info.points > 3) ? 5*info.points:-50; // Add a no claims discount
		discount += getNoClaimsDiscount(info);                // Generate the quotation and send it back
		return new Quotation(COMPANY, generateReference(PREFIX), (price * (100-discount)) / 100);
	}
	private int getNoClaimsDiscount(ClientInfo info) {
		return 10*info.noClaims;
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
