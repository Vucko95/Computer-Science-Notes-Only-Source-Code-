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
 *
 */
--%>

<%@page import="org.apache.juddi.adminconsole.hub.JUDDIRequestsAsXML"%>
<%@page import="org.apache.juddi.adminconsole.resources.ResourceLoader"%>
<%@page import="org.apache.juddi.adminconsole.PostBackConstants"%>
<%@page import="org.apache.juddi.adminconsole.hub.UddiAdminHub"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include  file="../csrf.jsp" %>
<%
    if (request.getMethod().equalsIgnoreCase("POST")) {
        String action = request.getParameter("advancedaction");
        if (action != null) {
            String method = request.getParameter("method");
            
            UddiAdminHub x = UddiAdminHub.getInstance(application,session);
            if (action.equalsIgnoreCase("getdefaultrequest")) {
 
               
                    out.write(JUDDIRequestsAsXML.getSampleXML(method));
               
            } else if (action.equalsIgnoreCase("senddata")) {
                Object j=JUDDIRequestsAsXML.getObjectJuddi(method, request.getParameter("content"));
                String msg=(x.SendAdvanced(j, method));
                if (msg.contains(ResourceLoader.GetResource(session, "errors.generic")))
                        response.setStatus(406);
                out.write(msg);
            }
        }



    }


%>