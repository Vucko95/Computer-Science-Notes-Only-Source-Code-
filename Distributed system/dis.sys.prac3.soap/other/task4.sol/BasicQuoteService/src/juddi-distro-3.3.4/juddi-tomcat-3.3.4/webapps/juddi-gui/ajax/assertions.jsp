<%-- 
    Document   : assertions
    Created on : Apr 13, 2013, 7:44:30 PM
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

<%@page import="org.uddi.api_v3.CompletionStatus"%>
<%@page import="org.uddi.api_v3.AssertionStatusItem"%>
<%@page import="org.apache.commons.lang.StringEscapeUtils"%>
<%@page import="java.util.concurrent.atomic.AtomicReference"%>
<%@page import="javax.xml.ws.Holder"%>
<%@page import="org.apache.juddi.webconsole.resources.ResourceLoader"%>
<%@page import="org.apache.juddi.webconsole.PostBackConstants"%>
<%@page import="java.util.List"%>
<%@page import="org.uddi.api_v3.PublisherAssertion"%>
<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<jsp:include page="../csrf.jsp" />
<% 
    UddiHub x = UddiHub.getInstance(application, session);
    if (request.getMethod().equalsIgnoreCase("post")) {
        if (request.getParameter("action") != null) {
            String action = request.getParameter("action");
            if (action.equalsIgnoreCase("delete")) {
                String msg = x.DeletePublisherAssertion(request.getParameter("tokey"), request.getParameter("fromkey"), request.getParameter("tmodelkey"), request.getParameter("keyname"), request.getParameter("keyvalue"));
                if (!msg.equals(ResourceLoader.GetResource(session, "actions.saved"))) {
                    response.setStatus(406);
                }
                out.write(msg);
            }
        } else {
            String msg = x.AddPublisherAssertion(request.getParameter("tokey"), request.getParameter("fromkey"), request.getParameter("tmodelkey"), request.getParameter("keyname"), request.getParameter("keyvalue"));
            if (!msg.equals(ResourceLoader.GetResource(session, "actions.saved"))) {
                response.setStatus(406);
            }
            out.write(msg);
        }
    } else {

        List<AssertionStatusItem> data = null;
        AtomicReference<String> msg = new AtomicReference<String>();
        data = x.GetPublisherAssertions(msg);
        if (msg != null && msg.get() != null) {
            out.write(UddiHub.ToErrorAlert(msg.get()));
        } else if (data == null || data.isEmpty())
            out.write(UddiHub.ToErrorAlert(ResourceLoader.GetResource(session, "errors.nodatareturned")));
        else {

%>
<table class="table table-hover">
    <tr><th><%=ResourceLoader.GetResource(session, "items.publisherassertions.from")%></th>
        <th><%=ResourceLoader.GetResource(session, "items.publisherassertions.to")%></th>
        <th><%=ResourceLoader.GetResource(session, "items.publisherassertions.relationship")%></th>
        <th><%=ResourceLoader.GetResource(session, "items.actions")%></th>
        <th><%=ResourceLoader.GetResource(session, "items.status")%></th>
    </tr>
        <%
   
        
            for (int i = 0; i < data.size(); i++) {
                out.write("<tr><td>");
                out.write(data.get(i).getFromKey());
                out.write("</td><td>");
                out.write(data.get(i).getToKey());
                out.write("</td><td>");
                if (data.get(i).getKeyedReference() != null) {
                    out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.key") + " :</div><div id=\"" + PostBackConstants.VALUE + "\" class=\"edit\">" + data.get(i).getKeyedReference().getTModelKey());
                    out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.name") + " :</div><div id=\"" + PostBackConstants.KEYNAME + "\" class=\"edit\">" + data.get(i).getKeyedReference().getKeyName());
                    out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.value") + " :</div><div id=\"" + PostBackConstants.KEYVALUE + "\" class=\"edit\">" + data.get(i).getKeyedReference().getKeyValue());
                }
                out.write("</td><td>");
                if (data.get(i).getCompletionStatus() == CompletionStatus.STATUS_FROM_KEY_INCOMPLETE ||
                        data.get(i).getCompletionStatus() == CompletionStatus.STATUS_TO_KEY_INCOMPLETE)
                                       {
                     out.write("<a class=\"btn btn-primary\" href=\"javascript:approveAssertion('"
                        + StringEscapeUtils.escapeJavaScript(data.get(i).getFromKey())
                        + "','"
                        + StringEscapeUtils.escapeJavaScript(data.get(i).getToKey())
                        + "','"
                        + StringEscapeUtils.escapeJavaScript(data.get(i).getKeyedReference().getTModelKey())
                        + "','"
                        + StringEscapeUtils.escapeJavaScript(data.get(i).getKeyedReference().getKeyName())
                        + "','"
                        + StringEscapeUtils.escapeJavaScript(data.get(i).getKeyedReference().getKeyValue())
                        + "');"
                        + "\">" + ResourceLoader.GetResource(session, "actions.approve") + "</a>");
                }
                out.write("<a class=\"btn btn-primary\" href=\"javascript:removeAssertion('"
                        + StringEscapeUtils.escapeJavaScript(data.get(i).getFromKey())
                        + "','"
                        + StringEscapeUtils.escapeJavaScript(data.get(i).getToKey())
                        + "','"
                        + StringEscapeUtils.escapeJavaScript(data.get(i).getKeyedReference().getTModelKey())
                        + "','"
                        + StringEscapeUtils.escapeJavaScript(data.get(i).getKeyedReference().getKeyName())
                        + "','"
                        + StringEscapeUtils.escapeJavaScript(data.get(i).getKeyedReference().getKeyValue())
                        + "');"
                        + "\">" + ResourceLoader.GetResource(session, "actions.delete") + "</a>");
                out.write("</td><td>");
                out.write(data.get(i).getCompletionStatus().toString());
                out.write("</td></tr>");
                
            }

        %>
</table>
<%
        }
    }
%>