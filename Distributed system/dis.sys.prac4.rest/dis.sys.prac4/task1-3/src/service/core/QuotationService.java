package service.core;
import service.registry.Service;

public interface QuotationService extends Service {
	public Quotation generateQuotation(ClientInfo info); // accept quotation object
}
