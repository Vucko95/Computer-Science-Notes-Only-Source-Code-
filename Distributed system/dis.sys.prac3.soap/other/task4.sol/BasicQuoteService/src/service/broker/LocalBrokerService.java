package service.broker;

//Imports
import java.util.LinkedList;
import java.util.List;
import java.net.MalformedURLException;
import java.net.URL;
import javax.xml.ws.Service;
import util.*;
import org.apache.juddi.v3.client.UDDIConstants;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.apache.juddi.v3.client.transport.Transport;
import org.uddi.api_v3.AuthToken;
import org.uddi.api_v3.BindingTemplate;
import org.uddi.api_v3.BusinessInfo;
import org.uddi.api_v3.BusinessList;
import org.uddi.api_v3.FindBusiness;
import org.uddi.api_v3.FindQualifiers;
import org.uddi.api_v3.GetAuthToken;
import org.uddi.api_v3.GetServiceDetail;
import org.uddi.api_v3.Name;
import org.uddi.api_v3.ServiceDetail;
import org.uddi.api_v3.ServiceList;
import org.uddi.v3_service.UDDIInquiryPortType;
import org.uddi.v3_service.UDDISecurityPortType;
import javax.xml.namespace.QName;
import java.nio.charset.MalformedInputException;
import service.core.BrokerService;
import service.core.ClientInfo;
import service.core.Quotation;
import service.core.QuotationService;
import javax.jws.WebService;
import javax.jws.soap.SOAPBinding;
import javax.jws.soap.SOAPBinding.Style;
import javax.jws.soap.SOAPBinding.Use;
import javax.xml.namespace.QName;
import javax.xml.ws.Endpoint;
import javax.xml.ws.Service;
import client.Client;
import client.Server;

@WebService(serviceName = "BrokerService", targetNamespace = "http://core.service/", portName = "BrokerServicePort")
@SOAPBinding(style = Style.DOCUMENT, use = Use.LITERAL)
public class LocalBrokerService implements BrokerService {
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
