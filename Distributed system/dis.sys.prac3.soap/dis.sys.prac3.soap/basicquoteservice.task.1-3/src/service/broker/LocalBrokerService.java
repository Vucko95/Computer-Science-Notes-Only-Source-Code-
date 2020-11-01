package service.broker;
import java.net.URL;
import java.util.LinkedList;
import java.util.List;
import service.core.BrokerService;
import service.core.ClientInfo;
import service.core.Quotation;
import service.core.QuotationService;
// import service.registry.ServiceRegistry;
import javax.jws.soap.SOAPBinding;
import javax.jws.soap.SOAPBinding.Style;
import javax.jws.soap.SOAPBinding.Use;
import javax.xml.namespace.QName;
import javax.xml.ws.Endpoint;
import javax.xml.ws.Service;

import client.Server;

import javax.jws.WebService;

/* 
to make sure we comminicate the right services we need to declair the @Webservice 
alonf with the servicename, targetnamespace and port name 
this data will show up on the xml.
* we also need to bind the SOAP Services 
*/

@WebService(serviceName="BrokerService", targetNamespace="http://core.service/", portName="BrokerServicePort")
@SOAPBinding(style = Style.DOCUMENT, use=Use.LITERAL)

public class LocalBrokerService implements BrokerService {

	public Quotation[] getQuotations(ClientInfo info) {
		List<Quotation> quotations = new LinkedList<Quotation>();
		/* passing in the urls to loop through the names */
		for (String name : Server.SERVICE_URLS) {
			try {

				/* 
				here we are creating a wsdurl object  
				we then give the quotationservice to the proper url 
				and create the service using the info from wsdURL, qname 
				*/

				URL wsdURL = new URL(name);
				QName qname = new QName("http://core.service/", "QuotationService"); 
				Service service = Service.create(wsdURL, qname);
				
				/* get the port information */
				QuotationService qs = service.getPort(new QName("http://core.service/", "QuotationServicePort"), QuotationService.class);
				/* add the quotation calc to quotation via the port */
				quotations.add(qs.generateQuotation(info)); 
	
		} catch (Exception e) {
			e.printStackTrace(); 
		}
		} 
		return quotations.toArray(new Quotation[quotations.size()]); 
	}
}

