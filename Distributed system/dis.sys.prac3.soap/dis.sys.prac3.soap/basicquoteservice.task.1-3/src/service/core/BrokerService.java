package service.core;
import javax.jws.WebMethod;
import javax.jws.WebService;
import service.registry.Service;

@WebService
public interface BrokerService extends Service {
	@WebMethod public Quotation[] getQuotations(ClientInfo info);

}
