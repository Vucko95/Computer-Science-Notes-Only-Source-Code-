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

import java.io.File;
import java.net.URL;
import java.util.List;
import java.util.Properties;
import java.util.Set;

import javax.xml.namespace.QName;

import org.apache.juddi.jaxb.PrintUDDI;
import org.apache.juddi.v3.client.config.UDDIClerk;
import org.apache.juddi.v3.client.config.UDDIClient;
import org.apache.juddi.v3.client.config.UDDIClientContainer;
import org.apache.juddi.v3.client.mapping.URLLocalizerDefaultImpl;
import org.apache.juddi.v3.client.mapping.wadl.Application;
import org.apache.juddi.v3.client.mapping.wadl.WADL2UDDI;
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
public class WadlImport {

        static PrintUDDI<TModel> pTModel = new PrintUDDI<TModel>();
        static Properties properties = new Properties();

        private static UDDISecurityPortType security = null;
        private static JUDDIApiPortType juddiApi = null;
        private static UDDIPublicationPortType publish = null;

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
                //publish.saveTModel(stm);
                //step three, we have two options
                //1) import the wsdl's services into a brand new business
                //2) import the wsdl's services into an existing business
                //in either case, we're going to have to parse the WSDL
                //Application app = WADL2UDDI.parseWadl(new URL("http://server/wsdl.wsdl"), "username", "password", clerkManager.getClientConfig().isX_To_Wsdl_Ignore_SSL_Errors() );
                Application app = null;
                if (!pathOrURL.startsWith("http")) {
                        File f = new File("test.wadl");
                        if (!f.exists()) {
                                System.out.println(pathOrURL + " doesn't exist!");
                                return;
                        } else {
                                System.out.println("Attempting to parse " + f.getAbsolutePath());
                                app = WADL2UDDI.parseWadl(f);
                        }
                } else {
                        app = WADL2UDDI.parseWadl(new URL(pathOrURL));
                }

                List<URL> urls = WADL2UDDI.getBaseAddresses(app);
                URL url = urls.get(0);
                String domain = url.getHost();
                PrintUDDI<TModel> tmodelPrinter = new PrintUDDI<TModel>();
                TModel keygen = UDDIClerk.createKeyGenator("uddi:" + domain + ":keygenerator", domain, "en");

                //save the keygen
                SaveTModel stm = new SaveTModel();
                stm.setAuthInfo(token);
                stm.getTModel().add(keygen);
                System.out.println("Saving the following tModel keygen");
                System.out.println(tmodelPrinter.print(keygen));
                publish.saveTModel(stm);

                properties.put("keyDomain", domain);
                properties.put("businessName", domain);
                properties.put("serverName", url.getHost());
                properties.put("serverPort", url.getPort());
                //wsdlURL = wsdlDefinition.getDocumentBaseURI();
                WADL2UDDI wadl2UDDI = new WADL2UDDI(null, new URLLocalizerDefaultImpl(), properties);

                BusinessService businessServices = wadl2UDDI.createBusinessService(new QName(domain, domain), app);

                Set<TModel> portTypeTModels = wadl2UDDI.createWADLPortTypeTModels(pathOrURL, app);

                // Set<TModel> createWSDLBindingTModels = wadl2UDDI.createWSDLBindingTModels(wsdlURL, allBindings);
                //When parsing a WSDL, there's really two things going on
                //1) convert a bunch of stuff (the portTypes) to tModels
                //2) convert the service definition to a BusinessService
                //Since the service depends on the tModel, we have to save the tModels first
                stm = new SaveTModel();
                stm.setAuthInfo(token);

                TModel[] tmodels = portTypeTModels.toArray(new TModel[0]);
                for (int i = 0; i < tmodels.length; i++) {
                        System.out.println(tmodelPrinter.print(tmodels[i]));
                        stm.getTModel().add(tmodels[i]);
                }

                tmodels = wadl2UDDI.createWADLTModels(pathOrURL, app).toArray(new TModel[0]);
                for (int i = 0; i < tmodels.length; i++) {
                        System.out.println(tmodelPrinter.print(tmodels[i]));
                        stm.getTModel().add(tmodels[i]);
                }
                //important, you'll need to save your new tModels, or else saving the business/service may fail
                System.out.println("Saving the following tModels " + stm.getTModel().size());
                publish.saveTModel(stm);

                //finaly, we're ready to save all of the services defined in the WSDL
                //again, we're creating a new business, if you have one already, look it up using the Inquiry getBusinessDetails
                PrintUDDI<BusinessService> servicePrinter = new PrintUDDI<BusinessService>();

                System.out.println("here's our new service: " + servicePrinter.print(businessServices));

                if (businessKey == null || businessKey.length() == 0) {
                        BusinessEntity be = new BusinessEntity();
                        be.setBusinessKey(businessServices.getBusinessKey());
                        be.getName().add(new Name());
                        be.getName().get(0).setValue(domain);
                        be.getName().get(0).setLang("en");
                        be.setBusinessServices(new BusinessServices());
                        be.getBusinessServices().getBusinessService().add(businessServices);
                        SaveBusiness sb = new SaveBusiness();
                        sb.setAuthInfo(token);
                        sb.getBusinessEntity().add(be);
                        BusinessDetail saveBusiness = publish.saveBusiness(sb);
                        System.out.println("new business created, key = " + saveBusiness.getBusinessEntity().get(0).getBusinessKey());
                }
                SaveService ss = new SaveService();
                ss.setAuthInfo(token);
                businessServices.setBusinessKey(businessKey);
                ss.getBusinessService().add(businessServices);
                publish.saveService(ss);
                System.out.println("Saved! " + businessServices.getServiceKey());

                //and we're done
                //Be sure to report any problems to the jUDDI JIRA bug tracker at 
                //https://issues.apache.org/jira/browse/JUDDI
        }

        public static void main(String[] args) throws Exception {

                new WadlImport().Fire("http://svn.apache.org/repos/asf/cxf/trunk/systests/jaxrs/src/test/resources/wadl/bookstoreImportResource.wadl", null, null, null);

        }
}
