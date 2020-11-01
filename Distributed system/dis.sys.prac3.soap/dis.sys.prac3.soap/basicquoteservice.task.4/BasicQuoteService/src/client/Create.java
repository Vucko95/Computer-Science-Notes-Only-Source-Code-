package client;

import javax.xml.ws.Endpoint;

import org.apache.juddi.v3.client.config.UDDIClerk;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.uddi.api_v3.BusinessService;

import service.broker.LocalBrokerService;
import util.WebServicesHelper;

public class Create {
	public static void main(String[] args) {
	BrokerCreate();
	GPQCreate();
	AFQCreate();
	DDQXCreate();
	}

	public static void BrokerCreate() {
		Endpoint.publish("http://localhost:8080/BrokerService/getQuotations?wsdl", new LocalBrokerService());
		UDDIClerk clerk = null;
		try {
			UDDIClient uddiClient = new UDDIClient("META-INF/uddi.xml");
			clerk = uddiClient.getClerk("default");
			if (clerk == null) {
				throw new Exception("clerknotfound");
			}
			String BusinessKey = WebServicesHelper.createBusiness("brokerBusiness", clerk);
			BusinessService myService = WebServicesHelper.createWSDLService("brokerService", BusinessKey,
					"http://localhost:8080/BrokerService/getQuotations?wsdl");
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

			public static void GPQCreate() {
				UDDIClerk clerk = null;
				try {
					UDDIClient uddiClient = new UDDIClient("META-INF/uddi.xml");
					clerk = uddiClient.getClerk("default");
					if (clerk == null) {
						throw new Exception("clerknotfound");
					}
					String BusinessKey = WebServicesHelper.createBusiness("GPQBusiness", clerk);
					BusinessService myService = WebServicesHelper.createWSDLService("QuotationService", BusinessKey,
							"http://localhost:80808/QuotationService/GPQService?wsdl");
					System.out.println("Business Key is" + "\n" + BusinessKey);
					BusinessService svc = clerk.register(myService);
					if (svc == null) {
		
						System.exit(1);
					}
					String myServKey = svc.getServiceKey();
					clerk.discardAuthToken();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		
			public static void AFQCreate() {
		
				UDDIClerk clerk = null;
		
				try {
					UDDIClient uddiClient = new UDDIClient("META-INF/uddi.xml");
					clerk = uddiClient.getClerk("default");
					if (clerk == null) {
						throw new Exception("clerknotfound");
					}
					String BusinessKey = WebServicesHelper.createBusiness("AFQBusiness", clerk);
					BusinessService myService = WebServicesHelper.createWSDLService("QuotationService", BusinessKey,
							"http://localhost:8080/QuotationService/AFQService?wsdl");
		
					BusinessService svc = clerk.register(myService);
					if (svc == null) {
		
						System.exit(1);
					}
					String myServKey = svc.getServiceKey();
					clerk.discardAuthToken();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		
			public static void DDQXCreate() {
				UDDIClerk clerk = null;
				try {
					UDDIClient uddiClient = new UDDIClient("META-INF/uddi.xml");
					clerk = uddiClient.getClerk("default");
					if (clerk == null) {
						throw new Exception("clerknotfound");
					}
					String BusinessKey = WebServicesHelper.createBusiness("DDQBusiness", clerk);
					BusinessService myService = WebServicesHelper.createWSDLService("QuotationService", BusinessKey, "http://localhost:8080/QuotationService/DDQService?wsdl");
		
					BusinessService svc = clerk.register(myService);
					if (svc == null) {
		
						System.exit(1);
					}
					String myServKey = svc.getServiceKey();
					clerk.discardAuthToken();
				} catch (Exception e) {
					e.printStackTrace();
				}
			

}
}
