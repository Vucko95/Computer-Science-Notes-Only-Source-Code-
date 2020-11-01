This example is a command line demonstration of how to interact with JUDDI.

1. Start the jUDDI-server (juddi-tomcat or juddi-bundle)

2. Check the settings of the META-INF/wsdl2uddi-uddi.xml, to make sure the serverName and serverPort are set correctly.

3. Create Joe Publisher and his keyGenerator and then register the services in wsdl/helloworld.wsdl to jUDDI.
it creates a businessEntity with businessKey 'uddi:uddi.joepublisher.com:business-for-wsdl'

mvn -Psetup test

You should see the following output being written to the console:

...

May 08, 2013 9:23:07 PM org.apache.juddi.v3.client.config.UDDIClerk register
INFO: Registering business WSDL-Business with key uddi:uddi.joepublisher.com:business-for-wsdl
[INFO] ------------------------------------------------------------------------
[INFO] BUILD SUCCESS
[INFO] ------------------------------------------------------------------------

4. Build the wsdl2uddi.war:

mvn clean package

5. Now that the business is there, we can deploy the wsdl2uddi.war which contains the
JAX-WS HelloWorld WebService and it deploys its wsdl (in wsdl/HelloWorld.wsdl). So on deployment
it brings up the WebService AND it registers it to UDDI. 

From the distro use:

mvn -Pdeploy cargo:deploy

when in src tree tomcat is in a different location, so use the deploydev profile:

mvn -Pdeploydev cargo:deploy

[INFO] Scanning for projects...
[INFO]                                                                         
[INFO] ------------------------------------------------------------------------
[INFO] Building jUDDI Example WSDL2UDDI Deployment Lifecycle 3.1.5-SNAPSHOT
[INFO] ------------------------------------------------------------------------
[INFO] 
[INFO] --- cargo-maven2-plugin:1.3.3:deploy (default-cli) @ wsdl2uddi-lifecycle ---
[INFO] [edDeployerDeployMojo] Resolved container artifact org.codehaus.cargo:cargo-core-container-tomcat:jar:1.3.3 for container tomcat6x
[INFO] [stalledLocalDeployer] Deploying [/Users/kstam/osc/apache/dev/juddi-patch/juddi-examples/wsdl2uddi-lifecyle/target/wsdl2uddi.war] to [/Users/kstam/osc/apache/dev/juddi-patch/juddi-examples/wsdl2uddi-lifecyle/../../juddi-tomcat/target/tomcat/apache-tomcat-6.0.26/webapps]...
[INFO] ------------------------------------------------------------------------
[INFO] BUILD SUCCESS
[INFO] ------------------------------------------------------------------------

while on the server in the <tomcat>/logs/juddi.log it should say:

Bringing up the endpoint:
2013-05-08 21:31:51,763 INFO [org.springframework.web.context.ContextLoader] - Root WebApplicationContext: initialization started
2013-05-08 21:31:51,792 INFO [org.springframework.web.context.support.XmlWebApplicationContext] - Refreshing Root WebApplicationContext: startup date [Wed May 08 21:31:51 EDT 2013]; root of context hierarchy
2013-05-08 21:31:51,831 INFO [org.springframework.beans.factory.xml.XmlBeanDefinitionReader] - Loading XML bean definitions from ServletContext resource [/WEB-INF/beans.xml]
2013-05-08 21:31:51,856 INFO [org.springframework.beans.factory.xml.XmlBeanDefinitionReader] - Loading XML bean definitions from class path resource [META-INF/cxf/cxf.xml]
2013-05-08 21:31:51,875 INFO [org.springframework.beans.factory.xml.XmlBeanDefinitionReader] - Loading XML bean definitions from class path resource [META-INF/cxf/cxf-extension-soap.xml]
2013-05-08 21:31:51,885 INFO [org.springframework.beans.factory.xml.XmlBeanDefinitionReader] - Loading XML bean definitions from class path resource [META-INF/cxf/cxf-servlet.xml]
2013-05-08 21:31:51,892 INFO [org.springframework.beans.factory.xml.XmlBeanDefinitionReader] - Loading XML bean definitions from class path resource [META-INF/cxf/cxf-extension-http.xml]
2013-05-08 21:31:52,038 INFO [org.springframework.beans.factory.support.DefaultListableBeanFactory] - Pre-instantiating singletons in org.springframework.beans.factory.support.DefaultListableBeanFactory@21e7937: defining beans [cxf,org.apache.cxf.bus.spring.BusApplicationListener,org.apache.cxf.bus.spring.BusWiringBeanFactoryPostProcessor,org.apache.cxf.bus.spring.Jsr250BeanPostProcessor,org.apache.cxf.bus.spring.BusExtensionPostProcessor,org.apache.cxf.resource.ResourceManager,org.apache.cxf.configuration.Configurer,org.apache.cxf.binding.BindingFactoryManager,org.apache.cxf.transport.DestinationFactoryManager,org.apache.cxf.transport.ConduitInitiatorManager,org.apache.cxf.wsdl.WSDLManager,org.apache.cxf.phase.PhaseManager,org.apache.cxf.workqueue.WorkQueueManager,org.apache.cxf.buslifecycle.BusLifeCycleManager,org.apache.cxf.endpoint.ServerRegistry,org.apache.cxf.endpoint.ServerLifeCycleManager,org.apache.cxf.endpoint.ClientLifeCycleManager,org.apache.cxf.transports.http.QueryHandlerRegistry,org.apache.cxf.endpoint.EndpointResolverRegistry,org.apache.cxf.headers.HeaderManager,org.apache.cxf.catalog.OASISCatalogManager,org.apache.cxf.service.factory.FactoryBeanListenerManager,org.apache.cxf.endpoint.ServiceContractResolverRegistry,org.apache.cxf.binding.soap.SoapBindingFactory,org.apache.cxf.binding.soap.SoapTransportFactory,org.apache.cxf.binding.soap.customEditorConfigurer,org.apache.cxf.transport.http.policy.HTTPClientAssertionBuilder,org.apache.cxf.transport.http.policy.HTTPServerAssertionBuilder,org.apache.cxf.transport.http.policy.NoOpPolicyInterceptorProvider,org.apache.cxf.transport.http.ClientOnlyHTTPTransportFactory,org.apache.cxf.transport.servlet.ServletTransportFactory,helloworld]; root of factory hierarchy
2013-05-08 21:31:52,736 INFO [org.springframework.web.context.ContextLoader] - Root WebApplicationContext: initialization completed in 973 ms
2013-05-08 21:31:52,744 INFO [org.apache.cxf.bus.spring.BusApplicationContext] - Refreshing org.apache.cxf.bus.spring.BusApplicationContext@f8ffe0b: startup date [Wed May 08 21:31:52 EDT 2013]; parent: Root WebApplicationContext
2013-05-08 21:31:52,769 INFO [org.springframework.beans.factory.support.DefaultListableBeanFactory] - Pre-instantiating singletons in org.springframework.beans.factory.support.DefaultListableBeanFactory@e161e1f: defining beans []; parent: org.springframework.beans.factory.support.DefaultListableBeanFactory@21e7937
Reading the clientside config: wsdl2uddi-uddi.xml:
2013-05-08 21:31:52,780 INFO [org.apache.juddi.v3.client.config.WebHelper] - Reading the managerName from the clientConfig file /META-INF/wsdl2uddi-uddi.xml
2013-05-08 21:31:52,822 INFO [org.apache.juddi.v3.client.config.ClientConfig] - Reading UDDI Client properties file file:/Users/kstam/osc/apache/dev/juddi-patch/juddi-tomcat/target/tomcat/apache-tomcat-6.0.26/webapps/wsdl2uddi/WEB-INF/classes/META-INF/wsdl2uddi-uddi.xml
2013-05-08 21:31:52,869 INFO [org.apache.juddi.v3.client.config.WebHelper] - Starting Clerk Manager example-manager...
2013-05-08 21:31:56,996 INFO [org.uddi.JAXBContextUtil] - Creating JAXB Context for org.uddi.api_v3
Registering the WSDL:
2013-05-08 21:31:57,083 INFO [org.apache.juddi.v3.client.config.UDDIClerk] - entityKey uddi:uddi.joepublisher.com:service_helloworld was not found in the registry
2013-05-08 21:31:57,141 INFO [org.apache.juddi.v3.client.config.UDDIClerk] - Registering tModel with key uddi:uddi.joepublisher.com:HelloWorld
2013-05-08 21:31:57,366 INFO [org.apache.juddi.v3.client.config.UDDIClerk] - Registering tModel with key uddi:uddi.joepublisher.com:HelloWorldSoapBinding
2013-05-08 21:31:58,396 INFO [org.apache.juddi.v3.client.config.UDDIClerk] - Registering service HelloWorld with key uddi:uddi.joepublisher.com:service_helloworld
2013-05-08 21:31:58,421 INFO [org.apache.juddi.v3.client.config.UDDIClerk] - Registering bindingTemplate with key uddi:uddi.joepublisher.com:binding_localhost_helloworld_helloworldimplport_8080


6. Check that we can find this business in the registry by running from Queries

mvn -Pfind test

[INFO] --- exec-maven-plugin:1.1.1:java (default) @ wsdl2uddi ---
May 08, 2013 12:18:14 PM org.apache.juddi.v3.client.config.ClientConfig loadConfiguration
INFO: Reading UDDI Client properties file file:/Users/kstam/osc/apache/dev/juddi-patch/juddi-examples/wsdl2uddi/target/classes/META-INF/wsdl2uddi-uddi.xml
Found business with name WSDL-Business
Number of services: 1
Service Name        = 'HelloWorld'
Service Key         = 'uddi:uddi.joepublisher.com:service_helloworld'
Service Description = 'The Hello World Service registered using WSDL2UDDI'
BindingTemplates: 1
--BindingTemplate 0:
  bindingKey          = uddi:uddi.joepublisher.com:binding_localhost_helloworld_helloworldimplport_8080
  accessPoint useType = endPoint
  accessPoint value   = http://localhost:8080/uddi-annotations/services/helloworld
  description         = The Hello World Binding registered using WSDL2UDDI
[INFO] ------------------------------------------------------------------------
[INFO] BUILD SUCCESS
[INFO] ------------------------------------------------------------------------

So we got one Service, which one binding. Note that the descriptions were provided in the wsdl file
using <wsdl:documentation> elements.

7. Finally to undeploy the wsdl2uddi.war call 

From the distro use:

mvn -Pdeploy cargo:undeploy

when in src tree tomcat is in a different location, so use the deploydev profile:

mvn -Pdeploydev cargo:undeploy

This removes the HelloWorld WebService and removes the data from the UDDI server.

ClientSide logging:
[INFO] Scanning for projects...
[INFO]                                                                         
[INFO] ------------------------------------------------------------------------
[INFO] Building jUDDI Example WSDL2UDDI Deployment Lifecycle 3.1.5-SNAPSHOT
[INFO] ------------------------------------------------------------------------
[INFO] 
[INFO] --- cargo-maven2-plugin:1.3.3:undeploy (default-cli) @ wsdl2uddi-lifecycle ---
[INFO] [DeployerUndeployMojo] Resolved container artifact org.codehaus.cargo:cargo-core-container-tomcat:jar:1.3.3 for container tomcat6x
[INFO] [stalledLocalDeployer] Undeploying context [wsdl2uddi] from [/Users/kstam/osc/apache/dev/juddi-patch/juddi-examples/wsdl2uddi-lifecyle/../../juddi-tomcat/target/tomcat/apache-tomcat-6.0.26/webapps]...
[INFO] [stalledLocalDeployer] Trying to delete WAR from [/Users/kstam/osc/apache/dev/juddi-patch/juddi-examples/wsdl2uddi-lifecyle/../../juddi-tomcat/target/tomcat/apache-tomcat-6.0.26/webapps/wsdl2uddi.war]...
[INFO] ------------------------------------------------------------------------
[INFO] BUILD SUCCESS
[INFO] ------------------------------------------------------------------------

ServerSide:
2013-05-08 21:40:39,067 INFO [org.apache.cxf.bus.spring.BusApplicationContext] - Closing org.apache.cxf.bus.spring.BusApplicationContext@f8ffe0b: startup date [Wed May 08 21:31:52 EDT 2013]; parent: Root WebApplicationContext
2013-05-08 21:40:39,068 INFO [org.springframework.beans.factory.support.DefaultListableBeanFactory] - Destroying singletons in org.springframework.beans.factory.support.DefaultListableBeanFactory@e161e1f: defining beans []; parent: org.springframework.beans.factory.support.DefaultListableBeanFactory@21e7937
2013-05-08 21:40:39,068 INFO [org.apache.juddi.v3.client.config.UDDIClerkManager] - Stopping UDDI Clerks for manager example-manager
2013-05-08 21:40:44,011 INFO [org.apache.juddi.v3.client.config.UDDIClerk] - UnRegistering binding key uddi:uddi.joepublisher.com:binding_localhost_helloworld_helloworldimplport_8080
2013-05-08 21:40:44,047 INFO [org.apache.juddi.v3.client.config.UDDIClerk] - UnRegistering the service uddi:uddi.joepublisher.com:service_helloworld
2013-05-08 21:40:44,108 INFO [org.apache.juddi.v3.client.config.UDDIClerk] - UnRegistering tModel key uddi:uddi.joepublisher.com:helloworldsoapbinding
2013-05-08 21:40:44,132 INFO [org.apache.juddi.v3.client.config.UDDIClerk] - UnRegistering tModel key uddi:uddi.joepublisher.com:helloworld
2013-05-08 21:40:44,145 INFO [org.apache.juddi.v3.client.config.UDDIClerkManager] - UDDI Clerks shutdown completed for manager example-manager
2013-05-08 21:40:44,146 INFO [org.springframework.web.context.support.XmlWebApplicationContext] - Closing Root WebApplicationContext: startup date [Wed May 08 21:31:51 EDT 2013]; root of context hierarchy
2013-05-08 21:40:44,147 INFO [org.springframework.beans.factory.support.DefaultListableBeanFactory] - Destroying singletons in org.springframework.beans.factory.support.DefaultListableBeanFactory@21e7937: defining beans [cxf,org.apache.cxf.bus.spring.BusApplicationListener,org.apache.cxf.bus.spring.BusWiringBeanFactoryPostProcessor,org.apache.cxf.bus.spring.Jsr250BeanPostProcessor,org.apache.cxf.bus.spring.BusExtensionPostProcessor,org.apache.cxf.resource.ResourceManager,org.apache.cxf.configuration.Configurer,org.apache.cxf.binding.BindingFactoryManager,org.apache.cxf.transport.DestinationFactoryManager,org.apache.cxf.transport.ConduitInitiatorManager,org.apache.cxf.wsdl.WSDLManager,org.apache.cxf.phase.PhaseManager,org.apache.cxf.workqueue.WorkQueueManager,org.apache.cxf.buslifecycle.BusLifeCycleManager,org.apache.cxf.endpoint.ServerRegistry,org.apache.cxf.endpoint.ServerLifeCycleManager,org.apache.cxf.endpoint.ClientLifeCycleManager,org.apache.cxf.transports.http.QueryHandlerRegistry,org.apache.cxf.endpoint.EndpointResolverRegistry,org.apache.cxf.headers.HeaderManager,org.apache.cxf.catalog.OASISCatalogManager,org.apache.cxf.service.factory.FactoryBeanListenerManager,org.apache.cxf.endpoint.ServiceContractResolverRegistry,org.apache.cxf.binding.soap.SoapBindingFactory,org.apache.cxf.binding.soap.SoapTransportFactory,org.apache.cxf.binding.soap.customEditorConfigurer,org.apache.cxf.transport.http.policy.HTTPClientAssertionBuilder,org.apache.cxf.transport.http.policy.HTTPServerAssertionBuilder,org.apache.cxf.transport.http.policy.NoOpPolicyInterceptorProvider,org.apache.cxf.transport.http.ClientOnlyHTTPTransportFactory,org.apache.cxf.transport.servlet.ServletTransportFactory,helloworld]; root of factory hierarchy

