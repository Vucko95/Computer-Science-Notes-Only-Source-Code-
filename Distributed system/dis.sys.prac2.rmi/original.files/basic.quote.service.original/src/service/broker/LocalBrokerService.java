package service.broker;

import java.util.LinkedList;
import java.util.List;

import service.core.BrokerService;
import service.core.ClientInfo;
import service.core.Quotation;
import service.core.QuotationService;
import service.registry.ServiceRegistry;

/**
 * Implementation of the broker service that uses the Service Registry.
 * 
 * @author Rem
 *
 */
public class LocalBrokerService implements BrokerService {
	public List<Quotation> getQuotations(ClientInfo info) {
		List<Quotation> quotations = new LinkedList<Quotation>();
		
		for (String name : ServiceRegistry.list()) {
			if (name.startsWith("qs-")) {
				QuotationService service = ServiceRegistry.lookup(name, QuotationService.class);
				quotations.add(service.generateQuotation(info));
			}
		}

		return quotations;
	}
}
