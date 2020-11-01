package helloworld;

import java.net.URL;

import javax.xml.namespace.QName;
import javax.xml.ws.Service;

import org.apache.juddi.v3.client.UDDIConstants;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.apache.juddi.v3.client.transport.Transport;
import org.uddi.api_v3.BindingTemplate;
import org.uddi.api_v3.BusinessInfo;
import org.uddi.api_v3.BusinessList;
import org.uddi.api_v3.ServiceDetail;
import org.uddi.v3_service.UDDIInquiryPortType;
import org.uddi.v3_service.UDDISecurityPortType;

import util.WebServicesClientHelper;

public class HelloClient {
	public static void main(String[] args) {
		UDDISecurityPortType security = null;
		UDDIInquiryPortType inquiry = null;

		try {
			UDDIClient client = new UDDIClient("META-INF/simple-browse-uddi.xml");
			Transport transport = client.getTransport("default");
			security = transport.getUDDISecurityService();
			inquiry = transport.getUDDIInquiryService();
		} catch (Exception e) {
			e.printStackTrace();
		}

		// Authenticate UDDI User
		String token = WebServicesClientHelper.getAuthKey(security, "uddi", "uddi");

		try {
			BusinessList findBusiness = WebServicesClientHelper.partialBusinessNameSearch(inquiry, token, "Rem" + UDDIConstants.WILDCARD);

			// Get the 1 business we expect to find (or loop through many
			// matching businesses)
			BusinessInfo info = findBusiness.getBusinessInfos().getBusinessInfo().get(0);
			ServiceDetail serviceDetail = WebServicesClientHelper.getServiceDetail(inquiry, token, info);

			// For each service, look for a binding template and contact the
			// service...
			System.out.println("Found: " + info.getName());
			for (int k = 0; k < serviceDetail.getBusinessService().size(); k++) {
				BindingTemplate bindingTemplate = serviceDetail.getBusinessService().get(k).getBindingTemplates()
						.getBindingTemplate().get(0);

				System.out.println("Access: " + bindingTemplate.getBindingKey());
				URL wsdlUrl = new URL(bindingTemplate.getAccessPoint().getValue());
				QName qname = new QName("http://helloworld/", "HelloWorld");
				Service service = Service.create(wsdlUrl, qname);
				HelloWorld helloWorld = service.getPort(HelloWorld.class);
				System.out.println(helloWorld.sayHi("It's Meee!!!"));
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
