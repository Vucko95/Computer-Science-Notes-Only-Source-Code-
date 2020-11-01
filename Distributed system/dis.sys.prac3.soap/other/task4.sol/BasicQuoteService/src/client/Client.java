package client;

import java.net.MalformedURLException;
import java.net.URL;
import java.text.NumberFormat;
import javax.xml.namespace.QName;
import javax.xml.ws.Endpoint;
import javax.xml.ws.Service;
import org.apache.juddi.v3.client.UDDIConstants;
import org.apache.juddi.v3.client.config.UDDIClerk;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.apache.juddi.v3.client.transport.Transport;
import org.uddi.api_v3.AuthToken;
import org.uddi.api_v3.BindingTemplate;
import org.uddi.api_v3.BusinessInfo;
import org.uddi.api_v3.BusinessList;
import org.uddi.api_v3.BusinessService;
import org.uddi.api_v3.FindBusiness;
import org.uddi.api_v3.FindQualifiers;
import org.uddi.api_v3.GetAuthToken;
import org.uddi.api_v3.GetServiceDetail;
import org.uddi.api_v3.Name;
import org.uddi.api_v3.ServiceDetail;
import org.uddi.v3_service.UDDIInquiryPortType;
import org.uddi.v3_service.UDDISecurityPortType;
import service.auldfellas.AFQService;
import service.broker.LocalBrokerService;
import service.core.BrokerService;
import service.core.ClientInfo;
import service.core.Quotation;
import service.core.QuotationService;
import service.dodgydrivers.DDQService;
import service.girlpower.GPQService;
import util.WebServicesClientHelper;
import util.WebServicesHelper;

public class Client {
	public static final String BROKER_SERVICE = "bs-BrokerService";
	public static final String GIRL_POWER_SERVICE = "qs-GirlPowerService";
	public static final String AULD_FELLAS_SERVICE = "qs-AuldFellasService";
	public static final String DODGY_DRIVERS_SERVICE = "qs-DodgyDriversService";

	public static void main(String[] args) {
		UDDISecurityPortType security = null;
		UDDIInquiryPortType inquiry = null;
		
		try {
			
			UDDIClient client = new UDDIClient("META-INF/simple-browse-uddi.xml");
			Transport transport = client.getTransport("default");
			security = transport.getUDDISecurityService();
			inquiry = transport.getUDDIInquiryService();

			String token = WebServicesClientHelper.getAuthKey(security, "uddi", "uddi");
			BusinessList findBusiness = WebServicesClientHelper.partialBusinessNameSearch(inquiry, token, "brokerBusiness" + UDDIConstants.WILDCARD);
			BusinessInfo Binfo = findBusiness.getBusinessInfos().getBusinessInfo().get(0);
			ServiceDetail serviceDetail = WebServicesClientHelper.getServiceDetail(inquiry, token, Binfo);
			System.out.println("serviceDetail.getBusinessService().size() is " + serviceDetail.getBusinessService().size());

			BindingTemplate bindingTemplate = serviceDetail.getBusinessService().get(0).getBindingTemplates().getBindingTemplate().get(0);
			System.out.println("Access: " + bindingTemplate.getBindingKey());
			URL wsdlUrl = new URL(bindingTemplate.getAccessPoint().getValue());
			System.out.println("wsdlURL is" + wsdlUrl);

			Service service = Service.create(wsdlUrl, new QName("http://core.service/", "BrokerService"));
			BrokerService brokerService = service.getPort(new QName("http://core.service/", "BrokerServicePort"), BrokerService.class);
			
			for (ClientInfo info : clients) {
				displayProfile(info);
				for (Quotation quotation : brokerService.getQuotations(info)) {
					displayQuotation(quotation);
				}
				System.out.println("\n");
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void displayProfile(ClientInfo info) {
		System.out.println(
				"|=================================================================================================================|");
		System.out.println(
				"|                                     |                                     |                                     |");
		System.out.println("| Name: " + String.format("%1$-29s", info.name) + " | Gender: "
				+ String.format("%1$-27s", (info.gender == ClientInfo.MALE ? "Male" : "Female")) + " | Age: "
				+ String.format("%1$-30s", info.age) + " |");
		System.out.println("| License Number: " + String.format("%1$-19s", info.licenseNumber) + " | No Claims: "
				+ String.format("%1$-24s", info.noClaims + " years") + " | Penalty Points: "
				+ String.format("%1$-19s", info.points) + " |");
		System.out.println(
				"|                                     |                                     |                                     |");
		System.out.println(
				"|=================================================================================================================|");
	}

	public static void createBroker() {
		Endpoint.publish("http://localhost:9000/BrokerService/getQuotations?wsdl", new LocalBrokerService());
		UDDIClerk clerk = null;
		try {
			UDDIClient uddiClient = new UDDIClient("META-INF/uddi.xml");
			clerk = uddiClient.getClerk("default");
			if (clerk == null) {
				throw new Exception("the clerk wasn't found, check the config file!");
			}
			String BusinessKey = WebServicesHelper.createBusiness("brokerBusiness", clerk);
			BusinessService myService = WebServicesHelper.createWSDLService("brokerService", BusinessKey,
					"http://localhost:9000/BrokerService/getQuotations?wsdl");
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

	public static void displayQuotation(Quotation quotation) {
		System.out.println("| Company: " + String.format("%1$-26s", quotation.company) + " | Reference: "
				+ String.format("%1$-24s", quotation.reference) + " | Price: "
				+ String.format("%1$-28s", NumberFormat.getCurrencyInstance().format(quotation.price)) + " |");
		System.out.println(
				"|=================================================================================================================|");
	}

	public static final ClientInfo[] clients = { new ClientInfo("Niki Collier", ClientInfo.FEMALE, 43, 0, 5, "PQR254/1"),
			new ClientInfo("Old Geeza", ClientInfo.MALE, 65, 0, 2, "ABC123/4"),
			new ClientInfo("Hannah Montana", ClientInfo.FEMALE, 16, 10, 0, "HMA304/9"),
			new ClientInfo("Rem Collier", ClientInfo.MALE, 44, 5, 3, "COL123/3"),
			new ClientInfo("Jim Quinn", ClientInfo.MALE, 55, 4, 7, "QUN987/4"),
			new ClientInfo("Donald Duck", ClientInfo.MALE, 35, 5, 2, "XYZ567/9") };
}
