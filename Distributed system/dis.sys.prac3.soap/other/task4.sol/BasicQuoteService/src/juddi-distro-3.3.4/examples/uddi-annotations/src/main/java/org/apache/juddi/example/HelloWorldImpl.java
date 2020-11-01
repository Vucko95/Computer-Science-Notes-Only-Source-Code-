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
package org.apache.juddi.example;

import javax.jws.WebService;

import org.apache.juddi.v3.annotations.UDDIService;
import org.apache.juddi.v3.annotations.UDDIServiceBinding;

/**
 * This example show you how to use UDDI Annotations to decorate a class.
 * When the Servlet Listener
 * 
 */

@UDDIService(
		businessKey="uddi:${keyDomain}:${department}-asf",
		serviceKey="uddi:${keyDomain}:services-hello${department}", 
		description = "Hello World test service")
@UDDIServiceBinding(
		bindingKey="uddi:${keyDomain}:${serverName}-${serverPort}-hello${department}-wsdl",
	    description="WSDL endpoint for the hello${department} Service. This service is used for "
				  + "testing the jUDDI annotation functionality",
	    accessPointType="wsdlDeployment",
	    accessPoint="http://${serverName}:${serverPort}/uddi-annotations/services/helloworld?wsdl")
@WebService(
		endpointInterface = "org.apache.juddi.example.HelloWorld",
        serviceName = "HelloWorld")

public class HelloWorldImpl implements HelloWorld {
    
    public String sayHi(String text) {
        System.out.println("sayHi called");
        return "Hello " + text;
    }
	
}
