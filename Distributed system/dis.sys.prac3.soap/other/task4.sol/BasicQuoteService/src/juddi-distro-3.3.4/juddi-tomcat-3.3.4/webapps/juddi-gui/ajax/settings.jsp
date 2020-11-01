<%-- 
    Document   : settings
    Created on : Apr 6, 2013, 9:45:02 PM
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

<%@page import="org.apache.commons.lang.StringEscapeUtils"%>
<%@page import="org.apache.juddi.v3.client.config.UDDINode"%>
<%@page import="org.apache.juddi.webconsole.resources.ResourceLoader"%>
<%@page import="java.io.File"%>
<%@page import="java.io.FileOutputStream"%>
<%@page import="java.util.Properties"%>
<%@page import="java.util.Enumeration"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include  file="../csrf.jsp" %>
<%        UddiHub x = UddiHub.getInstance(application, session);
        if (x.isAdminLocalhostOnly()
                && !request.getRemoteAddr().equalsIgnoreCase("localhost")
                && !request.getRemoteHost().equalsIgnoreCase("127.0.0.1")
                && !request.getRemoteHost().equalsIgnoreCase("0:0:0:0:0:0:0:1")) {
                out.write(ResourceLoader.GetResource(session, "pages.settings.accessdenied.remote"));
                UddiHub.log.fatal("Audit: FAILURE Attempt to alter configuration remotely from "
                        + request.getRemoteAddr() + " "
                        + request.getRemoteHost() + " "
                        + request.getRemoteUser());
                response.setStatus(403);
                return;
        } else {

                //this is controlled by web.xml
    /*if (!request.isUserInRole("uddiadmin")) {
                 out.write("Sorry, you need to have the 'uddiadmin' admin role to access this page.");
                 response.setStatus(403);
                 }*/
                if (request.getMethod().equalsIgnoreCase("post")) {
                        UddiHub.log.info("Audit: SUCCESS Altering juddi config "
                                + request.getRemoteAddr() + " "
                                + request.getRemoteHost() + " "
                                + request.getRemoteUser());
                        try {
                                String formaction = request.getParameter("formaction");
                                if (formaction == null) {
                                        response.setStatus(400);
                                        return;
                                }
                                if ("settings".equalsIgnoreCase(formaction)) {
                                        Enumeration it = request.getParameterNames();
                                        while (it.hasMoreElements()) {
                                                String key = (String) it.nextElement();
                                                String value = request.getParameter(key);
                                                if (key.startsWith("client.") || key.startsWith("config.")) {
                                                        if (!key.startsWith("client.nodes.")) {
                                                                //its part of the juddi client config file
                                                                x.GetJuddiClientConfig().getConfiguration().setProperty(key, value);
                                                                //this just sets the runtime config
                                                               // System.out.println(key + " = " + value);
                                                        }

                                                }
                                        }
                                } else if ("deleteNode".equalsIgnoreCase(formaction)) {
                                        String nn = request.getParameter("nodename");
                                        UDDINode un = x.GetJuddiClientConfig().getUDDINode(nn);
                                        x.GetJuddiClientConfig().removeUDDINode(nn);
                                        UddiHub.log.info("Deleting node config for " + nn);

                                } else if ("newNode".equalsIgnoreCase(formaction)) {
                                        UddiHub.log.info("New node config");
                                        UDDINode un = new UDDINode();
                                        un.setName(request.getParameter("nodename"));

                                        un.setClientName(x.GetJuddiClientConfig().getClientName());
                                        un.setInquiryUrl(request.getParameter("inquiry"));
                                        un.setProxyTransport(request.getParameter("transport"));
                                        un.setPublishUrl(request.getParameter("publish"));
                                        un.setDescription(request.getParameter("description"));
                                        un.setCustodyTransferUrl(request.getParameter("custody"));
                                        un.setSubscriptionUrl(request.getParameter("subscription"));
                                        un.setSecurityUrl(request.getParameter("security"));

                                        un.setFactoryInitial(request.getParameter("factoryinit"));
                                        un.setFactoryNamingProvider(request.getParameter("factorynaming"));
                                        un.setFactoryURLPkgs(request.getParameter("factoryurl"));
                                        un.setInquiryRESTUrl(request.getParameter("inquiryrest"));
                                        un.setReplicationUrl(request.getParameter("replication"));
                                        un.setJuddiApiUrl(request.getParameter("juddiapi"));
                                        x.GetJuddiClientConfig().addUDDINode(un);

                                } else if ("alterNode".equalsIgnoreCase(formaction)) {

                                        String nn = request.getParameter("nodenameAlter");
                                        UDDINode un = x.GetJuddiClientConfig().getUDDINode(nn);
                                        UddiHub.log.info("Altering node config for " + nn);
                                        un.setInquiryUrl(request.getParameter("inquiryAlter"));
                                        un.setProxyTransport(request.getParameter("transportAlter"));
                                        un.setPublishUrl(request.getParameter("publishAlter"));
                                        un.setDescription(request.getParameter("descriptionAlter"));
                                        un.setCustodyTransferUrl(request.getParameter("custodyAlter"));
                                        un.setSubscriptionUrl(request.getParameter("subscriptionAlter"));
                                        un.setSecurityUrl(request.getParameter("securityAlter"));

                                        un.setFactoryInitial(request.getParameter("factoryinitAlter"));
                                        un.setFactoryNamingProvider(request.getParameter("factorynamingAlter"));
                                        un.setFactoryURLPkgs(request.getParameter("factoryurlAlter"));
                                        un.setInquiryRESTUrl(request.getParameter("inquiryrestAlter"));
                                        un.setReplicationUrl(request.getParameter("replicationAlter"));
                                        un.setJuddiApiUrl(request.getParameter("juddiapiAlter"));
                                        x.GetJuddiClientConfig().removeUDDINode(nn);
                                        x.GetJuddiClientConfig().addUDDINode(un);

                                } else if ("getNode".equalsIgnoreCase(formaction)) {
                                        String nn = request.getParameter("nodename");
                                        UDDINode un = x.GetJuddiClientConfig().getUDDINode(nn);
                                        UddiHub.log.info("Get node config for " + nn);
                                         out.write("<table class=\"table table-hover\">");
                                out.write("<tr><td>Node Name</td><td><input class=\"crudnodeAlter\" type=text id=\"nodenameAlter\" value=\"" + StringEscapeUtils.escapeHtml(un.getName()) + "\"></td></tr>");

                                out.write("<tr><td>Description</td><td><input class=\"crudnodeAlter\" type=text id=\"descriptionAlter\" value=\"" + (un.getDescription() != null ? StringEscapeUtils.escapeHtml(un.getDescription()) : "") + "\"></td></tr>");
                                out.write("<tr><td>Transport</td><td><input class=\"crudnodeAlter\" type=text id=\"transportAlter\" value=\"" + (un.getProxyTransport() != null ? StringEscapeUtils.escapeHtml(un.getProxyTransport()) : "") + "\"></td></tr>");
                                out.write("<tr><td>Inquiry</td><td><input class=\"crudnodeAlter\" type=text id=\"inquiryAlter\" value=\"" + (un.getInquiryUrl() != null ? StringEscapeUtils.escapeHtml(un.getInquiryUrl()) : "") + "\"></td></tr>");
                                out.write("<tr><td>Publish</td><td><input class=\"crudnodeAlter\" type=text id=\"publishAlter\" value=\"" + (un.getPublishUrl() != null ? StringEscapeUtils.escapeHtml(un.getPublishUrl()) : "") + "\"></td></tr>");
                                out.write("<tr><td>Security</td><td><input class=\"crudnodeAlter\" type=text id=\"securityAlter\" value=\"" + (un.getSecurityUrl() != null ? StringEscapeUtils.escapeHtml(un.getSecurityUrl()) : "") + "\"></td></tr>");
                                out.write("<tr><td>Custody Transfer</td><td><input class=\"crudnodeAlter\" type=text id=\"custodyAlter\" value=\"" + (un.getCustodyTransferUrl() != null ? StringEscapeUtils.escapeHtml(un.getCustodyTransferUrl()) : "") + "\"></td></tr>");
                                out.write("<tr><td>Subscription</td><td><input class=\"crudnodeAlter\" type=text id=\"subscriptionAlter\" value=\"" + (un.getSubscriptionUrl() != null ? StringEscapeUtils.escapeHtml(un.getSubscriptionUrl()) : "") + "\"></td></tr>");
                                out.write("<tr><td colspan=2>Not used by juddi-gui</td></tr>");
                                out.write("<tr><td>Factory Initial</td><td><input type=text class=\"crudnodeAlter\" id=\"factoryinitAlter\" value=\"" + (un.getFactoryInitial() != null ? StringEscapeUtils.escapeHtml(un.getFactoryInitial()) : "") + "\"></td></tr>");
                                out.write("<tr><td>Factory Naming Provider</td><td><input class=\"crudnodeAlter\" type=text id=\"factorynamingAlter\" value=\"" + (un.getFactoryNamingProvider() != null ? StringEscapeUtils.escapeHtml(un.getFactoryNamingProvider()) : "") + "\"></td></tr>");
                                out.write("<tr><td>Factor URL Package</td><td><input class=\"crudnodeAlter\" type=text id=\"factoryurlAlter\" value=\"" + (un.getFactoryURLPkgs() != null ? StringEscapeUtils.escapeHtml(un.getFactoryURLPkgs()) : "") + "\"></td></tr>");
                                out.write("<tr><td>Inquiry REST</td><td><input class=\"crudnodeAlter\" type=text id=\"inquiryrestAlter\" value=\"" + (un.getInquiry_REST_Url() != null ? StringEscapeUtils.escapeHtml(un.getInquiry_REST_Url()) : "") + "\"></td></tr>");
                                out.write("<tr><td>Replication</td><td><input class=\"crudnodeAlter\" type=text id=\"replicationAlter\" value=\"" + (un.getReplicationUrl() != null ? StringEscapeUtils.escapeHtml(un.getReplicationUrl()) : "") + "\"></td></tr>");
                                out.write("<tr><td>jUDDI API</td><td><input class=\"crudnodeAlter\" type=text id=\"juddiapiAlter\" value=\"" + (un.getJuddiApiUrl() != null ? StringEscapeUtils.escapeHtml(un.getJuddiApiUrl()) : "") + "\"></td></tr>");
                                out.write("</table>");
                                        return;

                                } else {
                                        response.setStatus(400);
                                        return;
                                }

                                x.GetJuddiClientConfig().saveConfig();
                                out.write(ResourceLoader.GetResource(session, "actions.saved"));
                        } catch (Exception ex) {
                                response.setStatus(406);

                                out.write(x.HandleException(ex));
                        }
                } 
        }
%>