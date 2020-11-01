<%-- 
    Document   : about
    Created on : Apr 28, 2013, 4:26:58 PM
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


<%@page import="java.net.URLEncoder"%>
<%@page import="org.apache.juddi.webconsole.hub.builders.Printers"%>
<%@page import="org.uddi.api_v3.RegisteredInfo"%>
<%@page import="java.util.Iterator"%>
<%@page import="java.util.Set"%>
<%@page import="java.util.Properties"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include file="header-top.jsp" %>
<div class="container">

    <!-- Main hero unit for a primary marketing message or call to action -->
    <div class="well">
        <h1><%=ResourceLoader.GetResource(session, "navbar.help.about")%></h1>
    </div>

    <!-- Example row of columns -->
    <div class="row">
        <div class="span12">
            <%=ResourceLoader.GetResource(session, "pages.about.content")%>
            
            <ul>
                <li><a href="http://www.flickr.com/photos/acbo/2073367106/sizes/z/in/photostream/">Splash page photo</a></li>
                <li><a href="http://twitter.github.com/bootstrap/">Twitter Bootstrap</a></li>
                <li><a href="http://tarruda.github.io/bootstrap-datetimepicker/">Date/time picker</a></li>
                <li><a href="https://github.com/jschr/bootstrap-modal/">Modal Master</a></li>
                <li><a href="https://github.com/jdewit/bootstrap-timepicker">Time Picker</a></li>
                <li><a href="http://fortawesome.github.io/Font-Awesome/">Font Awesome</a></li>
                <li><a href="http://www.appelsiini.net/projects/jeditable">jEditable</a></li>
                <li><a href="http://jquery.com/">jQuery</a></li>
                <li><a href="http://jqueryui.com/">jQuery UI</a></li>
            </ul>
        </div>


    </div>

    <%@include file="header-bottom.jsp" %>