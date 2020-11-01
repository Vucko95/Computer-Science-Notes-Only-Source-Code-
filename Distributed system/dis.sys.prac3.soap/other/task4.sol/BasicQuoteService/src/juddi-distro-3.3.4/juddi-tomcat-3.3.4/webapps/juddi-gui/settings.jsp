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

<%@page import="org.apache.juddi.v3.client.config.UDDINode"%>
<%@page import="org.apache.juddi.v3.client.config.ClientConfig"%>
<%@page import="org.apache.commons.configuration.Configuration"%>
<%@page import="java.util.Iterator"%>
<%@page import="java.util.Set"%>
<%@page import="java.util.Properties"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include file="header-top.jsp" %>
<div class="container">

    <!-- Main hero unit for a primary marketing message or call to action -->
    <div class="well">
        <h1><%=ResourceLoader.GetResource(session, "navbar.settings")%></h1>
    </div>

    <!-- Example row of columns -->
    <div class="row">
        <div class="span12">
            <h2><%=ResourceLoader.GetResource(session, "navbar.settings")%></h2>
            <p><%=ResourceLoader.GetResource(session, "items.settings.description")%></p>
            <%
                    UddiHub x = UddiHub.getInstance(application, session);


            %>


            <%=ResourceLoader.GetResource(session, "pages.settings.loading")%> <%=StringEscapeUtils.escapeHtml(x.GetJuddiClientConfig().getConfigurationFile())%><br>
            <table class="table table-hover" id="configtable">
                <tr><th><%=ResourceLoader.GetResource(session, "items.key")%></th>
                    <th><%=ResourceLoader.GetResource(session, "items.value")%></th></tr>
                        <%
                                try {
                                        ClientConfig cfg = x.GetJuddiClientConfig();
                                        Configuration cfg2 = cfg.getConfiguration();
                                        Iterator<String> it2 = cfg.getConfiguration().getKeys();

                                        String[] nodes2 = cfg2.getStringArray("client.nodes.node.name");

                                        while (it2.hasNext()) {

                                                String key = it2.next();

                                                String value = cfg.getConfiguration().getString(key);
                                                if ((key.startsWith("client") || (key.startsWith("config.props"))) && !key.startsWith("client.nodes.node")) {
                                                        out.write("<tr id=\"" + StringEscapeUtils.escapeHtml(key) + "ROW\"><td>");
                                                        out.write("<a href=\"javascript:removeKey('" + StringEscapeUtils.escapeJavaScript(key) + "');\"><i class=\"icon-trash icon-large\"></i></a>");
                                                        out.write(StringEscapeUtils.escapeHtml(key));
                                                        out.write("</td><td><div ");
                                                        if ((key.startsWith("client") && !key.startsWith("client.nodes")) || key.startsWith("config.props")) {
                                                                out.write("class=\"edit\" id=\"" + StringEscapeUtils.escapeHtml(key) + "\"");
                                                        }
                                                        out.write(">");
                                                        out.write(StringEscapeUtils.escapeHtml(value));
                                                        out.write("</div></td></tr>");
                                                }
                                        }
                        %>
            </table><br>
            <a class="btn btn-primary" href="javascript:newItem();"><i class="icon-large icon-plus-sign"></i> <%=ResourceLoader.GetResource(session, "actions.add")%></a>
            <a class="btn btn-primary " href="javascript:saveSettings();"><i class="icon-large icon-save"></i> <%=ResourceLoader.GetResource(session, "actions.save")%></a>

            <hr>
            <h2>Node Management</h2>
            <a class="btn btn-primary" href="javascript:newNode();"><i class="icon-large icon-plus-sign"></i> <%=ResourceLoader.GetResource(session, "actions.add")%></a>
            <table class="table table-hover">



                <%

                                List<Node> nodesist = x.GetJuddiClientConfig().getUDDINodeList();
                                for (int i = 0; i < nodesist.size(); i++) {
                                        out.write("<tr><td>");
                                        out.write(StringEscapeUtils.escapeHtml(nodesist.get(i).getName()));
                                        out.write("</td><td><a href=\"javascript:editNode('" + StringEscapeUtils.escapeJavaScript(nodesist.get(i).getName()) + "');\">Edit</a></td>"
                                                + "<td><a href=\"javascript:deleteNode('" + StringEscapeUtils.escapeJavaScript(nodesist.get(i).getName()) + "');\">Delete</a></td></tr>");
                                        /*
                                         String key = "client.nodes.node(" + i + ").name";
                                         out.write("<tr id=\"" + StringEscapeUtils.escapeHtml(key) + "ROW\"><td>");
                                         out.write("<a href=\"javascript:removeKey('" + StringEscapeUtils.escapeJavaScript(key) + "');\"><i class=\"icon-trash icon-large\"></i></a>");
                                         out.write(StringEscapeUtils.escapeHtml(key));
                                         out.write("</td><td><div ");
                                         out.write("class=\"edit\" id=\"" + StringEscapeUtils.escapeHtml(key) + "\">");
                                         out.write(StringEscapeUtils.escapeHtml(cfg2.getString(key)));
                                         out.write("</div></td></tr>");

                                         key = "client.nodes.node(" + i + ").description";
                                         out.write("<tr id=\"" + StringEscapeUtils.escapeHtml(key) + "ROW\"><td>");
                                         out.write("<a href=\"javascript:removeKey('" + StringEscapeUtils.escapeJavaScript(key) + "');\"><i class=\"icon-trash icon-large\"></i></a>");
                                         out.write(StringEscapeUtils.escapeHtml(key));
                                         out.write("</td><td><div ");
                                         out.write("class=\"edit\" id=\"" + StringEscapeUtils.escapeHtml(key) + "\">");
                                         out.write(StringEscapeUtils.escapeHtml(cfg2.getString(key)));
                                         out.write("</div></td></tr>");

                                         key = "client.nodes.node(" + i + ").proxyTransport";
                                         out.write("<tr id=\"" + StringEscapeUtils.escapeHtml(key) + "ROW\"><td>");
                                         out.write("<a href=\"javascript:removeKey('" + StringEscapeUtils.escapeJavaScript(key) + "');\"><i class=\"icon-trash icon-large\"></i></a>");
                                         out.write(StringEscapeUtils.escapeHtml(key));
                                         out.write("</td><td><div ");
                                         out.write("class=\"edit\" id=\"" + StringEscapeUtils.escapeHtml(key) + "\">");
                                         out.write(StringEscapeUtils.escapeHtml(cfg2.getString(key)));
                                         out.write("</div></td></tr>");

                                         key = "client.nodes.node(" + i + ").custodyTransferUrl";
                                         out.write("<tr id=\"" + StringEscapeUtils.escapeHtml(key) + "ROW\"><td>");
                                         out.write("<a href=\"javascript:removeKey('" + StringEscapeUtils.escapeJavaScript(key) + "');\"><i class=\"icon-trash icon-large\"></i></a>");
                                         out.write(StringEscapeUtils.escapeHtml(key));
                                         out.write("</td><td><div ");
                                         out.write("class=\"edit\" id=\"" + StringEscapeUtils.escapeHtml(key) + "\">");
                                         out.write(StringEscapeUtils.escapeHtml(cfg2.getString(key)));
                                         out.write("</div></td></tr>");

                                         key = "client.nodes.node(" + i + ").inquiryUrl";
                                         out.write("<tr id=\"" + StringEscapeUtils.escapeHtml(key) + "ROW\"><td>");
                                         out.write("<a href=\"javascript:removeKey('" + StringEscapeUtils.escapeJavaScript(key) + "');\"><i class=\"icon-trash icon-large\"></i></a>");
                                         out.write(StringEscapeUtils.escapeHtml(key));
                                         out.write("</td><td><div ");
                                         out.write("class=\"edit\" id=\"" + StringEscapeUtils.escapeHtml(key) + "\">");
                                         out.write(StringEscapeUtils.escapeHtml(cfg2.getString(key)));
                                         out.write("</div></td></tr>");

                                         key = "client.nodes.node(" + i + ").publishUrl";
                                         out.write("<tr id=\"" + StringEscapeUtils.escapeHtml(key) + "ROW\"><td>");
                                         out.write("<a href=\"javascript:removeKey('" + StringEscapeUtils.escapeJavaScript(key) + "');\"><i class=\"icon-trash icon-large\"></i></a>");
                                         out.write(StringEscapeUtils.escapeHtml(key));
                                         out.write("</td><td><div ");
                                         out.write("class=\"edit\" id=\"" + StringEscapeUtils.escapeHtml(key) + "\">");
                                         out.write(StringEscapeUtils.escapeHtml(cfg2.getString(key)));
                                         out.write("</div></td></tr>");

                                         key = "client.nodes.node(" + i + ").securityUrl";
                                         out.write("<tr id=\"" + StringEscapeUtils.escapeHtml(key) + "ROW\"><td>");
                                         out.write("<a href=\"javascript:removeKey('" + StringEscapeUtils.escapeJavaScript(key) + "');\"><i class=\"icon-trash icon-large\"></i></a>");
                                         out.write(StringEscapeUtils.escapeHtml(key));
                                         out.write("</td><td><div ");
                                         out.write("class=\"edit\" id=\"" + StringEscapeUtils.escapeHtml(key) + "\">");
                                         out.write(StringEscapeUtils.escapeHtml(cfg2.getString(key)));
                                         out.write("</div></td></tr>");

                                         key = "client.nodes.node(" + i + ").subscriptionUrl";
                                         out.write("<tr id=\"" + StringEscapeUtils.escapeHtml(key) + "ROW\"><td>");
                                         out.write("<a href=\"javascript:removeKey('" + StringEscapeUtils.escapeJavaScript(key) + "');\"><i class=\"icon-trash icon-large\"></i></a>");
                                         out.write(StringEscapeUtils.escapeHtml(key));
                                         out.write("</td><td><div ");
                                         out.write("class=\"edit\" id=\"" + StringEscapeUtils.escapeHtml(key) + "\">");
                                         out.write(StringEscapeUtils.escapeHtml(cfg2.getString(key)));
                                         out.write("</div></td></tr>");*/

                                }

                        } catch (Exception ex) {
                                x.log.error(ex);
                        }
                %>
            </table>

            <script type="text/javascript">

                Reedit();
                function saveSettings()
                {
                    var url = 'ajax/settings.jsp';
                    var postbackdata = new Array();
                    $("div.edit").each(function ()
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
                    $("div.noedit").each(function ()
                    {
                        var id = $(this).attr("id");
                        var value = $(this).text();
                        postbackdata.push({
                            name: id,
                            value: value
                        });
                    });

                    postbackdata.push({
                        name: "formaction",
                        value: "settings"
                    });


                    var request = $.ajax({
                        url: url,
                        type: "POST",
                        //  data" + i18n_type + ": "html", 
                        cache: false,
                        //  processData: false,f
                        data: postbackdata
                    });


                    request.done(function (msg) {
                        window.console && console.log('postback done ' + url);

                        $("#alert_results").html('<i class="icon-2x icon-thumbs-up"></i><br>' + msg);
                        $("#alert").modal();
                    });

                    request.fail(function (jqXHR, textStatus) {
                        window.console && console.log('postback failed ' + url);
                        $("#alert_results").html('<i class="icon-2x icon-thumbs-down"></i><br>' + jqXHR.responseText + textStatus);
                        $("#alert").modal();
                    });


                }
            </script>

            <br><br>
            <script type="text/javascript">
                function showDebug() {
                    $("#debugtable").show();
                }
            </script>
            <a class="btn " href="javascript:showDebug();"><i class="icon-large icon-arrow-down"></i> <%=ResourceLoader.GetResource(session, "pages.settings.debuginfo")%></a>
            <div id="debugtable" class="hide">
                <table class="table table-hover">
                    <tr><th><%=ResourceLoader.GetResource(session, "items.key")%></th>
                        <th><%=ResourceLoader.GetResource(session, "items.value")%></th></tr>
                            <%

                                    try {
                                            ClientConfig cfg = x.GetJuddiClientConfig();
                                            Iterator<String> it2 = cfg.getConfiguration().getKeys();

                                            while (it2.hasNext()) {

                                                    String key = it2.next();

                                                    if (!key.startsWith("config.props.") && !key.startsWith("client")) {
                                                            String value = cfg.getConfiguration().getString(key);
                                                            out.write("<tr><td>");
                                                            out.write(StringEscapeUtils.escapeHtml(key));
                                                            out.write("</td><td><div ");
                                                            out.write(">");
                                                            out.write(StringEscapeUtils.escapeHtml(value));
                                                            out.write("</div></td></tr>");
                                                    }
                                            }
                                    } catch (Exception ex) {
                                            x.log.error(ex);
                                    }

                            %>
                </table>
            </div>
        </div>
    </div>



    <script type="text/javascript">
        function deleteNode(node) {
            var url = 'ajax/settings.jsp';
            var postbackdata = new Array();

            postbackdata.push({
                name: "nonce",
                value: $("#nonce").val()
            });

            postbackdata.push({
                name: "nodename",
                value: node
            });



            postbackdata.push({
                name: "formaction",
                value: "deleteNode"
            });


            var request = $.ajax({
                url: url,
                type: "POST",
                //  data" + i18n_type + ": "html", 
                cache: false,
                //  processData: false,f
                data: postbackdata
            });


            request.done(function (msg) {
                window.console && console.log('postback done ' + url);

                $("#alert_results").html('<i class="icon-2x icon-thumbs-up"></i><br>' + msg);
                $("#alert").modal();
            });

            request.fail(function (jqXHR, textStatus) {
                window.console && console.log('postback failed ' + url);
                $("#alert_results").html('<i class="icon-2x icon-thumbs-down"></i><br>' + jqXHR.responseText + textStatus);
                $("#alert").modal();
            });
        }
        function editNode(node) {
            var url = 'ajax/settings.jsp';
            var postbackdata = new Array();

            postbackdata.push({
                name: "nonce",
                value: $("#nonce").val()
            });

            postbackdata.push({
                name: "nodename",
                value: node
            });



            postbackdata.push({
                name: "formaction",
                value: "getNode"
            });


            var request = $.ajax({
                url: url,
                type: "POST",
                //  data" + i18n_type + ": "html", 
                cache: false,
                //  processData: false,f
                data: postbackdata
            });


            request.done(function (msg) {
                window.console && console.log('postback done ' + url);

                $("#alterNodeModalContent").html(msg);
                $("#alterNodeModal").modal();
            });

            request.fail(function (jqXHR, textStatus) {
                window.console && console.log('postback failed ' + url);
                $("#alert_results").html('<i class="icon-2x icon-thumbs-down"></i><br>' + jqXHR.responseText + textStatus);
                $("#alert").modal();
            });

        }
        function newNode() {
            $("#newNodeModal").modal('show');

        }
        function saveNewNode() {
            var url = 'ajax/settings.jsp';
            var postbackdata = new Array();

            postbackdata.push({
                name: "nonce",
                value: $("#nonce").val()
            });
            $(".crudnode").each(function ()
            {
                var id = $(this).attr("id");
                var value = $(this).val();
                postbackdata.push({
                    name: id,
                    value: value
                });
            });

            postbackdata.push({
                name: "formaction",
                value: "newNode"
            });


            var request = $.ajax({
                url: url,
                type: "POST",
                //  data" + i18n_type + ": "html", 
                cache: false,
                //  processData: false,f
                data: postbackdata
            });


            request.done(function (msg) {
                window.console && console.log('postback done ' + url);

                $("#alert_results").html('<i class="icon-2x icon-thumbs-up"></i><br>' + msg);
                $('#newNodeModal').modal('hide');
                $("#alert").modal();
            });

            request.fail(function (jqXHR, textStatus) {
                window.console && console.log('postback failed ' + url);
                $("#alert_results").html('<i class="icon-2x icon-thumbs-down"></i><br>' + jqXHR.responseText + textStatus);
                $("#alert").modal();
            });

        }
        function saveNode(){
            var url = 'ajax/settings.jsp';
            var postbackdata = new Array();

            postbackdata.push({
                name: "nonce",
                value: $("#nonce").val()
            });
            $(".crudnodeAlter").each(function ()
            {
                var id = $(this).attr("id");
                var value = $(this).val();
                postbackdata.push({
                    name: id,
                    value: value
                });
            });

            postbackdata.push({
                name: "formaction",
                value: "alterNode"
            });


            var request = $.ajax({
                url: url,
                type: "POST",
                //  data" + i18n_type + ": "html", 
                cache: false,
                //  processData: false,f
                data: postbackdata
            });


            request.done(function (msg) {
                window.console && console.log('postback done ' + url);
                $('#alterNodeModal').modal('hide');
                $("#alert_results").html('<i class="icon-2x icon-thumbs-up"></i><br>' + msg);
                $("#alert").modal();
               
                
            });

            request.fail(function (jqXHR, textStatus) {
                window.console && console.log('postback failed ' + url);
                $("#alert_results").html('<i class="icon-2x icon-thumbs-down"></i><br>' + jqXHR.responseText + textStatus);
                $("#alert").modal();
            });
            
            
        }
        function newItem() {
            $("#newItemModal").modal('show');
        }
        function appendKey()
        {
            $("#newItemModal").modal('hide');
            var key = safe_tags_replace($("#newItemKey").val());
            var value = safe_tags_replace($("#newItemValue").val());
            $("<tr id=\"" + key + "ROW\"><td>" +
                    "<a href=\"javascript:removeKey('" + key + "');\"><i class=\"icon-trash icon-large\"></i></a>" +
                    key + "</a></td><td><div id=\"" +
                    key + "\" class=\"edit\">" +
                    value + "</div></td></tr>").appendTo("#configtable");
            Reedit();

        }
        function removeKey(key)
        {
            $('#' + escapeJquerySelector(key) + "ROW").remove();
        }
    </script>

    <div class="modal hide fade container" id="newItemModal">
        <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
            <h3><%=ResourceLoader.GetResource(session, "items.settings.add")%></h3>
        </div>
        <div class="modal-body">
            <%=ResourceLoader.GetResource(session, "items.settings.note")%> client., config.props.<br>
            <%=ResourceLoader.GetResource(session, "items.key")%>: <input type="text" id="newItemKey" placeholder="client."><br>
            <%=ResourceLoader.GetResource(session, "items.value")%>: <input type="text" id="newItemValue" placeholder="value"><br>
        </div>
        <div class="modal-footer">
            <a href="javascript:appendKey();" class="btn btn-primary"><%=ResourceLoader.GetResource(session, "actions.add")%></a>
            <a href="javascript:$('#newItemModal').modal('hide');" class="btn"><%=ResourceLoader.GetResource(session, "modal.close")%></a>
        </div>
    </div>

    <div class="modal hide fade container" id="newNodeModal">
        <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
            <h3><%=ResourceLoader.GetResource(session, "items.settings.add")%></h3>
        </div>
        <div class="modal-body" id="newNodeContent">
            <%
                    out.write("<table class=\"table table-hover\">");
                    out.write("<tr><td>Node Name</td><td><input class=\"crudnode\" type=text id=\"nodename\" value=\"" + "\"></td></tr>");

                    out.write("<tr><td>Description</td><td><input class=\"crudnode\" type=text id=\"description\" value=\"" + "\"></td></tr>");
                    out.write("<tr><td>Transport</td><td><input class=\"crudnode\" type=text id=\"transport\" value=\"\"></td></tr>");
                    out.write("<tr><td>Inquiry</td><td><input class=\"crudnode\" type=text id=\"inquiry\" value=\"\"></td></tr>");
                    out.write("<tr><td>Publish</td><td><input class=\"crudnode\" type=text id=\"publish\" value=\"\"></td></tr>");
                    out.write("<tr><td>Security</td><td><input class=\"crudnode\" type=text id=\"security\" value=\"\"></td></tr>");
                    out.write("<tr><td>Custody Transfer</td><td><input class=\"crudnode\" type=text id=\"custody\" value=\"\"></td></tr>");
                    out.write("<tr><td>Subscription</td><td><input class=\"crudnode\" type=text id=\"subscription\" value=\"\"></td></tr>");
                    out.write("<tr><td colspan=2>Not used by juddi-gui");
                    out.write("<tr><td>Factory Initial</td><td><input type=text class=\"crudnode\" id=\"factoryinit\" value=\"\"></td></tr>");
                    out.write("<tr><td>Factory Naming Provider</td><td><input class=\"crudnode\" type=text id=\"factorynaming\" value=\"\"></td></tr>");
                    out.write("<tr><td>Factor URL Package</td><td><input class=\"crudnode\" type=text id=\"factoryurl\" value=\"\"></td></tr>");
                    out.write("<tr><td>Inquiry REST</td><td><input class=\"crudnode\" type=text id=\"inquiryrest\" value=\"\"></td></tr>");
                    out.write("<tr><td>Replication</td><td><input class=\"crudnode\" type=text id=\"replication\" value=\"\"></td></tr>");
                    out.write("<tr><td>jUDDI API</td><td><input class=\"crudnode\" type=text id=\"juddiapi\" value=\"\"></td></tr>");
                    out.write("</table>");
            %>
        </div>
        <div class="modal-footer">
            <a href="javascript:saveNewNode();" class="btn btn-primary"><%=ResourceLoader.GetResource(session, "actions.add")%></a>
            <a href="javascript:$('#newNodeModal').modal('hide');" class="btn"><%=ResourceLoader.GetResource(session, "modal.close")%></a>
        </div>
    </div>

        <div class="modal hide fade container" id="alterNodeModal">
        <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
            <h3><%=ResourceLoader.GetResource(session, "items.settings.edit")%></h3>
        </div>
        <div class="modal-body" id="alterNodeModalContent">
           
        </div>
        <div class="modal-footer">
            <a href="javascript:saveNode();" class="btn btn-primary"><%=ResourceLoader.GetResource(session, "actions.save")%></a>
            <a href="javascript:$('#alterNodeModal').modal('hide');" class="btn"><%=ResourceLoader.GetResource(session, "modal.close")%></a>
        </div>
    </div>

        


    <%@include file="header-bottom.jsp" %>