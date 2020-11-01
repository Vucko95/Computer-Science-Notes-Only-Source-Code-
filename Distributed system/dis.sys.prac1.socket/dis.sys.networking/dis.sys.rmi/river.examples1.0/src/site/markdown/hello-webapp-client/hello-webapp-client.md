<!--
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership. The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License. You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

-->

# The Hello WebApp Client

Web Applications deployed to Apache Tomcat or TomEE can access Jini services.
This might be the use case if we wanted to present a RESTful service that an
external client like a mobile device could connect to over the open internet.  Or we
might have a rich GUI implemented in a JavaScript framework.

To recall the architecture we have:

- A service browser so we can see what's on the network in our djinn.  
- A service registrar.  
- A "hello-world" service.  

The Jini components are running inside a 
container that is setup by the "service starter" framework.  This container handles
the details of setting up the class loaders and the dynamic security policy provider.
We configure this container with a "start-xyz.config" file.  The component itself
loads up its configuration from a "xyz.config" file.

In addition, let's assume that you have Apache TomEE installed and are able to run
it successfully (installing TomEE is outside the scope of this document - 
see [Apache TomEE](http://tomee.apache.org) for more information).

## Running in a Web Application

When we get to a webapp, things get slightly more complicated.  One of the things that
is critical in a Jini application is the setup of the classloader and the classloader 
hierarchy.  In the web container, we have limited control over the classloader, since
the Java EE specifications include classloader configurations.  Also, in order to provide
the environment, the container needs to use its own customized class loaders, which in 
general won't support the required behaviour for Jini classes.  In particular, it is usually not
possible (or at least not convenient) to setup the codebase annotation to support mobile code.
As a result, it isn't possible to use a web container to host Jini services (for the sake of 
completeness, there has been some work in this area, but it was long ago and seems to have
dropped off the web).

It is, however, quite possible for a web application
to act as a consumer of Jini services.  The fundamental problem
we face is that any objects instantiated in the servlet container will not carry a usable
codebase annotation.  We can work around this issue by applying some minor constraints to the 
interfaces used in a webapp.  Basically, we need to limit parameters and types that transit
the network to those that are part of the 
core Java language, or any other types that are expected to be present in both the service consumer and
provider's classpath.  This restriction is no more onerous than similar restrictions on
Enterprise Java Bean interfaces (in fact it's the same restriction - EJBs have no concept of
mobile code).

Security is another consideration - since Jini works on a mobile-code architecture, we need to be
able to load and run code that is loaded remotely.  Jini's infrastructure imposes the requirement
that we need to have a security manager running, in order to control this mobile code.
In addition, the proxy preparation process requires a customized security policy provider.

Java EE applications and application servers seldom bother to turn on the security manager,
since they don't run "untrusted" code that is downloaded from the network.  As such, it may be 
difficult or impossible to implement the correct security policies and policy provider.

Luckily, with Apache TomEE, the configuration is not that bad.

* Add the appropriate security policies to conf/catalina.policy.
* Edit conf/server.xml to start properly with a security manager
* Start up TomEE with the security manager

Let's look at these steps individually...

### Add Security Polices to conf/catalina.policy

In your TomEE installation directory, navigate to the 'conf' folder and open the
file 'catalina.policy'.  Look for the "Web Application Permissions" section...

    // ========== WEB APPLICATION PERMISSIONS =====================================


    // These permissions are granted by default to all web applications
    // In addition, a web application will be given a read FilePermission
    // and JndiPermission for all files and directories in its document root.
    grant {
        // Required for JNDI lookup of named JDBC DataSource's and
        // javamail named MimePart DataSource used to send mail
        permission java.util.PropertyPermission "java.home", "read";
        permission java.util.PropertyPermission "java.naming.*", "read";
        permission java.util.PropertyPermission "javax.sql.*", "read";

        // OS Specific properties to allow read access
        permission java.util.PropertyPermission "os.name", "read";
        permission java.util.PropertyPermission "os.version", "read";
        permission java.util.PropertyPermission "os.arch", "read";
        permission java.util.PropertyPermission "file.separator", "read";
        permission java.util.PropertyPermission "path.separator", "read";
        permission java.util.PropertyPermission "line.separator", "read";
        (cont'd...)

This section outlines the permissions that are granted to all web applications.
The format is in the familiar policy file format.

Find the bottom of this section, and just under the part where it says "Required for TomEE",
add the lines below, so it looks like:

        // Required for TomEE
        permission java.util.PropertyPermission "tomee.skip-tomcat-log", "read";

        // Required to allow Jini clients
        permission java.lang.RuntimePermission "createSecurityManager";
        permission java.security.SecurityPermission "getDomainCombiner";
        permission java.lang.RuntimePermission "getProtectionDomain";
        permission java.security.SecurityPermission "createAccessControlContext";
        permission java.security.SecurityPermission "getPolicy";
        permission com.sun.jini.discovery.internal.EndpointInternalsPermission "get";
        permission com.sun.jini.discovery.internal.EndpointInternalsPermission "set";
        permission net.jini.discovery.DiscoveryPermission "*";
        permission java.net.SocketPermission "*", "connect,accept,listen,resolve";
        permission java.lang.RuntimePermission "modifyThreadGroup";
        permission com.sun.jini.thread.ThreadPoolPermission "getSystemThreadPool";
        permission java.lang.RuntimePermission "getClassLoader";
        permission java.lang.RuntimePermission "modifyThread";
        permission java.lang.RuntimePermission "setContextClassLoader";
    }

These lines add the various permissions required to access simple Jini/JERI services
 to all web applications.

Note - we haven't done anything to enable dynamic permission grants in Tomcat/TomEE.
So if you try to use a service whose proxy needs any extra permissions, it probably
won't work.

What are dynamic permission grants, you ask?  When the JERI subsystem loads a proxy, it grants
no permissions to that proxy by default.  As part of the proxy preparation process,
the proxy preparer grants additional permissions after validating the proxy.  So the 
actual permissions granted to the proxy are specified in the web app's configuration file
under the initialization for the BasicProxyPreparer.  But in order for that to work, 
we need to enable Jini's DynamicPolicyProvider.  Service containers like the Service Starter framework,
River Container or Rio, enable this policy provider when they setup the security manager, 
but TomEE just uses the default policy file provider.  It's possible to override it, but
it's outside the scope of this basic tutorial.

### Edit conf/server.xml to start properly with a security manager

Tomcat has a slightly funny behavior when started up with a security manager - it
ignores the 'META-INF/context.xml' file that is normally packaged in the '.war' file,
and in fact rejects deployment of the application.  This behavior reflects Tomcat's
assumptions about why you'd want to use a security manager.  It assumes that you've
enabled J2EE security because your webapps contain untrusted code, and you want to
control what they can do.  In that scenario, you would also want to control the deployment
of the webapps, so you probably wouldn't want to allow the webapps to include a 'context.xml'
file.

In practice, it's very rare to deploy untrusted web applications, which is why you
have probably never run Tomcat, TomEE, WebSphere or any other application server with
J2EE security enabled.  In our case, we trust the web application; the security manager is
there to control code that might be downloaded with a proxy.

We can override the default behavior by editing Tomcat/TomEE's 'server.xml' file.

Open the 'conf/server.xml' file in your TomEE installation folder, and locate the 
'Host' element with the name attribute equal to 'localhost'.  Edit it so the 'deployXML' attribute
is 'true', as below:

      <Host name="localhost"  appBase="webapps"
            unpackWARs="true" autoDeploy="true" deployXML="true">

Now TomEE will deploy the application successfully.

### Start up TomEE with the security manager

If you're starting up TomEE manually, you simply need to add the '-security' option to 
'catalina.sh start'.  If you're starting TomEE through your IDE, you need to alter its
configuration to start with the security manager. 

## The Client Web Application

Assuming you've built the examples project with 'maven install', you should be
able to find the '.war' file under 'river-examples/hello-webapp-client/target'.
The file will be named something like 'hello-webapp-client-1.0-SNAPSHOT.war', as per
Maven's artifact naming convention.
You can either rename this file and copy it to TomEE's 'webapps' folder, or you may be
able to run the 'hello-webapp-client' subproject directly under your IDE (under NetBeans, simply 
right-click on the project and then select 'Run').

This is a simple Java Server Faces application - the main page looks like:

![hello-webapp-client home page](hello-webapp-client-homepage.png)

If you enter a name and then click 'Update', you should see the reply from the 
hello-world service, similar to the client we saw before.

![hello-webapp-client response](hello-webapp-client-response.png)

Lets look at how this application works...

First, the actual JSF page (index.xhtml):

    <?xml version='1.0' encoding='UTF-8' ?>
    <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
    <html xmlns="http://www.w3.org/1999/xhtml"
          xmlns:h="http://java.sun.com/jsf/html"
          xmlns:f="http://java.sun.com/jsf/core">
        <h:head>
            <title>Hello WebApp Client</title>
        </h:head>
        <h:body>
            <h:form>
                Please enter your name:<h:inputText value="#{helloBean.name}"/><br/>
                Message is: #{helloBean.message}.
                <h:commandButton value="Update" action="#{helloBean.updateMessage()}"/>
            </h:form>
        </h:body>
    </html>

The form references a managed bean called 'helloBean'.  This bean is defined in the 
class 'org.apache.river.examples.hello.webapp.client.HelloBean':

    /**
     * A Managed Bean that uses a Jini Service.
     */
    @Named
    @RequestScoped
    public class HelloBean {

        private static final Logger log = Logger.getLogger(HelloBean.class.getName());
        private static final String MODULE=HelloBean.class.getPackage().getName();

        String name;
        String message="Default";

        /*  Getters and setters elided... */

        @Inject
        private Configuration config;

        public void updateMessage() {
            log.info("Running updateMessage()...");
            log.info("Config is " + config);
            try {
                // From the config, get the ServiceDiscoveryManager
                ServiceDiscoveryManager sdm=
                        (ServiceDiscoveryManager) 
                        config.getEntry(MODULE, "sdm", ServiceDiscoveryManager.class);
                // We'll also need a proxy preparer.
                ProxyPreparer preparer=(ProxyPreparer) config.getEntry(MODULE, 
                        "greeterPreparer", ProxyPreparer.class);
                // Query the sdm for Greeter services.
                ServiceTemplate template=new ServiceTemplate(
                        null,
                        new Class[] { Greeter.class },
                        new Entry[0]
                );
                ServiceItem[] serviceItems=sdm.lookup(template, 5, null);
                if (serviceItems.length==0) {
                    message="We didn't find any greeter services.";
                    return;
                }
                // Pick a service item
                ServiceItem chosen=serviceItems[0];
                // Prepare the proxy.
                Greeter greeter=(Greeter) preparer.prepareProxy(chosen.service);
                // Make the call
                message=greeter.sayHello(name);
            } catch (Throwable ex) {
                message=ex.getMessage();
                ex.printStackTrace();
            }    
        }
    }

This code is quite similar to the stand-alone client code.  It retrieves the 
service discovery manager and proxy preparer from the Configuration, then looks up the 
Greeter service, selects the first service item returned, prepares the proxy, and calls
'sayHello(...)' on the proxy.

The only small mystery here - where does the Configuration come from?  Note the 
'@Inject' annotation on the configuration field.  Also, if you look carefully, you'll 
notice that there's a 'beans.xml' file inside the 'WEB-INF' folder in the web application.
The presence of this file triggers the Java EE 6 Contexts and Dependency Injection functionality.

The Configuration is supplied by the 'org.apache.river.examples.hello.webapp.client.ConfigHolder'
class:

    /**
     * This class acts as a ServletContextListener to load the configuration on 
     * startup of the application, and then acts as a CDI resource provider to allow
     * automatic injection of the Configuration to any other CDI components.
     */
    @WebListener
    public class ConfigHolder implements ServletContextListener {

        private static Logger log = Logger.getLogger(ConfigHolder.class.getName());

        private static Configuration config;

        @Override
        public void contextInitialized(ServletContextEvent sce) {
            ServletContext sc = sce.getServletContext();
            log.info("Got the servlet context in contextInitialized(...):" + sc);
            log.info("This is " + this);
            try {
                // Load the configuration
                log.info("servletContext=" + sc);
                Object configResourceUrl
                        = sc.getResource("/WEB-INF/client.config");
                String configResource = configResourceUrl.toString();

                log.info("Attempting to open config at "
                        + configResource);
                config
                        = new ConfigurationFile(new String[]{configResource});
                log.info("Got configuration.");
                /* Get the ServiceDiscoveryManager.  This call effectively causes discovery to 
                begin at application startup. 
                */
                config.getEntry(this.getClass().getPackage().getName(), 
                        "sdm", ServiceDiscoveryManager.class);
            } catch (Throwable t) {
                log.log(Level.SEVERE, "Got a throwable on startup", t);
            }

        }

        @Override
        public void contextDestroyed(ServletContextEvent sce) {

        }

        @Produces Configuration getConfig() {
            return config;
        }
    }

This class includes the '@WebListener' annotation, which sets up the class
to have its 'contextInitialized(...)' method called when the application starts up.  In
this method, the Configuration is loaded from the file 'WEB-INF/client.config' 
using the ConfigurationFile class, and placed into a static field.

The getter method 'getConfig()' is marked with the '@Produces' annotation which
sets it up as the source for any 'Configuration' objects.  Recall that the 'HelloBean' class
had its configuration field marked with the '@Inject' annotation.  So when the 'HelloBean' gets
initialized, TomEE's CDI subsystem creates an instance of ConfigHolder and then calls
the 'getConfig()' method to get the configuration, and then injects that configuration into
the 'HelloBean' instance.

That's it!  That's the core of a web application that accesses Jini/River services.
As an aside, TomEE implements the JAX-RS specification, so this same framework can be
used to create RESTful services that delegate to Jini services for the real work.




