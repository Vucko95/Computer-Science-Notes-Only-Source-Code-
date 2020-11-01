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

import java.net.URL;
import java.util.Map;

import javax.xml.ws.BindingProvider;

import org.apache.juddi.samples.HelloWorld;
import org.apache.juddi.samples.HelloWorld_Service;
import org.apache.juddi.v3.client.config.UDDIClerk;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.apache.juddi.v3.client.mapping.ServiceLocator;

public class Call {
	
	public void call() {
		try {
			UDDIClient uddiClient = new UDDIClient("META-INF/wsdl2uddi-uddi.xml");
			UDDIClerk clerk = uddiClient.getClerk("joe");
        	
        	//find the service in the UDDI registry
        	System.out.println("The clientside of a runtime lookup usually knows the serviceKey.");
        	System.out.println("To get updated binding information you should use the ServiceLocator with a live cache.");
        	String helloWorldServiceKey = "uddi:uddi.joepublisher.com:service_helloworld";
        	
        	long startTime = System.currentTimeMillis();
        	ServiceLocator serviceLocator = new ServiceLocator(clerk); 
        	System.out.println("Created Cache in " + (System.currentTimeMillis() - startTime) + " [milliseconds]");
        	System.out.println("Now adding a listener to the cache..."); //expensive
        	startTime = System.currentTimeMillis();
        	serviceLocator.withLiveCache(new URL("http://localhost:18079"));
        	System.out.println("Add Listener to Cache in " + (System.currentTimeMillis() - startTime) + " [milliseconds]");
        	
        	//first time the lookup will have to contact UDDI
        	startTime = System.currentTimeMillis();
        	String endpoint = serviceLocator.lookupEndpoint(helloWorldServiceKey);
        	long duration = System.currentTimeMillis() - startTime;
        	System.out.println("1. UDDI Lookup - Elapsed time: " + duration + "[milliseconds] Endpoint=" + endpoint);
        	
        	//second lookup should be lightning fast
        	long startTime2 = System.currentTimeMillis();;
        	String endpoint2 = serviceLocator.lookupEndpoint(helloWorldServiceKey);
        	long duration2 = System.currentTimeMillis() - startTime2;
        	System.out.println("2. Cache Lookup - Elapsed time: " + duration2 + "[milliseconds] Endpoint=" + endpoint2);
        	
        	//Invoke the endpoint using 'endpoint2'
        	HelloWorld_Service helloWorldService = new HelloWorld_Service();
        	HelloWorld helloWorld = helloWorldService.getHelloWorldImplPort();
        	Map<String, Object> requestContext = ((BindingProvider) helloWorld).getRequestContext();
			requestContext.put(BindingProvider.ENDPOINT_ADDRESS_PROPERTY, endpoint2);
			String reply = helloWorld.sayHi("Judy");
        	System.out.println("*************** Service reply: " + reply);
			//need to call shutdown to take down the LiveCache Callback Endpoint.
        	Thread.sleep(10l);
        	serviceLocator.shutdown();
        	//TODO JUDDI-610
			//FindTModel findBindingTModel = WSDL2UDDI.createFindBindingTModelForPortType(portType, namespace);
			
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
	}		

	public static void main (String args[]) {
		Call sp = new Call();
		sp.call();	
	}
}
