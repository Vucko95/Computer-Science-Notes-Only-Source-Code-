<%@page import="org.apache.commons.lang.StringEscapeUtils"%>
<%@ page session="false" %>
<%@ page import="java.util.List,
         org.apache.juddi.config.Install,
         javax.xml.bind.JAXBException,
         org.uddi.v3_service.DispositionReportFaultMessage,
         org.apache.juddi.config.AppConfig,
         org.apache.juddi.config.Property,
         org.uddi.api_v3.BusinessEntity,
         org.uddi.api_v3.Name,
         org.uddi.api_v3.Description,
         java.io.IOException,
         org.apache.juddi.config.Release"
         %>
<%
        
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
        
        %>
<!-- index.jsp -->
<html>
    <head>
        <title>Apache jUDDI Registry</title>
        <link rel="stylesheet" href="juddi.css" />
    </head>
    <body>
        <div class="header" align="right"><a href="http://juddi.apache.org/" target="_top">jUDDI@Apache</a></div>
        <h1>Apache jUDDI version <%= Release.getRegistryVersion()%></h1>


        <h2><em>Welcome</em> to Apache jUDDI!</h2>
        jUDDI is an open source implementation of <a href="http://oasis-open.org">OASIS</a>'s <a href="http://oasis-open.org/committees/uddi-spec/doc/tcspecs.htm#uddiv3">Universal Discovery Description and Integration (UDDI)</a>.
        You've reached the deployment page for jUDDI's web services.<br>

        Looking for the old jUDDI Portal/Porlets? We've completely rewritten it. 

        <h4><a href="/juddi-gui">View the jUDDI User Interface</a> - This is a nearly complete UDDIv3 end user web application.</h4>

        <h4><a href="admin">View the jUDDI Administration Interface</a> - This is for administrators to use to reconfigure jUDDI, check the status, and perform administrative actions.</h4>


        Here's some useful links to learn more about the UDDI and jUDDI.
        <ul>
            <li><a href="services">View the service listing on this UDDI node</a></li>
            <li><a href="http://juddi.apache.org/">The Apache-jUDDI Home Page</a></li>
            <li><a href="http://juddi.apache.org/docs.html" >Documentation</a></li>
            <li><a href="http://wiki.apache.org/juddi" >jUDDI Wiki</a></li>
            <li><a href="http://juddi.apache.org/issue-tracking.html" >jUDDI's Issue Tracker (report a bug)</a></li>
            <li><a href="http://juddi.apache.org/source.html" >jUDDI's Source Code</a></li>
            <li><a href="http://juddi.apache.org/mailing-list.html">jUDDI's Mailing lists</a></li>

        </ul>

        <div class="install">
            <h4>jUDDI Installation Status</h4>
            <div class="content">
                <%
                    // This will tirgger the install process...
                    String rootPartition = AppConfig.getConfiguration().getString(Property.JUDDI_ROOT_PARTITION);
                    String nodeId = AppConfig.getConfiguration().getString(Property.JUDDI_NODE_ID);
                    String rootBusiness = AppConfig.getConfiguration().getString(Property.JUDDI_NODE_ROOT_BUSINESS);
                    String nodeName = "";
                    String nodeDescription = "";
                    BusinessEntity be = null;
                    boolean ok = true;
                    String error = "";
                    try {
                        be = Install.getNodeBusinessEntity(rootBusiness);
                        Name n = be.getName().get(0);
                        if (n != null) {
                            nodeName = n.getValue();
                        }

                        List descList = be.getDescription();
                        if (descList != null && descList.size() > 0) {
                            Description d = (Description) descList.get(0);
                            if (d != null) {
                                nodeDescription = d.getValue();
                            }
                        }
                    } catch (Exception ex) {
                        ok = false;
                        error = ex.getMessage();

                    }
                    if (ok) {

                %>
                <div>jUDDI has been successfully installed!</div>

                <h3>Node Information</h3>
                <table>
                    <tr>
                        <td><b>Root Partition:</b></td>
                        <td><%= StringEscapeUtils.escapeHtml(rootPartition)%></td>
                    </tr>

                    <tr>
                        <td><b>Node Id:</b></td>
                        <td><%=StringEscapeUtils.escapeHtml(nodeId)%></td>
                    </tr>
                    <tr>
                        <td><b>Root Business Key:</b></td>
                        <td><%= StringEscapeUtils.escapeHtml(rootBusiness)%></td>
                    </tr>
                    <tr>
                        <td><b>Root Business Name:</b></td>
                        <td><%= StringEscapeUtils.escapeHtml(nodeName)%></td>
                    </tr>
                    <tr>
                        <td><b>Root Business Description:</b></td>
                        <td><%=StringEscapeUtils.escapeHtml(nodeDescription)%></td>
                    </tr>

                </table>
                <%
                } else {
                %>
                <h2 color="red">jUDDI has NOT installed correctly!</h2>
                <p />
                <h3>Error Information</h3>
                <p>
                    <%=StringEscapeUtils.escapeHtml(error)%><br>
                    Suggestion: Check the juddiv3.xml config file for the following settings (in Xpath notation) and ensure that they either match the defaults, or the install data.
                </p>
                <ul>
                    <li>config/juddi/nodeId, default = uddi:juddi.apache.org:node1</li>
                    <li>config/juddi/rootBusinessId, default = uddi:juddi.apache.org:businesses-asf</li>
                </ul>
                Configured values:
                <table>
                    <tr>
                        <td><b>Root Partition:</b></td>
                        <td><%= StringEscapeUtils.escapeHtml(rootPartition)%></td>
                    </tr>

                    <tr>
                        <td><b>Node Id:</b></td>
                        <td><%=StringEscapeUtils.escapeHtml(nodeId)%></td>
                    </tr>
                    <tr>
                        <td><b>Root Business Key:</b></td>
                        <td><%= StringEscapeUtils.escapeHtml(rootBusiness)%></td>
                    </tr>
                    <tr>
                        <td><b>Root Business Name:</b></td>
                        <td><%= StringEscapeUtils.escapeHtml(nodeName)%></td>
                    </tr>
                    <tr>
                        <td><b>Root Business Description:</b></td>
                        <td><%=StringEscapeUtils.escapeHtml(nodeDescription)%></td>
                    </tr>

                </table>

                <%                    }
                %>
            </div>
        </div>

        <hr />
        <table width="100%" border="0">
            <tr>
                <td height="50" align="center" valign="bottom" nowrap>
                    <div class="footer">&nbsp;</div>
                </td>
            </tr>
        </table>

    </body>
</html>
