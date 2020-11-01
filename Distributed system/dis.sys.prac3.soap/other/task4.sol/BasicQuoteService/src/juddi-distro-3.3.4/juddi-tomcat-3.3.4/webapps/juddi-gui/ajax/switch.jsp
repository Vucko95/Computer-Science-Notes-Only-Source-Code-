<%-- 
    Document   : switch, switches the ui instance to another node
    Created on : Jan 21, 2014, 4:23:25 PM
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
<%@page import="org.apache.juddi.webconsole.resources.ResourceLoader"%>
<%@page import="org.apache.juddi.api_v3.Node"%>
<%@page import="java.util.List"%>
<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include  file="../csrf.jsp" %>
<%        UddiHub x = UddiHub.getInstance(application, session);
        String node = request.getParameter("node");

        String description = null;
        List<Node> nodes = x.GetJuddiClientConfig().getUDDINodeList();
        boolean found = false;
        for (int i = 0; i < nodes.size(); i++) {
                if (nodes.get(i).getName().equals(node)) {
                        description = nodes.get(i).getDescription();
                        found = true;
                        break;
                }
        }
        if (!found) {
                response.setStatus(406);
                out.write(ResourceLoader.GetResource(session, "error.nodeexists"));
        } else {
                node = x.switchNodes(node);
                if (node == null) {
                        response.setStatus(406);
                        out.write(ResourceLoader.GetResource(session, "error.nodeexists"));
                } else {
                        out.write(ResourceLoader.GetResource(session, "items.nowconnectedto") + "<br>");
                        out.write(ResourceLoader.GetResource(session, "items.nodeid") + ": " + StringEscapeUtils.escapeHtml(node));
                        out.write("<br>");
                        out.write(ResourceLoader.GetResource(session, "items.description") + ": " + StringEscapeUtils.escapeHtml(description));
                        Cookie cookie = new Cookie("current_node", node);
                        cookie.setMaxAge(Integer.MAX_VALUE);
                        cookie.setPath("/");
                        response.addCookie(cookie);
                }
        }
%>