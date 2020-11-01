
package service.core;

import service.registry.Service;
import javax.jws.WebMethod;
import javax.jws.WebService;

/* we need to impliment @Webservices and the 
@Webmethod to comunicate SOAP  */

@WebService
public interface QuotationService extends Service {
  @WebMethod public Quotation generateQuotation(ClientInfo info);
}