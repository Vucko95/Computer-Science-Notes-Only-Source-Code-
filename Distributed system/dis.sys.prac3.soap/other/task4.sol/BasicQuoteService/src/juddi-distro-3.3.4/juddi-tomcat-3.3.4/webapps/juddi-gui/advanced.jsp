<%-- 
    Document   : Advanced query page
    Created on : July 30, 2013, 4:26:58 PM
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


<%@page import="org.uddi.v3_service.UDDIReplicationPortType"%>
<%@page import="org.uddi.v3_service.UDDISubscriptionPortType"%>
<%@page import="org.uddi.v3_service.UDDICustodyTransferPortType"%>
<%@page import="org.uddi.v3_service.UDDIPublicationPortType"%>
<%@page import="org.uddi.v3_service.UDDIInquiryPortType"%>
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
        <h1><%=ResourceLoader.GetResource(session, "navbar.advanced")%></h1>
    </div>

    <!-- Example row of columns -->
    <div class="row">
        <div class="span12">
            <%= ResourceLoader.GetResource(session, "pages.advanced.content")%>
            <br>
            <div class="btn-group" data-toggle="buttons-radio" id="serviceselection">
                <button type="button" value="inquiry" onclick="javascript:toggleParent('inquiryparent');" class="btn btn-primary">Inquiry</button>
                <button type="button" value="publish"  onclick="javascript:toggleParent('publishparent');" class="btn btn-primary">Publish</button>
                <button type="button" value="custody"  onclick="javascript:toggleParent('custodyparent');" class="btn btn-primary">Custody Transfer</button>
                <button type="button" value="subscription"  onclick="javascript:toggleParent('subscriptionparent');" class="btn btn-primary">Subscriptions</button>
            </div>
            <div id="inquiryparent">
                <select id="inquiry" onchange="toggledivs('inquiry');">
                    <option>findBinding</option>
                    <option>findBusiness</option>
                    <option>findService</option>
                    <option>findRelatedBusiness</option>
                    <option>findTModel</option>
                    <option>getBindingDetail</option>
                    <option>getBusinessDetail</option>
                    <option>getServiceDetail</option>
                    <option>getOperationalInfo</option>
                    <option>getTModelDetail</option>
                </select>
            </div>

            <div id="publishparent">
                <select id="publish" onchange="toggledivs('publish');">
                    <option>addPublisherAssertions</option>
                    <option>deleteBinding</option>
                    <option>deleteBusiness</option>
                    <option>deletePublisherAssertions</option>
                    <option>deleteService</option>
                    <option>deleteTModel</option>
                    <option>getAssertionStatusReport</option>
                    <option>getPublisherAssertions</option>
                    <option>getRegisteredInfo</option>
                    <option>saveBinding</option>
                    <option>saveBusiness</option>
                    <option>saveService</option>
                    <option>saveTModel</option>
                    <option>setPublisherAssertions</option>
                </select>
            </div>
            <div id="custodyparent">
                <select id="custody" onchange="toggledivs('custody');">
                    <option>discardTransferToken</option>
                    <option>getTransferToken</option>
                    <option>transferEntities</option>
                </select>
            </div>
            <div id="subscriptionparent">
                <select id="subscription" onchange="toggledivs('subscription');">
                    <option>deleteSubscription</option>
                    <option>getSubscriptionResults</option>
                    <option>getSubscriptions</option>
                    <option>saveSubscription</option>
                </select>
            </div>

            <script type="text/javascript">
                    function toggleParent(select) {

                        $("#custodyparent").hide();
                        $("#publishparent").hide();
                        $("#subscriptionparent").hide();
                        $("#inquiryparent").hide();
                        $("#" + select).show();
                    }
                    toggleParent('inquriyparent');
                    function toggledivs(select)
                    {
                        var x = $("#" + select).val();
                        var url = 'ajax/advanced.jsp';

                        var postbackdata = new Array();


                        postbackdata.push({
                            name: "advancedaction",
                            value: "getdefaultrequest"
                        });

                        postbackdata.push({
                            name: "nonce",
                            value: $("#nonce").val()
                        });

                        postbackdata.push({
                            name: "service",
                            value: select
                        });

                        postbackdata.push({
                            name: "method",
                            value: x
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
                            //trim it
                            $("#xmlcontent").html(msg.replace(/^\s+|\s+$/g, ''));
                        });

                        request.fail(function(jqXHR, textStatus) {
                            window.console && console.log('postback failed ' + url + ' ' + jqXHR.responseText + textStatus);
                            //$("#adminresults").html(jqXHR.responseText + textStatus);


                        });
                    }
                    toggledivs();//run when the page loads

                    function sendformdata() {
                        $("#senddataresults").html("<img src=\"img/bigrollergreen.gif\" title=\"Loading\"/>");
                        var select = $("#serviceselection > button.btn.active").val();
                        var x = $("#" + select).val();
                        var url = 'ajax/advanced.jsp';

                        var postbackdata = new Array();


                        postbackdata.push({
                            name: "advancedaction",
                            value: "senddata"
                        });

                        postbackdata.push({
                            name: "nonce",
                            value: $("#nonce").val()
                        });

                        postbackdata.push({
                            name: "service",
                            value: select
                        });

                        postbackdata.push({
                            name: "method",
                            value: x
                        });

                        postbackdata.push({
                            name: "content",
                            value: $("#xmlcontent").val()
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
                            //trim it
                            $("#senddataresults").html(msg.replace(/^\s+|\s+$/g, ''));
                        });

                        request.fail(function(jqXHR, textStatus) {
                            window.console && console.log('postback failed ' + url);
                            $("#senddataresults").html(jqXHR.responseText + textStatus);
                        });
                    }
            </script>
            <br>
            <textarea id="xmlcontent" rows="8" cols="120"></textarea><br>

            <a href="javascript:sendformdata();" class="btn brn-primary"><%= ResourceLoader.GetResource(session, "actions.submit")%></a>
            <br><br>
            <div id="senddataresults"></div>
        </div>
    </div>

    <%@include file="header-bottom.jsp" %>