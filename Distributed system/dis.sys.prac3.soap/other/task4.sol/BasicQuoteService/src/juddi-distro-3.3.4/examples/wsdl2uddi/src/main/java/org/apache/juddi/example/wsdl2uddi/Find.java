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
package org.apache.juddi.example.wsdl2uddi;

import org.apache.juddi.v3.client.config.UDDIClerk;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.uddi.api_v3.BindingTemplate;
import org.uddi.api_v3.BusinessEntity;
import org.uddi.api_v3.BusinessService;

public class Find {
	
	public void find() {
		try {
			UDDIClient uddiClient = new UDDIClient("META-INF/wsdl2uddi-uddi.xml");
			UDDIClerk clerk = uddiClient.getClerk("joe");
        	
			System.out.println("Do a find business using the businessKey uddi:uddi.joepublisher.com:business_wsdl-business");
        	BusinessEntity businessEntity = clerk.findBusiness("uddi:uddi.joepublisher.com:business_wsdl-business");
        	//
        	
        	if (businessEntity!=null) {
	        	System.out.println("Found business with name " + businessEntity.getName().get(0).getValue());
	        	System.out.println("Number of services: " + businessEntity.getBusinessServices().getBusinessService().size());
	        	
	        	for (BusinessService businessService: businessEntity.getBusinessServices().getBusinessService()) {
	        		System.out.println("Service Name        = '" + businessService.getName().get(0).getValue() + "'");
	        		System.out.println("Service Key         = '" + businessService.getServiceKey() + "'");
	        		System.out.println("Service Description = '" + businessService.getDescription().get(0).getValue() + "'");
	        		System.out.println("BindingTemplates: " + businessService.getBindingTemplates().getBindingTemplate().size());
	        		
	        		for (int i=0; i<businessService.getBindingTemplates().getBindingTemplate().size(); i++) {
	    				BindingTemplate bindingTemplate = businessService.getBindingTemplates().getBindingTemplate().get(i);
	    				System.out.println("--BindingTemplate" + " " + i + ":");
	    				System.out.println("  bindingKey          = " + bindingTemplate.getBindingKey());
	    				System.out.println("  accessPoint useType = " + bindingTemplate.getAccessPoint().getUseType());
	    				System.out.println("  accessPoint value   = " + bindingTemplate.getAccessPoint().getValue());
	    				System.out.println("  description         = " + bindingTemplate.getDescription().get(0).getValue());
	        		}
	        	}
        	}
	        
        	
        	//TODO JUDDI-610
			//FindTModel findBindingTModel = WSDL2UDDI.createFindBindingTModelForPortType(portType, namespace);
			
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
	}		

	public static void main (String args[]) {
		Find sp = new Find();
		sp.find();	
	}
}
