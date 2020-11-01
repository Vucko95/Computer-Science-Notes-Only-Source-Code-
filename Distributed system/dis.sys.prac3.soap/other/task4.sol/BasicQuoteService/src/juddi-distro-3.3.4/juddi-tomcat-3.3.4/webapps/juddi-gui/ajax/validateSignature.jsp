<%-- 
    Document   : validateSignature
    Created on : Apr 10, 2013, 10:14:19 PM
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
<%@page import="java.util.Iterator"%>
<%@page import="java.util.Set"%> 
<%@page import="java.util.Properties"%>
<%@page import="java.util.concurrent.atomic.AtomicReference"%>
<%@page import="org.apache.juddi.v3.client.cryptor.DigSigUtil"%>
<%@page import="org.apache.juddi.jaxb.JAXBMarshaller"%>
<%@page import="org.apache.juddi.jaxb.EntityCreator"%>
<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>
<%@page import="org.apache.juddi.webconsole.resources.ResourceLoader"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include  file="../csrf.jsp" %>
<%
    //org.apache.juddi.jaxb.PrintUDDI p = new PrintUDDI();
    UddiHub x = UddiHub.getInstance(application, session);

    String type = request.getParameter("type");
    String id = request.getParameter("id");
    if ((type != null && type.length() != 0) && (id != null && id.length() != 0)) {
        Object j = null;
        if (type.equalsIgnoreCase("business")) {
            j = x.GetBusinessDetailsAsObject(id);
        } else if (type.equalsIgnoreCase("service")) {
            j = x.GetServiceDetailsAsObject(id);
        } else if (type.equalsIgnoreCase("bindingTemplate")) {
            j = x.GetBindingDetailsAsObject(id);
        } else if (type.equalsIgnoreCase("tModel")) {
            j = x.GettModelDetailsAsObject(id);
        }
        if (j != null) {
            UddiHub hub = UddiHub.getInstance(application, session);
            
            org.apache.juddi.v3.client.cryptor.DigSigUtil dsig = new DigSigUtil(hub.GetDigitalSignatureConfig());

            AtomicReference<String> msg = new AtomicReference<String>();
            // dsig.put(DigSigUtil., value);
            boolean success = dsig.verifySignedUddiEntity(j, msg);
            if (!success) {
                out.write("<span class=\"label label-important\">" + ResourceLoader.GetResource(session, "items.signatures.invalid") + msg.get() + "</span>");
            } else {
                out.write("<span class=\"label label-success\">" + ResourceLoader.GetResource(session, "items.signatures.valid") + "</span>");
            }
        } else {
            //response.setStatus(500);
            out.write(ResourceLoader.GetResource(session, "items.unknown"));
        }
    }


    //get parameter type
    //fetch from UDDI
    //convert to string and output



%>