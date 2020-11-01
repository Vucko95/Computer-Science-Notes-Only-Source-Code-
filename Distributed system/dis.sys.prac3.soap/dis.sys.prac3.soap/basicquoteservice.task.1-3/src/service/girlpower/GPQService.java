package service.girlpower;
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

public class GPQService extends AbstractQuotationService implements QuotationService {
  public static final String PREFIX = "GP";
  public static final String COMPANY = "Girl Power Inc.";

  @Override
  public Quotation generateQuotation(ClientInfo info) {
    double price = generatePrice(600, 400);
    int discount = (info.gender == ClientInfo.FEMALE) ? 50 : 0;
    discount += getPointsDiscount(info);
    discount += getNoClaimsDiscount(info);
    return new Quotation(COMPANY, generateReference(PREFIX), (price * (100 - discount)) / 100);
  }

  private int getNoClaimsDiscount(ClientInfo info) { return 5 * info.noClaims; }

  private int getPointsDiscount(ClientInfo info) {
    if (info.points == 0) return 20;
    if (info.points < 3) return 15;
    if (info.points < 6) return 0;
    return -100;
  }
}
