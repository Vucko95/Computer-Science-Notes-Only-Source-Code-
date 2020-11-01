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

# Service Browser Example

This is a utility that allows you to browse the services that are
operating in your workgroup, or 'djinn'.  Although it's presented as an example,
you'll find it to be a useful utility, as well.

The example illustrates a basic use of the ServiceStarter utility class to 
setup the environment for the browser to run in, including the installation of
a DynamicPolicyProvider and custom classloader.

## Building the Service Browser

The project uses Apache Maven to manage the dependencies and build the examples.
There is no need to download and build the main River distribution or tools;
the River artifacts are deployed to Maven Central, so Maven will automatically
download the binary artifacts as needed for the examples build.

The examples project is a multi-module project.  'browser' is one of the modules.
It produces the 'jar' artifact 'browser-${version}.jar'.

However, as we'll see, there's a lot more to running a River application than just the 
jar files.  The code of the browser is in the browser project, but the configuration
files and other jars in the classpath are assembled in the 'home' module under
the parent 'river-examples' project.

So, to be completely safe, we should run 'mvn install' on the parent project when we
make a change to any code.  Doing so will cause Maven to build all the modules in the
order derived from their dependencies.  'home' declares a dependency on 'browser'
 (among others), so
the 'browser' module gets built, and then the 'home' module
gets built.  As part of its build, 'home' will gather the jar files from its dependency 
modules into the 'lib' directory of its target build.

## Running the Service Browser

First navigate to the directory that's built by the 'home' module:

    cd ${river-examples-home}/home/target/home-${version}-bin

This location follows the Maven conventions of putting all build output into the 
'target' folder under a module's home directory.

Services and clients in a Jini/River context generally don't run in a stand-alone 
fashion.  They need an environment setup for them.  

* The security environment needs 
particular attention, because Jini/River uses a 'mobile-code' approach to distributed 
systems.  Since we're going to load proxies that are transferred over the network, we
need to have a security policy in place.  And then, the client code will want to 
dynamically change the permissions that are granted to that remotely-loaded code, so that 
we can check out the authenticity of the proxy before we let it loose.  The standard
security policy in the JRE doesn't allow for dynamic permission grants, so we have to use 
a special security policy implementation (net.jini.security.policy.DynamicPolicyProvider),
which has to be configured into the JVM.

* If we're providing proxies that will be downloaded by someone else (this covers most
services and a surprising number of clients), then we're going to need to 
attach a codebase annotation to the 
class loader.  This annotation (not to be confused with a "Java 5 Annotation" that 
uses the '@' symbol in source code) ensures that the serialized version of an object
will include the location of an http server that can supply the bytecode for that
object.

* Speaking of the codebase annotation, the bytecode for a proxy has to be downloadable
from somewhere.  This could certainly be a standard web server like Tomcat, but it 
does need to be setup.  And the codebase annotation has to point to it. And in general, we have
to enable code downloading by setting the system property "java.rmi.server.useCodebaseOnly"
to "false".

It is (barely) possible to configure a JRE and setup the policy files using command-line
options to the JDK, but there's an easier way: The ServiceStarter container.

So the way that we "run" the service browser is to run the ServiceStarter container with 
a setup file that instructs it how to run the browser program that we're really interested in.

    java -Djava.security.manager -Djava.security.policy=server.policy -Djava.rmi.server.useCodebaseOnly=false -jar lib/start.jar start-browser.config

If all is well, you should see the Service Browser start up, with a window that looks like this:

![Service Browser home page](browser-start.png)

If all isn't well, feel free to ask about it on 
[user@river.apache.org](mailto:user@river.apache.org).

Right now, there's probably nothing to browse (No registrars to select). 
We'll fix that in another example.

For now, let's take a look at how we're actually running this client. First, the command line
turns on Java security ('-Djava.security.manager') and calls out a policy file 
('-Djava.security.policy=server.policy').  Together, these command line options enable the security
manager and set the permissions for code the 'ServiceStarter' code.  As we'll see shortly,
the actual browser code runs under a different set of security policies, and any proxies that 
we download run under yet a different policy.

The 'server.policy' file looks like:

    /* Security policy for non-secure server */

    /* Grant all permissions to our classes */
    grant codeBase "file:lib${/}*" {
        permission java.security.AllPermission;
    };

    grant codebase "file:lib${/}*" {
        permission java.security.AllPermission;
    };

It simply grants full permissions to any code that is contained in a jar file in the
'lib' folder.  Note - this policy is fairly safe, since we are in control of all the code
that's in the 'lib' folder.  You certainly could lock it down further if you had any 
doubts, but we'll typically be OK.

Note also that we're not granting any permissions to code that is not in our 'lib'
folder.  So if the running program downloads a proxy from a remote source, that proxy
has no permissions to do anything.  It's permissions will be granted to it dynamically
as part of the 'proxy preparation' process.  We'll explore that a little when we 
[create a client](../hello-client/hello-client.html) later on 

After that, the command line identifies the jar file to run ('-jar  lib/start.jar).
This jar file is not a product of the river-examples project - it was downloaded from 
Maven Central, since the browser module declares it as a dependency.  The file is created in the 
process of building the Jini Technology Starter Kit (you don't need to download or build the
JTSK sources for these examples - the artifacts are in Maven Central).

If you examine the contents of the start.jar file, you'll find that it contains the 
following manifest:

    Manifest-Version: 1.0
    Ant-Version: Apache Ant 1.9.2
    Created-By: 1.7.0_45-b18 (Oracle Corporation)
    Main-Class: com.sun.jini.start.ServiceStarter
    Class-Path: jsk-platform.jar

This manifest follows the guidelines to be an 'executable jar file'.  It lists a 
main class, and also the classpath that is needed to execute the file.  In this case, it
calls out 'jsk-platform.jar'.  This artifact is
built in the River JTSK project, and is published to Maven Central.  It's mentioned as
a dependency by the 'home' module's 'pom.xml', so it is downloaded by Maven automatically.
Additionally, for this class path to work, then the 'start.jar' file needs to be deployed into a folder
that also contains the 'jsk-*' jars.  That's handled by the assembly specification that's 
contained in the 'home' module.

The last parameter 'start-browser.config', is the name of the configuration file
for the service starter.  Let's have a look at it:

    /* Configuration file for starting non-secure Browser */

    import com.sun.jini.config.ConfigUtil;
    import com.sun.jini.start.NonActivatableServiceDescriptor;
    import com.sun.jini.start.ServiceDescriptor;

    com.sun.jini.start {

        private static policy = "server.policy";
        private static classpath = "lib${/}browser.jar";
        private static config = "browser.config";
        private static codebase = "";

        static serviceDescriptors = new ServiceDescriptor[] {
            new NonActivatableServiceDescriptor(
                codebase, policy, classpath,
                "org.apache.river.examples.browser.Browser",
                new String[] { config })
        };

    }//com.sun.jini.start

The syntax kind of looks like Java, but it isn't.  This is really a specification of 
all the objects that the service browser might need, in a form that can be 
relatively easily edited.  To understand the configuration, it helps to look at a 
small amount of the service starter startup code:

    public static void main(String[] args) {
       ensureSecurityManager();
       try {
           logger.entering(ServiceStarter.class.getName(),
	       MessageNames.MAIN, (Object[])args);
           Configuration config = ConfigurationProvider.getInstance(args);
           processServiceDescriptors(config);
       } catch (ConfigurationException cex) {
	   logger.log(Level.SEVERE, MessageNames.SERVICE_CONFIG_EXCEPTION, cex);
       } catch (Exception e) {
           logger.log(Level.SEVERE, MessageNames.SERVICE_CREATION_EXCEPTION, e);
       }
       logger.exiting(ServiceStarter.class.getName(), 
	   MessageNames.MAIN);
    }   

    private static void processServiceDescriptors( Configuration config ) throws Exception
    {
       ServiceDescriptor[] descs =  (ServiceDescriptor[])
               config.getEntry(START_PACKAGE, "serviceDescriptors",
                   ServiceDescriptor[].class, null);
       if (descs == null || descs.length == 0) {
           logger.warning("service.config.empty");
           return;
       }
           
Looking at the code above, you can see that the 'main(...)' method uses something called
'ConfigurationProvider' to create a configuration object based on the command line 
parameters, and then the 'processServiceDescriptors(...)' method calls 'config.getEntry(...)' to 
retrieve objects from the configuration.

So, the configuration file uses a Java-like syntax to specify how to create the 
objects that are needed to run the service browser.  It isn't really that much 
different from Spring bean configuration files, if you're familiar with those.
We'll end up using similar 
configuration files to configure the infrastructure services and also our service and client
examples.

The configuration file that we referenced on the command line is there to configure
the service starter.  It basically lets the service starter obtain a list of services that
it should start, by supplying a 'variable' that looks a lot like a plain old Java
variable initializer:

        static serviceDescriptors = new ServiceDescriptor[] {
            new NonActivatableServiceDescriptor(
                codebase, policy, classpath,
                "org.apache.river.examples.browser.Browser",
                new String[] { config })
        };

When the service starter asks its Configuration for a property called 'serviceDescriptors',
the configuration will return an array containing a single instance of 
the 'NonActivatableServiceDescriptor' class, constructed using the parameters 'codebase', 
'policy', 'classpath', etc.  Where these parameters look like variables, the configuration 
uses the initializer that's found elsewhere in the configuration file.  For instance, the 'policy'
entry is declared to be the literal string "server.policy".

That browser configuration file is perhaps more interesting.  It contains the following:

    org.apache.river.examples.browser {

        serverExporter = new BasicJeriExporter(TcpServerEndpoint.getInstance(0),
                                         new BasicILFactory());

        serviceInvocationConstraints=InvocationConstraints.EMPTY;

        proxyPermissions = new Permission[] {
            new RuntimePermission("accessClassInPackage.com.sun.proxy"),
            new java.lang.reflect.ReflectPermission("newProxyInPackage.*")
        };

        servicePreparer = 
            new BasicProxyPreparer(false, new BasicMethodConstraints(serviceInvocationConstraints),
                proxyPermissions );

        leasePreparer = 
            new BasicProxyPreparer(false, new BasicMethodConstraints(serviceInvocationConstraints),
                proxyPermissions );
    }

We'll actually explore these files more when we talk about writing services and clients.
The browser example is a little out of scope.

The net result of the service starter configuration is to construct an instance of 
'org.apache.river.examples.browser.Browser' using the arguments 'browser.config', and run
it in a classloader that has the appropriate codebase annotation set on it.

OK, now we need to get some services running, so we can see them in the browser.  
That's described in 
[Infrastructure Services...](../infrastructure/infrastructure.html).
