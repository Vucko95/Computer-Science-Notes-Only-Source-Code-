package test;

/*
 * Copyright 2001-2010 The Apache Software Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
import org.apache.juddi.api_v3.AccessPointType;
import org.apache.juddi.v3.client.config.UDDIClerk;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.uddi.api_v3.AccessPoint;
import org.uddi.api_v3.BindingTemplate;
import org.uddi.api_v3.BindingTemplates;
import org.uddi.api_v3.BusinessEntity;
import org.uddi.api_v3.BusinessService;
import org.uddi.api_v3.Name;

import helloworld.HelloWorldImpl;
import util.WebServicesHelper;

/**
 * This shows you to interact with a UDDI server by publishing a Business,
 * Service and Binding Template. It uses code that is specific to the jUDDI
 * client jar's and represents an easier, simpler way to do things. (UDDIClient
 * and UDDIClerk classes). Credentials and URLs are all set via uddi.xml
 */
public class SimplePublishClerk {
	private static final String RBSWSE_BUSINESS_KEY = "uddi:juddi.apache.org:ebcf8557-a924-4ded-93bb-f4bc7517ab67";
	
	private static UDDIClerk clerk = null;

	public SimplePublishClerk() {
		try {
			UDDIClient uddiClient = new UDDIClient("META-INF/uddi.xml");
			clerk = uddiClient.getClerk("default");
			if (clerk == null)
				throw new Exception("the clerk wasn't found, check the config file!");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * This function shows you how to publish to UDDI using a fairly generic
	 * mechanism that should be portable (meaning use any UDDI v3 library with
	 * this code)
	 */
	public void publish() {
		try {
			String myBusKey = WebServicesHelper.createBusiness("Rem's Bright and Shiny WS Emporium", clerk);

			BusinessService myService = WebServicesHelper.createWSDLService("HelloWorld Service", myBusKey, HelloWorldImpl.ENDPOINT_URL);
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


	public static void main(String args[]) {
		SimplePublishClerk sp = new SimplePublishClerk();
		sp.publish();
	}
}
