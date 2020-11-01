This example is a command line demonstration of how to interact with JUDDI using the juddi-client.
In step 4 is demonstrates how to use the ServiceLocator.

1. Start the jUDDI-server (juddi-tomcat or juddi-bundle)

2. Check the settings of the META-INF/wsdl2uddi-uddi.xml, to make sure the serverName and serverPort are set correctly.

3. Create Joe Publisher and his keyGenerator and then register the services in wsdl/helloworld.wsdl to jUDDI.
it creates a businessEntity with businessKey 'uddi:uddi.joepublisher.com:business_wsdl-business' using
the org.apache.juddi.example.wsdl2uddi.Publish class, which is called using

mvn -Ppublish test

You should see the following output being written to the console:

1. Bring up the hello world endpoint at port 18080
2. Programmatically publish the endpoint to UDDI
Dec 26, 2013 5:53:26 PM org.apache.juddi.v3.client.config.UDDIClient <init>
INFO: jUDDI Client version - 3.2.0.SNAPSHOT
Dec 26, 2013 5:53:26 PM org.apache.juddi.v3.client.config.ClientConfig loadConfiguration
INFO: Reading UDDI Client properties file file:///Users/kstam/osc/apache/dev/juddi-patch/juddi-examples/wsdl2uddi/target/classes/META-INF/wsdl2uddi-uddi.xml
setting up the publisher
root AUTHTOKEN = authtoken:f8d3b465-dca2-4780-ba6a-4ff397784dde
Dec 26, 2013 5:53:27 PM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering tModel with key uddi:uddi.joepublisher.com:keygenerator
Dec 26, 2013 5:53:27 PM org.apache.juddi.v3.client.config.UDDIClerk getAuthToken
WARNING: Hey, I couldn't help but notice that your credentials aren't encrypted. Please consider doing so
publish the business
Dec 26, 2013 5:53:27 PM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering business WSDL-Business with key uddi:uddi.joepublisher.com:business_WSDL-Business
and the wsdl
Retrieving document at 'file:/Users/kstam/osc/apache/dev/juddi-patch/juddi-examples/wsdl2uddi/target/classes/wsdl/helloworld.wsdl'.
Dec 26, 2013 5:53:28 PM org.uddi.JAXBContextUtil getContext
INFO: Creating JAXB Context for org.uddi.api_v3
Dec 26, 2013 5:53:28 PM org.apache.juddi.v3.client.config.UDDIClerk checkForErrorInDispositionReport
INFO: entityKey uddi:uddi.joepublisher.com:service_helloworld was not found in the registry
Dec 26, 2013 5:53:28 PM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering tModel with key uddi:uddi.joepublisher.com:HelloWorld
Dec 26, 2013 5:53:28 PM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering tModel with key uddi:uddi.joepublisher.com:HelloWorldSoapBinding
Dec 26, 2013 5:53:28 PM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering service HelloWorld with key uddi:uddi.joepublisher.com:service_helloworld
Dec 26, 2013 5:53:28 PM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering bindingTemplate with key uddi:uddi.joepublisher.com:binding_localhost_helloworld_helloworldimplport_18080
waiting for calls into the HelloWorldImpl...

This brought up the HelloWorld webservice, on http://localhost:18080/services/helloworld
You can check that it is up by navigating to this url in your browser.

Also you can check created UDDI data structures by browsing to this business using the juddi-gui.

4. Lets check that we can find this business in the registry by running from Queries
using the org.apache.juddi.example.wsdl2uddi.Find class which is called using:

mvn -Pfind test

Should result in the following output:

Dec 26, 2013 5:54:51 PM org.apache.juddi.v3.client.config.UDDIClient <init>
INFO: jUDDI Client version - 3.2.0.SNAPSHOT
Dec 26, 2013 5:54:52 PM org.apache.juddi.v3.client.config.ClientConfig loadConfiguration
INFO: Reading UDDI Client properties file file:///Users/kstam/osc/apache/dev/juddi-patch/juddi-examples/wsdl2uddi/target/classes/META-INF/wsdl2uddi-uddi.xml
Do a find business using the businessKey uddi:uddi.joepublisher.com:business_wsdl-business
Found business with name WSDL-Business
Number of services: 1
Service Name        = 'HelloWorld'
Service Key         = 'uddi:uddi.joepublisher.com:service_helloworld'
Service Description = 'The Hello World Service registered using WSDL2UDDI'
BindingTemplates: 1
--BindingTemplate 0:
  bindingKey          = uddi:uddi.joepublisher.com:binding_localhost_helloworld_helloworldimplport_18080
  accessPoint useType = endPoint
  accessPoint value   = http://localhost:18080/services/helloworld
  description         = The Hello World Binding registered using WSDL2UDDI
[INFO] ------------------------------------------------------------------------
[INFO] BUILD SUCCESS
[INFO] ------------------------------------------------------------------------


So we got one Service, which one binding. Note that the descriptions were provided in the wsdl file
using <wsdl:documentation> elements.

4. For extra credit we can use the ServiceLocator to obtain an accessPoint for service
'uddi:uddi.joepublisher.com:service_helloworld'. And we then use this information to call
this WebService Endpoint. In this example we use the code in the
org.apache.juddi.example.wsdl2uddi.Call class, which is called using

 mvn -Pcall test
 
 You should see the following output:
 
 Dec 26, 2013 5:59:51 PM org.apache.juddi.v3.client.config.UDDIClient <init>
INFO: jUDDI Client version - 3.2.0.SNAPSHOT
Dec 26, 2013 5:59:51 PM org.apache.juddi.v3.client.config.ClientConfig loadConfiguration
INFO: Reading UDDI Client properties file file:///Users/kstam/osc/apache/dev/juddi-patch/juddi-examples/wsdl2uddi/target/classes/META-INF/wsdl2uddi-uddi.xml
The clientside of a runtime lookup usually knows the serviceKey.
To get updated binding information you should use the ServiceLocator with a live cache.
Created Cache in 1 [milliseconds]
Now adding a listener to the cache...
Dec 26, 2013 5:59:51 PM org.apache.juddi.v3.client.mapping.ServiceLocator initCache
INFO: Creating a UDDICLientCache
Retrieving document at 'jar:file:/Users/kstam/.m2/repository/org/apache/juddi/juddi-client/3.2.0-SNAPSHOT/juddi-client-3.2.0-SNAPSHOT.jar!/org/apache/juddi/v3/client/mapping/UDDIClientSubscriptionListener.wsdl'.
Dec 26, 2013 5:59:51 PM org.apache.juddi.v3.client.config.UDDIClerk getAuthToken
WARNING: Hey, I couldn't help but notice that your credentials aren't encrypted. Please consider doing so
Dec 26, 2013 5:59:52 PM org.uddi.JAXBContextUtil getContext
INFO: Creating JAXB Context for org.uddi.api_v3
Dec 26, 2013 5:59:52 PM org.apache.juddi.v3.client.config.UDDIClerk checkForErrorInDispositionReport
INFO: entityKey uddi:uddi.joepublisher.com:service_uddiclientsubscriptionlistenerservice was not found in the registry
Dec 26, 2013 5:59:52 PM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering tModel with key uddi:uddi.joepublisher.com:UDDI_SubscriptionListener_PortType
Dec 26, 2013 5:59:52 PM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering tModel with key uddi:uddi.joepublisher.com:UDDI_SubscriptionListener_PortTypeBinding
Dec 26, 2013 5:59:52 PM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering service UDDIClientSubscriptionListenerService with key uddi:uddi.joepublisher.com:service_uddiclientsubscriptionlistenerservice
Dec 26, 2013 5:59:52 PM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering bindingTemplate with key uddi:uddi.joepublisher.com:binding_localhost_uddiclientsubscriptionlistenerservice_uddiclientsubscriptionlistenerimplport_18079
Dec 26, 2013 5:59:52 PM org.apache.juddi.v3.client.mapping.UDDIServiceCache publishAndRegisterHttpCallbackEndpoint
INFO: Bringing up a UDDIClientSubscriptionListenerImpl on Endpoint http://localhost:18079/subscriptionlistener_uddi_client
Dec 26, 2013 5:59:53 PM org.apache.juddi.v3.client.mapping.UDDIServiceCache publishAndRegisterHttpCallbackEndpoint
INFO: Registering a CallbackSubscription to this endpoint using bindingKey uddi:uddi.joepublisher.com:binding_localhost_uddiclientsubscriptionlistenerservice_uddiclientsubscriptionlistenerimplport_18079
Dec 26, 2013 5:59:53 PM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering subscription with key uddi:uddi.joepublisher.com:service_cache_localhost
Add Listener to Cache in 1847 [milliseconds]
1. UDDI Lookup - Elapsed time: 18[milliseconds] Endpoint=http://localhost:18080/services/helloworld
2. Cache Lookup - Elapsed time: 0[milliseconds] Endpoint=http://localhost:18080/services/helloworld
*************** Service reply: Hello Judy
Dec 26, 2013 5:59:53 PM org.apache.juddi.v3.client.config.UDDIClerk unRegisterSubscription
INFO: UnRegistering subscription with key uddi:uddi.joepublisher.com:service_cache_localhost
Dec 26, 2013 5:59:53 PM org.apache.juddi.v3.client.config.UDDIClerk unRegisterBinding
INFO: UnRegistering binding key uddi:uddi.joepublisher.com:binding_localhost_uddiclientsubscriptionlistenerservice_uddiclientsubscriptionlistenerimplport_18079
Dec 26, 2013 5:59:53 PM org.apache.juddi.v3.client.config.UDDIClerk unRegisterService
INFO: UnRegistering the service uddi:uddi.joepublisher.com:service_uddiclientsubscriptionlistenerservice
Dec 26, 2013 5:59:53 PM org.apache.juddi.v3.client.config.UDDIClerk unRegisterTModel
INFO: UnRegistering tModel key uddi:uddi.joepublisher.com:uddi_subscriptionlistener_porttypebinding
Dec 26, 2013 5:59:53 PM org.apache.juddi.v3.client.config.UDDIClerk unRegisterTModel
INFO: UnRegistering tModel key uddi:uddi.joepublisher.com:uddi_subscriptionlistener_porttype
[INFO] ------------------------------------------------------------------------
[INFO] BUILD SUCCESS
[INFO] ------------------------------------------------------------------------
 
This shows that the UDDI lookup took 18 milliseconds; while Cache lookup was much faster. Note that while
it is check to obtain a regular Cache it is more expensive to obtain a LiveCache. A LiveCache brings up
a WS Endpoint, and registers this Endpoint with the UDDI Server. If there is an change to any of the UDDI
services it calls back into this Endpoint which invalidates the cache.

5. Finally to remove all data structures call 

mvn -Pdelete test

This cleans up the business and the wsdl2uddi data structures.

6. You can now <cntr>-c out of the mvn -Ppublish test, to take down the HelloWorld Service.

