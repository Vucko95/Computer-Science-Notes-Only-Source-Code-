package service.dodgydrivers;

import javax.jws.WebService;
import javax.jws.soap.SOAPBinding;
import javax.jws.soap.SOAPBinding.Style;
import javax.jws.soap.SOAPBinding.Use;
import javax.xml.ws.Endpoint;
import service.core.AbstractQuotationService;
import service.core.ClientInfo;
import service.core.Quotation;
import service.core.QuotationService;


/*
to make sure we comminicate the right services we need to declair the @Webservice
alonf with the servicename, targetnamespace and port name
this data will show up on the xml.
* we also need to bind the SOAP Services
*/

@WebService(serviceName = "QuotationService", targetNamespace = "http://core.service/", portName = "QuotationServicePort")
@SOAPBinding(style = Style.DOCUMENT, use = Use.LITERAL)

public class DDQService extends AbstractQuotationService implements QuotationService {

  public static final String PREFIX = "DD";
  public static final String COMPANY = "Dodgy Drivers Corp.";

  @Override
  public Quotation generateQuotation(ClientInfo info) {
    double price = generatePrice(800, 200);
    int discount = (info.points > 3) ? 5 * info.points : -50;
    discount += getNoClaimsDiscount(info);
    return new Quotation(COMPANY, generateReference(PREFIX), (price * (100 - discount)) / 100);
  }

  private int getNoClaimsDiscount(ClientInfo info) { return 10 * info.noClaims; }
}
