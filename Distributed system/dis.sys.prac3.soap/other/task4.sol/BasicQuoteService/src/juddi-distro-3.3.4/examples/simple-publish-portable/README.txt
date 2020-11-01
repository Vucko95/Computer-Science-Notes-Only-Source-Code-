This example is a command line demonstration of how to interact with UDDI.

Specifically, this code gives you a fairly vanilla mechanism for interaction with any UDDIv3 server.

1. Start the jUDDI-server (juddi-tomcat or juddi-bundle)

2. Check the settings of the META-INF/uddi.xml, to make sure the serverName and serverPort are set correctly.

3. mvn -Pdemo test

You should see the following output being written to the console:

root AUTHTOKEN = authtoken:0494e382-1ad3-4c52-8806-ae70a0ed37ad
myPub AUTHTOKEN = authtoken:bf973e5f-7361-4c57-92f7-7b499b886b6d
myBusiness key:  uddi:juddi.apache.org:6f3e4e62-e483-48ff-a1b3-6855310505c6
myService key:  uddi:juddi.apache.org:549a9580-cd7b-4969-9b77-527ab9f8f261

However since the keys are being generated in this case your keys will differ.

