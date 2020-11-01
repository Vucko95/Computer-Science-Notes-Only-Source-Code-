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

public class Delete {
	
	static UDDIClient uddiClient;
	
	public void deleteBusiness(UDDIClerk clerk) {
		// Deleting the parent business entity that contains our service.
		clerk.unRegisterBusiness("uddi:uddi.joepublisher.com:business_wsdl-business");
	}	
	
	public void deleteWSDL(UDDIClerk clerk) {
		// Register the wsdls for this clerk, referenced in the wsdl2uddi-uddi.xml
		clerk.unRegisterWsdls();
	}

	public static void main (String args[]) {
		
		Delete sp = new Delete();
		try {
			uddiClient = new UDDIClient("META-INF/wsdl2uddi-uddi.xml");
			UDDIClerk clerk = uddiClient.getClerk("joe");
			
			sp.deleteWSDL(clerk);
			sp.deleteBusiness(clerk);
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	
}
