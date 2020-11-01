<%-- 
    Document   : login
    Created on : Feb 24, 2013, 9:08:02 AM
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

<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>
<%@page import="org.apache.juddi.webconsole.resources.ResourceLoader"%>
<%@page import="org.apache.commons.lang.StringEscapeUtils"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<div class="navbar-form pull-right">

    <%
        if (session.getAttribute("username") != null && session.getAttribute("password") != null
                && ((String) session.getAttribute("username")).length() > 0 && ((String) session.getAttribute("password")).length() > 0) {
            //we're probably logged in

    %>
    <script type="text/javascript">
        loggedin = true;
    </script>
    <a class="btn" title="<%=ResourceLoader.GetResource(session, "navbar.login.logout")%>" href="javascript:logout();">
        <%
                if (!request.isSecure() ||  !UddiHub.getInstance(application, session).isSecure()) {
            %>
            <i class="icon-warning-sign" title="<%=ResourceLoader.GetResource(session, "warning.ssl")%>"></i>
            <%
                }
            %>
        
        <i class="icon-user"></i>
        <%
            out.write(ResourceLoader.GetResource(session, "items.welcome") + " " + StringEscapeUtils.escapeHtml((String) session.getAttribute("username")) + "</a>");

        } else {
        %>

        <script type="text/javascript">
            loggedin = false;
        </script>

        <input class="span2" type="text" placeholder="<%=ResourceLoader.GetResource(session, "navbar.login.username")%>" name="username" id="username">
        <input class="span2" type="password" placeholder="<%=ResourceLoader.GetResource(session, "navbar.login.password")%>" name="password" id="password">
        <button type="button" onclick="javascript:Login();" class="btn" id="loginbutton">
            <%
                if (!request.isSecure()) {
            %>
            <i class="icon-warning-sign" title="<%=ResourceLoader.GetResource(session, "warning.ssl")%>"></i>
            <%
                }
            %>
            <%=ResourceLoader.GetResource(session, "navbar.login.button")%>
        </button>
        <%
            }
        %>


</div>

        
<div class="modal hide fade container" id="loginfailure">
    <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
        <h3><%=ResourceLoader.GetResource(session, "errors.generic")%></h3>
    </div>
    <div class="modal-body">
            <i class="icon-4x icon-thumbs-down"></i><br>
            <div id="loginfailuredetails"></div>
    </div>
    <div class="modal-footer">

        <button type="button" class="btn" data-dismiss="modal" ><%=ResourceLoader.GetResource(session, "modal.close")%></button>
    </div>
</div>

    