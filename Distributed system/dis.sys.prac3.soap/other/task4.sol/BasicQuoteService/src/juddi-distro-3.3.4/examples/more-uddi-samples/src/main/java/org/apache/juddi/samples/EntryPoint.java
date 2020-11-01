/*
 * Copyright 2014 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.apache.juddi.samples;

import java.io.File;
import java.util.List;
import org.apache.juddi.api_v3.Node;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.apache.juddi.v3.client.config.UDDINode;
import org.apache.juddi.v3.client.transport.Transport;
import org.uddi.api_v3.DiscardAuthToken;
import org.uddi.api_v3.GetAuthToken;
import org.uddi.v3_service.UDDISecurityPortType;

/**
 *
 * @author Alex O'Ree
 */
public class EntryPoint {

        public static void main(String[] args) throws Exception {

                if (System.getProperty("javax.net.ssl.trustStore") == null) {
                        File f = new File("../../juddi-tomcat/truststore.jks");
                        if (f.exists()) {
                                System.setProperty("javax.net.ssl.trustStore", f.getAbsolutePath());

                        } else {
                                f = new File("../juddi-tomcat/truststore.jks");
                                if (f.exists()) {
                                        System.setProperty("javax.net.ssl.trustStore", f.getAbsolutePath());

                                } else {
                                        f = new File("./juddi-tomcat/truststore.jks");
                                        if (f.exists()) {
                                                System.setProperty("javax.net.ssl.trustStore", f.getAbsolutePath());

                                        }
                                }
                        }

                        System.setProperty("javax.net.ssl.trustStorePassword", "password");
                        //System.setProperty("javax.net.ssl.keyStore", "keystore.jks");

                        //System.setProperty("javax.net.ssl.keyStorePassword", "changeit");
                }
                //set up trust store

                String trustStore = System.getProperty("javax.net.ssl.trustStore");
                if (trustStore == null) {
                        System.out.println("javax.net.ssl.trustStore is not defined");
                } else {
                        System.out.println("javax.net.ssl.trustStore = " + trustStore);
                }
                
                
                if (System.getProperty("javax.net.ssl.keyStore") == null) {
                        File f = new File("../../juddi-tomcat/keystore.jks");
                        if (f.exists()) {
                                System.setProperty("javax.net.ssl.keyStore", f.getAbsolutePath());

                        } else {
                                f = new File("../juddi-tomcat/keyStore.jks");
                                if (f.exists()) {
                                        System.setProperty("javax.net.ssl.keyStore", f.getAbsolutePath());

                                } else {
                                        f = new File("./juddi-tomcat/keystore.jks");
                                        if (f.exists()) {
                                                System.setProperty("javax.net.ssl.keyStore", f.getAbsolutePath());

                                        }
                                }
                        }

                        System.setProperty("javax.net.ssl.keyStorePassword", "password");
                        //System.setProperty("javax.net.ssl.keyStore", "keystore.jks");

                        //System.setProperty("javax.net.ssl.keyStorePassword", "changeit");
                }
                //set up trust store

                String keyStore = System.getProperty("javax.net.ssl.trustStore");
                if (keyStore == null) {
                        System.out.println("javax.net.ssl.keyStore is not defined");
                } else {
                        System.out.println("javax.net.ssl.keyStore = " + trustStore);
                }
                //first menu
                //connect to a node and do work on it
                //multinode 
                String input = null;
                do {
                        System.out.println("____________________________");
                        System.out.println("jUDDI Interactive Command Line Interface");
                        System.out.println("____________________________");
                        System.out.println(" 1) Connect and login to a Node");
                        System.out.println(" 2) Multinode and Replication commands");
                        System.out.println(" 3) Offline code examples");
                        System.out.println(" q) Quit/exit");
                        System.out.print("jUDDI Main# ");
                        input = System.console().readLine();
                        if ("1".equals(input)) {
                                goSingleNode();
                        } else if ("2".equals(input)) {
                                goMultiNode();
                        } else if ("3".equals(input)) {
                                goOfflineExamples();
                        }
                } while (!"q".equalsIgnoreCase(input));
        }

        static void goMultiNode() throws Exception {
                EntryPoitMultiNode.goMultiNode();
        }

        static void goSingleNode() throws Exception {
                EntryPointSingleNode.goSingleNode();

        }

        private static void goOfflineExamples() throws Exception {
                String input = null;
                do {
                        System.out.println("____________________________");
                        System.out.println("Offline/Code Examples (you'll want to look at the source for some of these");
                        System.out.println("____________________________");
                        System.out.println(" 1) Compare Two Binding/tModelInstanceInfo - QOS Code Example");
                        System.out.println("2) Digitally sign a UDDI entity from a file.");
                        System.out.println(" q) Quit/exit");
                        System.out.print("#");
                        input=System.console().readLine();
                        processOffline(input);
                } while (!"q".equalsIgnoreCase(input));

        }

        private static void processOffline(String input) throws Exception {
                if (input.equals("1")) {
                        CompareByTModelInstanceInfoQOS.main(null);
                }
                if (input.equals("2")) {
                        new UddiDigitalSignatureFile().Fire(null, null, null);
                }
        }

}
