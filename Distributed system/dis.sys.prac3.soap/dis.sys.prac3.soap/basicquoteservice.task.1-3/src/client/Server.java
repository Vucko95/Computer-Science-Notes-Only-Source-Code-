package client;

import javax.xml.ws.Endpoint;

import service.auldfellas.AFQService;
import service.broker.LocalBrokerService;
import service.dodgydrivers.DDQService;
import service.girlpower.GPQService;

public class Server {
	public static final String BROKER_SERVICE = "bs-BrokerService";
	public static final String GIRL_POWER_SERVICE = "qs-GirlPowerService";
	public static final String AULD_FELLAS_SERVICE = "qs-AuldFellasService";
	public static final String DODGY_DRIVERS_SERVICE = "qs-DodgyDriversService";

	public static final String[] SERVICE_URLS = {
			/* here we have the different urls that we create to make sure we can see the different services */
			// "http://localhost:9000/BrokerService/getQuotations?wsdl", // not this one
			"http://localhost:9000/QuotationService/DDQService?wsdl",
			"http://localhost:9000/QuotationService/AFQService?wsdl",
			"http://localhost:9000/QuotationService/GPQService?wsdl" };

	public static void main(String[] args) {
		/* this will give us the ability to publishs the services to the wsdl */
		Endpoint.publish("http://localhost:9000/BrokerService/getQuotations?wsdl", new LocalBrokerService());
		Endpoint.publish("http://localhost:9000/QuotationService/DDQService?wsdl", new DDQService());
		Endpoint.publish("http://localhost:9000/QuotationService/AFQService?wsdl", new AFQService());
		Endpoint.publish("http://localhost:9000/QuotationService/GPQService?wsdl", new GPQService());

	};
}
