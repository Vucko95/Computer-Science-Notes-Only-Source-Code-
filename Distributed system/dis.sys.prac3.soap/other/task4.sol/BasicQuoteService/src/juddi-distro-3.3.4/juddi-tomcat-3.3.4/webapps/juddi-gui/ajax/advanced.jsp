<%-- 
    Document   : advanced
    Created on : Aug 9, 2013, 4:09:06 PM
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

<%@page import="org.apache.juddi.webconsole.hub.UDDIRequestsAsXML"%>
<%@page import="org.apache.juddi.webconsole.resources.ResourceLoader"%>
<%@page import="org.apache.juddi.webconsole.PostBackConstants"%>
<%@page import="org.apache.juddi.webconsole.hub.PagableContainer"%>
<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include  file="../csrf.jsp" %>
<%
    if (request.getMethod().equalsIgnoreCase("POST")) {
        String action = request.getParameter("advancedaction");
        if (action != null) {
            String method = request.getParameter("method");
            String service = request.getParameter("service");
            UddiHub x = UddiHub.getInstance(application,session);
            if (action.equalsIgnoreCase("getdefaultrequest")) {
 
                if (service != null && service.equalsIgnoreCase(UDDIRequestsAsXML.custody)) {
                    out.write(UDDIRequestsAsXML.getCustody(method));
                }
                if (service != null && service.equalsIgnoreCase(UDDIRequestsAsXML.inquiry)) {
                    out.write(UDDIRequestsAsXML.getInquiry(method));
                }
                if (service != null && service.equalsIgnoreCase(UDDIRequestsAsXML.publish)) {
                    out.write(UDDIRequestsAsXML.getPublish(method));
                }
                if (service != null && service.equalsIgnoreCase(UDDIRequestsAsXML.subscription)) {
                    out.write(UDDIRequestsAsXML.getSubscription(method));
                }
            } else if (action.equalsIgnoreCase("senddata")) {
                Object j=UDDIRequestsAsXML.getObject(service, method, request.getParameter("content"));
                String msg=(x.SendAdvancedQuery(j, service, method));
                if (msg.contains(ResourceLoader.GetResource(session, "errors.generic")))
                        response.setStatus(406);
                out.write(msg);
            }
        }



    }


%>