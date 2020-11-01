<%-- 
    Document   : go - handles requests for the admin actions page
    Created on : Aug 9, 2013, 6:52:50 PM
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
<%@page import="org.apache.juddi.adminconsole.resources.ResourceLoader"%>
<%@page import="org.apache.juddi.adminconsole.hub.UddiAdminHub"%>
<%@page import="org.apache.commons.lang.StringEscapeUtils"%>
<%@page import="java.util.Enumeration"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include  file="../csrf.jsp" %>
<%
    if (request.getMethod().equalsIgnoreCase("POST")) {
        UddiAdminHub x = UddiAdminHub.getInstance(application, session);
        try {
            out.write(x.go(request));
            /*Enumeration it=request.getParameterNames();
            while (it.hasMoreElements()){
                    String s= (String)it.nextElement();
                    out.write("<br>"+s+"="+ request.getParameter(s));
            }*/
        } catch (Exception ex) {
            out.write("<i class=\"icon-thumbs-down icon-2x\"> " + ResourceLoader.GetResource(session, "pages.config.savefailed") +"<br>" + StringEscapeUtils.escapeHtml(ex.getMessage()));
        }
    }
%>