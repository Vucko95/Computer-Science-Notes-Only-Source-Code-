package rmiproject.serverside;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.text.NumberFormat;
import java.util.LinkedList;
import java.util.List;
import rmiproject.RMIBrokerServices;
import rmiproject.RMIProject;
import rmiproject.RMIQuotationServices;
import rmiproject.registry.ServiceRegistry;
import rmiproject.serverside.datamapper.ClientInfo;
import rmiproject.serverside.datamapper.Quotation;

public class ServerRMIQuotation extends UnicastRemoteObject implements RMIQuotationServices {
    public ServerRMIQuotation() throws RemoteException {
        super();
    }

      public void displayQuotation(Quotation quotation) {
			System.out.println("| Company: " + String.format("%1$-26s", quotation.company) + " | Reference: "
					+ String.format("%1$-24s", quotation.reference) + " | Price: "
					+ String.format("%1$-28s", NumberFormat.getCurrencyInstance().format(quotation.price)) + " |");
			System.out.println("|=================================================================================================================|");
        }


       public List<Quotation> getQuotations(ClientInfo info) throws RemoteException {
		List<Quotation> quotations = new LinkedList<>();
			for (String name : ServiceRegistry.list()) {
                                System.out.println("ServerRMIQuotation] "+name);
				if (name.startsWith("qs-")) {
					RMIQuotationServices service = ServiceRegistry.lookup(name, RMIQuotationServices.class); // girl power and dog and all 
                                        quotations.add(service.generateQuotation(info)); // adds to the service // calling generate quotation for every single one of them 
				}
			}
		return quotations;
    }
    
    public static void main(String args[]) throws RemoteException
    {
        try
        {s
            Registry reg = LocateRegistry.createRegistry(7780);
            reg.rebind("myquotationserver", new ServerRMIQuotation());
            System.out.println("I am up as a quotation server...");
        }catch(RemoteException e)
        {
            System.out.println("Exception e"+e);
        }
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
    public Quotation generateQuotation(ClientInfo info) {
        throw new UnsupportedOperationException("Not supported yet."); 
    }
    @Override
    public String getOnline(String question) throws RemoteException {
       return "yes";
    }
}
