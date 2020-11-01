<%-- 
    Document   : signer
    Created on : Mar 24, 2013, 8:23:30 AM
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

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include file="header-top.jsp" %>
<div class="container">

    <!-- Main hero unit for a primary marketing message or call to action -->
    <div class="well">
        <h1>
            <%=ResourceLoader.GetResource(session, "items.dsigs")%>
        </h1>
    </div>

    <!-- Example row of columns -->
    <div class="row">
        <div class="span12">
            <%=ResourceLoader.GetResource(session, "items.dsigs.description")%><br>
            <%
                //figure out what we are signing
                //fetch the xml from ajex/toXml and fill the text area
                String id = request.getParameter("id");
                String itemtype = request.getParameter("type");

            %>

            You're about to digitally sign the <b><%=StringEscapeUtils.escapeHtml(itemtype)%></b> identified by the key <b><%=StringEscapeUtils.escapeHtml(id)%></b>.<br>
            By electronically signing this UDDI entry, other users will then be able to verify that this entry hasn't been modified.<br>

            <applet code="org.apache.juddi.gui.dsig.XmlSigApplet2" archive="applets/juddi-gui-dsig-all.jar" MAYSCRIPT height="350px" width="400px"></applet> 
            <script type="text/javascript">
                $.get("ajax/toXML.jsp?id=<%=id%>&type=<%=itemtype%>", function(data){
                    $("#data").val(data);
                });
                /**
                 * Called by the applet to obtaining the xml to be signed
                 */
                function getXml()
                {
                    return $("#data").val();
                }
                    
                function go()
                {
                        
                    var form = $("#uddiform");
                    var d = form.serializeArray();
                    var request=   $.ajax({
                        url: 'ajax/saveFromXML.jsp?id=<%=id%>&type=<%=itemtype%>',
                        type:"POST",
                        cache: false, 

                        data: d
                    });
                  
                    request.done(function(msg) {
                        window.console && console.log('postback done ');                
                        $("#alert_results").html('<i class="icon-2x icon-thumbs-up"></i><br>' + msg);
                        $("#alert").modal();
                        //TODO timer to auto redirect to the
                        window.setTimeout(function(){
                <%
                    if (itemtype == "business") {
                        out.write("window.location=\"businessEditor2.jsp?id=" + StringEscapeUtils.escapeJavaScript(id) + "\";");
                    }
                    if (itemtype == "service") {
                        out.write("window.location=\"serviceEditor.jsp?id=" + StringEscapeUtils.escapeJavaScript(id) + "\";");
                    }
                    if (itemtype == "tmodel") {
                        out.write("window.location=\"tmodelEditor.jsp?id=" + StringEscapeUtils.escapeJavaScript(id) + "\";");
                    }
                    if (itemtype == "bindingTemplate") {
                        out.write("window.location=\"bindingEditor.jsp?id=" + StringEscapeUtils.escapeJavaScript(id) + "\";");
                    }
                 
                %>
                            }, 5000);
                        });

                        request.fail(function(jqXHR, textStatus) {
                            window.console && console.log('postback failed ');                                
                            $("#alert_results").html('<i class="icon-2x icon-thumbs-down"></i><br>' +jqXHR.responseText + textStatus);
                            $("#alert").modal();
                        });
                    }
				 
                    /**
                     * called by the applet to refresh the page with the signed data
                     */	 
                    function writeXml(data)
                    {
                        $("#data").val(data);
                        //post back to the publishing thread
                        var url='ajax/saveFromXML.jsp?id=<%=id%>&type=<%=itemtype%>'
                        var form = $("#uddiform");
                        var d = form.serializeArray();
                        var request=   $.ajax({
                            url: url,
                            type:"POST",
                            cache: false, 

                            data: d
                        });
                  
                       request.done(function(msg) {
                        window.console && console.log('postback done '  + url);                

                        $("#alert_results").html('<i class="icon-2x icon-thumbs-up"></i><br>'  + msg);
                        $("#alert").modal();

                    });

                    request.fail(function(jqXHR, textStatus) {
                        window.console && console.log('postback failed ' + url);                                
                        $("#alert_results").html('<i class="icon-2x icon-thumbs-down"></i><br>'  + jqXHR.responseText + textStatus);
                        $("#alert").modal();
                    });
                    
                    }
				
                    function getBrowserName()
                    {
                        return navigator.appName;
                    }
                    function getOsName()
                    {
                        var OSName="unknown OS";
                        if (navigator.appVersion.indexOf("Win")!=-1) OSName="Windows";
                        if (navigator.appVersion.indexOf("Mac")!=-1) OSName="MacOS";
                        if (navigator.appVersion.indexOf("X11")!=-1) OSName="UNIX";
                        if (navigator.appVersion.indexOf("Linux")!=-1) OSName="Linux";
                        return OSName;
                    }
                    function getObjectType()
                    {
                        return "<%=StringEscapeUtils.escapeJavaScript(itemtype)%>";
                    }
                    //
                    //display:none  <a class="btn" href="javascript:go();">Go</a>
            </script>

            <textarea class="hide" name="data" rows="15" cols="80" id="data" style=""><%=ResourceLoader.GetResource(session, "items.loading")%>....</textarea>
        </div>

    </div>
    <%@include file="header-bottom.jsp" %>
