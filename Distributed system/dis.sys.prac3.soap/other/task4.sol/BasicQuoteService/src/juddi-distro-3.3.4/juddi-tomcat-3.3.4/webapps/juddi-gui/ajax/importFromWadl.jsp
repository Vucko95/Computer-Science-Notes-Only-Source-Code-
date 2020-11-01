<%-- 
    Document   : importFromWadl
    Created on : July 11, 2013, 3:26:42 PM
    Author     : Alex O'Ree 
/*
 * Copyright 2001-2008 The Apache Software Foundation.
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
--%>
<%@page import="org.apache.juddi.webconsole.resources.ResourceLoader"%>
<%@page import="org.apache.juddi.jaxb.PrintUDDI"%>
<%@page import="org.uddi.api_v3.BusinessService"%>
<%@page import="org.apache.juddi.v3.client.mapping.wadl.Application"%>
<%@page import="org.apache.juddi.v3.client.mapping.wadl.WADL2UDDI"%>
<%@page import="java.io.File"%>
<%@page import="org.apache.juddi.v3.client.config.TokenResolver"%>
<%@page import="org.uddi.api_v3.Name"%> 
<%@page import="org.uddi.api_v3.BusinessEntity"%>
<%@page import="java.util.ArrayList"%>
<%@page import="java.util.List"%>
<%@page import="org.apache.juddi.webconsole.hub.builders.Printers"%>
<%@page import="org.apache.commons.lang.StringEscapeUtils"%>
<%@page import="java.util.Set"%>
<%@page import="javax.xml.namespace.QName"%>
<%@page import="javax.wsdl.PortType"%>
<%@page import="java.util.Map"%>
<%@page import="org.uddi.api_v3.BusinessServices"%>
<%@page import="org.apache.juddi.v3.client.mapping.URLLocalizerDefaultImpl"%>
<%@page import="java.util.Properties"%>
<%@page import="javax.wsdl.Definition"%>
<%@page import="org.apache.juddi.v3.client.config.UDDIClerk"%>
<%@page import="org.uddi.api_v3.TModel"%>
<%@page import="java.net.URL"%>
<%@include  file="../csrf.jsp" %>
<%
    if (request.getMethod().equalsIgnoreCase("POST")) {
        String method = request.getParameter("formaction");
        if (method != null && method.length() > 0) {

            if (method.equalsIgnoreCase("preview") || method.equalsIgnoreCase("save")) {
                UddiHub x = UddiHub.getInstance(application, session);
                //Fetch the WSDL w/wo credentials
                String uri = request.getParameter("wsdlurl");
                String username = request.getParameter("wsdlusername");
                String password = request.getParameter("wsdlpassword");
                String keydomain = request.getParameter("keydomain");
                String businessname = request.getParameter("businessname");
                boolean ignoreSSL = false;
                try {
                    ignoreSSL = Boolean.parseBoolean(request.getParameter("ignoressl"));
                } catch (Exception ex) {
                }
                try {
                    URL url = new URL(uri);
                    //"http://graphical.weather.gov/xml/SOAP_server/ndfdXMLserver.php?wsdl");
                    //String domain = url.getHost();
                    //TModel keygen = UDDIClerk.createKeyGenator("uddi:" + domain + ":keygenerator", domain, "en");

                    Application app = WADL2UDDI.parseWadl(url, username, password, ignoreSSL);

                    List<URL> urls = WADL2UDDI.getBaseAddresses(app);
                    URL baseurl = urls.get(0);

                    //TModel keygen = UDDIClerk.createKeyGenator("uddi:" + domain + ":keygenerator", domain, "en");
                    Properties properties = new Properties();
                    properties.put("keyDomain", keydomain);
                    properties.put("businessName", businessname);
                    properties.put("serverName", url.getHost());
                    properties.put("serverPort", url.getPort());
                    //wsdlURL = wsdlDefinition.getDocumentBaseURI();
                    WADL2UDDI wadl2UDDI = new WADL2UDDI(null, new URLLocalizerDefaultImpl(), properties);

                    BusinessService businessServices = wadl2UDDI.createBusinessService(new QName(url.getHost(), "Servicename"), app);


                    Set<TModel> portTypeTModels = wadl2UDDI.createWADLPortTypeTModels(uri, app);
                    List<TModel> tmodels = new ArrayList<TModel>();
                    tmodels.addAll(portTypeTModels);
                    Set<TModel> bindings = wadl2UDDI.createWADLTModels(uri, app);

                    tmodels.addAll(bindings);
                    boolean createKeyGen = false;
                    TModel keygen = UDDIClerk.createKeyGenator("uddi:" + keydomain + ":keygenerator", 
                            keydomain + " Key Generator Partition", (String) session.getAttribute("locale"));
                    if (x.getTmodelDetails(keygen.getTModelKey()) == null) {
                        createKeyGen = true;
                    }
                    out.write("<i class=\"icon-thumbs-up icon-large\"></i> WADL successfully parsed! This will create " 
                            + portTypeTModels.size()
                            + " Port tModels, " 
                            + bindings.size()
                            + " Binding tModels, " 
                            + ((createKeyGen == true) ? "one tModel Key Generator, " : "")
                            + "1 binding, and 1 service(s) attached to the business with "
                            + "the key " + StringEscapeUtils.escapeHtml(businessname) + " .<br>");
                    out.write("Services:<br><ul>");

                    out.write("<li>Key: "
                            + StringEscapeUtils.escapeHtml(businessServices.getServiceKey())
                            + " <br>Name: "
                            + StringEscapeUtils.escapeHtml(Printers.ListNamesToString(businessServices.getName())));
                    if (businessServices.getBindingTemplates() != null) {
                        out.write("<br>Binding Templates:<ul>");
                        for (int k = 0; k < businessServices.getBindingTemplates().getBindingTemplate().size(); k++) {
                            out.write("<li>Key: " + StringEscapeUtils.escapeHtml(businessServices.getBindingTemplates().getBindingTemplate().get(k).getBindingKey())
                                    + "<br>Access Point: ");
                            if (businessServices.getBindingTemplates().getBindingTemplate().get(k).getAccessPoint() != null) {
                                out.write(StringEscapeUtils.escapeHtml(
                                        businessServices.getBindingTemplates().getBindingTemplate().get(k).getAccessPoint().getValue()));
                            }
                            out.write("</li>");
                        }
                        out.write("</ul>");
                    }
                    out.write("</li>");

                    out.write("</ul>");

                    out.write("tModels<br><ul>");
                    for (int i = 0; i < tmodels.size(); i++) {
                        out.write("<li>Key:"
                                + StringEscapeUtils.escapeHtml(tmodels.get(i).getTModelKey())
                                + " Name: "
                                + StringEscapeUtils.escapeHtml(tmodels.get(i).getName().getValue())
                                + "</li>");
                    }
                    out.write("</ul>");

                            
                    if (method.equalsIgnoreCase("save")) {

                        //forgot the key generator

                        StringBuilder result = new StringBuilder();
                        if (createKeyGen) {
                            result.append("Saving tModel " + StringEscapeUtils.escapeHtml(keygen.getName().getValue()) + "..." + x.SaveTModel(keygen)).append("<br>");
                        }
                        for (int i = 0; i < tmodels.size(); i++) {
                            result.append("Saving tModel " + StringEscapeUtils.escapeHtml(tmodels.get(i).getName().getValue()) + "..." + x.SaveTModel(tmodels.get(i))).append("<br>");
                        }

                        //this needs work
                        BusinessEntity biz = x.GetBusinessDetails(businessname);
                        if (biz != null) {
                            if (biz.getBusinessServices() == null) {
                                biz.setBusinessServices(new BusinessServices());
                            }

                        } else {
                            biz = new BusinessEntity();
                            biz.setBusinessKey(TokenResolver.replaceTokens("uddi:${keyDomain}:business_${businessName}", properties).toLowerCase());
                            biz.getName().add(new Name(businessname, "en"));
                        }
                        if (biz.getBusinessServices() == null) {
                            biz.setBusinessServices(new BusinessServices());
                        }

                        biz.getBusinessServices().getBusinessService().add(businessServices);

                          for (int i = 0; i < biz.getBusinessServices().getBusinessService().size(); i++) {
                            biz.getBusinessServices().getBusinessService().get(i).setBusinessKey(biz.getBusinessKey());
                        }
         //               PrintUDDI<BusinessEntity> sbp = new PrintUDDI<BusinessEntity>();
           //             result.append("<br>" + sbp.print(biz) + "<br>");
                                    
                        result.append("Saving business " + StringEscapeUtils.escapeHtml(biz.getName().get(0).getValue()) + "..." + x.SaveBusinessDetails(biz));
                        out.write(result.toString());
                    }

                } catch (Exception ex) {
                        response.setStatus(406);
                        String msg = x.HandleException(ex);     
                        if (msg.contains(ResourceLoader.GetResource(session, "errors.generic")))
                                response.setStatus(406);
                        out.write(msg);
                }
            } else {
                    response.setStatus(406);
                out.write(ResourceLoader.GetResource(session, "errors.generic"));
            }
        } else {
                response.setStatus(406);
            out.write(ResourceLoader.GetResource(session, "errors.generic"));
        }
    } else {
            response.setStatus(406);
        out.write(ResourceLoader.GetResource(session, "errors.generic"));
    }



%>
