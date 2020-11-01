This example creates a new UDDI partition. 

1. Start the jUDDI-server (juddi-tomcat or juddi-bundle)

2. Check the settings of the META-INF/uddi.xml, to make sure the serverName and serverPort are set correctly.

3. mvn -Pdemo test

Should print:

root AUTHTOKEN = authtoken:a1b910fb-618e-4e46-a06e-29451265862c
Creation of Partition Success!
Creation of tModel Department Success!
Creation of tModel Auth Mode Success!

