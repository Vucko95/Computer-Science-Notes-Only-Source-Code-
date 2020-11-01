<%-- 
    Document   : admin
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
                        <%=ResourceLoader.GetResource(session, "pages.admin.content")%>
                        <br>
                        <select onchange="toggledivs();" id="divselector">
                                
                                <option>------ Subscription Management -----</option>
                                <option>get_AllClientSubscriptionInfo</option>
                                <option>delete_ClientSubscriptionInfo</option>
                                <option>invoke_SyncSubscription</option>
                                <option>save_ClientSubscriptionInfo</option>
                                
                                <option>admin_SaveSubscription</option>
                                <option>admin_DeleteSubscription</option>
                                
                                <option>get_AllNodes</option>
                                <option>save_Node</option>
                                <option>delete_Node</option>
                                
                                <option>get_AllClerks</option>
                                <option>save_Clerk</option>
                                <option>delete_Clerk</option>
                                
                                <option>------ Publisher/User Management -----</option>
                                <option>getAllPublisherDetail</option>
                                <option>get_publisherDetail</option>
                                <option>delete_publisher</option>
                                <option>save_publisher</option>
                                
                                
                                
                                <option>------ Node Management -----</option>
                                <option>set_ReplicationNodes</option>
                                <option>get_ReplicationNodes</option>
                                <option>get_EntityHistory</option>
                                <option>change_NodeID</option>
                                <option>getFailedReplicationChangeRecords</option>

                                <option>------ Backup/Restore Management -----</option>
                                <option>admin_SaveBusiness</option>
                                <option>admin_SaveTModel</option>
                                <option>adminDelete_tmodel</option>                                 
                                <option>send_EmailTest</option>
                               
                                
                        </select>

                        <div>
                                <div id="adminDelete_tmodel" style="display:none">
                                        <input type="text" id="adminDelete_tmodelKEY" class="forminput" placeholder="Enter tModel Key">
                                </div>
                                <div id="delete_ClientSubscriptionInfo"  style="display:none">
                                        <input type="text" id="delete_ClientSubscriptionInfoKEY" class="forminput" placeholder="Enter subscription Key">
                                </div>
                                <div id="invoke_SyncSubscription" style="display:none">
                                        <%=ResourceLoader.GetResource(session, "items.noauthtoken")%>  <br>
                                        <textarea rows="4" cols="80" id="invoke_SyncSubscriptionXML" class="forminput" placeholder="Enter subscription XML"></textarea>

                                </div>
                                <div id="delete_publisher" style="display:none">
                                        <input type="text"  class="forminput" id="delete_publisherKEY" placeholder="Enter publisher id">
                                </div>
                                <div id="getAllPublisherDetail" style="display:none">
                                        <%=ResourceLoader.GetResource(session, "items.noinput")%>
                                </div>
                                <div id="get_publisherDetail" style="display:none">
                                        <input type="text" id="get_publisherDetailKEY"  class="forminput" placeholder="Enter publisher id">
                                </div>
                                <div id="save_ClientSubscriptionInfo" style="display:none">
                                        <%=ResourceLoader.GetResource(session, "items.noauthtoken")%><br>
                                        <textarea rows="4" cols="80" id="ClientSubscriptionInfoDetailXML" class="forminput" placeholder="Enter subscription XML"><%=StringEscapeUtils.escapeHtml(x.getSampleSave_ClientSubscriptionInfo())%></textarea>
                                </div>
                                <div id="save_publisher" style="display:none">
                                        <%=ResourceLoader.GetResource(session, "items.name")%> <input type="text" id="savePublisherNAME"  class="forminput" placeholder="Enter name"><br>
                                        <%=ResourceLoader.GetResource(session, "items.email")%>  <input type="text" id="savePublisherEMAIL"  class="forminput" placeholder="Enter email"><br>
                                        <%=ResourceLoader.GetResource(session, "items.authorizedname")%>  <input type="text" id="savePublisherAuthorizedName"  class="forminput" placeholder="Enter Authorized Name (username)"><br>
                                        <%=ResourceLoader.GetResource(session, "items.publisher.admin")%>  <input type="checkbox" id="savePublisherIsAdmin"   ><br>
                                        <%=ResourceLoader.GetResource(session, "items.enable")%>  <input type="checkbox" id="savePublisherIsEnabled"  ><br>
                                        <%=ResourceLoader.GetResource(session, "max.bindings.per.service")%> <input type="text" id="savePublisherMaxBindings" placeholder="100"  class="forminput"><br>
                                        <%=ResourceLoader.GetResource(session, "max.services.per.business")%> <input type="text" id="savePublisherMaxServices" placeholder="1000" class="forminput"><br>
                                        <%=ResourceLoader.GetResource(session, "max.business")%> <input type="text" id="savePublisherMaxBusiness" placeholder="1000"  class="forminput"><br>
                                        <%=ResourceLoader.GetResource(session, "max.tmodel")%> <input type="text" id="savePublisherMaxTModels" placeholder="1000" class="forminput"><br>
                                        <br>
                                        <%=ResourceLoader.GetResource(session, "pages.admin.max")%>
                                </div>
                                <div id="save_Node" style="display:none">

                                        <%=ResourceLoader.GetResource(session, "items.clientname")%> <input type="text" id="NODEsetClientName"  class="forminput" placeholder="Client Name"><br>
                                        <%=ResourceLoader.GetResource(session, "items.name")%> <input type="text" id="NODEsetName"  class="forminput" placeholder="Enter name"><br>

                                        <%=ResourceLoader.GetResource(session, "items.description")%> <input type="text" id="NODEsetDescription"  class="forminput" placeholder="Enter description"><br>
                                        Factory Initial <input type="text" id="NODEsetFactoryInitial"  class="forminput" placeholder="only needed for RMI transport"><br>
                                        Factory URL Packages <input type="text" id="NODEsetFactoryURLPkgs"  class="forminput" placeholder="only needed for RMI transport"><br>
                                        Factory Naming Provider <input type="text" id="NODEsetFactoryNamingProvider"  class="forminput" placeholder="only needed for RMI transport"><br>
                                        <%=ResourceLoader.GetResource(session, "items.transport")%> <input type="text" id="NODEsetProxyTransport"  class="forminput" placeholder="org.apache.juddi.v3.client.transport.JAXWSTransport" value="org.apache.juddi.v3.client.transport.JAXWSTransport"><br>
                                        <%=ResourceLoader.GetResource(session, "items.inquiry")%> <input type="text" id="NODEsetInquiryUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/inquiry" value="http://localhost:8080/juddiv3/services/inquiry"><br>
                                        <%=ResourceLoader.GetResource(session, "items.publish")%> <input type="text" id="NODEsetPublishUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/publish" value="http://localhost:8080/juddiv3/services/publish"><br>
                                        <%=ResourceLoader.GetResource(session, "items.security")%> <input type="text" id="NODEsetSecurityUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/security" value="http://localhost:8080/juddiv3/services/security"><br>
                                        <%=ResourceLoader.GetResource(session, "items.subscription.list")%> <input type="text" id="NODEsetSubscriptionListenerUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/subscription-listener" value="http://localhost:8080/juddiv3/services/subscription-listener"><br>
                                        <%=ResourceLoader.GetResource(session, "items.subscription")%> <input type="text" id="NODEsetSubscriptionUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/subscription" value="http://localhost:8080/juddiv3/services/subscription"><br>
                                        <%=ResourceLoader.GetResource(session, "items.custodytransfer")%> <input type="text" id="NODEsetCustodyTransferUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/custody-transfer" value="http://localhost:8080/juddiv3/services/custody-transfer"><br>
                                        <%=ResourceLoader.GetResource(session, "items.replication")%> <input type="text" id="NODEsetReplicationUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/replication" value="http://localhost:8080/juddiv3/services/replication"><br>
                                        jUDDI API <input type="text" id="NODEsetJuddiApiUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/juddi-api" value="http://localhost:8080/juddiv3/services/juddi-api"><br>
                                </div>
                                <div id="save_Clerk" style="display:none">
                                        <%=ResourceLoader.GetResource(session, "items.name")%> <input type="text" id="CLERKsetName"  class="forminput" placeholder="Enter name"><br>
                                        <%=ResourceLoader.GetResource(session, "items.authorizedname")%> <input type="text" id="CLERKsetPublisher"  class="forminput" placeholder="Enter Authorized Name (username)"><br>
                                        <%=ResourceLoader.GetResource(session, "navbar.login.password")%> <input type="password" id="CLERKsetPassword"  class="forminput" placeholder="Enter password"><br>
                                        <hr>
                                        <%=ResourceLoader.GetResource(session, "items.clientname")%> <input type="text" id="CLERKNODEsetClientName"  class="forminput" placeholder="Client Name"><br>
                                        <%=ResourceLoader.GetResource(session, "items.name")%> <input type="text" id="CLERKNODEsetName"  class="forminput" placeholder="Enter name"><br>

                                        <%=ResourceLoader.GetResource(session, "items.description")%> <input type="text" id="CLERKNODEsetDescription"  class="forminput" placeholder="Enter description"><br>
                                        Factory Initial <input type="text" id="CLERKNODEsetFactoryInitial"  class="forminput" placeholder="only needed for RMI transport"><br>
                                        Factory URL Packages <input type="text" id="CLERKNODEsetFactoryURLPkgs"  class="forminput" placeholder="only needed for RMI transport"><br>
                                        Factory Naming Provider <input type="text" id="CLERKNODEsetFactoryNamingProvider"  class="forminput" placeholder="only needed for RMI transport"><br>
                                        <%=ResourceLoader.GetResource(session, "items.transport")%> <input type="text" id="CLERKNODEsetProxyTransport"  class="forminput" placeholder="org.apache.juddi.v3.client.transport.JAXWSTransport" value="org.apache.juddi.v3.client.transport.JAXWSTransport"><br>
                                        <%=ResourceLoader.GetResource(session, "items.inquiry")%> <input type="text" id="CLERKNODEsetInquiryUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/inquiry" value="http://localhost:8080/juddiv3/services/inquiry"><br>
                                        <%=ResourceLoader.GetResource(session, "items.publish")%> <input type="text" id="CLERKNODEsetPublishUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/publish" value="http://localhost:8080/juddiv3/services/publish"><br>
                                        <%=ResourceLoader.GetResource(session, "items.security")%> <input type="text" id="CLERKNODEsetSecurityUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/security" value="http://localhost:8080/juddiv3/services/security"><br>
                                        <%=ResourceLoader.GetResource(session, "items.subscription.list")%> <input type="text" id="CLERKNODEsetSubscriptionListenerUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/subscription-listener" value="http://localhost:8080/juddiv3/services/subscription-listener"><br>
                                        <%=ResourceLoader.GetResource(session, "items.subscription")%> <input type="text" id="CLERKNODEsetSubscriptionUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/subscription" value="http://localhost:8080/juddiv3/services/subscription"><br>
                                        <%=ResourceLoader.GetResource(session, "items.custodytransfer")%> <input type="text" id="CLERKNODEsetCustodyTransferUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/custody-transfer" value="http://localhost:8080/juddiv3/services/custody-transfer"><br>
                                        <%=ResourceLoader.GetResource(session, "items.replication")%> <input type="text" id="CLERKNODEsetReplicationUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/replication" value="http://localhost:8080/juddiv3/services/replication"><br>
                                        jUDDI API <input type="text" id="CLERKNODEsetJuddiApiUrl"  class="forminput" placeholder="http://localhost:8080/juddiv3/services/juddi-api" value="http://localhost:8080/juddiv3/services/juddi-api"><br>

                                </div>
                                        
                                        
                                        
                                <div id="send_EmailTest" style="display:none">
                                <%=ResourceLoader.GetResource(session, "items.email")%>  <input type="text" id="send_EmailTestEMAIL"  class="forminput" placeholder="Enter email"><br>    
                                </div>
                                <div id="get_AllNodes" style="display:none">
                                    No input required.
                                </div>
                                <div id="get_AllClerks" style="display:none">
                                    No input required.
                                </div>
                                <div id="delete_Node" style="display:none">
                                    Node name <input type="text" id="delete_NodeName"  class="forminput" placeholder="Node name"><br>
                                </div>
                                <div id="delete_Clerk" style="display:none">
                                    Clerk name <input type="text" id="delete_ClerkName"  class="forminput" placeholder="Clerk name"><br>
                                </div>
                                <div id="admin_DeleteSubscription" style="display:none">
                                   Subscription Key <input type="text" id="admin_DeleteSubscriptionKey"  class="forminput" placeholder="Subscription Key"><br>
                                </div>
                                <div id="admin_SaveBusiness" style="display:none">
                                     <%=ResourceLoader.GetResource(session, "items.noauthtoken")%>  <br>
                                        <textarea rows="4" cols="80" id="admin_SaveBusinessXML" class="forminput" placeholder="Enter save business XML"></textarea>

                                </div>
                                <div id="admin_SaveTModel" style="display:none">
                                     <%=ResourceLoader.GetResource(session, "items.noauthtoken")%>  <br>
                                        <textarea rows="4" cols="80" id="admin_SaveTModelXML" class="forminput" placeholder="Enter save tmodel XML"></textarea>

                                </div>
                                <div id="get_AllClientSubscriptionInfo" style="display:none">
                                    No input required.
                                </div>
                                <div id="set_ReplicationNodes" style="display:none">
                                    
                                         <%=ResourceLoader.GetResource(session, "items.noauthtoken")%>  <br>
                                        <textarea rows="4" cols="80" id="set_ReplicationNodesXML" class="forminput" placeholder="Enter replication config XML"></textarea>

                                </div>
                                <div id="get_ReplicationNodes" style="display:none">
                                    No input required.
                                </div>
                                <div id="admin_SaveSubscription" style="display:none">
                                    
                                         <%=ResourceLoader.GetResource(session, "items.noauthtoken")%>  <br>
                                        <textarea rows="4" cols="80" id="admin_SaveSubscriptionXML" class="forminput" placeholder="Enter save subscription XML"></textarea>

                                </div>
                                <div id="get_EntityHistory" style="display:none">
                                   Entity Key <input type="text" id="get_EntityHistoryKey"  class="forminput" placeholder="Entity Key"><br>
                                   Records to fetch <input type="text" id="get_EntityHistoryMaxCount"  class="forminput" value="25"><br>
                                   Offset <input type="text" id="get_EntityHistoryOffset"  class="forminput" value="0"><br>
                                </div>
                                        
                                <div id="change_NodeID" style="display:none">
                                    This will change the current node's identifier. During the transaction, no one will be able to modify items stored in the database.
                                    This option is not available if this node is configured for replication. It must be removed from the replication configuration on all nodes before renaming.
                                    <br><br>
                                    Note: Depending on how jUDDI was deployed, you may have to manually edit the juddiv3.xml config file, then restart jUDDI after this process is complete.<br><br>
                                    New Node ID <input type="text" id="change_NodeIDKey"  class="forminput" placeholder="Node ID" value="<%=StringEscapeUtils.escapeHtml( AppConfig.getConfiguration().getString(Property.JUDDI_NODE_ID))%>"><br>
                                </div>
                                <div id="getFailedReplicationChangeRecords" style="display:none">
                                    Records to fetch <input type="text" id="getFailedReplicationChangeRecordsMaxCount"  class="forminput" value="5"><br>
                                    Offset <input type="text" id="getFailedReplicationChangeRecordsOffset"  class="forminput" value="0"><br>
                                </div>
                                        
                                
                               

                        </div>
                            
                        <script type="text/javascript">
                                function toggledivs()
                                {
                                        var x = $("#divselector").val();
                                        //alert(x);
                                        $("#adminDelete_tmodel").hide();
                                        $("#delete_ClientSubscriptionInfo").hide();
                                        $("#delete_publisher").hide();
                                        $("#getAllPublisherDetail").hide();
                                        $("#get_publisherDetail").hide();
                                        $("#invoke_SyncSubscription").hide();
                                        $("#save_ClientSubscriptionInfo").hide();
                                        $("#save_publisher").hide();
                                        $("#save_Clerk").hide();
                                        $("#save_Node").hide();
                                        
                                        
                                        $("#send_EmailTest").hide();
                                        $("#get_AllNodes").hide();
                                        $("#get_AllClerks").hide();
                                        $("#delete_Node").hide();
                                        $("#delete_Clerk").hide();
                                        $("#admin_DeleteSubscription").hide();
                                        $("#admin_SaveBusiness").hide();
                                        $("#admin_SaveTModel").hide();
                                        $("#get_AllClientSubscriptionInfo").hide();
                                        $("#set_ReplicationNodes").hide();
                                        $("#get_ReplicationNodes").hide();
                                        $("#admin_SaveSubscription").hide();
                                        $("#get_EntityHistory").hide();
                                        $("#change_NodeID").hide();
                                        $("#getFailedReplicationChangeRecords").hide();
                                       
                        
                                        $("#" + x).show();
                                        
                                        //get a samle xml doc
                                        
                                       // var x = $("#" + select).val();
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

                                        $("#resultsDiv").html("");
                                        request.done(function(msg) {
                                            window.console && console.log('postback done ' + url);
                                            //trim it
                                            $("#" + x + "XML").html(msg.replace(/^\s+|\s+$/g, ''));
                                        });

                                        request.fail(function(jqXHR, textStatus) {
                                            window.console && console.log('postback failed ' + url + ' ' + jqXHR.responseText + textStatus);
                                            //$("#adminresults").html(jqXHR.responseText + textStatus);


                                        });
                                }
                                toggledivs();//run when the page loads
                                function submitform() {
                                    $("#resultsDiv").val("Please wait...");
                                        var url = 'ajax/go.jsp';

                                        var postbackdata = new Array();

                                        var x = $("#divselector").val();
                                        postbackdata.push({
                                                name: "soapaction",
                                                value: x
                                        });

                                        postbackdata.push({
                                                name: "nonce",
                                                value: $("#nonce").val()
                                        });

                                        $(".forminput").each(function()
                                        {
                                                var id = $(this).attr("id");
                                                var value = $(this).val();
                                                if (value === null || value === "" || value === undefined)
                                                        value=$(this).text();
                                                postbackdata.push({
                                                        name: id,
                                                        value: value
                                                });
                                        });
                                     
                                        postbackdata.push({
                                                name: "savePublisherIsEnabled",
                                                value: $('#savePublisherIsEnabled').prop("checked")
                                        });
                                        postbackdata.push({
                                                name: "savePublisherIsAdmin",
                                                value: $('#savePublisherIsAdmin').prop("checked")
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
                                                if (StringStartsWith(msg.trim(),"Error")){
                                                     $("#adminresults").html(msg);
                                                    $('#adminresultsmodal').modal();
                                                }
                                                else
                                                {
                                                    $("#resultsDiv").html(msg);
                                                    location.hash = "#resultsAnchor";
                                                }
                                        });

                                        request.fail(function(jqXHR, textStatus) {
                                                window.console && console.log('postback failed ' + url);
                                                $("#adminresults").html(jqXHR.responseText + textStatus);
                                                $('#adminresultsmodal').modal();

                                        });
                                }
                                
                                function StringStartsWith(source, str){
                                    
                                      return source.slice(0, str.length) == str;
                                    
                                  }
                        </script>
                        <br>
                        <%=ResourceLoader.GetResource(session, "pages.admin.notes")%>

                        <br>
                        <a href="javascript:submitform();" class="btn btn-primary"><%=ResourceLoader.GetResource(session, "actions.go")%></a><br>
                        
                        <hr>
                        <br><a name="resultsAnchor"></a>
                            <div id="resultsDiv"></div>

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