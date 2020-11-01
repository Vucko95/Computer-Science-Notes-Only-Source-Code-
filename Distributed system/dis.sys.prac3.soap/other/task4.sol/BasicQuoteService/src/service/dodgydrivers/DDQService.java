package service.dodgydrivers;

import org.apache.*;
import org.apache.juddi.api_v3.AccessPointType;
import org.apache.juddi.v3.client.config.UDDIClerk;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.*;
import util.*;
import org.uddi.api_v3.AccessPoint;
import org.uddi.api_v3.BindingTemplate;
import org.uddi.api_v3.BindingTemplates;
import org.uddi.api_v3.BusinessEntity;
import org.uddi.api_v3.BusinessService;
import org.uddi.api_v3.Name;
import service.broker.LocalBrokerService;
import service.core.AbstractQuotationService;
import service.core.ClientInfo;
import service.core.Quotation;
import service.core.QuotationService;
import javax.jws.WebService;
import javax.jws.soap.SOAPBinding;
import javax.jws.soap.SOAPBinding.Style;
import javax.jws.soap.SOAPBinding.Use;
import javax.xml.ws.Endpoint;

@WebService(serviceName = "QuotationService", targetNamespace = "http://core.service/", portName = "QuotationServicePort")
@SOAPBinding(style = Style.DOCUMENT, use = Use.LITERAL)
public class DDQService extends AbstractQuotationService implements QuotationService {
	public static void main(String[] args) {
		createDDQOnJUDDI();
	}

	public static void createDDQOnJUDDI() {
		UDDIClerk clerk = null;
		try {
			UDDIClient uddiClient = new UDDIClient("META-INF/uddi.xml");
			clerk = uddiClient.getClerk("default");
			if (clerk == null) {
				throw new Exception("the clerk wasn't found, check the config file!");
			}
			String BusinessKey = WebServicesHelper.createBusiness("DDQBusiness", clerk);
			BusinessService myService = WebServicesHelper.createWSDLService("QuotationService", BusinessKey, "http://localhost:9000/QuotationService/DDQService?wsdl");
			System.out.println("Business Key is" + "\n" + BusinessKey);
			BusinessService svc = clerk.register(myService);
			if (svc == null) {
				System.out.println("Save failed!");
				System.exit(1);
			}
			String myServKey = svc.getServiceKey();
			clerk.discardAuthToken();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static final String PREFIX = "DD";
	public static final String COMPANY = "Dodgy Drivers Corp.";

	@Override
	public Quotation generateQuotation(ClientInfo info) {
		double price = generatePrice(800, 200);
		int discount = (info.points > 3) ? 5 * info.points : -50;
		discount += getNoClaimsDiscount(info);
		return new Quotation(COMPANY, generateReference(PREFIX), (price * (100 - discount)) / 100);
	}

	private int getNoClaimsDiscount(ClientInfo info) {
		return 10 * info.noClaims;
	}
}
