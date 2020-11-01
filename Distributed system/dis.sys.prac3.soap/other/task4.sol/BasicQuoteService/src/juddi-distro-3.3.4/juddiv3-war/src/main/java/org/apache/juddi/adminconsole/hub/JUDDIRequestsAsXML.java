/*
 * Copyright 2013 The Apache Software Foundation.
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
package org.apache.juddi.adminconsole.hub;

import java.io.StringReader;
import java.io.StringWriter;
import java.util.GregorianCalendar;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.xml.bind.JAXB;
import javax.xml.datatype.DatatypeConfigurationException;
import javax.xml.datatype.DatatypeFactory;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.stream.StreamSource;
import org.apache.commons.configuration.ConfigurationException;
import org.apache.juddi.api_v3.AdminSaveBusiness;
import org.apache.juddi.api_v3.AdminSaveBusinessWrapper;
import org.apache.juddi.api_v3.AdminSaveSubscriptionRequest;
import org.apache.juddi.api_v3.AdminSaveTModel;
import org.apache.juddi.api_v3.AdminSaveTModelWrapper;
import org.apache.juddi.api_v3.Clerk;
import org.apache.juddi.api_v3.ClientSubscriptionInfo;
import org.apache.juddi.api_v3.SaveClientSubscriptionInfo;
import org.apache.juddi.api_v3.SyncSubscription;
import org.apache.juddi.config.AppConfig;
import org.apache.juddi.config.Property;
import org.apache.juddi.v3.client.UDDIConstants;
import org.uddi.api_v3.BusinessEntity;
import org.uddi.api_v3.Contact;
import org.uddi.api_v3.FindBusiness;
import org.uddi.api_v3.FindQualifiers;
import org.uddi.api_v3.Name;
import org.uddi.api_v3.PersonName;
import org.uddi.api_v3.TModel;
import org.uddi.repl_v3.CommunicationGraph;
import org.uddi.repl_v3.Operator;
import org.uddi.repl_v3.OperatorStatusType;
import org.uddi.repl_v3.ReplicationConfiguration;
import org.uddi.sub_v3.CoveragePeriod;
import org.uddi.sub_v3.GetSubscriptionResults;
import org.uddi.sub_v3.Subscription;
import org.uddi.sub_v3.SubscriptionFilter;

/**
 * This class generates XML as String objects for UDDI requests. This is used
 * from the "advanced" web pages
 *
 * @author <a href="mailto:alexoree@apache.org">Alex O'Ree</a>
 */
public class JUDDIRequestsAsXML {

        private static String PrettyPrintXML(String input) {
                if (input == null || input.length() == 0) {
                        return "";
                }
                try {
                        Transformer transformer = TransformerFactory.newInstance().newTransformer();
                        transformer.setOutputProperty(OutputKeys.INDENT, "yes");
                        transformer.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION, "yes");
                        //initialize StreamResult with File object to save to file
                        StreamResult result = new StreamResult(new StringWriter());
                        StreamSource source = new StreamSource(new StringReader(input.trim()));
                        transformer.transform(source, result);
                        String xmlString = result.getWriter().toString();
                        return (xmlString);
                } catch (Exception ex) {
                }
                return null;
        }

        public static String getSampleXML(String method) {
                StringWriter sw = new StringWriter();

                if (method.equalsIgnoreCase("save_ClientSubscriptionInfo")) {
                        SaveClientSubscriptionInfo obj = new SaveClientSubscriptionInfo();
                        obj.getClientSubscriptionInfo().add(new ClientSubscriptionInfo());
                        obj.getClientSubscriptionInfo().get(0).setFromClerk(new Clerk());
                        obj.getClientSubscriptionInfo().get(0).setToClerk(new Clerk());
                        obj.getClientSubscriptionInfo().get(0).setSubscriptionKey("key");

                        JAXB.marshal(obj, sw);
                }
                if (method.equalsIgnoreCase("invoke_SyncSubscription")) {
                        SyncSubscription obj = new SyncSubscription();
                        obj.getGetSubscriptionResultsList().add(new GetSubscriptionResults());
                        obj.getGetSubscriptionResultsList().get(0).setSubscriptionKey("key");
                        obj.getGetSubscriptionResultsList().get(0).setCoveragePeriod(new CoveragePeriod());
                        DatatypeFactory newInstance;
                        try {
                                newInstance = DatatypeFactory.newInstance();
                                obj.getGetSubscriptionResultsList().get(0).getCoveragePeriod().setEndPoint(newInstance.newXMLGregorianCalendar(new GregorianCalendar()));
                                obj.getGetSubscriptionResultsList().get(0).getCoveragePeriod().setStartPoint(newInstance.newXMLGregorianCalendar(new GregorianCalendar()));

                        } catch (DatatypeConfigurationException ex) {
                                Logger.getLogger(JUDDIRequestsAsXML.class.getName()).log(Level.SEVERE, null, ex);
                        }
                        JAXB.marshal(obj, sw);
                }
                if (method.equalsIgnoreCase("admin_SaveBusiness")) {
                        AdminSaveBusiness obj = new AdminSaveBusiness();
                        obj.getValues().add(new AdminSaveBusinessWrapper());
                        obj.getValues().get(0).setPublisherID("username");
                        obj.getValues().get(0).getBusinessEntity().add(new BusinessEntity());
                        obj.getValues().get(0).getBusinessEntity().get(0).getName().add(new Name("Business Name", "en"));
                        JAXB.marshal(obj, sw);
                }
                if (method.equalsIgnoreCase("admin_SaveTModel")) {
                        AdminSaveTModel obj = new AdminSaveTModel();
                        obj.getValues().add(new AdminSaveTModelWrapper());
                        obj.getValues().get(0).setPublisherID("username");
                        obj.getValues().get(0).getTModel().add(new TModel());
                        obj.getValues().get(0).getTModel().get(0).setName(new Name("TModel Name", "en"));
                        JAXB.marshal(obj, sw);
                }

                if (method.equalsIgnoreCase("admin_SaveSubscription")) {
                        AdminSaveSubscriptionRequest obj = new AdminSaveSubscriptionRequest();
                        obj.setPublisherOrUsername("username");
                        obj.getSubscriptions().add(new Subscription());
                        obj.getSubscriptions().get(0).setSubscriptionFilter(new SubscriptionFilter());
                        obj.getSubscriptions().get(0).setBrief(Boolean.TRUE);
                        obj.getSubscriptions().get(0).getSubscriptionFilter().setFindBusiness(new FindBusiness());
                        obj.getSubscriptions().get(0).getSubscriptionFilter().getFindBusiness().getName().add(new Name(UDDIConstants.WILDCARD, null));
                        obj.getSubscriptions().get(0).getSubscriptionFilter().getFindBusiness().setFindQualifiers(new FindQualifiers());
                        obj.getSubscriptions().get(0).getSubscriptionFilter().getFindBusiness().getFindQualifiers().getFindQualifier().add(UDDIConstants.APPROXIMATE_MATCH);
                        obj.getSubscriptions().get(0).getSubscriptionFilter().getFindBusiness().getFindQualifiers().getFindQualifier().add(UDDIConstants.CASE_INSENSITIVE_MATCH);
                        //obj.getSubscriptions().get(0).getSubscriptionFilter().getFindBusiness()
                        JAXB.marshal(obj, sw);
                }

                if (method.equalsIgnoreCase("set_ReplicationNodes")) {
                        ReplicationConfiguration replicationConfiguration = new ReplicationConfiguration();
                        replicationConfiguration.setCommunicationGraph(new CommunicationGraph());
                        String thisnode = "NODEID";
                        try {
                                thisnode = AppConfig.getConfiguration().getString(Property.JUDDI_NODE_ID);
                        } catch (ConfigurationException ex) {
                                Logger.getLogger(JUDDIRequestsAsXML.class.getName()).log(Level.SEVERE, null, ex);
                        }

                        replicationConfiguration.getCommunicationGraph().getNode().add(thisnode);
                        Operator op = new Operator();
                        op.setOperatorNodeID(thisnode);

                        op.setOperatorStatus(OperatorStatusType.NORMAL);
                        String url = "https://localhost:8443/juddiv3replication/services/replication";
                        try {
                                url = AppConfig.getConfiguration().getString(Property.JUDDI_BASE_URL_SECURE) + "replication/services/replication";
                        } catch (ConfigurationException ex) {
                                Logger.getLogger(JUDDIRequestsAsXML.class.getName()).log(Level.SEVERE, null, ex);
                        }
                        op.setSoapReplicationURL(url);

                        replicationConfiguration.getOperator().add(op);
                        replicationConfiguration.setRegistryContact(new ReplicationConfiguration.RegistryContact());
                        replicationConfiguration.getRegistryContact().setContact(new Contact());
                        replicationConfiguration.getRegistryContact().getContact().getPersonName().add(new PersonName("UNKNOWN", "en"));

                        JAXB.marshal(replicationConfiguration, sw);
                }

                return PrettyPrintXML(sw.toString());
        }

        public static Object getObjectJuddi(String method, String content) {
                StringReader sr = new StringReader(content);

                if (method.equalsIgnoreCase("save_ClientSubscriptionInfo")) {
                        return JAXB.unmarshal(sr, SaveClientSubscriptionInfo.class);
                }
                if (method.equalsIgnoreCase("invoke_SyncSubscription")) {
                        return JAXB.unmarshal(sr, SyncSubscription.class);
                }
                if (method.equalsIgnoreCase("admin_SaveBusiness")) {
                        return JAXB.unmarshal(sr, AdminSaveBusiness.class);
                }
                if (method.equalsIgnoreCase("admin_SaveTModel")) {
                        //System.out.println(content);
                        return JAXB.unmarshal(sr, AdminSaveTModel.class);
                }

                if (method.equalsIgnoreCase("admin_SaveSubscription")) {
                        return JAXB.unmarshal(sr, AdminSaveSubscriptionRequest.class);
                }

                if (method.equalsIgnoreCase("set_ReplicationNodes")) {
                        return JAXB.unmarshal(sr, ReplicationConfiguration.class);
                }

                return null;
        }

}
