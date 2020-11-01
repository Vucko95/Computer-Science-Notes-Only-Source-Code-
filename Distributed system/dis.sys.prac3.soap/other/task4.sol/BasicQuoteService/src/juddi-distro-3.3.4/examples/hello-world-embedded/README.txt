This example is a command line demonstration of how to run with an embedded JUDDI.
Note that this example is identical to the hello-world demo but in this case the jUDDI
server runs in embedded mode. 

1. The following configuration files were changes compared to the hello-world demo.

- The META-INF/embedded-uddi.xml now contains the connection settings for InVmTransport.
- The serverside config file juddiv3.xml was added to the classpath.
- A META-INF/persistence.xml was added (using Hibernate as JPA provider)
- We added the juddi-core (UDDI server) and derby (Embedded Database) dependencies to the pom.

2. Now run mvn -Pdemo test

should print the auth token:

     AUTHTOKEN = authtoken:8aa26a8a-461b-485f-904b-4be4fd5fab76
  
Note that the value of the authtoken will differ. You will need an auth token 
to on subsequent UDDI calls. The token can be used until you call discard. 
The server can be configured to timeout tokens after a certain age, 
or when not used for a certain number of minutes.

Off course you don't have to use Derby and can use a regular database instead,
which will make this demo significantly faster as the jUDDI server won't have to 
through the process of database creation and seeding. WHen you change databases
you will need to change the peristence.xml and add the driver for that particular
database. If you want to use OpenJPA instead of Hibernate, then change the juddi-core
dependency to juddi-core-openjpa. This will bring in the appropriate OpenJPA dependencies
as well as openjpa enhanced jUDDI persistence classes. For more info on openjpa enhancement
of persistance classes please see the openjpa documentation.
