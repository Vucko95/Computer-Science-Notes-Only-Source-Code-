To run this demo, first go here
http://qpid.apache.org/

1) Download the following:
 - Java broker from http://qpid.apache.org/components/java-broker/index.html
2) Start Qpid Java broker (qpid-server) using ./bin/qpid-server
	- Reconfigure Qpid. The goal here is to have Qpid's http management interface rerouted to another port that 8080
	- Launch a browser to http://localhost:8080
	- Login with admin/admin (default credentials for Qpid), 
	- Under Broker > Ports, add a new HTTP port on a port other than 8080, such as 9080.
    - Delete the existing HTTP port on 8080
	- Restart Qpid
3) run mvn clean install
4) copy target/subscription-notification-amqp-<version>-jar-with-dependencies.jar to tomcat/webapps/juddiv3.war/WEB-INF/lib
5) Start Tomcat with jUDDI
6) run juddi-qpid-notifier> mvn clean install -Pdemo

At this point, our AMQP client will sit and listen for changes to business, services and tModels.

It's pretty each to change something using the juddi-gui.
	http://localhost:8080/juddi-gui

	
Notes: this example is very basic and does not consider cases such as authentication and SSL key information for connecting to Qpid.