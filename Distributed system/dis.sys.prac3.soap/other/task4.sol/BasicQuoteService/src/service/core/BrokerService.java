package service.core;
import javax.jws.WebMethod;
import javax.jws.WebService;
import java.util.List;

@WebService 
public interface BrokerService {
	@WebMethod public Quotation[] getQuotations(ClientInfo info);	
}
