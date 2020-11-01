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
package org.apache.river.examples.hello.service;

import com.sun.jini.config.Config;
import com.sun.jini.start.LifeCycle;
import java.io.IOException;
import java.rmi.server.ExportException;
import net.jini.config.Configuration;
import net.jini.config.ConfigurationException;
import net.jini.config.ConfigurationProvider;
import net.jini.core.entry.Entry;
import net.jini.core.lookup.ServiceID;
import net.jini.discovery.DiscoveryManagement;
import net.jini.export.Exporter;
import net.jini.lookup.JoinManager;
import net.jini.lookup.ServiceIDListener;
import net.jini.security.ProxyPreparer;
import org.apache.river.examples.hello.api.Greeter;

/**
 *
 * Implementation of the Greeter interface, suitable for starting under the
 * ServiceStarter framework.
 * 
 * Note: This code is part of a comprehensive tutorial - Be sure to have a look
 * at the 'README.md' file in the root of the parent 'river-examples' project
 * for instructions on how to build and view the complete tutorial.
 * 
 */

public class GreeterService implements Greeter, ServiceIDListener {

    private static final String GREETER = "org.apache.river.examples.hello.greeter";

    Configuration config = null;
    Greeter myProxy = null;
    Exporter exporter = null;
    ProxyPreparer registrarPreparer = null;
    JoinManager joinManager = null;
    DiscoveryManagement discoveryManager = null;
    Entry[] attributes = null;

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
        discoveryManager = (DiscoveryManagement) config.getEntry(GREETER, "discoveryManager", DiscoveryManagement.class);
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

    ServiceID sid = null;

    public void serviceIDNotify(ServiceID sid) {
        this.sid = sid;
        System.out.println("Hello service was assigned service id of " + sid);
    }

}
