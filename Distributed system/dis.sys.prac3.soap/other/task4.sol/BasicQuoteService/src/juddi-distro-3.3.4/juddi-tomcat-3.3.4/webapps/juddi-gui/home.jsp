<%-- 
    Document   : index
    Created on : Feb 23, 2013, 2:05:35 PM
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
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include file="header-top.jsp"%>

<div class="container">

    <!-- Main hero unit for a primary marketing message or call to action -->
    <div class="hero-unit">
        <h1>jUDDI</h1>
        <p><%=ResourceLoader.GetResource(session, "index.juddi")%></p>
        <p><a href="http://juddi.apache.org" class="btn btn-primary btn-large"><%=ResourceLoader.GetResource(session, "learnmore")%> &raquo;</a></p>
    </div>

    <!-- Example row of columns -->
    <div class="row">
        <div class="span4">
            <h2><%=ResourceLoader.GetResource(session, "index.browse.title")%></h2>
            <p><%=ResourceLoader.GetResource(session, "index.browse")%></p>
            <p><a class="btn" href="businessBrowse.jsp"><%=ResourceLoader.GetResource(session, "viewdetails")%> &raquo;</a></p>
        </div>
        <div class="span4">
            <h2><%=ResourceLoader.GetResource(session, "navbar.search")%></h2>
            <p><%=ResourceLoader.GetResource(session, "index.search")%></p>
            <p><a class="btn" href="search.jsp"><%=ResourceLoader.GetResource(session, "viewdetails")%> &raquo;</a></p>
        </div>
        <div class="span4">
            <h2><%=ResourceLoader.GetResource(session, "index.learn.title")%></h2>
            <p><%=ResourceLoader.GetResource(session, "index.learn")%></p>
            <p><a class="btn" href="http://uddi.org/pubs/uddi_v3.htm"><%=ResourceLoader.GetResource(session, "viewdetails")%> &raquo;</a></p>
        </div>
    </div>
    <%@include file="header-bottom.jsp"%>