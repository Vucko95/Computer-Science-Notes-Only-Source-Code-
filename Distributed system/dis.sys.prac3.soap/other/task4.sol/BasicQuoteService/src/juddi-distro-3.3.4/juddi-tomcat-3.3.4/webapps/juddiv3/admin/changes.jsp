<%-- 
    Document   : change record browser
    Created on : Jan 27, 2015, 2:05:35 PM
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


<%@page import="org.apache.juddi.config.Property"%>
<%@page import="org.apache.juddi.config.AppConfig"%>
<%@page import="org.apache.juddi.api_v3.Publisher"%>
<%@page import="org.apache.juddi.api_v3.SavePublisher"%>
<%@page import="org.apache.juddi.api_v3.Clerk"%>
<%@page import="org.apache.juddi.api_v3.SaveClerk"%>
<%@page import="org.apache.juddi.api_v3.SyncSubscription"%>
<%@page import="org.apache.juddi.api_v3.GetPublisherDetail"%>
<%@page import="org.apache.juddi.api_v3.GetAllPublisherDetail"%>
<%@page import="org.apache.juddi.api_v3.DeletePublisher"%>
<%@page import="org.uddi.api_v3.DeleteTModel"%>
<%@page import="org.apache.juddi.v3_service.JUDDIApiPortType"%>
<%@page import="org.apache.commons.lang.StringEscapeUtils"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include file="header-top.jsp"%>

<div class="container">

    <!-- Main hero unit for a primary marketing message or call to action -->
    <div class="well">
        <h1><%=ResourceLoader.GetResource(session, "pages.home.admin")%></h1>

    </div>

    <!-- Example row of columns -->
    <div class="row">


        <div class="span12">
            <% UddiAdminHub x = UddiAdminHub.getInstance(application, session);

            %> 
            Change Record browser, you can use your left and right keyboard keys to page through the change records<br>
            You are connected to: <%=StringEscapeUtils.escapeHtml(AppConfig.getConfiguration().getString(Property.JUDDI_NODE_ID))%><br>
            <br>
            <div>

                <a href="javascript:recordDown();"><i class="icon-circle-arrow-left  icon-2x" id="pageupBusiness"></i></a>
                <a href="javascript:recordUp();"><i class="icon-circle-arrow-right  icon-2x" id="pagedownBusiness"></i></a>
                <br>
                Record ID:    <input type="text" id="recordid" value="1"><Br>
                NodeID: <input type="text" id="nodeid" value="<%=StringEscapeUtils.escapeHtml(AppConfig.getConfiguration().getString(Property.JUDDI_NODE_ID))%>">
                <br>


            </div>
            <div id="resultsBrowser">
                <img src="img/bigrollergreen.gif" title="<%=ResourceLoader.GetResource(session, "items.loading")%>"/>
            </div>
            <script type="text/javascript">

                function recordUp() {
                    $("#recordid").val(parseInt($("#recordid").val()) + 1);
                    go();
                }
                function recordDown() {
                    $("#recordid").val(parseInt($("#recordid").val()) - 1);
                    if ($("#recordid").val() < 1)
                    {
                        $("#recordid").val(1);
                    }
                    else
                        go();
                }
                function go() {
                    var url = 'ajax/go.jsp';

                    var postbackdata = new Array();

                    var x = $("#divselector").val();
                    postbackdata.push({
                        name: "soapaction",
                        value: "changeRecord"
                    });

                    postbackdata.push({
                        name: "nonce",
                        value: $("#nonce").val()
                    });
                    postbackdata.push({
                        name: "recordid",
                        value: $("#recordid").val()
                    });


                    postbackdata.push({
                        name: "nodeid",
                        value: $("#nodeid").val()
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
                        $("#resultsBrowser").html(msg);
                        //$('#adminresultsmodal').modal();

                    });

                    request.fail(function (jqXHR, textStatus) {
                        window.console && console.log('postback failed ' + url);
                        $("#adminresults").html(jqXHR.responseText + textStatus);
                        $('#adminresultsmodal').modal();

                    });
                }
                go(); //run when the page loads

                $(document).keydown(function (e) {
                    switch (e.which) {
                        case 37: // left
                            recordDown();
                            break;

                        case 39: // right
                            recordUp();
                            break;

                        default:
                            return; // exit this handler for other keys
                    }
                    e.preventDefault(); // prevent the default action (scroll / move caret)
                });


            </script>
            <br>
            <%=ResourceLoader.GetResource(session, "pages.admin.notes")%>

            <br>
            <a href="javascript:submitform();" class="btn btn-primary"><%=ResourceLoader.GetResource(session, "actions.go")%></a><br><br>
            <br>

        </div>
    </div>


    <div class="modal hide fade container " id="adminresultsmodal">
        <div class="modal-header">
            <a href="javascript:$('#adminresultsmodal').modal('hide');" class="close" data-dismiss="modal" aria-hidden="true">&times;</a>
            <h3><%=ResourceLoader.GetResource(session, "items.results")%></h3>
        </div>
        <div class="modal-body" align="center">
            <div id="adminresults"></div>
        </div>
        <div class="modal-footer">
            <a href="javascript:$('#adminresultsmodal').modal('hide');" class="btn btn-primary" data-dismiss="modal"><%=ResourceLoader.GetResource(session, "modal.close")%></a>
        </div>
    </div>

    <%@include file="header-bottom.jsp"%>