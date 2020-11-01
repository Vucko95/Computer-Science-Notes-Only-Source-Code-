package service.core;

import service.registry.Service;

/**
 * Interface to define the behaviour of a quotation service.
 */

public interface QuotationService extends Service {
	public Quotation generateQuotation(ClientInfo info);
}
