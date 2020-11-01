This example is a command line demonstration of how to interact with JUDDI and how to use 
annotate items in UDDI for service or software versioning. 

1. Start the jUDDI-server (juddi-tomcat or juddi-bundle)

2. Check the settings of the META-INF/simple-publish-uddi.xml, to make sure the serverName and serverPort are set correctly.

Note: This is an interactive program. Do not run this from a headless server or from CI/Buildbot/Jenkins

3. mvn clean install -Pinteractive

Follow the onscreen prompts