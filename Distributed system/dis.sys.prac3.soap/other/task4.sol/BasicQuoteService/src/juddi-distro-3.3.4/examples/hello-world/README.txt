This example is a command line demonstration of how to interact with JUDDI.

1. Start the jUDDI-server (juddi-tomcat or juddi-bundle)

2. Check the settings of the META-INF/uddi.xml, to make sure the serverName and serverPort are set correctly.

3. mvn -Pdemo test

Should print the auth token:

     AUTHTOKEN = authtoken:8aa26a8a-461b-485f-904b-4be4fd5fab76
  
You will need an auth token to on subsequent UDDI calls. The token
can be used until you call discard. The server can be configured to 
timeout tokens after a certain age, or when not used for a certain
number of minutes.
