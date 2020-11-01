<%-- 
    Document   : saveconfig
    Created on : Jul 31, 2013, 6:52:50 PM
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
<%@page import="org.apache.commons.lang.StringEscapeUtils"%>
<%@page import="org.apache.juddi.config.AppConfig"%>
<%@page import="org.apache.commons.configuration.Configuration"%>
<%@page import="java.util.Enumeration"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@include  file="../csrf.jsp" %>
<%
    UddiAdminHub ahub = UddiAdminHub.getInstance(application, session);

    if (ahub.isAdminLocalhostOnly() && 
            !request.getRemoteAddr().equalsIgnoreCase("localhost") && 
            !request.getRemoteHost().equalsIgnoreCase("127.0.0.1") &&
            !request.getRemoteHost().equalsIgnoreCase("0:0:0:0:0:0:0:1")) {
        out.write("Access Denied");
        UddiAdminHub.log.fatal("Audit: FAILURE Attempt to alter configuration remotely from "
                + request.getRemoteAddr() + " "
                + request.getRemoteHost() + " "
                + request.getRemoteUser());
        response.setStatus(403);
    } else {
        if (request.getMethod().equalsIgnoreCase("POST")) {
            try {
                Enumeration it = request.getParameterNames();
                Configuration cfg = null;
                Configuration server = AppConfig.getConfiguration();
                Configuration client = ahub.GetJuddiClientConfig().getConfiguration();
                while (it.hasMoreElements()) {
                    String key = (String) it.nextElement();
                    String val = request.getParameter(key);
                    if (key != "nonce") {
                        if (key.startsWith("config.props.") || key.startsWith("client.")) {
                            cfg = client;
                        }
                        if (key.startsWith("juddi.")) {
                            cfg = server;
                        }
                        if (cfg == null) {
                            continue;
                        }
                        boolean isbool = false;
                        boolean isint = false;
                        boolean boolval = false;
                        int intval = 0;
                        if (val.equalsIgnoreCase("true") || val.equalsIgnoreCase("true")) {
                            isbool = true;
                            boolval = Boolean.parseBoolean(val);
                        }

                        try {
                            intval = Integer.parseInt(val);
                            isint = true;
                        } catch (Exception ex) {
                        }
                        if (isbool) {
                            cfg.setProperty(key, boolval);
                        } else if (isint) {
                            cfg.setProperty(key, intval);
                        } else {
                            cfg.setProperty(key, val);
                        }
                        cfg = null;

                    }
                    UddiAdminHub.getInstance(application, session).GetJuddiClientConfig().saveConfig();
                    //note server config is autosave.
                }
                out.write("<i class=\"icon-thumbs-up icon-2x\"> " + ResourceLoader.GetResource(session, "actions.saved"));
            } catch (Exception ex) {
                out.write("<i class=\"icon-thumbs-down icon-2x\"> " + ResourceLoader.GetResource(session, "pages.config.savefailed") +"<br>" + StringEscapeUtils.escapeHtml(ex.getMessage()));
            }
        }
    }
%>