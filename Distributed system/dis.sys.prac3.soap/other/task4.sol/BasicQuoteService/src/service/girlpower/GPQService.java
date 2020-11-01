package service.girlpower;

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
import util.WebServicesHelper;

@WebService(serviceName = "QuotationService", targetNamespace = "http://core.service/", portName = "QuotationServicePort")
@SOAPBinding(style = Style.DOCUMENT, use = Use.LITERAL)
public class GPQService extends AbstractQuotationService implements QuotationService {
	public static void main(String[] args) {
		createGPQOnJUDDI();
	}

	public static void createGPQOnJUDDI() {
		UDDIClerk clerk = null;
		try {
			UDDIClient uddiClient = new UDDIClient("META-INF/uddi.xml");
			clerk = uddiClient.getClerk("default");
			if (clerk == null) {
				throw new Exception("the clerk wasn't found, check the config file!");
			}
			String BusinessKey = WebServicesHelper.createBusiness("GPQBusiness", clerk);
			BusinessService myService = WebServicesHelper.createWSDLService("QuotationService", BusinessKey, "http://localhost:9000/QuotationService/GPQService?wsdl");
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

	private int getNoClaimsDiscount(ClientInfo info) {
		return 5 * info.noClaims;
	}

	private int getPointsDiscount(ClientInfo info) {
		if (info.points == 0)
			return 20;
		if (info.points < 3)
			return 15;
		if (info.points < 6)
			return 0;
		return -100;
	}
}
