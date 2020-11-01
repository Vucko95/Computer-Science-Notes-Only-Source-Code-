package util;

import org.apache.juddi.api_v3.AccessPointType;
import org.apache.juddi.v3.client.config.UDDIClerk;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.uddi.api_v3.AccessPoint;
import org.uddi.api_v3.BindingTemplate;
import org.uddi.api_v3.BindingTemplates;
import org.uddi.api_v3.BusinessEntity;
import org.uddi.api_v3.BusinessService;
import org.uddi.api_v3.Name;

public class WebServicesHelper {
	public static BusinessService createWSDLService(String serviceName, String myBusKey, String endpointUrl) {
		// Create a new business service
		BusinessService myService = new BusinessService();
		myService.setBusinessKey(myBusKey);
		Name myServName = new Name();
		myServName.setValue(serviceName);
		myService.getName().add(myServName);

		BindingTemplates myBindingTemplates = new BindingTemplates();
		
		// Create a WSDL/SOAP binding Template
		BindingTemplate myBindingTemplate = new BindingTemplate();
		AccessPoint accessPoint = new AccessPoint();
		accessPoint.setUseType(AccessPointType.WSDL_DEPLOYMENT.toString());
		accessPoint.setValue(endpointUrl);
		myBindingTemplate.setAccessPoint(accessPoint);
		// Add the tModel for Soap/Http...
		myBindingTemplate = UDDIClient.addSOAPtModels(myBindingTemplate);
		myBindingTemplates.getBindingTemplate().add(myBindingTemplate);
		
		// Add it to the set of binding templates for the service
		myService.setBindingTemplates(myBindingTemplates);
		
		return myService;
	}

	public static String createBusiness(String businessName, UDDIClerk clerk) {
		// Step 1: Creating the parent business entity that will contain our
		// service.
		BusinessEntity myBusEntity = new BusinessEntity();
		Name myBusName = new Name();
		myBusName.setValue(businessName);
		myBusEntity.getName().add(myBusName);
		
		// Adding the business entity to the "save" structure, using our
		// publisher's authentication info and saving away.
		BusinessEntity register = clerk.register(myBusEntity);
		if (register == null) {
			System.out.println("Save failed!");
			System.exit(1);
		}
		return register.getBusinessKey();
	}
}
