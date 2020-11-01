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

<%@page import="java.net.URLEncoder"%>
<%@page import="org.uddi.api_v3.*"%>
<%@page import="org.apache.juddi.webconsole.PostBackConstants"%>
<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>


<%//@include file="csrf.jsp" 
        boolean newitem = false;
        String bindingid = request.getParameter("id");
        String serviceid = request.getParameter("svcid");
        if (bindingid == null && serviceid == null) {
                response.sendRedirect("index.jsp");
        }
        if (bindingid == null || bindingid.length() == 0) {
                //response.sendRedirect("browse.jsp");
                if (serviceid != null && serviceid.length() > 0) {
                        newitem = true;
                } else {
                        //no service id or business id
                        response.sendRedirect("index.jsp");
                }

        }

        UddiHub x = UddiHub.getInstance(application, request.getSession());

        BindingTemplate bd = null;
        if (!newitem) {
                bd = x.GetBindingDetailsAsObject(bindingid);
        } else {
                bd = new BindingTemplate();
                bd.setServiceKey(serviceid);
                BusinessService be = x.GetServiceDetail(serviceid);
                if (be == null) {
                        //incase an invalid business id was passed in
                        response.sendRedirect("index.jsp");
                } else {
                        bd.setServiceKey(be.getServiceKey());
                }
        }

        if (bd == null) {

                //we can't make a new binding without a service to reference
                response.sendRedirect("index.jsp");
                return;
        }
%>
<%@include file="header-top.jsp" %>
<div class="container">
        <script type="text/javascript" src="js/bindingeditor.js"></script>
        <!-- Main hero unit for a primary marketing message or call to action -->
        <div class="well" >
                <h1><%=ResourceLoader.GetResource(session, "pages.bindingeditor.title")%></h1>
        </div>

        <!-- Example row of columns -->
        <div class="row">
                <div class="span12" >

                        <div id="bindingeditor">
                                <%

                                        int totalBTDescriptions = 0;
                                %>

                                <i class="icon-lock icon-large"></i>

                                <b><%=ResourceLoader.GetResource(session, "items.service.key")%></b> 
                                <br>
                                <div style="border-width: 2px; border-style: solid;" class="noedit" id="<%=PostBackConstants.SERVICEKEY%>">
                                        <%
                                                if (bd == null || bd.getServiceKey() == null) {
                                                        out.write("");
                                                } else {
                                                        out.write("<a href=\"serviceEditor.jsp?id=" + StringEscapeUtils.escapeHtml(bd.getServiceKey()) + "\">");
                                                        out.write(StringEscapeUtils.escapeHtml(bd.getServiceKey()));
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
                                <b><%=ResourceLoader.GetResource(session, "items.bindingtemplate.key")%> </b>-
                                <%=ResourceLoader.GetResource(session, "items.bindingtemplate.description")%> 
                                <a href="javascript:ShowKeyHelp();"><i class="icon-question-sign icon-large"></i> <%=ResourceLoader.GetResource(session, "navbar.help")%></a>
                                <div style="border-width: 2px; border-style: solid;" <%
                                        if (!newitem) {
                                                out.write("class=\"noedit\"");
                                        } else {
                                                out.write("class=\"edit\"");
                                        }
                                     %>
                                     id="<%=PostBackConstants.BINDINGKEY%>">
                                        <%
                                                if (!newitem) {
                                                        out.write(StringEscapeUtils.escapeHtml(bd.getBindingKey()));
                                                }

                                                int currentcatkeyrefBT = 0;
                                                int currentcatkeyrefgrpBT = 0;
                                                int currentbindingtemplatesInstance = 0;
                                                int currentOverviewDocs = 0;

                                                if (bd.getCategoryBag() != null) {
                                                        currentcatkeyrefBT += bd.getCategoryBag().getKeyedReference().size();
                                                        currentcatkeyrefgrpBT += bd.getCategoryBag().getKeyedReferenceGroup().size();
                                                }

                                                if (bd.getTModelInstanceDetails() != null) {
                                                        currentbindingtemplatesInstance = bd.getTModelInstanceDetails().getTModelInstanceInfo().size();
                                                }
                                                if (bd.getTModelInstanceDetails() != null) {
                                                        for (int k = 0; k < bd.getTModelInstanceDetails().getTModelInstanceInfo().size(); k++) {
                                                                if (bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails() != null) {
                                                                        currentOverviewDocs += bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getOverviewDoc().size();
                                                                }
                                                        }
                                                }


                                        %>
                                </div>
                                <br>

                                <script type="text/javascript">
                    var currentbindingtemplatesInstance =<%=currentbindingtemplatesInstance%>;
                    var currentDescriptionEntries =<%= bd.getDescription().size() - 1%>;
                    var currentcatkeyrefBT =<%=currentcatkeyrefBT%>;
                    var currentcatkeyref =<%=bd.getCategoryBag().getKeyedReference().size()%>;
                    var currentcatkeyrefgrpBT =<%=currentcatkeyrefgrpBT%>;
                    var currentcatkeyrefgrp =<%=bd.getCategoryBag().getKeyedReferenceGroup().size()%>;
                    var currentOverviewDocs = <%=currentOverviewDocs%>;
                                </script> 

                                <ul class="nav nav-tabs" id="myTab">
                                        <li class="active"><a  href="#general"><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.general")%></a></li>

                                        <li><a href="#categories" ><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.categories")%></a></li>

                                        <li><a href="#accesspoint" ><%=ResourceLoader.GetResource(session, "items.accesspoint")%></a></li>

                                        <li><a href="#instanceinfo" ><%=ResourceLoader.GetResource(session, "items.tmodelinstance.info")%></a></li>

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
                                        $('#myTab a[href=#accesspoint]').click(function(e) {
                                                e.preventDefault();
                                                $(this).tab('show');
                                        });
                                        $('#myTab a[href=#instanceinfo]').click(function(e) {
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





                                                <b><%=ResourceLoader.GetResource(session, "items.description")%> </b>- 
                                                <%=ResourceLoader.GetResource(session, "items.services.description")%><br>
                                                <a href="javascript:AddDescription('Description');"><i class="icon-plus-sign icon-large"></i> <%=ResourceLoader.GetResource(session, "items.description.add")%></a>

                                                <div id="Description" style="border-width: 2px; border-style: solid;" >
                                                        <%
                                                                for (int i = 0; i < bd.getDescription().size(); i++) {
                                                                        out.write("<div id=\"" + PostBackConstants.DESCRIPTION + i + "\" style=\"border-width:1px; border-style:solid\">");
                                                                        out.write("<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('Description" + i + "');\"><i class=\"icon-trash icon-large\"></i>&nbsp;</a></div>");
                                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.value") + ":&nbsp;</div>"
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
                                                
                                                <%@include  file="quickref_catbag.jsp" %>        
                                                
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

                                        <div class="tab-pane" id="accesspoint">

                                                <b><%=ResourceLoader.GetResource(session, "items.accesspoint")%></b> - <%=ResourceLoader.GetResource(session, "items.accesspoint.description")%><br>
                                                <%

                           //items.hostingredirector
                                                        //TODO need an html select in here?
                                                
                                                if (bd.getHostingRedirector() == null && 
                                                     bd.getAccessPoint()==null)
                                                {
                                                        bd.setAccessPoint(new AccessPoint());
                                                }
                                                if (bd.getHostingRedirector() != null) {
                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.hostingredirector") + ": &nbsp;</div>"
                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.HOSTINGREDIRECTOR + "\">" + 
                                                            (bd.getHostingRedirector().getBindingKey()==null ? "" :StringEscapeUtils.escapeHtml(bd.getHostingRedirector().getBindingKey())) + "</div>");
                                                }
                                                if (bd.getAccessPoint() != null) {

                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.accesspoint.type") + ": &nbsp;</div>"
                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.ACCESSPOINT_TYPE + "\">" + 
                                                             (bd.getAccessPoint().getUseType()==null?"":StringEscapeUtils.escapeHtml(bd.getAccessPoint().getUseType())) + "</div>");
                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.accesspoint.value") + ": &nbsp;</div>"
                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.ACCESSPOINT_VALUE + "\">" + 
                                                             (bd.getAccessPoint().getValue()==null?"":StringEscapeUtils.escapeHtml(bd.getAccessPoint().getValue())) + "</div>");
                                                        // this was an unbalanced divout.write("</div>");
                                                }
                                                %>

                                        </div>
                                        <div class="tab-pane" id="instanceinfo">   
                                                <b><%=ResourceLoader.GetResource(session, "items.tmodelinstance.info")%></b> - <%=ResourceLoader.GetResource(session, "items.tmodelinstance.info.desc")%> <br>
                                                <a href="javascript:AddTmodelInstance('<%=PostBackConstants.TMODELINSTANCE%>');"><i class="icon-plus-sign icon-large"></i></a> <%=ResourceLoader.GetResource(session, "items.tmodelinstance.add")%><br>
        
                                                <%@include file="quickref_tmodelinstance.jsp" %>
                                                
                                                <div id="<%=PostBackConstants.TMODELINSTANCE%>" >        
                                                        <%
                                                                if (bd.getTModelInstanceDetails() != null) {
                                                                        for (int k = 0; k < bd.getTModelInstanceDetails().getTModelInstanceInfo().size(); k++) {
                                                        %>
                                                        <div id="<%=PostBackConstants.TMODELINSTANCE + k%>" style="border-width: 2px; border-style: solid " >        
                                                                <%
                                                                        out.write("<div style=\"float:left;height:100%\">"
                                                                             + "<a href=\"javascript:Remove('" + PostBackConstants.TMODELINSTANCE + k + "');\"><i class=\"icon-trash icon-large\"></i>&nbsp;</a></div>");

                                                                        out.write("<div style=\"float:left\"><b>" + ResourceLoader.GetResource(session, "items.tmodel.key") + " </b> (<a href=\"javascript:tModelModal('" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.KEYNAME + "')\" ><i class=\"icon-list-alt icon-large\"></i>" + ResourceLoader.GetResource(session, "items.picker") + "</a>) "
                                                                             + "<a href=\"tmodelEditor.jsp?id=" + URLEncoder.encode(bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getTModelKey(), "UTF8") + "\"><i class=\"icon-zoom-in icon-large\"></i></a>"
                                                                             + ": &nbsp;</div>"
                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.KEYNAME + "\">" + StringEscapeUtils.escapeHtml(bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getTModelKey()) + "</div>");
                                                                    //  out.write("<div style=\"float:left\"><span title=\"Instance Params\">Value</span>:&nbsp;</div>"
                                                                        //          + "<div class=\"edit\" id=\"" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.VALUE + "\">" + ((bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails() != null) ? StringEscapeUtils.escapeHtml(bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getInstanceParms()) : "") + "</div>");
                                                                %>
                                                                <br>
                                                                <%
                                                                        out.write("<div style=\"float:left\"><b>" + ResourceLoader.GetResource(session, "items.tmodelinstance.parameters") + ":</b> &nbsp;</div>"
                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.VALUE + "\">");
                                                                        if (bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails() != null
                                                                             && bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getInstanceParms() != null) {

                                                                                out.write(StringEscapeUtils.escapeHtml(bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getInstanceParms()));
                                                                        }
                                                                        out.write("</div>");
                                                                %>
                                                                <br>

                                                                <b>
                                                                        <%=ResourceLoader.GetResource(session, "items.tmodelinstance.description")%>
                                                                </b> - <%=ResourceLoader.GetResource(session, "items.tmodelinstance.description2")%> <br>
                                                                <a href="javascript:AddDescriptionSpecific('<%=PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.DESCRIPTION%>');"><i class="icon-plus-sign icon-large"></i></a> <%=ResourceLoader.GetResource(session, "items.tmodelinstance.description.add")%><br>
                                                                <div id="<%=PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.DESCRIPTION%>" style="border-width: 1px; border-style: groove;" >
                                                                        <%
                                                                                for (int j = 0; j < bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getDescription().size(); j++) {
                                                                                        out.write("<div id=\"" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.DESCRIPTION + j + "\" style=\"border-width:1px; border-style:solid\">");
                                                                                        out.write("<div style=\"float:left;height:100%\">"
                                                                                             + "<a href=\"javascript:Remove('" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.DESCRIPTION + j + "');\"><i class=\"icon-trash icon-large\"></i>&nbsp;</a></div>");
                                                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.name") + ":&nbsp;</div>"
                                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.DESCRIPTION + j + PostBackConstants.VALUE + "\">" + StringEscapeUtils.escapeHtml(bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getDescription().get(j).getValue()) + "</div>");
                                                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.lang") + ":&nbsp;</div>"
                                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.DESCRIPTION + j + PostBackConstants.LANG + "\">"
                                                                                             + (bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getDescription().get(j).getLang() == null ? " " : StringEscapeUtils.escapeHtml(bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getDescription().get(j).getLang()))
                                                                                             + "</div>");
                                                                                        out.write("</div>");
                                                                                }

                                                                        %>
                                                                </div>

                                                                <div><br>
                                                                        <b><%=ResourceLoader.GetResource(session, "items.overviewurl")%></b> - <%=ResourceLoader.GetResource(session, "items.overviewurl.description")%> <br>
                                                                        <a href="javascript:AddOverviewDocumentSpecific('<%=PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.OVERVIEW%>');"><i class="icon-plus-sign icon-large"></i></a> <%=ResourceLoader.GetResource(session, "items.overviewurl.add")%><br>
                                                                        <div id="<%=PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.OVERVIEW%>" style="border-width: 1px; border-style: groove;" >
                                                                                <%
                                                                                        //  out.write("<div id=\"" + PostBackConstants.OVERVIEW + "\" style=\"border-width:2px; border-style:solid\">");
                                                                                        if (bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails() != null)
                                                                                                for (int j = 0; j < bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getOverviewDoc().size(); j++) {
                                                                                                        if (bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getOverviewDoc().get(j) == null) {
                                                                                                                continue;
                                                                                                        }
                                                                                                        out.write("<div id=\"" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.OVERVIEW + j + "\" style=\"border-width:1px; border-style:solid\">");

                                                                                                        if (bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getOverviewDoc().get(j).getOverviewURL() != null) {
                                                                                                                out.write("<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.OVERVIEW + j + "');\"><i class=\"icon-trash icon-large\"></i>&nbsp;</a></div>");
                                                                                                                out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.value") + ":&nbsp;</div>"
                                                                                                                     + "<div class=\"edit\" id=\"" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.OVERVIEW + j + PostBackConstants.VALUE + "\">" + (bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getOverviewDoc().get(j).getOverviewURL().getValue() != null ? StringEscapeUtils.escapeHtml(bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getOverviewDoc().get(j).getOverviewURL().getValue()) : "") + "</div>");
                                                                                                                out.write("<div style=\"float:left\">Use type:&nbsp;</div>"
                                                                                                                     + "<div class=\"edit\" id=\"" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.OVERVIEW + j + PostBackConstants.TYPE + "\">" + (bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getOverviewDoc().get(j).getOverviewURL().getUseType() != null ? StringEscapeUtils.escapeHtml(bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getOverviewDoc().get(j).getOverviewURL().getUseType()) : "") + "</div>");
                                                                                                        }

                                                                                %>
                                                                                <br><b><%=ResourceLoader.GetResource(session, "items.overviewdocument.description")%> </b><br>
                                                                                <a href="javascript:AddDescriptionSpecific('<%=PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.OVERVIEW + j + PostBackConstants.DESCRIPTION%>');"><i class="icon-plus-sign icon-large"></i></a><%=ResourceLoader.GetResource(session, "items.overviewurl.description.add")%>
                                                                                <div id="<%=PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.OVERVIEW + j + PostBackConstants.DESCRIPTION%>" style="border-width: 1px; border-style: groove;" >
                                                                                        <%
                                                                                                //  out.write("<div id=\"" + PostBackConstants.OVERVIEW + "\" style=\"border-width:2px; border-style:solid\">");
                                                                                                for (int h = 0; h < bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getOverviewDoc().get(j).getDescription().size(); h++) {
                                                                                                        out.write("<div id=\"" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.OVERVIEW + j + PostBackConstants.DESCRIPTION + h + "\" style=\"border-width:1px; border-style:solid\">");
                                                                                                        out.write("<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.OVERVIEW + j + PostBackConstants.DESCRIPTION + h + "');\"><i class=\"icon-trash icon-large\"></i>&nbsp;</a></div>");
                                                                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.value") + ":&nbsp;</div>"
                                                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.OVERVIEW + j + PostBackConstants.DESCRIPTION + h + PostBackConstants.VALUE + "\">" + StringEscapeUtils.escapeHtml(bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getOverviewDoc().get(j).getDescription().get(h).getValue()) + "</div>");
                                                                                                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.lang") + ":&nbsp;</div>"
                                                                                                             + "<div class=\"edit\" id=\"" + PostBackConstants.TMODELINSTANCE + k + PostBackConstants.INSTANCE + PostBackConstants.OVERVIEW + j + PostBackConstants.DESCRIPTION + h + PostBackConstants.LANG + "\">"
                                                                                                             + (bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getOverviewDoc().get(j).getDescription().get(h).getLang() == null ? "" : StringEscapeUtils.escapeHtml(bd.getTModelInstanceDetails().getTModelInstanceInfo().get(k).getInstanceDetails().getOverviewDoc().get(j).getDescription().get(h).getLang())) + "</div>");
                                                                                                        out.write("</div>");
                                                                                                }
                                                                                        %>
                                                                                </div>
                                                                                <%
                                                                                                out.write("</div>");
                                                                                        }
                                                                                %>

                                                                        </div>

                                                                </div>

                                                        </div>
                                                        <br>

                                                        <%    } //end of instance details
                                                        %>

                                                        <%
                                                                }
                                                        %>
                                                </div>
                                        </div>





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
                          $.get("ajax/validateSignature.jsp?type=bindingTemplate&id=<%=StringEscapeUtils.escapeJavaScript(bd.getBindingKey())%>", function(data) {
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
                       $.get("ajax/opInfo.jsp?id=<%=StringEscapeUtils.escapeJavaScript(bd.getBindingKey())%>", function(data) {
                               $("#opinfodiv").html(data);
                       })
                                                </script>
                                                <div id="opinfodiv"> </div>
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
                        <a class="btn btn-primary " href="javascript:saveBinding();"><i class="icon-save icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.save")%></a>


                        <%  } else {
                        %>
                        <a href="#confirmDialog" role="button" class="btn btn-primary" data-toggle="modal"><i class="icon-save icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.save")%></a> |

                        <%        }
                                if (!newitem) {
                        %>

| 
                        <a class="btn btn-danger " href="javascript:deleteBinding();"><i class="icon-trash icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.delete")%></a> |
                        <a class="btn btn-success " href="signer.jsp?id=<%=URLEncoder.encode(bd.getBindingKey(), "UTF-8")%>&type=bindingTemplate"><i class="icon-pencil icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.sign")%></a> |
                        <a class="btn btn-info " href="editSubscription.jsp?bindingTemplate=<%=URLEncoder.encode(bd.getBindingKey(), "UTF-8")%>" title="<%=ResourceLoader.GetResource(session, "actions.subscribe.description")%>"><i class="icon-rss icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.subscribe")%></a> |
                        <a class="btn "  href="javascript:ViewAsXML();"><i class="icon-screenshot icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.asxml")%></a>
                        <script type="text/javascript">
                                function ViewAsXML()
                                {
                                        $.get("ajax/toXML.jsp?id=<%=URLEncoder.encode(bindingid, "UTF-8")%>&type=bindingTemplate", function(data) {
                                                window.console && console.log('asXml success');
                                                $("#viewAsXmlContent").html(safe_tags_replace(data));
                                                $("#viewAsXml").modal('show');
                                        });

                                }
                                function saveAnyhow() {
                                        $('#confirmDialog').modal('hide');
                                        saveBinding();
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
                        <a href="ajax/toXML.jsp?id=<%=URLEncoder.encode(bd.getBindingKey(), "UTF-8")%>&type=bindingTemplate" class="btn btn-primary" target="_blank"><%=ResourceLoader.GetResource(session, "actions.popout")%></a> 
                        <a href="javascript:closeXmlPop('viewAsXml');" class="btn"><%=ResourceLoader.GetResource(session, "modal.close")%></a>
                </div>
        </div>
        <%
                }
        %>


        <script type="text/javascript">


                      function saveBinding() {
                              var url = 'ajax/savebinding.jsp';
                              var postbackdata = new Array();
                              $("div.edit").each(function()
                              {

                                      var id = $(this).attr("id");
                                      var value = $(this).text();
                                      postbackdata.push({
                                              name: id,
                                              value: value
                                      });
                              });
                              postbackdata.push({
                                      name: "nonce",
                                      value: $("#nonce").val()
                              });
                              $("div.noedit").each(function()
                              {
                                      var id = $(this).attr("id");
                                      var value = $(this).text();
                                      postbackdata.push({
                                              name: id,
                                              value: value
                                      });
                              });


                              var request = $.ajax({
                                      url: url,
                                      type: "POST",
                                      //  data" + i18n_type + ": "html", 
                                      cache: false,
                                      //  processData: false,f
                                      data: postbackdata
                              });
                              request.done(function(msg) {
                                      window.console && console.log('postback done ' + url);

                                      $("#alert_results").html('<i class="icon-2x icon-thumbs-up"></i><br>' + msg);
                                      $("#alert").modal();
                              });

                              request.fail(function(jqXHR, textStatus) {
                                      window.console && console.log('postback failed ' + url);
                                      $("#alert_results").html('<i class="icon-2x icon-thumbs-down"></i><br>' + jqXHR.responseText + textStatus);
                                      $("#alert").modal();
                              });


                      }
                      function deleteBinding() {
                              var url = 'ajax/deletebinding.jsp';
                              var postbackdata = new Array();
                                      postbackdata.push({
                                              name: "id",
                                              value: $("#" + "<%=PostBackConstants.BINDINGKEY%>").text().trim()
                                      });
                                      postbackdata.push({
                                              name: "svcid",
                                              value: $("#" + "<%=PostBackConstants.SERVICEKEY %>").text().trim()
                                      });
                                      
                                      
                              
                              postbackdata.push({
                                      name: "nonce",
                                      value: $("#nonce").val()
                              });
                              
                              var request = $.ajax({
                                      url: url,
                                      type: "POST",
                                      //  data" + i18n_type + ": "html", 
                                      cache: false,
                                      //  processData: false,f
                                      data: postbackdata
                              });
                              request.done(function(msg) {
                                      window.console && console.log('postback done ' + url);

                                      $("#alert_results").html('<i class="icon-2x icon-thumbs-up"></i><br>' + msg);
                                      $("#alert").modal();
                              });

                              request.fail(function(jqXHR, textStatus) {
                                      window.console && console.log('postback failed ' + url);
                                      $("#alert_results").html('<i class="icon-2x icon-thumbs-down"></i><br>' + jqXHR.responseText + textStatus);
                                      $("#alert").modal();
                              });
                      }
        </script>

        <%@include file="tmodelChooser.jsp" %>
        <%@include file="keyHelpModal.jsp" %>
        <!-- container div is in header bottom-->
        <%@include file="header-bottom.jsp" %>

