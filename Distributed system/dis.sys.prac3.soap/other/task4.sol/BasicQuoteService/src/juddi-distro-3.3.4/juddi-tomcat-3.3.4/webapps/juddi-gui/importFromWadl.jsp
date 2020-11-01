<%-- 
    Document   : importFromWadl
    Created on : July 11, 2013, 6:52:05 PM
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

<%@page import="java.util.ArrayList"%>
<%@page import="java.util.List"%>
<%@page import="javax.xml.datatype.XMLGregorianCalendar"%>
<%@page import="javax.xml.ws.Holder"%>
<%@page import="org.apache.juddi.webconsole.resources.ResourceLoader"%>
<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include file="header-top.jsp" %>
<div class="container">
 
        <!-- Main hero unit for a primary marketing message or call to action -->
        <div class="well" >
                <h1><%=ResourceLoader.GetResource(session, "navbar.create.serviceimport.wadl")%></h1>

        </div>

        <!-- Example row of columns -->
        <div class="row">
                <div class="span12" >
                        <%=ResourceLoader.GetResource(session, "pages.serviceimport.content.wadl")%>
                        <Br>
                        <br>

                        <div class="accordion" id="accordion2">
                                <div class="accordion-group">
                                        <div class="accordion-heading">
                                                <a class="accordion-toggle" data-toggle="collapse" data-parent="#accordion2" href="#collapse1">
                                                        <%=ResourceLoader.GetResource(session, "pages.serviceimport.content.step1.wadl")%>
                                                </a>
                                        </div>
                                        <div id="collapse1" class="accordion-body collapse in">
                                                <div class="accordion-inner">
                                                        <%=ResourceLoader.GetResource(session, "pages.serviceimport.content.step1a.wadl")%><br>
                                                        <input type="text" id="wsdlurl" placeholder="http://localhost:8080/services/myService?wadl" style="width:100%" ><br>
                                                        <%=ResourceLoader.GetResource(session, "pages.serviceimport.content.step1b")%><br>
                                                        <%
                                                                if (!request.isSecure()) {
                                                        %>
                                                        <div class="alert alert-error">
                                                                <button type="button" class="close" data-dismiss="alert">&times;</button>
                                                                <h4><i class="icon-warning-sign"></i> <%=ResourceLoader.GetResource(session, "pages.serviceimport.content.sslwarning")%></h4>
                                                                <%=ResourceLoader.GetResource(session, "pages.serviceimport.content.usessl")%>

                                                        </div>
                                                        <%                                }
                                                        %>
                                                        <input type="text" id="wsdlusername" placeholder="<%=ResourceLoader.GetResource(session, "navbar.login.username")%> <%=ResourceLoader.GetResource(session, "items.optional")%>" ><br>
                                                        <input type="password" id="wsdlpassword" placeholder="<%=ResourceLoader.GetResource(session, "navbar.login.password")%> <%=ResourceLoader.GetResource(session, "items.optional")%>" ><br>
                                                        <input type="checkbox" id="wsdlignoressl" > <%=ResourceLoader.GetResource(session, "items.ignoresslerror")%><br>
                                                </div>
                                        </div>
                                </div>
                                <script type="text/javascript">

                                        //by James Padolsey
                                        //http://james.padolsey.com/javascript/parsing-urls-with-the-dom/
                                        function parseURL(url) {
                                                var a = document.createElement('a');
                                                a.href = url;
                                                return {
                                                        source: url,
                                                        protocol: a.protocol.replace(':', ''),
                                                        host: a.hostname,
                                                        port: a.port,
                                                        query: a.search,
                                                        params: (function() {
                                                                var ret = {},
                                                                        seg = a.search.replace(/^\?/, '').split('&'),
                                                                        len = seg.length, i = 0, s;
                                                                for (; i < len; i++) {
                                                                        if (!seg[i]) {
                                                                                continue;
                                                                        }
                                                                        s = seg[i].split('=');
                                                                        ret[s[0]] = s[1];
                                                                }
                                                                return ret;
                                                        })(),
                                                        file: (a.pathname.match(/\/([^\/?#]+)$/i) || [, ''])[1],
                                                        hash: a.hash.replace('#', ''),
                                                        path: a.pathname.replace(/^([^\/])/, '/$1'),
                                                        relative: (a.href.match(/tps?:\/\/[^\/]+(.+)/) || [, ''])[1],
                                                        segments: a.pathname.replace(/^\//, '').split('/')
                                                };
                                        }

                                        //after is entered, fetch the wsdl, parse the key domain
                                        var trigger1_triggered = false;
                                        //considerations, if its an ip address? what about localhost
                                        function trigger1()
                                        {
                                                if (!trigger1_triggered) {
                                                        var l = parseURL($("#wsdlurl").val());
                                                        $("#keydomain").val(l.host);
                                                        $("#collapse1").collapse('hide');
                                                        $("#collapse2").collapse('show');
                                                        var trigger1_triggered = true;
                                                }
                                        }

                                        function save(preview)
                                        {
                                                var ok = true;
                                                var postbackdata = new Array();
                                                var url = 'ajax/importFromWadl.jsp';
                                                postbackdata.push({
                                                        name: "nonce",
                                                        value: $("#nonce").val()
                                                });
                                                if (preview) {
                                                        postbackdata.push({
                                                                name: "formaction",
                                                                value: "preview"
                                                        });
                                                }
                                                else
                                                {
                                                        postbackdata.push({
                                                                name: "formaction",
                                                                value: "save"
                                                        });
                                                }
                                                postbackdata.push({
                                                        name: "wsdlusername",
                                                        value: $("#wsdlusername").val()
                                                });
                                                postbackdata.push({
                                                        name: "wsdlpassword",
                                                        value: $("#wsdlpassword").val()
                                                });
                                                postbackdata.push({
                                                        name: "wsdlurl",
                                                        value: $("#wsdlurl").val()
                                                });
                                                if ($("#wsdlurl").val() === "")
                                                        ok = false;
                                                if ($('#wsdlignoressl').is(':checked')) {
                                                        postbackdata.push({
                                                                name: "ignoressl",
                                                                value: true
                                                        });
                                                }
                                                else
                                                {
                                                        postbackdata.push({
                                                                name: "ignoressl",
                                                                value: false
                                                        });
                                                }
                                                if ($("#businessname").val() === "")
                                                        ok = false;
                                                postbackdata.push({
                                                        name: "businessname",
                                                        value: $("#businessname").val()
                                                });

                                                postbackdata.push({
                                                        name: "keydomain",
                                                        value: $("#keydomain").val()
                                                });


                                                if ($("#keydomain").val() === "")
                                                        ok = false;
                                                if (!ok)
                                                {
                                                        alert('<%=ResourceLoader.GetResource(session, "form.missing.information")%>');
                                                        return;
                                                }


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
                                                        $("#preview").html(msg);
                                                });

                                                request.fail(function(jqXHR, textStatus) {
                                                        window.console && console.log('postback failed ' + url);
                                                        $("#preview").html(jqXHR + textStatus);

                                                });
                                        }

                                </script>
                                <div class="accordion-group">
                                        <div class="accordion-heading">
                                                <a class="accordion-toggle" data-toggle="collapse" data-parent="#accordion2" href="#collapse2" onclick="trigger1();">
                                                        <%=ResourceLoader.GetResource(session, "pages.serviceimport.content.step2")%>
                                                </a>
                                        </div>
                                        <div id="collapse2" class="accordion-body collapse">
                                                <div class="accordion-inner">
                                                        <%=ResourceLoader.GetResource(session, "pages.serviceimport.content.step2a")%>
                                                        <br>
                                                        <input type="text" id="keydomain" placeholder="<%=ResourceLoader.GetResource(session, "items.import.autofill")%>">
                                                </div>
                                        </div>
                                </div>

                                <div class="accordion-group">
                                        <div class="accordion-heading">
                                                <a class="accordion-toggle" data-toggle="collapse" data-parent="#accordion2" href="#collapse3">
                                                        <%=ResourceLoader.GetResource(session, "pages.serviceimport.content.step3")%>

                                                </a>
                                        </div>
                                        <div id="collapse3" class="accordion-body collapse">
                                                <div class="accordion-inner">
                                                        <%=ResourceLoader.GetResource(session, "pages.serviceimport.content.step3a")%><br>
                                                        <a href="javascript:loadBusinessModel();"><i class="icon-list-alt icon-large"></i> <%=ResourceLoader.GetResource(session, "items.picker")%></a>

                                                        <script type="text/javascript">
                                                                function loadBusinessModel()
                                                                {
                                                                        reloadBusinessModal();
                                                                        $.dialogBusiness.confirm({
                                                                                callback: function(success, result) {
                                                                                        if (success)
                                                                                        {
                                                                                                for (var i = 0; i < result.length; i++) {
                                                                                                        $("#businessname").val(result[i]);
                                                                                                        //if ($("#keylist option[value='"+result[i]+"']").length == 0)
                                                                                                        //$("#keylist").append("<option value=\"" + result[i] + "\">" + result[i] + "</option>");
                                                                                                }

                                                                                        }
                                                                                }
                                                                        });
                                                                }
                                                        </script>
                                                        <input type="text" id="businessname" placeholder="<%=ResourceLoader.GetResource(session, "items.import.bizname")%>">
                                                </div>
                                        </div>
                                </div>


                                <div class="accordion-group">
                                        <div class="accordion-heading">
                                                <a class="accordion-toggle" data-toggle="collapse" data-parent="#accordion2" href="#collapse4">
                                                        <%=ResourceLoader.GetResource(session, "pages.serviceimport.content.step4")%>
                                                </a>
                                        </div>
                                        <div id="collapse4" class="accordion-body collapse">
                                                <div class="accordion-inner">
                                                        <%=ResourceLoader.GetResource(session, "pages.serviceimport.content.step4a")%>

                                                        <Br><br>
                                                        <div id="preview"></div>
                                                        <a class="btn btn-info" onclick="save(true);"><i class="icon-eye-open icon-large"></i> <%=ResourceLoader.GetResource(session, "actions.preview")%></a>
                                                        <a class="btn btn-primary" onclick="save(false);"><i class="icon-save icon-large"></i>  <%=ResourceLoader.GetResource(session, "actions.save")%></a>
                                                </div>
                                        </div>
                                </div>

                        </div>



                </div>
        </div>

        <%@include file="businessChooser.jsp" %>
        <%@include file="header-bottom.jsp" %>
