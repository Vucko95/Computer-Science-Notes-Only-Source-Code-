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
    Document   : header-top
    Created on : Feb 24, 2013, 9:08:12 AM
    Author     : Alex O'Ree
--%>
<%@page session="true"%>
<%@page trimDirectiveWhitespaces="true" %>
<%@page import="org.apache.juddi.api_v3.Node"%>
<%@page import="java.util.List"%>
<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>
<%@page import="org.apache.juddi.webconsole.resources.ResourceLoader"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%        //this is to catch someone that bookmarked a page after selecting a language
        Cookie[] cookies2 = request.getCookies();
        if (cookies2 != null && cookies2.length > 0) {
                for (int i = 0; i < cookies2.length; i++) {
                        if (cookies2[i] != null && cookies2[i].getName() != null && cookies2[i].getName().equalsIgnoreCase("locale")) {
                                if (cookies2[i].getValue() != null) {
                                        session.setAttribute("locale", cookies2[i].getValue());
                                }
                        }
                }
        }
        if (session.getAttribute("locale") == null) {
                //last chance, default to english
                session.setAttribute("locale", "en");
        }
%>
<html lang="<%=(String) session.getAttribute("locale")%>" dir="<%=ResourceLoader.GetResource(session, "direction")%>">
        <head>
                <meta charset="utf-8">
                <title><%=ResourceLoader.GetResource(session, "title")%></title>
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <meta name="description" content="<%=ResourceLoader.GetResource(session, "description")%>">
                <meta name="author" content="Apache Software Foundation">

                <link href="css/bootstrap.min.css" rel="stylesheet">
                <link href="css/bootstrap-datetimepicker.min.css" rel="stylesheet">
                <link href="css/bootstrap-timepicker.min.css" rel="stylesheet">
                <link rel="stylesheet" href="css/font-awesome.min.css">
                <link rel="stylesheet" href="css/ui-lightness/jquery-ui-1.10.2.custom.min.css">
                <!--[if IE 7]>
                <link rel="stylesheet" href="css/font-awesome-ie7.min.css">
                <![endif]-->

                <link rel="shortcut icon" href="favicon.ico" />
                <style type="text/css">
                        body {
                                padding-top: 60px;
                                padding-bottom: 40px;
                        }
                        .tab-content {
                                overflow: visible;
                            }
                </style>
                <link href="css/bootstrap-responsive.min.css" rel="stylesheet">
                <link href="css/bootstrap-modal.css" rel="stylesheet">

                <!-- HTML5 shim, for IE6-8 support of HTML5 elements -->
                <!--[if lt IE 9]>
                  <script src="js/html5shiv.js"></script>
                <![endif]-->

                <!-- Fav and touch icons -->

                <link rel="shortcut icon" href="ico/favicon.png">
                <script src="js/jquery-1.9.1.js"></script>
                <script src="js/i18n.js.jsp"></script>
                <script src="js/bootstrap.min.js"></script>
                <script src="js/bootstrap-datetimepicker.min.js"></script>
                <script src="js/bootstrap-timepicker.min.js"></script>
                <script src="js/bootstrap-modalmanager.js"></script>
                <script src="js/bootstrap-modal.js"></script>
                <script src="js/jquery.jeditable.js"></script>
                <script src="js/jquery-ui-1.10.2.custom.min.js"></script>
                <script src="js/main.js"></script>
        </head>

        <body>
                <%@include file="user/banner.jsp" %>        
                <%@include file="autoLogoutModal.jsp" %>        
                <form id="uddiform">
                        <%@include  file="csrf.jsp" %>
                        <input type="hidden" name="nonce" id="nonce" value="<%=StringEscapeUtils.escapeHtml((String) session.getAttribute("nonce"))%>" />
                        
                        
                        <div class="modal hide fade container" id="alert">
                                <div class="modal-header">
                                        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                                        <h3><%=ResourceLoader.GetResource(session, "actions.result")%></h3>
                                </div>
                                <div class="modal-body">
                                        <div id="alert_results"><i class="icon-2x icon-thumbs-up"></i></div>
                                </div>
                                <div class="modal-footer">

                                        <button type="button" class="close" data-dismiss="modal"><%=ResourceLoader.GetResource(session, "modal.close")%></button>
                                </div>
                        </div>
    
                        <%
                                UddiHub hub = UddiHub.getInstance(application, session);
                                Cookie[] cs = request.getCookies();
                                String newnode=null;
                                if (cs!=null){
                                        for (int i=0; i < cs.length; i++){
                                                if (cs[i].getName().equalsIgnoreCase("current_node")){
                                                        newnode = cs[i].getValue();
                                                        break;
                                                }
                                        }
                                }
                                hub.switchNodes(newnode);
                        %>


                        <div class="navbar navbar-inverse navbar-fixed-top">
                                <div class="navbar-inner">
                                        <div class="container">
                                                <button type="button" class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
                                                        <span class="icon-bar"></span>
                                                        <span class="icon-bar"></span>
                                                        <span class="icon-bar"></span>
                                                </button>
                                                <a class="brand" href="home.jsp" style="padding-left:19px; padding-top:0px; padding-bottom:0px"><img src="img/logo2.png"></a>
                                                <div class="nav-collapse collapse">
                                                        <ul class="nav">
                                                                <li class="dropdown"><a href="home.jsp" data-toggle="dropdown" class="dropdowb-town"><i class="icon-home icon-large"></i><%=ResourceLoader.GetResource(session, "navbar.home")%><b class="caret"></b></a>
                                                                        <ul class="dropdown-menu">
                                                                                <li><a href="reginfo.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.create.mybiz.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.create.mybiz")%></a></li>
                                                                                <li><a href="assertions.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.publisherassertions.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.publisherassertions")%></a></li>
                                                                                <li><a href="transfer.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.transfer.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.transfer")%></a></li>
                                                                                <li class="divider"></li>
                                                                                <li><a href="viewSubscriptions.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.subscriptions.view.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.subscriptions.view")%></a></li>
                                                                                <li><a href="editSubscription.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.subscriptions.create.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.subscriptions.create")%></a></li>
                                                                                <li><a href="subscriptionFeed.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.subscriptions.feed.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.subscriptions.feed")%></a></li>
                                                                        </ul>


                                                                </li>
                                                                <li class="dropdown" ><a href="#" data-toggle="dropdown" class="dropdowb-town"><i class="icon-search icon-large"></i><%=ResourceLoader.GetResource(session, "navbar.discover")%><b class="caret"></b></a>
                                                                        <ul class="dropdown-menu">
                                                                                <li><a href="businessBrowse.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.businesses.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.businesses")%></a></li>
                                                                                <li><a href="serviceBrowse.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.services.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.services")%></a></li>
                                                                                <li><a href="tmodelBrowse.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.tmodels.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.tmodels")%></a></li>
                                                                                        <%//                                        <li><a href="publisherBrowse.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.publishers.tooltip")">ResourceLoader.GetResource(session, "navbar.publishers")</a></li>
                                                                                               %>
                                                                                <li class="divider"> </li>

                                                                                <li><a href="search.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.search.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.search")%></a></li>


                                                                        </ul>
                                                                </li>
                                                                <li class="dropdown"><a href="#" data-toggle="dropdown" class="dropdowb-town"><i class="icon-pencil icon-large"></i><%=ResourceLoader.GetResource(session, "navbar.create")%><b class="caret"></b></a>
                                                                        <ul class="dropdown-menu">
                                                                                <li><a href="businessEditor2.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.create.business.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.create.business")%></a></li>
                                                                                <li><a href="businessBrowse.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.create.service.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.create.service")%></a></li>
                                                                                <li><a href="importFromWsdl.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.create.serviceimport.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.create.serviceimport")%></a></li>
                                                                                <li><a href="importFromWadl.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.create.serviceimport.tooltip.wadl")%>"><%=ResourceLoader.GetResource(session, "navbar.create.serviceimport.wadl")%></a></li>
                                                                                <li><a href="tmodelEditor.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.create.tmodel.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.create.tmodel")%></a></li>
                                                                                <li><a href="tmodelPartitions.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.create.tmodelkeygen.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.create.tmodelkeygen")%></a></li>
                                                                                <li><a href="editSubscription.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.subscriptions.create.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.subscriptions")%></a></li>
                                                                                <li><a href="advanced.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.advanced")%>"><%=ResourceLoader.GetResource(session, "navbar.advanced")%></a></li>
                                                                        </ul>
                                                                </li>

                                                                <li class="dropdown"><a href="#" data-toggle="dropdown" class="dropdowb-town"><i class="icon-cog icon-large"></i><%=ResourceLoader.GetResource(session, "navbar.settings")%><b class="caret"></b></a>
                                                                        <ul class="dropdown-menu">
                                                                                <li><a href="settings.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.settings.config.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.settings.config")%></a></li>
                                                                                <li class="divider"></li>
                                                                                <li><a href="#" data-toggle="tooltip" data-container="body" class="uddi_tooltips" title="<%=ResourceLoader.GetResource(session, "items.switchnode.tooltip")%>"><%=ResourceLoader.GetResource(session, "items.switchnode")%></a></li>
                                                                                
                                                                                        <%
                                                                                                List<Node> nodes = hub.GetJuddiClientConfig().getUDDINodeList();
                                                                                                for (int i = 0; i < nodes.size(); i++) {
                                                                                                        out.write("<li><a href=\"javascript:switchNode('" + StringEscapeUtils.escapeHtml(nodes.get(i).getName()) + "')\" title=\"" + StringEscapeUtils.escapeHtml(nodes.get(i).getDescription()) + "\" >");
                                                                                                        if (hub.getNodeName().equals(nodes.get(i).getName())) {
                                                                                                                out.write("<i class=\"icon icon-check\"></i> ");
                                                                                                        } else {
                                                                                                                out.write("<i class=\"icon icon-check-empty\"></i> ");
                                                                                                        }
                                                                                                        out.write(StringEscapeUtils.escapeHtml(nodes.get(i).getName()));
                                                                                                        if (hub.getNodeName().equals(nodes.get(i).getName())) {
                                                                                                                out.write("(" + ResourceLoader.GetResource(session, "items.active") + ")");
                                                                                                        }
                                                                                                        out.write("</a></li>");
                                                                                                }
                                                                                        %>
                                                                        </ul>
                                                                </li>
                                                                <script type="text/javascript">
                                                                         $('.uddi_tooltips').tooltip();
                                                                        function switchNode(name) {
                                                                                var postbackdata = new Array();
                                                                                postbackdata.push({
                                                                                        name: "nonce",
                                                                                        value: $("#nonce").val()
                                                                                });
                                                                                postbackdata.push({
                                                                                        name: "node",
                                                                                        value: name
                                                                                });
                                                                                window.console && console.log('reconfiguring node name');
                                                                                var request = $.ajax({
                                                                                        url: 'ajax/switch.jsp',
                                                                                        type: "POST",
                                                                                        cache: false,
                                                                                        data: postbackdata
                                                                                });

                                                                                request.done(function(msg) {
                                                                                        window.console && console.log(msg);
                                                                                        window.console && console.log('postback done to div ' );
                                                                                        $("#" + jqSelector('nodeswitcherdetails')).html(msg);
                                                                                        $("#nodeswitcher").modal();
                                                                                });

                                                                                request.fail(function(jqXHR, textStatus) {
                                                                                        window.console && console.log('postback failed ');
                                                                                        $("#" + jqSelector('nodeswitcherdetails')).html("An error occured! " + jqXHR.responseText + textStatus);
                                                                                        $("#nodeswitcher").modal();
                                                                                });


                                                                        }
                                                                </script>

                                                                <li class="dropdown"><a href="#" data-toggle="dropdown" class="dropdowb-town"><i class="icon-question-sign icon-large"></i><%=ResourceLoader.GetResource(session, "navbar.help")%> <b class="caret"></b></a>
                                                                        <ul class="dropdown-menu">
                                                                                <li><a href="http://juddi.apache.org/docs.html" title="<%=ResourceLoader.GetResource(session, "navbar.help.userguide")%>"><%=ResourceLoader.GetResource(session, "navbar.help.userguide")%></a></li>
                                                                                <li><a href="http://wiki.apache.org/juddi" title="<%=ResourceLoader.GetResource(session, "navbar.help.wiki")%>"><%=ResourceLoader.GetResource(session, "navbar.help.wiki")%></a></li>
                                                                                <li><a href="http://juddi.apache.org/issue-tracking.html" title="<%=ResourceLoader.GetResource(session, "navbar.help.bugreport")%>"><%=ResourceLoader.GetResource(session, "navbar.help.bugreport")%></a></li>
                                                                                <li><a href="http://juddi.apache.org/" title="<%=ResourceLoader.GetResource(session, "navbar.help.website")%>"><%=ResourceLoader.GetResource(session, "navbar.help.website")%></a></li>
                                                                                <li><a href="http://juddi.apache.org/mailing-list.html" title="<%=ResourceLoader.GetResource(session, "navbar.help.mailinglist")%>"><%=ResourceLoader.GetResource(session, "navbar.help.mailinglist")%></a></li>
                                                                                <li><a href="http://juddi.apache.org/source.html" title="<%=ResourceLoader.GetResource(session, "navbar.help.source")%>"><%=ResourceLoader.GetResource(session, "navbar.help.source")%></a></li>
                                                                                <li><a href="about.jsp" title="<%=ResourceLoader.GetResource(session, "navbar.help.about.tooltip")%>"><%=ResourceLoader.GetResource(session, "navbar.help.about")%></a></li>

                                                                        </ul>
                                                                </li>
                                                        </ul>
                                                        <div id="loginfield">
                                                                <%@include file="login.jsp" %>
                                                        </div>
                                                </div><!--/.nav-collapse -->
                                        </div>
                                </div>
                        </div>

                                                        
                                                        
<div class="modal hide fade container" id="nodeswitcher">
    <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
        <h3><%=ResourceLoader.GetResource(session, "items.switchnode")%></h3>
    </div>
    <div class="modal-body">
            <div id="nodeswitcherdetails"></div>
    </div>
    <div class="modal-footer">

            <a href="index.jsp" class="btn btn-primary" ><%=ResourceLoader.GetResource(session, "actions.continue")%></a>
    </div>
</div>