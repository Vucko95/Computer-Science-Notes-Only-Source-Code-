This example demonstrates how to use the UDDI annotations to 
selfregister a WebService to UDDI at deployment time.

1. Start the jUDDI-server (juddi-tomcat or juddi-bundle)

2. Check the settings of the META-INF/uddi.xml, to make sure the serverName and serverPort are set correctly.

3. Build the uddi-annotations.war 

mvn package

4. Deploy the uddi-annotations.war to tomcat

mvn -Pdemo cargo:deploy

5. A HelloWorld service should now be deployed. Point your browser to

http://localhost:8080/uddi-annotations/services

and see 

    Available SOAP services:
    HelloWorld
    
        sayHi
    
        Endpoint address: http://localhost:8080/uddi-annotations/services/helloworld
    WSDL : {http://samples.juddi.apache.org/}HelloWorld
    Target namespace: http://samples.juddi.apache.org/
    
6. The service and binding should also be registered into UDDI. On the tomcat/logs/juddi.log
should show and entry:

    [org.apache.juddi.v3.client.config.UDDIClerk] - Registering service HelloWorld with key uddi:juddi.apache.org:services-hellobusinesses

To check even further fire up a uddi-console, or you can go to the simple-browse example and run

mvn -Pdemo test

Among other services it should show

    Fetching data for business uddi:juddi.apache.org:businesses-asf
    Name HelloWorld 
    Desc Hello World test service 
    Key uddi:juddi.apache.org:services-hellobusinesses
    Cat bag no data
    Item is not digitally signed
    Binding Key: uddi:juddi.apache.org:localhost-8080-hellobusinesses-wsdl
    Access Point: http://localhost:8080/juddiv3-samples/services/helloworld?wsdl type wsdlDeployment
    
7. To remove the hello world service from UDDI simple undeploy the uddi-annotations.war. Go 
back to the uddi-annotation example and run

mvn -Pdemo cargo:undeploy

The juddi.log should show

    [org.apache.juddi.v3.client.config.UDDIClerkManager] - Stopping UDDI Clerks for manager uddi-manager
    [org.apache.juddi.v3.client.config.UDDIClerk] - UnRegistering binding key uddi:juddi.apache.org:localhost-8080-hellobusinesses-wsdl
    [org.apache.juddi.v3.client.config.UDDIClerk] - UnRegistering the service uddi:juddi.apache.org:services-hellobusinesses



