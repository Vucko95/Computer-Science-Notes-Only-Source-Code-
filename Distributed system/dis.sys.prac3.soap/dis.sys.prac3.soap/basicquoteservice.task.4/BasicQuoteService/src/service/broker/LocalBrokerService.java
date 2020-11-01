package service.broker;

//Imports
import java.util.LinkedList;
import java.util.List;

import javax.jws.WebService;
import javax.jws.soap.SOAPBinding;
import javax.jws.soap.SOAPBinding.Style;
import javax.jws.soap.SOAPBinding.Use;

import org.apache.juddi.v3.client.UDDIConstants;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.apache.juddi.v3.client.transport.Transport;
import org.uddi.api_v3.ServiceList;
import org.uddi.v3_service.UDDIInquiryPortType;
import org.uddi.v3_service.UDDISecurityPortType;

import service.core.BrokerService;
import service.core.ClientInfo;
import service.core.Quotation;
import util.WebServicesClientHelper;

@WebService(serviceName = "BrokerService", targetNamespace = "http://core.service/", portName = "BrokerServicePort")
@SOAPBinding(style = Style.DOCUMENT, use = Use.LITERAL)
public class LocalBrokerService implements BrokerService {


		// run all services one by one 
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
		String token = WebServicesClientHelper.getAuthKey(security, "uddi", "uddi");
		try {
			System.out.println(" hello ");
			WebServicesClientHelper.ServiceLookUpByName(inquiry, token, "QuotationService" + UDDIConstants.WILDCARD);
		} catch (Exception e) {
		}
	}

	public Quotation[] getQuotations(ClientInfo info) {
		UDDISecurityPortType security = null;
		UDDIInquiryPortType inquiry = null;
		List<Quotation> quotations = new LinkedList<Quotation>();
		try {
			UDDIClient client = new UDDIClient("META-INF/simple-browse-uddi.xml");
			Transport transport = client.getTransport("default");
			security = transport.getUDDISecurityService();
			inquiry = transport.getUDDIInquiryService();
		} catch (Exception e) {
			e.printStackTrace();
		}
		String token = WebServicesClientHelper.getAuthKey(security, "uddi", "uddi");
		try {
			ServiceList services = WebServicesClientHelper.partialServiceNameSearch(inquiry, token, "QuotationService" + UDDIConstants.WILDCARD);
			System.out.println(services);
		} catch (Exception e) {
			e.printStackTrace();
		}
		return quotations.toArray(new Quotation[quotations.size()]);
	}
}
