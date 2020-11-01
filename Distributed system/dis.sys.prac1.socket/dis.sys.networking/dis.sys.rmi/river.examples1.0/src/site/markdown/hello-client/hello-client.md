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

# The Hello Client

Finally, we are ready to code a service consumer, also known as a client.

To summarize, so far, we've done the following:

- Started a service browser so we can see what's on the network in our djinn.  
- Started up a service registrar.  
- Started up a "hello-world" service.  

By now, the pattern should be coming clear - we run Jini components inside a 
container that is setup by the "service starter" framework.  This container handles
the details of setting up the class loaders and the dynamic security policy provider.
We configure this container with a "start-xyz.config" file.  The component itself
loads up its configuration from a "xyz.config" file.

So let's finish it off by looking at the client.  The code part is in the module
"hello-client" inside the examples project.  The main code is in the class
"org.apache.river.examples.hello.client.App":

    public class App {

        private static final String MODULE=App.class.getPackage().getName();

        public App(final String[] args, LifeCycle lc) {
            main(args);
        }

        public static synchronized void main(String[] args) {
            try {
                // Get the config
                Configuration config = ConfigurationProvider.getInstance(args);
                // From the config, get the ServiceDiscoveryManager
                ServiceDiscoveryManager sdm=
                        (ServiceDiscoveryManager) 
                        config.getEntry(MODULE, "sdm", ServiceDiscoveryManager.class);
                // We'll also need a proxy preparer.
                ProxyPreparer preparer=(ProxyPreparer) config.getEntry(MODULE, 
                        "greeterPreparer", ProxyPreparer.class);
                // While the sdm is finding registrars, let's ask the user for their
                // name.
                Scanner in = new Scanner(System.in);
                System.out.println("Please enter your name:");
                String name = in.nextLine();
                // Query the sdm for Greeter services.
                ServiceTemplate template=new ServiceTemplate(
                        null,
                        new Class[] { Greeter.class },
                        new Entry[0]
                );
                ServiceItem[] serviceItems=sdm.lookup(template, 5, null);
                if (serviceItems.length==0) {
                    System.out.println("We didn't find any greeter services.");
                    System.exit(0);
                }
                // Pick a service item
                ServiceItem chosen=serviceItems[0];
                // Prepare the proxy.
                Greeter greeter=(Greeter) preparer.prepareProxy(chosen.service);
                // Make the call
                String message=greeter.sayHello(name);
                // Print the result
                System.out.println("Greeter replied '" + message + "'.");
            } catch (Exception ex) {
                ex.printStackTrace();
            } finally {
                System.exit(0);
            }
        }
    }

The only thing that looks a little funny is that we call the main(...) method
from the constructor.  This quirk is because of the way the ServiceStarter works, by 
instantiating the object.

Apart from that, we can see the usual pattern of getting a Configuration object based
on the command-line parameters, and pulling entries out of the configuration.  In this case,
the program shows the basic pattern for using a service:

1 - Get a ServiceDiscoveryManager from the configuration.  Inside the configuration, the
ServiceDiscoveryManager is configured to use a LookupDiscoveryManager to find all the service 
registrars that appear on the network.  
2 - Use the ServiceDiscoveryManager to look up the service itself.  Note that we lookup the
service by its interface, as defined in the API module.  
3 - Select a proxy (in this case, we simply use the first one we find), and prepare it
using a ProxyPreparer.  
4 - Invoke methods on the proxy, which in turn communicates with the real service.

The configuration for the client is as follows:

    org.apache.river.examples.hello.client {

        discoveryGroup="example-group";

        groups = new String[] {discoveryGroup};

        exporter = new BasicJeriExporter(TcpServerEndpoint.getInstance(0),
                                         new BasicILFactory());

        serviceInvocationConstraints=InvocationConstraints.EMPTY;

        basicPreparer = 
            new BasicProxyPreparer(false, new BasicMethodConstraints(serviceInvocationConstraints),
                new Permission[] { new RuntimePermission("accessClassInPackage.com.sun.proxy") } );

        static discoveryManager = 
            new LookupDiscovery( groups, this);

        greeterPreparer = basicPreparer;
        registrarPreparer = basicPreparer;

        static sdm = new ServiceDiscoveryManager(discoveryManager, null);

    }

And the 'starter' configuration is:

    com.sun.jini.start {

        private static policy = "server.policy";
        private static classpath = "lib${/}hello-api.jar:lib${/}hello-client.jar";
        private static config = "hello-client.config";
        private static codebase="";

        static serviceDescriptors = new ServiceDescriptor[] {
            new NonActivatableServiceDescriptor(
                codebase, policy, classpath,
                "org.apache.river.examples.hello.client.App",
                new String[] { config })
        };

    }//com.sun.jini.start

Finally, run the client:

    java -Djava.security.manager -Djava.security.policy=server.policy -Djava.rmi.server.useCodebaseOnly=false -jar lib/start.jar start-hello-client.config

The client will ask you to enter your name on the command line, and then call the
service's 'sayHello(..)' method, and print out the results.

![Running the client](Client-run.png)

Now, for extra points, copy the 'home' binary to another machine that has Java 
installed, and run the client.  You should see that it still works, with no real
configuration other than the name of the discovery group.

