<%-- 
    Document   : settings
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

<%@page import="java.util.concurrent.atomic.AtomicReference"%>
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
        <h1><%=ResourceLoader.GetResource(session, "navbar.create.mybiz")%></h1>
    </div>

    <!-- Example row of columns -->
    <div class="row">
        <div class="span12">
            <%=ResourceLoader.GetResource(session, "navbar.create.mybiz.content")%>
            <br><Br>
            <%
                UddiHub x = UddiHub.getInstance(application, session);
                AtomicReference<String> msg = new AtomicReference<String>();
                RegisteredInfo info = x.GetNodeInformation(msg);
                if (msg != null && msg.get() != null) {
                    out.write(UddiHub.ToErrorAlert(msg.get()));
                } else if (info == null || info.getBusinessInfos() == null || info.getBusinessInfos().getBusinessInfo().isEmpty()) {
                    out.write(UddiHub.ToErrorAlert(ResourceLoader.GetResource(session, "errors.nodatareturned")));
                } else {
                    //TODO i18n
            %>

            <table class="table table-hover">
                <tr><th><%=ResourceLoader.GetResource(session, "items.key")%></th><th><%=ResourceLoader.GetResource(session, "items.name")%></th>
                    <th><%=ResourceLoader.GetResource(session, "items.actions")%></th></tr>

                <%
                    for (int i = 0; i < info.getBusinessInfos().getBusinessInfo().size(); i++) {
                        out.write("<tr id=\"" + StringEscapeUtils.escapeHtml(info.getBusinessInfos().getBusinessInfo().get(i).getBusinessKey()) + "\"><td>");
                        out.write("<a href=\"businessEditor2.jsp?id=" + URLEncoder.encode(info.getBusinessInfos().getBusinessInfo().get(i).getBusinessKey(), "UTF-8") + "\">");
                        out.write(StringEscapeUtils.escapeHtml(info.getBusinessInfos().getBusinessInfo().get(i).getBusinessKey()));
                        out.write(" <i class=\"icon-edit icon-large\"></i></a>");
                        out.write("</td><td>");
                        out.write(StringEscapeUtils.escapeHtml(Printers.ListNamesToString(info.getBusinessInfos().getBusinessInfo().get(i).getName())));
                        out.write("</td><td>");
                %>
                <div class="btn-group">
                    <button class="btn">Actions</button>
                    <button class="btn dropdown-toggle" data-toggle="dropdown">
                        <span class="caret"></span>
                    </button>
                    <ul class="dropdown-menu">
                        <!-- dropdown menu links -->
                        <li>
                            <a class="btn btn-danger " href="javascript:deleteBusinessByID('<%=URLEncoder.encode(info.getBusinessInfos().getBusinessInfo().get(i).getBusinessKey(), "UTF-8")%>');"><%=ResourceLoader.GetResource(session, "actions.delete")%></a></li>
                        <li><a class="btn btn-success " href="signer.jsp?id=<%=URLEncoder.encode(info.getBusinessInfos().getBusinessInfo().get(i).getBusinessKey(), "UTF-8")%>&type=business"><%=ResourceLoader.GetResource(session, "actions.sign")%></a></li>
                        <li><a class="btn btn-info " href="#" title="<%=ResourceLoader.GetResource(session, "actions.subscribe.description")%>"><%=ResourceLoader.GetResource(session, "actions.subscribe")%></a></li>
                        <li><a class="btn btn-warning " href="#" title="<%=ResourceLoader.GetResource(session, "actions.transfer.description")%>"><%=ResourceLoader.GetResource(session, "actions.transfer")%></a></li>
                        <li><a class="btn "  href="javascript:ViewAsXML('<%=StringEscapeUtils.escapeJavaScript(info.getBusinessInfos().getBusinessInfo().get(i).getBusinessKey())%>');"><%=ResourceLoader.GetResource(session, "actions.asxml")%></a></li>
                    </ul>
                </div>

                <%
                        //    out.write("Edit, Delete, Transfer, Sign, Subscribe, Create Relationship");
                        out.write("</td></tr>");
                    }
                %>
            </table>
            <%
                }
            %>
        </div>

        <div class="modal hide fade" id="viewAsXml">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                <h3><%=ResourceLoader.GetResource(session, "actions.asxml")%></h3>
            </div>
            <div class="modal-body" id="viewAsXmlContent">


            </div>
            <div class="modal-footer">
                <a href="javascript:$('#viewAsXml').modal('hide');" class="btn"><%=ResourceLoader.GetResource(session, "modal.close")%></a>
            </div>
        </div>

    </div>
    <script type="text/javascript" src="js/businessEditor.js"></script>
    <script type="text/javascript">
        
                       
    
        
        function ViewAsXML(bizid)
        {
            $.get("ajax/toXML.jsp?id=" + bizid + "&type=business", function(data){
                window.console && console.log('asXml success');                
                  
                $("#viewAsXmlContent").html(
                "<a href=\"ajax/toXML.jsp?id=" + bizid + "&type=business\" class=\"btn btn-primary\">Popout</a>  " 
                    +safe_tags_replace(data) + "<br>" 
            );
                $( "#viewAsXml" ).modal('show');
            });
                       
        }
    </script>
    <%@include file="header-bottom.jsp" %>