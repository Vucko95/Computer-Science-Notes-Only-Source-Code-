This example is a command line demonstration of how to interact with JUDDI and how to use 
annotate items in UDDI for service or software versioning. 

1. Start the jUDDI-server (juddi-tomcat or juddi-bundle)

2. Check the settings of the META-INF/uddi.xml, to make sure the serverName and serverPort are set correctly.

3. mvn -Pdemo test

Should print the following:

Hello World!
Jan 08, 2014 6:47:47 AM org.apache.juddi.v3.client.config.UDDIClient <init>
INFO: jUDDI Client version - 3.2.0.SNAPSHOT
Jan 08, 2014 6:47:47 AM org.apache.juddi.v3.client.config.ClientConfig loadConfiguration
INFO: Reading UDDI Client properties file file:///C:/juddi/trunk/juddi-examples/service-version/target/classes/META-INF/
uddi.xml
Jan 08, 2014 6:47:49 AM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering tModel with key uddi:mydomain.com:keygenerator
Jan 08, 2014 6:47:49 AM org.apache.juddi.v3.client.config.UDDIClerk getAuthToken
WARNING: Hey, I couldn't help but notice that your credentials aren't encrypted. Please consider doing so
Jan 08, 2014 6:47:50 AM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering business ZeroCool Business with key uddi:mydomain.com:zerocoolbiz
SUCCESS! Found the right version on key uddi:mydomain.com:binding12
Jan 08, 2014 6:47:50 AM org.apache.juddi.v3.client.config.UDDIClerk unRegisterBusiness
INFO: UnRegistering the business uddi:mydomain.com:zerocoolbiz
Jan 08, 2014 6:47:50 AM org.apache.juddi.v3.client.config.UDDIClerk unRegisterTModel
INFO: UnRegistering tModel key uddi:mydomain.com:keygenerator


This will register tModels, two services that are versioned, then query for service by name.
After that, the data is handed off to helper function which sorts out version information for you
and returns the 0 or more binding Templates.