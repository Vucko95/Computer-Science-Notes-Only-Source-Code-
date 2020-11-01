package service.auldfellas;

import service.core.AbstractQuotationService;
import service.core.ClientInfo;
import service.core.Quotation;
import service.core.QuotationService;

import javax.jws.WebService;
import javax.jws.soap.SOAPBinding;
import javax.jws.soap.SOAPBinding.Style;
import javax.jws.soap.SOAPBinding.Use;

/* 
to make sure we comminicate the right services we need to declair the @Webservice 
alonf with the servicename, targetnamespace and port name 
this data will show up on the xml.
* we also need to bind the SOAP Services 
*/

@WebService(serviceName="QuotationService", targetNamespace="http://core.service/", portName="QuotationServicePort")

@SOAPBinding(style = Style.DOCUMENT, use=Use.LITERAL)
public class AFQService extends AbstractQuotationService implements QuotationService {
	public static final String PREFIX = "AF";
	public static final String COMPANY = "Auld Fellas Ltd.";

	@Override
	public Quotation generateQuotation(ClientInfo info) {
		double price = generatePrice(600, 600);
		int discount = (info.gender == ClientInfo.MALE) ? 30 : 0;
		discount += (info.age > 60) ? (2 * (info.age - 60)) : 0;
		discount += getPointsDiscount(info);
		return new Quotation(COMPANY, generateReference(PREFIX), (price * (100 - discount)) / 100);
	}

	private int getPointsDiscount(ClientInfo info) {
		if (info.points < 3)
			return 20;

		if (info.points <= 6)
			return 0;
		return -50;
	}
}
