<%-- 
    Document   : subscription
    Created on : Apr 21, 2013, 12:00:30 PM
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
<%@page import="java.util.concurrent.atomic.AtomicReference"%>
<%@page import="org.apache.juddi.webconsole.hub.builders.Builders"%>
<%@page import="org.uddi.sub_v3.Subscription"%>
<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<jsp:include page="../csrf.jsp"></jsp:include>
<%
    if (request.getMethod().equalsIgnoreCase("POST")) { 
        UddiHub x = UddiHub.getInstance(application, session);
        if (request.getParameter("DELETE") != null) {
             String msg=( x.RemoveSubscription(request.getParameter("DELETE")));
             if (msg.contains(ResourceLoader.GetResource(session, "errors.generic")))
                response.setStatus(406);
             out.write(msg);
        } else {
            AtomicReference<String> outmsg = new AtomicReference<String>();
            Subscription sub = Builders.BuildClientSubscription(request.getParameterMap(), outmsg, session);
            if (sub == null) {
                    response.setStatus(406);
                out.write(outmsg.get());
            } else {
                out.write(x.AddSubscription(sub));
            }
        }
    } else {
        response.setStatus(500);
    }


%>