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
    Document   : tmodelEditor
    Created on : Feb 27, 2013, 9:31:19 PM
    Author     : Alex O'Ree
--%>



<%@page import="java.net.URLEncoder"%>
<%@page import="org.uddi.api_v3.*"%>
<%@page import="org.apache.juddi.webconsole.PostBackConstants"%>
<%@page import="org.apache.juddi.webconsole.hub.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include file="header-top.jsp" %>
<div class="container">

   <!-- Main hero unit for a primary marketing message or call to action -->
   <div class="well">
      <h1><%=ResourceLoader.GetResource(session, "pages.tmodeleditor.title")%></h1>
   </div>

   <!-- Example row of columns -->
   <div class="row">
      <div class="span12">
         <p>
            <%
               UddiHub x = UddiHub.getInstance(application, session);
               TModel bd = hub.getTmodelDetails(request.getParameter("id"));
               boolean newitem = false;
               if (bd == null) {
                  bd = new TModel();
                  newitem = true;
               }
            %>

         <ul class="nav nav-tabs" id="myTab">
            <li class="active"><a  href="#general"><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.general")%></a></li>

            <li><a href="#discovery" ><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.overview")%></a></li>

            <li><a href="#categories" ><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.categories")%></a></li>

            <li><a href="#identifiers" ><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.identifiers")%></a></li>

            <li><a href="#signatures"  id="sigtagheader"><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.signatures")%></a></li>
            <li><a href="#Instances" ><%=ResourceLoader.GetResource(session, "pages.editor.tmodel.instances")%></a></li>
            <li><a href="#opinfo" ><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.opinfo")%></a></li>

         </ul>
         <script type="text/javascript">
            $(function() {
               $('#myTab').tab;//('show');
            })
            $('#myTab a[href=#general]').click(function(e) {
               e.preventDefault();
               $(this).tab('show');
            });
            $('#myTab a[href=#discovery]').click(function(e) {
               e.preventDefault();
               $(this).tab('show');
            });

            $('#myTab a[href=#categories]').click(function(e) {
               e.preventDefault();
               $(this).tab('show');
            });
            $('#myTab a[href=#identifiers]').click(function(e) {
               e.preventDefault();
               $(this).tab('show');
            });

            $('#myTab a[href=#signatures]').click(function(e) {
               e.preventDefault();
               $(this).tab('show');
            });
            $('#myTab a[href=#Instances]').click(function(e) {
               e.preventDefault();
               $(this).tab('show');
            });

            $('#myTab a[href=#opinfo]').click(function(e) {
               e.preventDefault();
               $(this).tab('show');
            });

            var currentDescriptionEntries =<%=bd.getDescription().size()%>;
            var currentOverviewDocs =<%=bd.getOverviewDoc().size()%>;
            <%
               int currentDescriptionSpecific = 0;
               if (bd.getOverviewDoc() != null) {
                  for (int i = 0; i < bd.getOverviewDoc().size(); i++) {
                     if (bd.getOverviewDoc().get(i) == null) {
                        continue;
                     }
                     currentDescriptionSpecific += bd.getOverviewDoc().get(i).getDescription().size();
                  }
               }

               int currentcatkeyref = 0;
               int currentcatkeyrefgrp=0;
               if (bd.getCategoryBag() != null) {
                  currentcatkeyref = bd.getCategoryBag().getKeyedReference().size();
                  currentcatkeyrefgrp =bd.getCategoryBag().getKeyedReferenceGroup().size();
               }
               
               int currentident = 0;
               if (bd.getIdentifierBag() != null) {
                  currentident = bd.getIdentifierBag().getKeyedReference().size();
               }
            %>
            var currentcatkeyref =<%=currentcatkeyref%>;
            var currentDescriptionSpecific =<%=currentDescriptionSpecific%>;
            var currentident =<%=currentident%>;
            var currentcatkeyrefgrp =<%=currentcatkeyrefgrp%>;
         </script>
         <div class="tab-content">
            <div class="tab-pane active" id="general">
               <%
                  if (!newitem) {
                     out.write("<i class=\"icon-lock icon-large\"></i> ");
                  }
               %>
               <%= ResourceLoader.GetResource(session, "items.tmodel.key.description")%>
               <a href="javascript:ShowKeyHelp();"><i class="icon-question-sign icon-large"></i> <%=ResourceLoader.GetResource(session, "navbar.help")%></a>

               <div style="border-width: 2px; border-style: solid;" <%
                  if (!newitem) {
                     out.write("class=\"noedit\"");
                  } else {
                     out.write("class=\"edit\"");
                  }
                    %>
                    id="<%=PostBackConstants.SERVICEKEY%>"><%
                       if (!newitem) {
                          out.write(StringEscapeUtils.escapeHtml(bd.getTModelKey()));
                       }
                  %></div><br>


               <%=ResourceLoader.GetResource(session, "items.tmodel.name")%>

               <%

                  if (bd.getName() == null) {
                     bd.setName(new Name());
                  }
                  out.write("<div id=\"" + PostBackConstants.NAME + "\" style=\"border-width:2px; border-style:solid\" >");
                  //out.write("<div style=\"float:left; height:100%\"><a href=\"javascript:Remove('Name');\"><i class=\"icon-trash icon-large\"></i></a></div>");
                  out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.value") + ":&nbsp;</div>"
                          + "<div class=\"edit\" id=\"" + PostBackConstants.NAME + PostBackConstants.VALUE + "\">" + (bd.getName().getValue() == null ? " " : StringEscapeUtils.escapeHtml(bd.getName().getValue())) + "</div>");
                  out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.lang") + ":&nbsp;</div>"
                          + "<div class=\"edit\" id=\"" + PostBackConstants.NAME + PostBackConstants.LANG + "\">"
                          + ((bd.getName().getLang() == null ? " " : StringEscapeUtils.escapeHtml(bd.getName().getLang())))
                          + "</div>");

                  out.write("</div>");

               %>

               <Br>
               <a href="javascript:AddDescription();"><i class="icon-plus-sign icon-large"></i></a><b><%=ResourceLoader.GetResource(session, "items.description")%> </b> - <%=ResourceLoader.GetResource(session, "items.tmodel.description")%>
               <div id="Description" style="border-width: 2px; border-style: solid;" >
                  <%
                     if (bd.getDescription() != null) //bd.(new Description());
                     {
                        for (int i = 0; i < bd.getDescription().size(); i++) {
                           out.write("<div id=\"" + PostBackConstants.DESCRIPTION + i + "\" style=\"border-width:1px; border-style:solid\">");
                           out.write("<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('Description" + i + "');\"><i class=\"icon-trash icon-large\"></i></a></div>");
                           out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.value") + ":&nbsp;</div>"
                                   + "<div class=\"edit\" id=\"" + PostBackConstants.DESCRIPTION + i + PostBackConstants.VALUE + "\">" + StringEscapeUtils.escapeHtml(bd.getDescription().get(i).getValue()) + "</div>");
                           out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.lang") + ":&nbsp;</div>"
                                   + "<div class=\"edit\" id=\"" + PostBackConstants.DESCRIPTION + i + PostBackConstants.LANG + "\">"
                                   + (bd.getDescription().get(i).getLang() != null
                                   ? StringEscapeUtils.escapeHtml(bd.getDescription().get(i).getLang()) : "")
                                   + "</div>");

                           out.write("</div>");
                        }
                     }
                  %>
               </div>

               <input type="checkbox" id="<%=PostBackConstants.TMODEL_DELETED%>" class="noedit" <%
                  if (bd.isDeleted()) {
                     out.write("checked=checked");
                  }
                      %>> <%=ResourceLoader.GetResource(session, "pages.editor.tmodel.deleted")%><br>
            </div>

            <div class="tab-pane " id="discovery">
               <a href="javascript:AddOverviewDocument();"><i class="icon-plus-sign icon-large"></i></a><%=ResourceLoader.GetResource(session, "pages.editor.tabnav.overview")%> - <%=ResourceLoader.GetResource(session, "pages.editor.tabnav.overview.description")%>
                  <%
                     out.write("<div id=\"" + PostBackConstants.OVERVIEW + "\" style=\"border-width:2px; border-style:solid\">");
                     if (bd.getOverviewDoc() != null)
                        for (int i = 0; i < bd.getOverviewDoc().size(); i++) {
                           if (bd.getOverviewDoc().get(i) == null) {
                              continue;
                           }
                           out.write("<div id=\"" + PostBackConstants.OVERVIEW + i + "\" style=\"border-width:1px; border-style:solid\">");
                           out.write("<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('" + PostBackConstants.OVERVIEW + i + "');\"><i class=\"icon-trash icon-large\"></i></a></div>");
                           out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.value") + ":&nbsp;</div>"
                                   + "<div class=\"edit\" id=\"" + PostBackConstants.OVERVIEW + i + PostBackConstants.VALUE + "\">" + StringEscapeUtils.escapeHtml(bd.getOverviewDoc().get(i).getOverviewURL().getValue()) + "</div>");
                           out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.type") + ":&nbsp;</div>"
                                   + "<div class=\"edit\" id=\"" + PostBackConstants.OVERVIEW + i + PostBackConstants.TYPE + "\">" + StringEscapeUtils.escapeHtml(bd.getOverviewDoc().get(i).getOverviewURL().getUseType()) + "</div>");

                  %>

               <a href="javascript:AddDescriptionSpecific('<%=PostBackConstants.OVERVIEW + i + PostBackConstants.DESCRIPTION%>');"><i class="icon-plus-sign icon-large"></i></a> <%=ResourceLoader.GetResource(session, "items.description.add")%>
                  <%
                           out.write("<div id=\"" + PostBackConstants.OVERVIEW + i + PostBackConstants.DESCRIPTION + "\" style=\"border-width:1px; border-style:dotted\">");
                           for (int k = 0; k < bd.getOverviewDoc().get(i).getDescription().size(); k++) {
                              out.write("<div id=\"" + PostBackConstants.OVERVIEW + i + PostBackConstants.DESCRIPTION + k + "\" style=\"border-width:1px; border-style:solid\">");
                              out.write("<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('" + PostBackConstants.OVERVIEW + i + PostBackConstants.DESCRIPTION + k + "');\"><i class=\"icon-trash\"></i></a></div>");
                              out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.value") + ":&nbsp;</div>"
                                      + "<div class=\"edit\" id=\"" + PostBackConstants.OVERVIEW + i + PostBackConstants.DESCRIPTION + k + PostBackConstants.VALUE + "\">" + StringEscapeUtils.escapeHtml(bd.getOverviewDoc().get(i).getDescription().get(k).getValue()) + "</div>");
                              out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.lang") + ":&nbsp;</div>"
                                      + "<div class=\"edit\" id=\"" + PostBackConstants.OVERVIEW + i + PostBackConstants.DESCRIPTION + k + PostBackConstants.LANG + "\">" + StringEscapeUtils.escapeHtml(bd.getOverviewDoc().get(i).getDescription().get(k).getLang()) + "</div>");
                              out.write("</div>"); //end of this instance of overview doc description
                           }
                           out.write("</div>");//end description
                           out.write("</div>");//end this block
                        }
                     out.write("</div>");//end of overview
%>

            </div>

            <div class="tab-pane " id="categories">

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
                        out.write("<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('" + PostBackConstants.CATBAG_KEY_REF + i + "');\"><i class=\"icon-trash icon-large\"></i></a></div>");
                        out.write(//"<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.key") + ": &nbsp;</div>"
                                "<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.key") + " (<a href=\"javascript:tModelModal('" + PostBackConstants.CATBAG_KEY_REF + i + PostBackConstants.VALUE + "')\" >" + "<i class=\"icon-list-alt icon-large\"></i>" + ResourceLoader.GetResource(session, "items.picker") + "</a>)"
                                + " <a href=\"tmodelEditor.jsp?id=" + URLEncoder.encode(bd.getCategoryBag().getKeyedReference().get(i).getTModelKey(), "UTF8") + "\"><i class=\"icon-zoom-in icon-large\"></i></a>"
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
               <b><%=ResourceLoader.GetResource(session, "items.keyrefgroup")%>:</b><br>
               <a href="javascript:AddCategoryKeyReferenceGroup();"><i class="icon-plus-sign icon-large"></i></a> <%=ResourceLoader.GetResource(session, "items.keyrefgroup.add")%><br>
               <%@include file="quickref_krgrp.jsp" %>
               <div id="catContainerGrp" style="border-width: 2px; border-style: solid;" >


                  <%
                     for (int i = 0; i < bd.getCategoryBag().getKeyedReferenceGroup().size(); i++) {

                        out.write("<div id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + "\" style=\"border-width:2px; border-style:solid\">"
                                + "<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('" + PostBackConstants.CATBAG_KEY_REF_GRP + i + "');\"><i class=\"icon-trash icon-large\"></i></a></div>"
                                + "<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.key") + " (<a href=\"javascript:tModelModal('" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.VALUE + "')\" >"
                                + "<i class=\"icon-list-alt icon-large\"></i>" + ResourceLoader.GetResource(session, "items.picker") + "</a>) "
                                + " <a href=\"tmodelEditor.jsp?id=" + URLEncoder.encode(bd.getCategoryBag().getKeyedReferenceGroup().get(i).getTModelKey(), "UTF8") + "\"><i class=\"icon-zoom-in icon-large\"></i></a>"
                                + ": &nbsp;</div>"
                                + "<div class=\"edit\" id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.VALUE + "\">"
                                + StringEscapeUtils.escapeHtml(bd.getCategoryBag().getKeyedReferenceGroup().get(i).getTModelKey())
                                + "</div>"
                                + "<div id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF + "\" style=\"border-width:1px; border-style:solid\">"
                                + "<div style=\"float:left;height:100%\"><a href=\"javascript:AddCategoryKeyReferenceGroupKeyRef('" + PostBackConstants.CATBAG_KEY_REF_GRP + i + "');\"><i class=\"icon-plus-sign icon-large\"></i></a></div>"
                                + ResourceLoader.GetResource(session, "items.keyrefcat.add")
                                + "</div>");
                        for (int k = 0; k < bd.getCategoryBag().getKeyedReferenceGroup().get(i).getKeyedReference().size(); k++) {

                           out.write("<div id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF + k + "\" style=\"border-width:1px; border-style:solid\">");
                           out.write("<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF + k + "');\"><i class=\"icon-trash icon-large\"></i></a></div>");
                           out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.key") + " (<a href=\"javascript:tModelModal('" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF + k + PostBackConstants.VALUE + "')\" >" + "<i class=\"icon-list-alt icon-large\"></i>" + ResourceLoader.GetResource(session, "items.picker") + "</a>)"
                                   + " <a href=\"tmodelEditor.jsp?id=" + URLEncoder.encode(bd.getCategoryBag().getKeyedReferenceGroup().get(i).getKeyedReference().get(k).getTModelKey(), "UTF8") + "\"><i class=\"icon-zoom-in icon-large\"></i></a>"
                                   + ": &nbsp;</div>"
                                   + "<div class=\"edit\" id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF + k + PostBackConstants.VALUE + "\">" + StringEscapeUtils.escapeHtml(bd.getCategoryBag().getKeyedReferenceGroup().get(i).getKeyedReference().get(k).getTModelKey()) + "</div>");
                           out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.name") + ":  &nbsp;</div>"
                                   + "<div class=\"edit\" id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF + k + PostBackConstants.KEYNAME + "\">" + StringEscapeUtils.escapeHtml(bd.getCategoryBag().getKeyedReferenceGroup().get(i).getKeyedReference().get(k).getKeyName()) + "</div>");
                           out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.value") + ": &nbsp;</div>"
                                   + "<div class=\"edit\" id=\"" + PostBackConstants.CATBAG_KEY_REF_GRP + i + PostBackConstants.KEY_REF + k + PostBackConstants.KEYVALUE + "\">" + StringEscapeUtils.escapeHtml(bd.getCategoryBag().getKeyedReferenceGroup().get(i).getKeyedReference().get(k).getKeyValue()) + "</div>");
                           out.write("</div>");
                        }

                        out.write("</div>");
                     }


                  %>
               </div>
            </div>
            <div class="tab-pane " id="identifiers">
               <b><%=ResourceLoader.GetResource(session, "items.identifiers")%></b> - <%=ResourceLoader.GetResource(session, "items.identifiers.description")%><Br>
               <a href="javascript:AddIdentKeyReference();"><i class="icon-plus-sign icon-large"></i></a> <%=ResourceLoader.GetResource(session, "items.keyrefcat.add")%><Br>
               <%@include file="quickref_ident.jsp" %>
               <div id="identContainer" style="border-width: 2px; border-style: solid;" >
                  <%
                     if (bd.getIdentifierBag() == null) {
                        bd.setIdentifierBag(new IdentifierBag());
                     }
                     for (int i = 0; i < bd.getIdentifierBag().getKeyedReference().size(); i++) {
                        out.write("<div id=\"" + PostBackConstants.IDENT_KEY_REF + i + "\" style=\"border-width:2px; border-style:solid\">");
                        out.write("<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('" + PostBackConstants.IDENT_KEY_REF + i + "');\"><i class=\"icon-trash icon-large\"></i></a></div>");
                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.key") + 
                                " (<a href=\"javascript:tModelModal('" + PostBackConstants.IDENT_KEY_REF + i + PostBackConstants.IDENT_KEY_REF + i + PostBackConstants.VALUE + "')\" >" + "<i class=\"icon-list-alt icon-large\"></i>" + ResourceLoader.GetResource(session, "items.picker") + "</a>)" 
                                + " <a href=\"tmodelEditor.jsp?id=" + URLEncoder.encode(bd.getIdentifierBag().getKeyedReference().get(i).getTModelKey(), "UTF8") + "\"><i class=\"icon-zoom-in icon-large\"></i></a>" 
                                +        ": &nbsp;</div>"
                                + "<div class=\"edit\" id=\"" + PostBackConstants.IDENT_KEY_REF + i + "Value\">" + StringEscapeUtils.escapeHtml(bd.getIdentifierBag().getKeyedReference().get(i).getTModelKey()) + "</div>");
                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.name") + ": &nbsp;</div>"
                                + "<div class=\"edit\" id=\"" + PostBackConstants.IDENT_KEY_REF + i + "KeyName\">" + StringEscapeUtils.escapeHtml(bd.getIdentifierBag().getKeyedReference().get(i).getKeyName()) + "</div>");
                        out.write("<div style=\"float:left\">" + ResourceLoader.GetResource(session, "items.value") + ": &nbsp;</div>"
                                + "<div class=\"edit\" id=\"" + PostBackConstants.IDENT_KEY_REF + i + "KeyValue\">" + StringEscapeUtils.escapeHtml(bd.getIdentifierBag().getKeyedReference().get(i).getKeyValue()) + "</div>");
                        out.write("</div>");
                     }
                  %>
               </div>
            </div>
            <div class="tab-pane " id="signatures">

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
                        out.write("<a href=\"ajax/getCert.jsp?type=tmodel&id=" + URLEncoder.encode(bd.getTModelKey(), "UTF-8") + "&index=" + k + "\">" + ResourceLoader.GetResource(session, "items.signed.viewcert") + "</a>");
                        out.write("</td><td><div id=\"digsig" + k + "\">" + ResourceLoader.GetResource(session, "items.loading") + "</div>");
                  %>
                  <script type="text/javascript">
                     $.get("ajax/validateSignature.jsp?type=tmodel&id=<%=StringEscapeUtils.escapeJavaScript(bd.getTModelKey())%>", function(data) {
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
            </div>
            <div class="tab-pane " id="Instances">
               <b><%=ResourceLoader.GetResource(session, "pages.editor.tmodel.instances")%></b> - 
               <%=ResourceLoader.GetResource(session, "pages.editor.tmodel.instances.content")%><Br>
               <select id="relatedSearches" onchange="search()">
                  <option></option>
                  <option value="business"> <%=ResourceLoader.GetResource(session, "pages.editor.tmodel.search.business")%></option>
                  <option value="bindingTemplate"> <%=ResourceLoader.GetResource(session, "pages.editor.tmodel.search.binding")%></option>
                  <option value="service"> <%=ResourceLoader.GetResource(session, "pages.editor.tmodel.search.services")%></option>
               </select>
               <script type="text/javascript">

                  var offset = 0;
                  var maxrecords = 20;
                  function search()
                  {
                     var val = $("#relatedSearches").val();

                     var selection = "tmodel";

                     var searchfor = $("#relatedSearches").val();
                     if (searchfor === "" || searchfor === null)
                     {
                        $("#InstancesContainer").html("");
                        return;
                     }
                     var searchcontent = "<%
                        if (bd.getTModelKey() != null) {
                           out.write(StringEscapeUtils.escapeJavaScript(bd.getTModelKey()));
                        }
                  %>";

                     var url = 'ajax/search.jsp';

                     var postbackdata = new Array();

                     postbackdata.push({
                        name: "selection",
                        value: selection
                     });

                     postbackdata.push({
                        name: "searchcontent",
                        value: searchcontent
                     });

                     postbackdata.push({
                        name: "searchfor",
                        value: searchfor
                     });

                     postbackdata.push({
                        name: "nonce",
                        value: $("#nonce").val()
                     });

                     var request = $.ajax({
                        url: url,
                        type: "POST",
                        //  dataType: "html", 
                        cache: false,
                        //  processData: false,f
                        data: postbackdata
                     });


                     request.done(function(msg) {
                        window.console && console.log('postback done ' + url);

                        $("#InstancesContainer").html(msg);


                     });

                     request.fail(function(jqXHR, textStatus) {
                        window.console && console.log('postback failed ' + url);
                        $("#InstancesContainer").html(jqXHR.responseText + textStatus);
                        //$(".alert").alert();


                     });

                  }

               </script>
               <div id="InstancesContainer" style="border-width: 2px; border-style: solid;" >
               </div>

            </div>

            <div class="tab-pane" id="opinfo">
               <%
                  if (!newitem) {
               %>
               <script type="text/javascript">
                  $.get("ajax/opInfo.jsp?id=<%=StringEscapeUtils.escapeJavaScript(bd.getTModelKey())%>", function(data) {
                     $("#opinfodiv").html(data);
                  })
               </script>
               <div id="opinfodiv"></div>
               <%
                  }
               %>
            </div>

         </div>
         <div><br>
            <%
               if (bd.getSignature().isEmpty()) {
            %>
            <a class="btn btn-primary " href="javascript:savetModel();"><i class="icon-save icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.save")%></a>
            <%  } else {
            %>
            <a href="#confirmDialog" role="button" class="btn btn-primary" data-toggle="modal"><i class="icon-save icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.save")%></a>

            <%        }
            %>



            <%
               if (!newitem) {
            %> |
            <a class="btn btn-danger " href="javascript:deletetModel();"><i class="icon-trash icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.delete")%></a> |
            <a class="btn btn-success " href="signer.jsp?id=<%=URLEncoder.encode(bd.getTModelKey(), "UTF-8")%>&type=tmodel"><i class="icon-pencil icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.sign")%></a> |
            <a class="btn btn-info " href="editSubscription.jsp?tid=<%=URLEncoder.encode(bd.getTModelKey(), "UTF-8")%>" title="<%=ResourceLoader.GetResource(session, "actions.subscribe.description")%>"><i class="icon-rss icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.subscribe")%></a> |
            <a class="btn btn-warning " href="transfer.jsp?biz=<%=URLEncoder.encode(bd.getTModelKey(), "UTF-8")%>"  title="<%=ResourceLoader.GetResource(session, "actions.transfer.description")%>"><i class="icon-exchange icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.transfer")%></a> |
            <a class="btn "  href="javascript:ViewAsXML();"><i class="icon-screenshot icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.asxml")%></a>
            <%
               }
            %>


         </div>




      </div>
      <script src="js/tmodeledit.js"></script>
      <script src="js/businessEditor.js"></script>
      <script type="text/javascript">
                  Reedit();
         <%
            if (!newitem) {
         %>

                  function ViewAsXML()
                  {
                     $.get("ajax/toXML.jsp?id=<%=URLEncoder.encode(bd.getTModelKey(), "UTF-8")%>&type=tmodel", function(data) {
                        window.console && console.log('asXml success');
                        $("#viewAsXmlContent").html(safe_tags_replace(data));
                        $("#viewAsXml").modal('show');
                     });

                  }
                  function saveAnyhow(){
                     savetModel();
                     $('#confirmDialog').modal('hide');
                  }
         <%
            }
         %>
      </script>


   </div>

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
         <h3><%=ResourceLoader.GetResource(session, "actions.asxml")%></h3>
      </div>
      <div class="modal-body" id="viewAsXmlContent">


      </div>

      <div class="modal-footer">
         <a href="ajax/toXML.jsp?id=<%=URLEncoder.encode(bd.getTModelKey(), "UTF-8")%>&type=tmodel" class="btn btn-primary" target="_blank"><%=ResourceLoader.GetResource(session, "actions.popout")%></a> 
         <a href="javascript:closeXmlPop('viewAsXml');" class="btn"><%=ResourceLoader.GetResource(session, "modal.close")%></a>
      </div>
   </div>
   <%
      }
   %>
   <%@include file="tmodelChooser.jsp" %>
   <%@include file="keyHelpModal.jsp" %>

   <%@include file="header-bottom.jsp" %>
