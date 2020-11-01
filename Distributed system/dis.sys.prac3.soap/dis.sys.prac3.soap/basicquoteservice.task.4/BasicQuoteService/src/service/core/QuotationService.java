package service.core;

import javax.jws.WebMethod;
import javax.jws.WebService;

@WebService
public interface QuotationService {
	@WebMethod
	public Quotation generateQuotation(ClientInfo info);

}
