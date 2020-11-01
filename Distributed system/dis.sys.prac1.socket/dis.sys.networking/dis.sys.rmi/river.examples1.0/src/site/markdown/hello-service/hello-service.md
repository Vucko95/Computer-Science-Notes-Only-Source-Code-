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

A Hello Service Example
=================

OK, let's look at a service!

##The API

Actually, before we create a service, we need to create the Application 
Programming Interface (API) for a service.  We do that in a separate Maven module,
so that the api will be contained in its own artifact.  Then later on, we can 
refer to that artifact in both the service implementation and the client implementation.

That way, the service and client both have a dependency on the API, but the client does
not have any dependency on the service implementation.

So, if you have a look at the 'hello-api' module of the examples project, you'll see the 
following interface defined:

    public interface Greeter extends Remote {
        /**
         * Say 'Hello' to the client with the name provided.
         * @param name The name of the client.
         * @return a greeting message.
         * @throws IOException 
         */
        public String sayHello(String name) throws IOException;
    }

Notice a couple things about this interface:  

First, it extends 'java.rmi.Remote'.
This is typical of interfaces that will be exported as remote services, like this one.
'Remote' is called a 'tag' interface, similar to 'java.io.Serializable'.  It doesn't specify
any methods; the simple fact that an object implements the interface conveys a message to someone.
When we eventually instantiate a service object and pass it into the JERI Exporter, the
exporter creates a serializable proxy that implements all the interfaces that extend 'Remote'.  
That proxy is what we'll eventually register with the lookup service.

More importantly, the Remote interface tells a potential user of the interface that the
implementation is likely to be accessed remotely over a network connection.  As such, the
consumer of a 'Remote' interface knows that she has to allow for network latency, 
temporary failures, call-by-value semantics, and all the other things that go with using a
remote service ([A Note on Distributed Computing](eecs.harvard.edu/~waldo/Readings/waldo-94.pdf)
provides some interesting background reading).

Second, the methods that the interface specifies throw 'java.io.IOException'.  Again, this
is to reflect the fact the consumer of this interface should expect to deal with 
communication-related exceptions, since the interface is likely implemented using remote
calls.

## The Service Class

OK, now that we have an API, we can implement it.  This implementation is contained in the
module called 'hello-service', specifically in the
 'org.apache.river.examples.hello.service.GreeterService' class.  Let's have a look at that
class:

    public class GreeterService implements Greeter, ServiceIDListener {
        private static final String GREETER="org.apache.river.container.examples.greeter";

        Configuration config=null;
        Greeter myProxy=null;
        Exporter exporter=null;
        ProxyPreparer registrarPreparer=null;
        JoinManager joinManager=null;
        DiscoveryManagement discoveryManager=null;
        Entry[] attributes=null;

        public GreeterService(String[] args, final LifeCycle lc)
                throws ConfigurationException, ExportException, IOException {
            config = ConfigurationProvider.getInstance(args);

            // Get the exporter and create our proxy.
            exporter = (Exporter) Config.getNonNullEntry(config, GREETER, "exporter", Exporter.class);
            myProxy = (Greeter) exporter.export(this);

            /* 
             The "discovery manager" looks after finding one or more service 
             registrars for the join manager to use.
             */
            discoveryManager
                    = (DiscoveryManagement) config.getEntry(GREETER, "discoveryManager",
                            DiscoveryManagement.class);
            attributes = (Entry[]) config.getEntry(GREETER, "attributes", Entry[].class);

            /*
             Publish it using the join manager.
             The "join manager" takes care of registering our service with any/all 
             service registrars that appear in the workgroup.

             We don't have to do anything with it - just creating it starts the join process.
             */
            joinManager = new JoinManager(myProxy, attributes, this, discoveryManager, null, config);
            System.out.println("Hello service has been started successfully.");
        }

        public String sayHello(String name) throws IOException {
            return "Hi there " + name;

        }

        ServiceID sid=null;

        public void serviceIDNotify(ServiceID sid) {
            this.sid=sid;
        }
    }

This class is written to conform to the "Service-Starter" conventions: primarily, its setup and
startup is done in the constructor.  When we configure the Service Starter to start this service,
it will create an instance of the service, supplying a set of arguments and a "LifeCycle" object.

The arguments are supplied in the configuration for the service starter; they are essentially 
(and usually) the command line arguments that might have been supplied to the service.

We should probably note that this is kind of an odd way to start a service, and potentially could
induce concurrency issues under the modern Java Memory Model (tl;dr - don't use final variables in
your service).  It's a bit of a historical relic from the days when a Jini service would be a 
standalone Java process, and you'd normally have a `main(...)` method in the service implementation.
The River community has been discussing a new startup API for a while now.

Anyhow, the constructor
uses a `Configuration` object to retrieve entries from an editable file, much the same
as we've talked about for the Service Starter and the browser.

The basic scenario of establishing a service is as follows:

- Create an instance of the service.  The service starter is doing this, which 
is why we're adding code inside the constructor.  
- Use an "exporter" to make the service instance available over a remote communications
mechanism.  The exporter is defined in the configuration file; different classes of 
exporters make the service available over different communications mechanisms.  In the
configuration of this example service, we're using a "JERI" (Java Extensible Remote
Invocation) exporter on top of a plain TCP socket endpoint.  
- Establish a "discovery manager" to find all the service registrars that exist in the 
workgroup, or might start up later.  Again, this helper is defined in the configuration file.  
- Establish a "join manager" that looks after the on-going task of registering our proxy
with whatever service registrars are found by the discovery manager.  You guessed it - it's 
defined in the configuration file.

As you can see, most of the real work of setting up the application's object graph
is done in the service configuration file.  The service's constructor retrieves the 
configuration using the following code:

    config = ConfigurationProvider.getInstance(args);

The arguments do two things: first, they include the name of the configuration file.
Potentially, the arguments could also include overrides to the configuration file's settings.
In this case, we're using the arguments that were passed in to the service class's 
constructor, which means that they are actually set in the service starter's configuration file,
"start-hello-service.config".  If you look that up, you'll find that the service's configuration
file is "hello-service.config".

Let's take a look at "hello-service.config":

    org.apache.river.examples.hello.greeter {
        discoveryGroup="example-group";

        groups = new String[] {discoveryGroup};

        exporter = new BasicJeriExporter(TcpServerEndpoint.getInstance(0),
                                         new BasicILFactory());

        serviceInvocationConstraints=InvocationConstraints.EMPTY;

        registrarPermissions= new Permission[] { 
            new RuntimePermission("accessClassInPackage.com.sun.proxy"),
            new ReflectPermission("newProxyInPackage.com.sun.jini.reggie")
        };

        registrarPreparer = 
            new BasicProxyPreparer(false, new BasicMethodConstraints(serviceInvocationConstraints),
                registrarPermissions );

        static discoveryManager = 
            new LookupDiscovery( groups, this);

        static attributes = new Entry[] { new Name("greeter-service") };

    }

    net.jini.lookup.JoinManager {
        registrarPreparer = org.apache.river.examples.hello.greeter.registrarPreparer;
        registrationPreparer = org.apache.river.examples.hello.greeter.registrarPreparer;

    }

We haven't shown the import statements here - like Java import statements, they define
the fully qualified class names for classes that we'd like to use by their short names 
in the configuration.

This file uses a syntax that is reminiscent of Java, but isn't Java.  It's a declarative syntax.
The configuration file is not executed in any particular order - it's simply a set of definitions
that tell a "Configuration" instance how to create an object that a program might ask for.
These definitions look like variable initializations in the configuration file.  A declaration can also
reference other declarations.  So the line,

        exporter = new BasicJeriExporter(TcpServerEndpoint.getInstance(0),
                                         new BasicILFactory());

tells the configuration instance that if someone asks for an entry called "exporter", it should
create an instance of "BasicJeriExporter" using the results of "TcpServerEndpoint.getInstance(0)"
and "new BasicILFactory()" as the constructor parameters.  What this actually does is create an exporter 
that creates a JERI proxy that makes a service available on a plain TCP socket on a randomly-assigned port.

"Hold on," you might be thinking, "if my service is on a randomly-assigned port, how is the 
service consumer going to know what port to open?  Don't I need to configure that?"

No, you don't need to configure that, unless you want to (maybe in the case of firewall issues).
In Jini/River, the service consumer is not going to make contact directly with the service.  What it's going to do 
is find a service registrar, and retrieve a serialized proxy object from the registrar.  The proxy knows how and where to 
contact the real service provider.  Even if you choose a specific port, it's still the
provider's problem.  The service consumer simply makes calls on the proxy that was registered
with the registrar, so the consumer doesn't need to be configured for the port.  The configuration is
implicitly retrieved when the consumer gets the proxy from the registrar.

One other thing that's worth pointing out in the configuration is the following set of entries:

    registrarPermissions= new Permission[] { 
        new RuntimePermission("accessClassInPackage.com.sun.proxy"),
        new ReflectPermission("newProxyInPackage.com.sun.jini.reggie")
    };

    registrarPreparer = 
        new BasicProxyPreparer(false, new BasicMethodConstraints(serviceInvocationConstraints),
            registrarPermissions );

Retrieving a proxy is sort of like inviting a guest into your house.  You might not want to 
give them free run of the place (you don't want the cable guy raiding your fridge, for instance).
In Jini, we have the concept of "Proxy Preparation".  Anytime we get a proxy from the registrar 
or anywhere else, we hand it to a "Proxy Preparer" object, that typically gives it the once-over
to see if it meets our requirements, and then allows it "into the house", by granting permissions to it.
So, in the configuration above, we are creating a proxy preparer that checks the proxy against any
constraints that we want to impose (in this case the constraints are empty, but they could be 
things like "needs encryption", or "needs message integrity"), and then grants the Java security
permissions that the proxy will need to do it's job.

##Starting the Service

We're going to use the Service Starter again.  Here's the configuration for it:

    com.sun.jini.start {

        private static policy = "server.policy";
        private static classpath = "lib${/}hello-api.jar:lib${/}hello-service.jar";
        private static config = "hello-service.config";
        port="8090";
        private static codebasePrefix= "http://" + ConfigUtil.getHostAddress() 
            + ":" + port + "/";
        private static codebase = codebasePrefix + "hello-api.jar";

        static serviceDescriptors = new ServiceDescriptor[] {
            new NonActivatableServiceDescriptor(
                "",
                policy,
                "lib/tools.jar",
                "com.sun.jini.tool.ClassServer",
                new String[]{"-port", port, "-dir",
                    "lib-dl"}),
            new NonActivatableServiceDescriptor(
                codebase, policy, classpath,
                "org.apache.river.examples.hello.service.GreeterService",
                new String[] { config })
        };

    }//com.sun.jini.start

Note that this configuration starts up the service provider as well as a 
"ClassServer".  Remote Method Invocation requires that the bytecode for any
marshalled objects is available for download.  The class server makes that available.

In this case, as a practical matter, the service is exporting a dynamically-created
proxy, so strictly-speaking, no code download is required at the client side. 
However, we would like the service to appear in the service browser, and for that to happen, the
service browser will need to be able to download the "hello-api" jar file (the client will
generally have this jar file in its local classpath, so it won't need to download it).
As such, we are setting up a class server for the service.

With all that said, we can start the service. First navigate to the directory 
that's built by the 'home' module:

    cd ${river-examples-home}/home/target/home-${version}-bin

and then execute the service-starter with the required configuration file:

    java -Djava.security.manager -Djava.security.policy=server.policy -Djava.rmi.server.useCodebaseOnly=false -jar lib/start.jar start-hello-service.config

You should see the service start up:  
![Hello service start-up](hello-service-cmd.png)

And, if you still have the browser running from earlier, your new service should appear
in the browser.

![Hello service in the browser](hello-svc-in-browser.png)

You may notice something interesting if you happen to stop the service by hitting ctrl-C, and
then restart it.  You will appear to get duplicate services in the browser.

![Duplicate Hello services](duplicate-hello-services.png)

They will even appear to "work", i.e. you'll be able to see their info and browse them.
But, you're really just looking at the registration info that the service registered with the 
service registrar before it was stopped.  Neither Reggie nor the browser make any
attempt to contact the actual service.

If you wait a little while, you'll notice something else interesting - the duplicate 
services will disappear on their own.

Here's what's happening:

When the service registers itself with Reggie, it takes out a lease on the registration. 
That lease is usually renewed periodically by the service’s JoinManager (that 
isn’t quite the whole story, but it’ll do for now).  When you kill the service 
unexpectedly with ctrl-c, the service doesn’t de-register itself, however the 
lease eventually runs out (now that it’s not being renewed by the service) and 
then the registration expires, allowing Reggie to reclaim its resources and 
notify any registrar listeners. 

It would be possible to register a vm shutdown hook to de-register the service 
before the vm exits, but that's left out of this example, so as to demonstrate 
that a dead  service (or at least a dead 
JoinManager) eventually gets dropped from the registrar.

The duplicate service instances appear to “work”, in that you can show info and 
browse the service, but of course, you’re really just looking at the information 
that’s in the registry - the registrar and service browser don’t actually contact 
the service.  Reggie has no knowledge of the “liveness” of the service, and 
doesn’t attempt to do any sort of “health check”.  

In fact, it’s a common misconception that if the service renews the lease, it must 
be “live”.  This idea turns out to be false for many reasons. Some of those reasons are:
(1) The service could 
have delegated its lease renewals to a different service.  (2) There’s no guarantee 
that failure of the actual service thread would also cause failure of the lease 
renewal thread, even if they are in the same process (embedded programmers might 
recognize this as being similar to the “resetting the watchdog in a timer-triggered 
interrupt service routine” problem).  (3) Even if there were a health check 
task, the service could fail in the instant just after the health check.  The 
most a health check, monitor or heartbeat can do is place a limit on how long it 
takes to find out a service has failed.  The only way to say with certainty 
that a service “works” is to attempt to use it.

The lease is purely for the convenience of the registrar (or generically, the 
service granting the lease).  If ever the lease is not renewed, the landlord 
can go ahead and reclaim whatever resources were dedicated to the lease.  In 
the case of Reggie, if the lease isn’t renewed, Reggie drops the registration.  
So there’s little risk of “stuck registrations”.  And since the lease can be 
renewed, there’s no need for any kind of extended default timeout.

Next, we'll need a [client](../hello-client/hello-client.html).

