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

public class Delete {
	static UDDIClient uddiClient;
	public void deleteBusiness(UDDIClerk clerk) {
		clerk.unRegisterBusiness("uddi:juddi.apache.org:8e726b6e-f534-4844-8dd0-0946c5f06d05");
	}	
	public void deleteWSDL(UDDIClerk clerk) {
		clerk.unRegisterWsdls();
	}
	public static void main (String args[]) {
		Delete sp = new Delete();
		try {
			uddiClient = new UDDIClient("META-INF/simple-browse-uddi.xml");
			UDDIClerk clerk = uddiClient.getClerk("default");
			sp.deleteBusiness(clerk);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
