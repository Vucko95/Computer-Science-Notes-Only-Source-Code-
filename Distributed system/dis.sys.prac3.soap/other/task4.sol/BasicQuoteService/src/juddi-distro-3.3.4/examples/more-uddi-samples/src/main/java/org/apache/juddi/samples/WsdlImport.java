/*
 * Copyright 2001-2013 The Apache Software Foundation.
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
 *
 */
package org.apache.juddi.samples;

import java.net.URL;
import java.util.Map;
import java.util.Properties;
import java.util.Set;

import javax.wsdl.Definition;
import javax.wsdl.PortType;
import javax.xml.namespace.QName;

import org.apache.juddi.jaxb.PrintUDDI;
import org.apache.juddi.v3.client.config.UDDIClerk;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.apache.juddi.v3.client.config.UDDIClientContainer;
import org.apache.juddi.v3.client.mapping.URLLocalizerDefaultImpl;
import org.apache.juddi.v3.client.mapping.wsdl.ReadWSDL;
import org.apache.juddi.v3.client.mapping.wsdl.WSDL2UDDI;
import org.apache.juddi.v3.client.transport.Transport;
import org.apache.juddi.v3_service.JUDDIApiPortType;
import org.uddi.api_v3.AuthToken;
import org.uddi.api_v3.BusinessDetail;
import org.uddi.api_v3.BusinessEntity;
import org.uddi.api_v3.BusinessService;
import org.uddi.api_v3.BusinessServices;
import org.uddi.api_v3.GetAuthToken;
import org.uddi.api_v3.Name;
import org.uddi.api_v3.SaveBusiness;
import org.uddi.api_v3.SaveService;
import org.uddi.api_v3.SaveTModel;
import org.uddi.api_v3.TModel;
import org.uddi.v3_service.UDDIPublicationPortType;
import org.uddi.v3_service.UDDISecurityPortType;

/**
 * This class shows how to perform a WSDL2UDDI import manually. More
 * specifically, this is WSDL2UDDI without using annotations.
 *
 * @author <a href="mailto:alexoree@apache.org">Alex O'Ree</a>
 */
public class WsdlImport {

        static PrintUDDI<TModel> pTModel = new PrintUDDI<TModel>();
        static Properties properties = new Properties();
        static String wsdlURL = null;
        private static UDDISecurityPortType security = null;
        private static JUDDIApiPortType juddiApi = null;
        private static UDDIPublicationPortType publish = null;

        public static void main(String[] args) throws Exception {
                new WsdlImport().Fire("http://svn.apache.org/repos/asf/juddi/trunk/uddi-ws/src/main/resources/juddi_api_v1.wsdl", null, null, null);
        }

        public void Fire(String pathOrURL, String businessKey, String token, Transport transport) throws Exception {

                if (transport == null) {
                // create a manager and read the config in the archive; 
                        // you can use your config file name
                        UDDIClient clerkManager = new UDDIClient("META-INF/simple-publish-uddi.xml");
                        transport = clerkManager.getTransport();
                }
                // Now you create a reference to the UDDI API
                security = transport.getUDDISecurityService();
                publish = transport.getUDDIPublishService();

                if (token == null) {
                        //step one, get a token
                        GetAuthToken getAuthTokenRoot = new GetAuthToken();
                        getAuthTokenRoot.setUserID("uddi");
                        getAuthTokenRoot.setCred("uddi");

                        // Making API call that retrieves the authentication token for the 'root' user.
                        AuthToken rootAuthToken = security.getAuthToken(getAuthTokenRoot);
                        token = rootAuthToken.getAuthInfo();
                }

                //step two, identify the key used for all your stuff
                //you must have a key generator created already
                //here, we are assuming that you don't have one
                //NOTE: these are some of the publically available WSDLs that were used to test WSDL2UDDI
                //URL url = new URL("http://wsf.cdyne.com/WeatherWS/Weather.asmx?WSDL");
                //http://www.bccs.uni.no/~pve002/wsdls/ebi-mafft.wsdl");
                //http://www.webservicex.net/GenericNAICS.asmx?WSDL");
                //http://www.webservicex.net/stockquote.asmx?WSDL");
                //http://www.webservicex.com/globalweather.asmx?WSDL");
                //http://graphical.weather.gov/xml/SOAP_server/ndfdXMLserver.php?wsdl");
                String domain = "localhost";
                int port = 80;
                if (pathOrURL.startsWith("http")) {
                        URL url = new URL(pathOrURL);
                        domain = url.getHost();
                        port = url.getPort();
                        if (port == -1) {
                                if (pathOrURL.startsWith("https://")) {
                                        port = 443;
                                }
                                if (pathOrURL.startsWith("http://")) {
                                        port = 80;
                                }

                        }
                }

                TModel keygen = UDDIClerk.createKeyGenator("uddi:" + domain + ":keygenerator", domain, "en");
                //save the keygen
                SaveTModel stm = new SaveTModel();
                stm.setAuthInfo(token);
                stm.getTModel().add(keygen);
                System.out.println("Saving key gen " + keygen.getTModelKey());
                publish.saveTModel(stm);
                System.out.println("Saved!");

                //step three, we have two options
                //1) import the wsdl's services into a brand new business
                //2) import the wsdl's services into an existing business
                //in either case, we're going to have to parse the WSDL
                ReadWSDL rw = new ReadWSDL();
                Definition wsdlDefinition = null;
                if (pathOrURL.startsWith("http")) {
                        wsdlDefinition = rw.readWSDL(new URL(pathOrURL));
                } else {
                        wsdlDefinition = rw.readWSDL(pathOrURL);
                }

                if (wsdlDefinition == null) {
                        System.out.println("There was an error parsing the WSDL!");
                        return;
                }
                properties.put("keyDomain", domain);
                properties.put("businessName", domain);
                properties.put("serverName", domain);
                properties.put("serverPort", port);
                wsdlURL = wsdlDefinition.getDocumentBaseURI();
                WSDL2UDDI wsdl2UDDI = new WSDL2UDDI(null, new URLLocalizerDefaultImpl(), properties);
                BusinessServices businessServices = wsdl2UDDI.createBusinessServices(wsdlDefinition);
                @SuppressWarnings("unchecked")
                Map<QName, PortType> portTypes = (Map<QName, PortType>) wsdlDefinition.getAllPortTypes();
                Set<TModel> portTypeTModels = wsdl2UDDI.createWSDLPortTypeTModels(wsdlURL, portTypes);
                Map allBindings = wsdlDefinition.getAllBindings();
                Set<TModel> createWSDLBindingTModels = wsdl2UDDI.createWSDLBindingTModels(wsdlURL, allBindings);
        //When parsing a WSDL, there's really two things going on
                //1) convert a bunch of stuff (the portTypes) to tModels
                //2) convert the service definition to a BusinessService

                //Since the service depends on the tModel, we have to save the tModels first
                stm = new SaveTModel();
                stm.setAuthInfo(token);

                TModel[] tmodels = portTypeTModels.toArray(new TModel[0]);
                for (int i = 0; i < tmodels.length; i++) {
                        stm.getTModel().add(tmodels[i]);
                }

                tmodels = createWSDLBindingTModels.toArray(new TModel[0]);
                for (int i = 0; i < tmodels.length; i++) {
                        stm.getTModel().add(tmodels[i]);
                }

                //important, you'll need to save your new tModels first, or else saving the business/service may fail
                System.out.println(new PrintUDDI<SaveTModel>().print(stm));
                System.out.println("Saving " + stm.getTModel().size() + " tModels");
                publish.saveTModel(stm);
                System.out.println("Saved!");

                if (businessKey == null || businessKey.length() == 0) {
                        SaveBusiness sb = new SaveBusiness();
                        sb.setAuthInfo(token);
                        BusinessEntity be = new BusinessEntity();
                        be.setBusinessKey(businessServices.getBusinessService().get(0).getBusinessKey());
                        be.getName().add(new Name());
                        be.getName().get(0).setValue(domain);
                        be.getName().get(0).setLang("en");
                        sb.getBusinessEntity().add(be);
                        BusinessDetail saveBusiness = publish.saveBusiness(sb);
                        businessKey = saveBusiness.getBusinessEntity().get(0).getBusinessKey();
                        System.out.println("new business created key= " + businessKey);
                }

                //finaly, we're ready to save all of the services defined in the WSDL
                //again, we're creating a new business, if you have one already, look it up using the Inquiry getBusinessDetails
                SaveService ss = new SaveService();
                ss.setAuthInfo(token);
                for (int i = 0; i < businessServices.getBusinessService().size(); i++) {
                        businessServices.getBusinessService().get(i).setBusinessKey(businessKey);
                        ss.getBusinessService().add(businessServices.getBusinessService().get(i));

                }

                System.out.println("Here's our new service(s): " + new PrintUDDI<SaveService>().print(ss));

                publish.saveService(ss);
                System.out.println("Saved!");

                //and we're done
                //Be sure to report any problems to the jUDDI JIRA bug tracker at 
                //https://issues.apache.org/jira/browse/JUDDI
        }
}
