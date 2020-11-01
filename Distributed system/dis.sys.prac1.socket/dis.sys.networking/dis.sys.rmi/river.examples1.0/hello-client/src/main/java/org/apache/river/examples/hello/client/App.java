/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.apache.river.examples.hello.client;

import com.sun.jini.start.LifeCycle;
import java.util.Scanner;
import net.jini.config.Configuration;
import net.jini.config.ConfigurationProvider;
import net.jini.core.entry.Entry;
import net.jini.core.lookup.ServiceItem;
import net.jini.core.lookup.ServiceTemplate;
import net.jini.lookup.ServiceDiscoveryManager;
import net.jini.security.ProxyPreparer;
import org.apache.river.examples.hello.api.Greeter;

/**
 * Hello world using a client to the Greeter service.
 * 
 * Note: This code is part of a comprehensive tutorial - Be sure to have a look
 * at the 'README.md' file in the root of the parent 'river-examples' project
 * for instructions on how to build and view the complete tutorial.
 * 
 *
 */
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
