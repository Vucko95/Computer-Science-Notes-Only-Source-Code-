package helloworld;
import javax.jws.WebService;
import javax.xml.ws.Endpoint;

import org.apache.juddi.v3.client.config.UDDIClerk;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.uddi.api_v3.BusinessService;

import util.WebServicesHelper;

/**
 * This example show you how to use UDDI Annotations to decorate a class.
 * When the Servlet Listener
 */

@WebService(
		endpointInterface = "helloworld.HelloWorld",
        serviceName = "HelloWorld")

public class HelloWorldImpl implements HelloWorld {
	public static final String RBSWSE_BUSINESS_KEY = "uddi:juddi.apache.org:ebcf8557-a924-4ded-93bb-f4bc7517ab67";
	public static final String ENDPOINT_URL = "http://localhost:9000/HelloWorld/HelloWorld";
	
    public static void main(String[] args) {
    	UDDIClerk clerk = null;
		try {
			UDDIClient uddiClient = new UDDIClient("META-INF/uddi.xml");
			clerk = uddiClient.getClerk("default");
			if (clerk == null)
				throw new Exception("the clerk wasn't found, check the config file!");
		} catch (Exception e) {
			e.printStackTrace();
		}
    	
    	Endpoint.publish(ENDPOINT_URL, new HelloWorldImpl());
    	System.out.println("Hello World Endpoint Published on: " + ENDPOINT_URL);
    	
		try {
			
			BusinessService myService = WebServicesHelper.createWSDLService("HelloWorld Service", RBSWSE_BUSINESS_KEY, HelloWorldImpl.ENDPOINT_URL);
			BusinessService svc = clerk.register(myService);
			if (svc == null) {
				System.out.println("Save failed!");
				System.exit(1);
			}

			String myServKey = svc.getServiceKey();
			System.out.println("myService key:  " + myServKey);

			clerk.discardAuthToken();
			System.out.println("Web Service Registered!");
		} catch (Exception e) {
			e.printStackTrace();
		}
    }
        
    public String sayHi(String text) {
        System.out.println("sayHi called");
        return "Hello " + text;
    }
	
}