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

Apache River Examples
=====================

This project contains a set of examples that show how to use Apache River.

## Building the examples

The project uses Apache Maven to manage the dependencies and build the examples.
There is no need to download and build the main River distribution or tools;
the River artifacts are deployed to Maven Central, so Maven will automatically
download the binary artifacts as needed for the examples build.

You'll need Apache Maven installed.  See [Apache Maven](http://maven.apache.org).

To build the examples, simply unpack the source distribution of 'river-examples',
and then,

    cd river-examples
    mvn install
    mvn site

The first time you run the build, Maven will go out to Maven Central and
retrieve the River binary artifacts, storing them in your local Maven cache
(see Maven's documentation for more information).

## Service Browser

This is a utility that allows you to browse the services that are
operating in your workgroup, or 'djinn'.  Although it's presented as an example,
you'll find it to be a useful utility, as well.

The example illustrates a basic use of the ServiceStarter utility class to 
setup the environment for the browser to run in, including the installation of
a DynamicPolicyProvider and custom classloader.
 
[Read More...](browser/browser.html)

##Infrastructure Services

A set of services and clients that are interoperating using Jini is called a
'workgroup' or sometimes a 'djinn'.

These services and clients need some basic infrastructure available to them.  There needs
to be a service registrar in order for clients to find services.  Clients may want to 
use a transaction manager.  They may want to use messaging intermediaries, and so on.

All these supporting functions are implemented by River's infrastructure services.
Because services are run by the service starter,...

[Read More...](infrastructure/infrastructure.html)

##A Hello Service Example

OK, let's look at a service!

Actually, before we create a service, we need to create the 
Application Programming Interface...

[Read More...](hello-service/hello-service.html)

## The Hello Client

Finally, we are ready to code a service consumer, also known as a client.

[Read More...](hello-client/hello-client.html)

## The Hello Web App Client

Web applications running under Apache Tomcat or TomEE can access Jini services.

[Read More...](hello-webapp-client/hello-webapp-client.html)
