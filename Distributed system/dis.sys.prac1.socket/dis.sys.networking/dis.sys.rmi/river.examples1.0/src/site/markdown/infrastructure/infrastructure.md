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

Infrastructure Services
=======================

A set of services and clients that are interoperating using Jini is called a
'workgroup' or sometimes a 'djinn'.

These services and clients need some basic infrastructure available to them.  There needs
to be a service registrar in order for clients to find services.  Clients may want to 
use a transaction manager.  They may want to use messaging intermediaries, and so on.

All these supporting functions are implemented by River's infrastructure services.
Because services are run by the service starter, we need to run the service starter with the 
list of infrastructure services that we want to run.

In some cases, we only want one instance of an infrastructure service to running in a 
workgroup.  For example, if we have a shared JavaSpaces implementation, we usually 
only want that running on one machine.

In other cases, we might want more than one instance.  The service registrar, for example,
should probably run on at least two machines in the work group, so that we don't have a 
single point of failure.

In any case, in order to show a simple client and service, we'll need a service registrar.
There's another configuration provided in the examples 'home' module, which we can run as below:

    java -Djava.security.manager -Djava.security.policy=server.policy -Djava.rmi.server.useCodebaseOnly=false -jar lib/start.jar start-infra.config

If you run this command line, and you still have your service browser open from the 
previous section, you should see a registrar appear in the browser, like so:

![Service Browser with a registrar](browser-with-registrar.png)

Click on the _Registrar_ menu and select the registrar that's shown.

![Select Registrar](select-registrar.png)

Now the service browser should show you all the services that are registered with
that registrar.  You should now see one service, which is the registrar itself.

![Service Browser showing registered services](browser-show-registrar.png)

Congratulations! You now have a working infrastructure for Jini/Reggie!

Next, let's [build a service](../hello-service/hello-service.html) that executes within this workgroup.  
