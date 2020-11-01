<%-- 
    Document   : tmodelPartitions
    Created on : Feb 28, 2013, 8:21:25 AM
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


<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include file="header-top.jsp" %>
<div class="container">

        <!-- Main hero unit for a primary marketing message or call to action -->
        <div class="well" >
                <h1><%=ResourceLoader.GetResource(session, "pages.tmodelpart.title")%></h1>
        </div>

        <!-- Example row of columns -->
        <div class="row">
                <div class="span12" >

                        <div id="container">
                                <%=ResourceLoader.GetResource(session, "pages.tmodelpart.content")%>
                                <br><br>
                                <div class="alert alert-info">
                                        <i class="icon-info-sign  icon-large"></i> <%=ResourceLoader.GetResource(session, "pages.tmodelpart.juddinote")%></div>
                                <br><Br>
                                <table class="table">
                                        <tr><td><%=ResourceLoader.GetResource(session, "pages.tmodelpart.key")%></td><td><input type="text" value="uddi:www.mycompany.com:keygenerator" id="keyGeneratorKey"  style="width:100%"></td></tr>
                                        <tr><td><%=ResourceLoader.GetResource(session, "pages.thmodepart.name")%></td><td><input type="text" value="My business's key generator" id="keyGeneratorName" style="width:100%"></td></tr>
                                        <tr><td><%=ResourceLoader.GetResource(session, "items.lang")%></td><td><input type="text" value="<%=ResourceLoader.GetResource(session, "language")%>" id="keyGeneratorLang" style="width:100%"></td></tr>
                                </table>

                                <a class="btn btn-primary" title="Save" id="savekeygen" onclick="javascript:savekeygen();">
                                        <i class="icon-save icon-large"></i> 
                                        <%=ResourceLoader.GetResource(session, "actions.save")%></a>
                        </div><br>
                        <script type="text/javascript">
                                function savekeygen()
                                {
                                        //$("#results").html("<img src=\"img");
                                        $("#savekeygen").addClass("disabled");
                                        var keygen = $("#keyGeneratorKey").val();
                                        var keyname = $("#keyGeneratorName").val();
                                        var keylang = $("#keyGeneratorLang").val();
                                        var postbackdata = new Array();

                                        postbackdata.push({
                                                name: "action",
                                                value: "createKeyGen"
                                        });
                                        postbackdata.push({
                                                name: "keygen",
                                                value: keygen
                                        });
                                        postbackdata.push({
                                                name: "keyname",
                                                value: keyname
                                        });
                                        postbackdata.push({
                                                name: "keylang",
                                                value: keylang
                                        });
                                        postbackdata.push({
                                                name: "nonce",
                                                value: $("#nonce").val()
                                        });
                                        var request = $.ajax({
                                                url: 'ajax/tmodel.jsp',
                                                type: "POST",
                                                //  dataType: "html", 
                                                cache: false,
                                                //  processData: false,f
                                                data: postbackdata
                                        });

                                        request.done(function(msg) {
                                                window.console && console.log('postback done ');
                                                $("#results").html(msg);
                                                $("#savekeygen").removeClass("disabled");
                                                $("#createtmodelkeygen").modal();
                                        });

                                        request.fail(function(jqXHR, textStatus) {
                                                window.console && console.log('postback failed ');
                                                $("#results").text(textStatus + " " + jqXHR.responseText);
                                                $("#savekeygen").removeClass("disabled");
                                                $("#createtmodelkeygen").modal();

                                        });
                                }
                        </script>

                </div>
        </div>

        <div class="modal hide fade container" id="createtmodelkeygen">
                <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                        <h3><%=ResourceLoader.GetResource(session, "actions.result")%></h3>
                </div>
                <div class="modal-body">
                        <div id="results"></div>
                </div>
                <div class="modal-footer">
                        <button type="button" class="btn" data-dismiss="modal" ><%=ResourceLoader.GetResource(session, "modal.close")%></button>
                </div>
        </div>
        <%@include file="header-bottom.jsp" %>
