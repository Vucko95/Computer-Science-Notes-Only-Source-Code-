<%-- 
    Document   : subscriptionFeed
    Created on : Apr 14, 2013, 7:56:16 PM
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

<%@page import="java.util.Calendar"%>
<%@page import="javax.xml.datatype.XMLGregorianCalendar"%>
<%@page import="java.util.GregorianCalendar"%>
<%@page import="javax.xml.datatype.DatatypeFactory"%>
<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include  file="../csrf.jsp" %>
<!DOCTYPE html>
<%
    UddiHub x = UddiHub.getInstance(application, session);
    DatatypeFactory df = DatatypeFactory.newInstance();
    GregorianCalendar gcal = new GregorianCalendar(); 
    gcal.setTimeInMillis(System.currentTimeMillis());
    //TODO get/set cookie data
    gcal.add(Calendar.DATE, -1);
    XMLGregorianCalendar xcal = df.newXMLGregorianCalendar(gcal);
    out.write(x.GetNewsFeed(xcal));

%>