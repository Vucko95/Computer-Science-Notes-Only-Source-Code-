<%-- 
/*
 * Copyright 2001-2013 The Apache Software Foundation.
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
    Document   : service editor
    Created on : Feb 24, 2013, 3:31:39 PM
    Author     : Alex O'Ree
--%>

<%@page import="org.apache.juddi.api_v3.AccessPointType"%>
<%@page import="java.net.URLEncoder"%>
<%@page import="org.uddi.api_v3.*"%>
<%@page import="org.apache.juddi.webconsole.PostBackConstants"%>
<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>


<%//@include file="csrf.jsp" 
        boolean newitem = false;
        String serviceid = request.getParameter("id");
        String businessid = request.getParameter("bizid");
        if (serviceid == null && businessid == null) {
                response.sendRedirect("index.jsp");
        }
        if (serviceid == null || serviceid.length() == 0) {
                //response.sendRedirect("browse.jsp");
                if (businessid != null && businessid.length() > 0) {
                        newitem = true;
                } else {
                        //no service id or business id
                        response.sendRedirect("index.jsp");
                }

        }

        UddiHub x = UddiHub.getInstance(application, request.getSession());

        BusinessService bd = null;
        if (!newitem) {
                bd = x.GetServiceDetail(serviceid);
        } else {
                bd = new BusinessService();
                bd.setBusinessKey(businessid);
                BusinessEntity be = x.GetBusinessDetails(businessid);
                if (be == null) {
                        //incase an invalid business id was passed in
                        response.sendRedirect("index.jsp");
                } else {
                        bd.setBusinessKey(be.getBusinessKey());
                }
        }

        if (bd == null) {

                //we can't make a new service without a business to reference
                response.sendRedirect("index.jsp");
                return;
        }
%>
<%@include file="header-top.jsp" %>
<div class="container">

        <!-- Main hero unit for a primary marketing message or call to action -->
        <div class="well" >
                <h1><%=ResourceLoader.GetResource(session, "pages.serviceeditor.title")%></h1>
        </div>

        <!-- Example row of columns -->
        <div class="row">
                <div class="span12" >

                        <div id="businesseditor">
                                <%

                                        int totalBTDescriptions = 0;
                                %>

                                <i class="icon-lock icon-large"></i>

                                <b><%=ResourceLoader.GetResource(session, "pages.businesskey")%></b> -
                                <%=ResourceLoader.GetResource(session, "pages.businesskey.description")%>
                                <a href="javascript:ShowKeyHelp();"><i class="icon-question-sign icon-large"></i> <%=ResourceLoader.GetResource(session, "navbar.help")%></a>
                                <br>
                                <div style="border-width: 2px; border-style: solid;" class="noedit" id="<%=PostBackConstants.BUSINESSKEY%>">
                                        <%
                                                if (bd == null || bd.getBusinessKey() == null) {
                                                        out.write("");
                                                } else {
                                                        out.write("<a href=\"businessEditor2.jsp?id=" + StringEscapeUtils.escapeHtml(bd.getBusinessKey()) + "\">");
                                                        out.write(StringEscapeUtils.escapeHtml(bd.getBusinessKey()));
                                                        out.write("</a>");

                                                        if (bd.getCategoryBag() == null) {
                                                                bd.setCategoryBag(new CategoryBag());
                                                        }
                                                }
                                        %>
                                </div>
                                <br>
                                <%
                                        if (!newitem) {
                                                out.write("<i class=\"icon-lock icon-large\"></i> ");
                                        }
                                %>
                                <b><%=ResourceLoader.GetResource(session, "items.service.key")%> </b>-
                                <%=ResourceLoader.GetResource(session, "items.service.key.description")%><br>
                                <div style="border-width: 2px; border-style: solid;" <%
                                        if (!newitem) {
                                                out.write("class=\"noedit\"");
                                        } else {
                                                out.write("class=\"edit\"");
                                        }
                                     %>
                                     id="<%=PostBackConstants.SERVICEKEY%>">
                                        <%
                                                if (!newitem) {
                                                        out.write(StringEscapeUtils.escapeHtml(bd.getServiceKey()));
                                                }

                                                if (bd.getCategoryBag() == null) {
                                                        bd.setCategoryBag(new CategoryBag());
                                                }

                                                if (bd.getBindingTemplates() == null) {
                                                        bd.setBindingTemplates(new BindingTemplates());
                                                }
                                                int currentcatkeyrefBT = 0;
                                                int currentcatkeyrefgrpBT = 0;
                                                int currentbindingtemplatesInstance = 0;
                                                int currentOverviewDocs = 0;
                                                for (int i = 0; i < bd.getBindingTemplates().getBindingTemplate().size(); i++) {
                                                        if (bd.getBindingTemplates().getBindingTemplate().get(i).getCategoryBag() != null) {
                                                                currentcatkeyrefBT += bd.getBindingTemplates().getBindingTemplate().get(i).getCategoryBag().getKeyedReference().size();
                                                                currentcatkeyrefgrpBT += bd.getBindingTemplates().getBindingTemplate().get(i).getCategoryBag().getKeyedReferenceGroup().size();
                                                        }

                                                        if (bd.getBindingTemplates().getBindingTemplate().get(i).getTModelInstanceDetails() != null) {
                                                                currentbindingtemplatesInstance = bd.getBindingTemplates().getBindingTemplate().get(i).getTModelInstanceDetails().getTModelInstanceInfo().size();
                                                        }
                                                        if (bd.getBindingTemplates().getBindingTemplate().get(i).getTModelInstanceDetails() != null) {
                                                                for (int k = 0; k < bd.getBindingTemplates().getBindingTemplate().get(i).getTModelInstanceDetails().getTModelInstanceInfo().size(); k++) {
                                                                        if (bd.getBindingTemplates().getBindingTemplate().get(i).getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails() != null) {
                                                                                currentOverviewDocs += bd.getBindingTemplates().getBindingTemplate().get(i).getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getOverviewDoc().size();
                                                                        }
                                                                }
                                                        }
                                                }


                                        %>
                                </div>
                                <br>

                                <script type="text/javascript">
                    var currentNameEntries =<%= bd.getName().size() - 1%>;
                    var currentbindingtemplatesInstance =<%=currentbindingtemplatesInstance%>;
                    var currentDescriptionEntries =<%= bd.getDescription().size() - 1%>;
                    var currentcatkeyrefBT =<%=currentcatkeyrefBT%>;
                    var currentcatkeyref =<%=bd.getCategoryBag().getKeyedReference().size()%>;
                    var currentcatkeyrefgrpBT =<%=currentcatkeyrefgrpBT%>;
                    var currentcatkeyrefgrp =<%=bd.getCategoryBag().getKeyedReferenceGroup().size()%>;
                    var currentbindingtemplates = <%=bd.getBindingTemplates().getBindingTemplate().size()%>;
                    var currentOverviewDocs = <%=currentOverviewDocs%>;
                                </script> 

                                <ul class="nav nav-tabs" id="myTab">
                                        <li class="active"><a  href="#general"><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.general")%></a></li>

                                        <li><a href="#categories" ><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.categories")%></a></li>

                                        <li><a href="#bindingtemplates" ><%=ResourceLoader.GetResource(session, "items.bindingtemplate")%></a></li>

                                        <li><a href="#signatures"  id="sigtagheader"><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.signatures")%></a></li>

                                        <li><a href="#opinfo" ><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.opinfo")%></a></li>
                                </ul>
                                <script>
                                        $(function() {
                                                $('#myTab').tab;//('show');
                                        })
                                        $('#myTab a[href=#general]').click(function(e) {
                                                e.preventDefault();
                                                $(this).tab('show');
                                        });
                                        $('#myTab a[href=#categories]').click(function(e) {
                                                e.preventDefault();
                                                $(this).tab('show');
                                        });
                                        $('#myTab a[href=#bindingtemplates]').click(function(e) {
                                                e.preventDefault();
                                                $(this).tab('show');
                                        });
                                        $('#myTab a[href=#signatures]').click(function(e) {
                                                e.preventDefault();
                                                $(this).tab('show');
                                        });
                                        $('#myTab a[href=#opinfo]').click(function(e) {
                                                e.preventDefault();
                                                $(this).tab('show');
                                        });

                                </script>
                                <div class="tab-content">
                                        <div class="tab-pane active" id="general">




                                                <b><%=ResourceLoader.GetResource(session, "items.name")%> </b>- 
                                                <%=ResourceLoader.GetResource(session, "items.name.description")%><br>
                                                <a href="javascript:AddName();"><i class="icon-plus-sign icon-large"></i></a><%=ResourceLoader.GetResource(session, "items.name.add")%>
                                                <div id="nameContainer" style="border-width: 2px; border-style: solid;" >
                                                        <%
                                                                for (int i = 0; i < bd.getName().size(); i++) {
                                                                        out.write("<div id=\"" + PostBackConstants.NAME + i + "\" style=\"border-width:1px; border-style:solid\" >");
                                                                        out.write("<div style=\"float:left; height:100%\"><a href=\"javascript:Remove('" + PostBackConstants.NAME + i + "');\"><i class=\"icon-trash icon-large\"></i>&nbsp;</a></div>");
                                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.key") + ":&nbsp;</div>"
                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.NAME + i + PostBackConstants.VALUE + "\">" + StringEscapeUtils.escapeHtml(bd.getName().get(i).getValue()) + "</div>");
                                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.lang") + ":&nbsp;</div>"
                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.NAME + i + PostBackConstants.LANG + "\">");
                                                                        if (bd.getName().get(i).getLang() != null) {
                                                                                out.write(StringEscapeUtils.escapeHtml(bd.getName().get(i).getLang()));
                                                                        }
                                                                        out.write("</div>");

                                                                        out.write("</div>");
                                                                        //confirmed one to one div tags
                                                                }
                                                        %></div>
                                                <Br>
                                                <b><%=ResourceLoader.GetResource(session, "items.description")%> </b>- 
                                                <%=ResourceLoader.GetResource(session, "items.services.description")%><br>
                                                <a href="javascript:AddDescription('Description');"><i class="icon-plus-sign icon-large"></i></a> <%=ResourceLoader.GetResource(session, "items.description.add")%>

                                                <div id="Description" style="border-width: 2px; border-style: solid;" >
                                                        <%
                                                                for (int i = 0; i < bd.getDescription().size(); i++) {
                                                                        out.write("<div id=\"" + PostBackConstants.DESCRIPTION + i + "\" style=\"border-width:1px; border-style:solid\">");
                                                                        out.write("<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('Description" + i + "');\"><i class=\"icon-trash icon-large\"></i>&nbsp;</a></div>");
                                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.key") + ":&nbsp;</div>"
                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.DESCRIPTION + i + PostBackConstants.VALUE + "\">" + StringEscapeUtils.escapeHtml(bd.getDescription().get(i).getValue()) + "</div>");
                                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.lang") + ":&nbsp;</div>"
                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.DESCRIPTION + i + PostBackConstants.LANG + "\">"
                                                                             + (bd.getDescription().get(i).getLang() == null ? "" : StringEscapeUtils.escapeHtml(bd.getDescription().get(i).getLang()))
                                                                             + "</div>");

                                                                        out.write("</div>");
                                                                        //confirmed 1:1
                                                                }

                                                        %>
                                                </div>
                                                <br>
                                        </div>
                                        <div class="tab-pane" id="categories">

                                                <b><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.categories")%> </b>- 
                                                <%=ResourceLoader.GetResource(session, "items.categories.description")%>
                                                <br><br>
                                                <b><%=ResourceLoader.GetResource(session, "items.keyrefcats")%>:</b><br>
                                                <a href="javascript:AddCategoryKeyReference();"><i class="icon-plus-sign icon-large"></i></a> <%=ResourceLoader.GetResource(session, "items.keyrefcat.add")%> <Br>
                                                <%@include file="quickref_catbag.jsp" %>
                                                <div id="catContainer" style="border-width: 2px; border-style: solid;" >
                                                        <%
                                                                if (bd.getCategoryBag() == null) {
                                                                        bd.setCategoryBag(new CategoryBag());
                                                                }
                                                                //                        out.write("Keyed Reference Categories:");
                                                                for (int i = 0; i < bd.getCategoryBag().getKeyedReference().size(); i++) {

                                                                        out.write("<div id=\"" + PostBackConstants.CATBAG_KEY_REF + i + "\" style=\"border-width:2px; border-style:solid\">");
                                                                        out.write("<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('" + PostBackConstants.CATBAG_KEY_REF + i + "');\"><i class=\"icon-trash icon-large\"></i>&nbsp;</a></div>");
                                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.key") + " (<a href=\"javascript:tModelModal('" + PostBackConstants.CATBAG_KEY_REF + i + PostBackConstants.VALUE + "')\" ><i class=\"icon-list-alt icon-large\"></i>" + ResourceLoader.GetResource(session, "items.picker") + "</a>) "
                                                                             + "<a href=\"tmodelEditor.jsp?id=" + URLEncoder.encode(bd.getCategoryBag().getKeyedReference().get(i).getTModelKey(), "UTF8") + "\"><i class=\"icon-zoom-in icon-large\"></i></a>"
                                                                             + ": &nbsp;</div>"
                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.CATBAG_KEY_REF + i + PostBackConstants.VALUE + "\">" + StringEscapeUtils.escapeHtml(bd.getCategoryBag().getKeyedReference().get(i).getTModelKey()) + "</div>");
                                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.name") + ": &nbsp;</div>"
                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.CATBAG_KEY_REF + i + PostBackConstants.KEYNAME + "\">" + StringEscapeUtils.escapeHtml(bd.getCategoryBag().getKeyedReference().get(i).getKeyName()) + "</div>");
                                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.value") + ": &nbsp;</div>"
                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.CATBAG_KEY_REF + i + PostBackConstants.KEYVALUE + "\">" + StringEscapeUtils.escapeHtml(bd.getCategoryBag().getKeyedReference().get(i).getKeyValue()) + "</div>");
                                                                        out.write("</div>");
                                                                }
                                                        %>
                                                </div>
                                                <br>
                                                <b><%=ResourceLoader.GetResource(session, "items.keyrefgroup")%></b><br>
                                                <a href="javascript:AddCategoryKeyReferenceGroup();"><i class="icon-plus-sign icon-large"></i></a> <%=ResourceLoader.GetResource(session, "items.keyrefgroup.add")%><br>
                                                <%@include file="quickref_krgrp.jsp" %>
                                                <div id="catContainerGrp" style="border-width: 2px; border-style: solid;" >


                                                        <%
                                                                //div count good so far
                                                                for (int i = 0; i < bd.getCategoryBag().getKeyedReferenceGroup().size(); i++) {

                                                                        out.write("<div id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + "\" style=\"border-width:2px; border-style:solid\">"
                                                                             + "<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('catbaggrpkeyref" + i + "');\"><i class=\"icon-trash icon-large\"></i>&nbsp;</a></div>"
                                                                             + "<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.key") + " (<a href=\"javascript:tModelModal('" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.VALUE + "')\" ><i class=\"icon-list-alt icon-large\"></i>" + ResourceLoader.GetResource(session, "items.picker") + "</a>) "
                                                                             + "<a href=\"tmodelEditor.jsp?id=" + URLEncoder.encode(bd.getCategoryBag().getKeyedReferenceGroup().get(i).getTModelKey(), "UTF8") + "\"><i class=\"icon-zoom-in icon-large\"></i></a>"
                                                                             + ": &nbsp;</div>"
                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.VALUE + "\">"
                                                                             + StringEscapeUtils.escapeHtml(bd.getCategoryBag().getKeyedReferenceGroup().get(i).getTModelKey())
                                                                             + "</div>"
                                                                             + "<div id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF + "\" style=\"border-width:1px; border-style:solid\">"
                                                                             + "<div style=\"float:left;height:100%\"><a href=\"javascript:AddCategoryKeyReferenceGroupKeyRef('" + PostBackConstants.CATBAG_KEY_REF_GRP + i + "');\"><i class=\"icon-plus-sign icon-large\"></i></a></div>"
                                                                             + ResourceLoader.GetResource(session, "items.keyrefcat.add")
                                                                             + "</div>");

                                                                        for (int k = 0; k < bd.getCategoryBag().getKeyedReferenceGroup().get(i).getKeyedReference().size(); k++) {

                                                                                out.write("<div id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + "keyref" + k + "\" style=\"border-width:1px; border-style:solid\">");
                                                                                out.write("<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF + k + "');\"><i class=\"icon-trash icon-large\"></i>&nbsp;</a></div>");
                                                                                out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.key") + " (<a href=\"javascript:tModelModal('" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF + k + PostBackConstants.VALUE + "')\" ><i class=\"icon-list-alt icon-large\"></i>" + ResourceLoader.GetResource(session, "items.picker") + "</a>) "
                                                                                     + "<a href=\"tmodelEditor.jsp?id=" + URLEncoder.encode(bd.getCategoryBag().getKeyedReferenceGroup().get(i).getKeyedReference().get(k).getTModelKey(), "UTF8") + "\"><i class=\"icon-zoom-in icon-large\"></i></a>"
                                                                                     + ": &nbsp;</div>"
                                                                                     + "<div class=\"edit\" id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF + k + PostBackConstants.VALUE + "\">" + StringEscapeUtils.escapeHtml(bd.getCategoryBag().getKeyedReferenceGroup().get(i).getKeyedReference().get(k).getTModelKey()) + "</div>");
                                                                                out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.name") + ": &nbsp;</div>"
                                                                                     + "<div class=\"edit\" id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF + k + PostBackConstants.KEYNAME + "\">" + StringEscapeUtils.escapeHtml(bd.getCategoryBag().getKeyedReferenceGroup().get(i).getKeyedReference().get(k).getKeyName()) + "</div>");
                                                                                out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.value") + ": &nbsp;</div>"
                                                                                     + "<div class=\"edit\" id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF + k + PostBackConstants.KEYVALUE + "\">" + StringEscapeUtils.escapeHtml(bd.getCategoryBag().getKeyedReferenceGroup().get(i).getKeyedReference().get(k).getKeyValue()) + "</div>");
                                                                                out.write("</div>");
                                                                        }

                                                                        out.write("</div>"); //this ends the group container for key ref PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF
                                                                }


                                                        %>
                                                </div>
                                                <br>
                                        </div>

                                        <div class="tab-pane" id="bindingtemplates">
                                                <b><%=ResourceLoader.GetResource(session, "items.bindingtemplate")%> </b>- <%=ResourceLoader.GetResource(session, "items.bindingtemplate.description")%> <br>
                                                <% if (!newitem) {
                                                %>
                                                <a href="bindingEditor.jsp?svcid=<%=URLEncoder.encode(bd.getServiceKey(), "UTF8")%>"><i class="icon-plus-sign icon-large"></i> <%=ResourceLoader.GetResource(session, "items.bindingtemplate.add")%></a> <Br>
                                                
                                                        <%
                                                }
                                                else
                                                     out.write("<br><div class=\"alert alert-error\">" + ResourceLoader.GetResource(session, "items.service.nobinding") + "</div><br>");
                                                                if (bd.getBindingTemplates() != null && !bd.getBindingTemplates().getBindingTemplate().isEmpty()) {
                                                        %>
                                                <table class="table table-hover">
                                                        <tr><th><%=ResourceLoader.GetResource(session, "items.bindingtemplate.key")%></th>
                                                                <th><%=ResourceLoader.GetResource(session, "items.accesspoint.type")%></th>
                                                                <th><%=ResourceLoader.GetResource(session, "items.accesspoint")%></th></tr>

                                                        <%
                                                                for (int i = 0; i < bd.getBindingTemplates().getBindingTemplate().size(); i++) {
                                                                        out.write("<tr>");
                                                                        out.write("<td><a href=\"bindingEditor.jsp?id=" + URLEncoder.encode(bd.getBindingTemplates().getBindingTemplate().get(i).getBindingKey(),"UTF8") + "\">");
                                                                        out.write(StringEscapeUtils.escapeHtml(bd.getBindingTemplates().getBindingTemplate().get(i).getBindingKey()));
                                                                        out.write(" <i class=\"icon-edit\"></i> ");
                                                                        out.write("</a></td>");
                                                                        out.write("<td>");

                                                                        if (bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint() != null)
                                                                              {
                                                                                if (bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getUseType() != null) {
                                                                                        out.write(StringEscapeUtils.escapeHtml(bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getUseType()));
                                                                                } else {
                                                                                        //no use type defined!
                                                                                }
                                                                        } else {
                                                                                out.write(ResourceLoader.GetResource(session, "items.hostingredirector"));
                                                                        }

                                                                        out.write("</td>");
                                                                        out.write("<td>");
                                                                        if (bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint() != null)
                                                                              {
                                                                                if (bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getValue() != null) {
                                                                                        if (bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getUseType()!=null)
                                                                                        {
                                                                                                if ("wsdlDeployment".equalsIgnoreCase(bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getUseType()))
                                                                                                {
                                                                                                        out.write("<a href=\"");
                                                                                                        out.write(StringEscapeUtils.escapeHtml(bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getValue()));
                                                                                                        out.write("\" target=\"_blank\" >");
                                                                                                        out.write(StringEscapeUtils.escapeHtml(bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getValue()));
                                                                                                        out.write("</a> <i class=\"icon-external-link\"></i>");
                                                                                                }
                                                                                                else if ("hostingRedirector".equalsIgnoreCase(bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getUseType()))
                                                                                                {
                                                                                                        out.write("<a href=\"bindingEditor.jsp?id=" + URLEncoder.encode(bd.getBindingTemplates().getBindingTemplate().get(i).getBindingKey(),"UTF8") + "\">");
                                                                                                        out.write("<i class=\"icon-edit\"></i> ");
                                                                                                        out.write(StringEscapeUtils.escapeHtml(bd.getBindingTemplates().getBindingTemplate().get(i).getBindingKey()));
                                                                                                        out.write("</a>");
                                                                                                }
                                                                                                else if ("bindingTemplate".equalsIgnoreCase(bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getUseType()))
                                                                                                {
                                                                                                        out.write("<a href=\"bindingEditor.jsp?id=" + URLEncoder.encode(bd.getBindingTemplates().getBindingTemplate().get(i).getBindingKey(),"UTF8") + "\">");
                                                                                                        out.write("<i class=\"icon-edit\"></i> ");
                                                                                                        out.write(StringEscapeUtils.escapeHtml(bd.getBindingTemplates().getBindingTemplate().get(i).getBindingKey()));
                                                                                                        out.write("</a>");
                                                                                                }
                                                                                                else if ("endPoint".equalsIgnoreCase(bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getUseType()))
                                                                                                {
                                                                                                        out.write("<a href=\"");
                                                                                                        out.write(StringEscapeUtils.escapeHtml(bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getValue()));
                                                                                                        out.write("\" target=\"_blank\" >");
                                                                                                        out.write(StringEscapeUtils.escapeHtml(bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getValue()));
                                                                                                        out.write("</a> <i class=\"icon-external-link\"></i>");
                                                                                                }
                                                                                                else {
                                                                                                        //no use type defined, try to guess if it's a href-able url
                                                                                                        if (bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getValue().toLowerCase().startsWith("http://") ||
                                                                                                             bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getValue().toLowerCase().startsWith("https://") ||
                                                                                                             bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getValue().toLowerCase().startsWith("mailto:")){
                                                                                                                out.write("<a href=\"");
                                                                                                                out.write(StringEscapeUtils.escapeHtml(bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getValue()));
                                                                                                                out.write("\" target=\"_blank\" >");
                                                                                                                out.write(StringEscapeUtils.escapeHtml(bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getValue()));
                                                                                                                out.write("</a> <i class=\"icon-external-link\"></i>");
                                                                                                                
                                                                                                        }else
                                                                                                        {
                                                                                                                //just render it
                                                                                                        out.write(StringEscapeUtils.escapeHtml(bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getValue()));        
                                                                                                        }
                                                                                                }
                                                                                                //fancy stuff goes here
                                                                                                //wsdlDeployment
                                                                                                //hostingRedirector
                                                                                                //bindingTemplate
                                                                                                //endPoint
                                                                                        }
                                                                                        else{
                                                                                                //use type isn't defined, just render it
                                                                                        out.write(StringEscapeUtils.escapeHtml(bd.getBindingTemplates().getBindingTemplate().get(i).getAccessPoint().getValue()));
                                                                                        }
                                                                                } else {
                                                                                        //no value defined!
                                                                                }
                                                                        } else {
                                                                                if (bd.getBindingTemplates().getBindingTemplate().get(i).getHostingRedirector() != null)
                                                                              {
                                                                                        if (bd.getBindingTemplates().getBindingTemplate().get(i).getHostingRedirector().getBindingKey() != null) {
                                                                                                out.write("<td><a href=\"bindingEditor.jsp?id=" + URLEncoder.encode(bd.getBindingTemplates().getBindingTemplate().get(i).getBindingKey(),"UTF8") + "\">");
                                                                                                
                                                                                                out.write(StringEscapeUtils.escapeHtml(bd.getBindingTemplates().getBindingTemplate().get(i).getHostingRedirector().getBindingKey()));
                                                                                                out.write(" <i class=\"icon-edit\"></i> ");
                                                                                                out.write("</a></td>");
                                                                                               
                                                                                        } else {
                                                                                                //no value defined!
                                                                                        }
                                                                                }
                                                                        }
                                                                        out.write("</td>");
                                                                        out.write("</tr>");
                                                                }
                                                        %>
                                                </table>
                                                <%
                                                        }
                                                %>

                                        


                                        <br>
                                </div><!-- binding template tab pane -->






                                <div class="tab-pane" id="signatures"><b><%=ResourceLoader.GetResource(session, "items.dsigs")%></b>
                                        <br>
                                        <%
                                                if (bd.getSignature().isEmpty()) {
                                                        out.write(ResourceLoader.GetResource(session, "items.signed.not"));
                                                } else {
                                                        out.write(ResourceLoader.GetResource(session, "items.signed") + " " + bd.getSignature().size());
                                        %>
                                        <table class="table table-hover">
                                                <tr><th>#</th>
                                                        <th><%=ResourceLoader.GetResource(session, "pages.signatures.signedby")%></th>
                                                        <th></th>
                                                        <th><%=ResourceLoader.GetResource(session, "pages.signatures.status")%></th></tr>

                                                <%
                                                        for (int k = 0; k < bd.getSignature().size(); k++) {
                                                                out.write("<tr><td>" + k + "</td><td>");
                                                                out.write(x.SignatureToReadable(bd.getSignature().get(k)));
                                                                out.write("</td><td>");
                                                                out.write("<a href=\"ajax/getCert.jsp?type=service&id=" + URLEncoder.encode(bd.getServiceKey(), "UTF-8") + "&index=" + k + "\">" + ResourceLoader.GetResource(session, "items.signed.viewcert") + "</a>");
                                                                out.write("</td><td><div id=\"digsig" + k + "\">" + ResourceLoader.GetResource(session, "items.loading") + "</div>");
                                                %>
                                                <script type="text/javascript">
                          $.get("ajax/validateSignature.jsp?type=service&id=<%=StringEscapeUtils.escapeJavaScript(bd.getServiceKey())%>", function(data) {
                                  $("#digsig<%=k%>").html(data);
                                  if (data.indexOf("invalid") !== -1)
                                  {
                                          $("#sigtagheader").html($("#sigtagheader").html() + "<i class=\"icon-thumbs-down icon-large\" style=\"color:red\"></i>");
                                  }
                                  else
                                  {
                                          $("#sigtagheader").html($("#sigtagheader").html() + "<i class=\"icon-thumbs-up icon-large\" style=\"color:green\"></i>");
                                  }
                          })
                                                </script>
                                                <%
                                                                out.write("</td></tr>");
                                                        }
                                                %>
                                        </table>
                                        <%
                                                }
                                        %>
                                        <br><Br>
                                </div>

                                <div class="tab-pane" id="opinfo">
                                        <%
                                                if (!newitem) {

                                        %>
                                        <script type="text/javascript">
                       $.get("ajax/opInfo.jsp?id=<%=StringEscapeUtils.escapeJavaScript(bd.getServiceKey())%>", function(data) {
                               $("#opinfodiv").html(data);
                       })
                                        </script>
                                        <div id="opinfodiv"></div>
                                        <%
                                                }
                                        %>
                                        <Br>
                                </div><!-- end opinfo-->
                        </div><!-- tab content -->
                </div><!-- end business editor -->


                <script type="text/javascript">
              var currentDescriptionSpecific =<%=totalBTDescriptions%>;
                </script>
                <Br><br>
                <%
                        if (bd.getSignature().isEmpty()) {
                %>
                <a class="btn btn-primary " href="javascript:saveService();"><i class="icon-save icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.save")%></a>


                <%  } else {
                %>
                <a href="#confirmDialog" role="button" class="btn btn-primary" data-toggle="modal"><i class="icon-save icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.save")%></a> |

                <%        }
                        if (!newitem) {
                %>


                <a class="btn btn-danger " href="javascript:deleteService();"><i class="icon-trash icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.delete")%></a> |
                <a class="btn btn-success " href="signer.jsp?id=<%=URLEncoder.encode(bd.getServiceKey(), "UTF-8")%>&type=service"><i class="icon-pencil icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.sign")%></a> |
                <a class="btn btn-info " href="editSubscription.jsp?svcid=<%=URLEncoder.encode(bd.getServiceKey(), "UTF-8")%>" title="<%=ResourceLoader.GetResource(session, "actions.subscribe.description")%>"><i class="icon-rss icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.subscribe")%></a> |
                <a class="btn btn-warning " href="transfer.jsp?biz=<%=URLEncoder.encode(bd.getBusinessKey(), "UTF-8")%>" title="<%=ResourceLoader.GetResource(session, "actions.transfer.description")%>"><i class="icon-exchange icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.transfer")%></a> |
                <a class="btn "  href="javascript:ViewAsXML();"><i class="icon-screenshot icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.asxml")%></a>
                <script type="text/javascript">
                        function ViewAsXML()
                        {
                                $.get("ajax/toXML.jsp?id=<%=URLEncoder.encode(serviceid, "UTF-8")%>&type=service", function(data) {
                                        window.console && console.log('asXml success');
                                        $("#viewAsXmlContent").html(safe_tags_replace(data));
                                        $("#viewAsXml").modal('show');
                                });

                        }
                        function saveAnyhow() {
                                saveService();
                                $('#confirmDialog').modal('hide');
                        }
                </script>
                <%
                        }
                %>
        </div> <!-- end of the row -->

        <script type="text/javascript" src="js/businessEditor.js"></script>
        <script type="text/javascript" src="js/serviceEditor.js"></script>
</div> <!-- span12-->

<div class="modal hide fade container" id="confirmDialog">
        <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                <h3><%=ResourceLoader.GetResource(session, "modal.digitalsignaturewarning.title")%></h3>
        </div>
        <div class="modal-body">
                <p><%=ResourceLoader.GetResource(session, "modal.digitalsignaturewarning.body")%></p>
        </div>
        <div class="modal-footer">
                <a href="javascript:closeXmlPop('confirmDialog');" class="btn"><%=ResourceLoader.GetResource(session, "modal.close")%></a>
                <a href="javascript:saveAnyhow();" class="btn btn-primary">
                        <%=ResourceLoader.GetResource(session, "modal.savechanges")%></a>
        </div>
</div>
<%
        if (!newitem) {

%>
<div class="modal hide fade container" id="viewAsXml">
        <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                <h3><%=ResourceLoader.GetResource(session, "actions.asxml")%> </h3>
        </div>

        <div class="modal-body" id="viewAsXmlContent">


        </div>
        <div class="modal-footer">
                <a href="ajax/toXML.jsp?id=<%=URLEncoder.encode(bd.getServiceKey(), "UTF-8")%>&type=service" class="btn btn-primary" target="_blank"><%=ResourceLoader.GetResource(session, "actions.popout")%></a> 
                <a href="javascript:closeXmlPop('viewAsXml');" class="btn"><%=ResourceLoader.GetResource(session, "modal.close")%></a>
        </div>
</div>
<%
        }
%>

<%@include file="tmodelChooser.jsp" %>
<%@include file="keyHelpModal.jsp" %>
<!-- container div is in header bottom-->
<%@include file="header-bottom.jsp" %>

