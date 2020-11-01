package service.core;
import javax.jws.WebMethod;
import javax.jws.WebService;

@WebService 
public interface BrokerService {
	@WebMethod public Quotation[] getQuotations(ClientInfo info);	
}
