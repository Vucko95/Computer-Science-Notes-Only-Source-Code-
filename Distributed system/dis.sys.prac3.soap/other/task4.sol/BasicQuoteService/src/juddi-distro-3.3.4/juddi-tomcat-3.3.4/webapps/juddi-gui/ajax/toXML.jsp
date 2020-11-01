<%-- 
    Document   : toXML
    Created on : Mar 14, 2013, 9:17:21 PM
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
--%><%@page import="javax.xml.bind.JAXB"%><%@page import="org.apache.juddi.webconsole.resources.ResourceLoader"%><%@page import="org.apache.juddi.jaxb.JAXBMarshaller"%><%@page import="org.apache.juddi.jaxb.EntityCreator"%><%@page import="org.apache.juddi.webconsole.hub.UddiHub"%><%@page import="org.apache.juddi.jaxb.PrintUDDI"%><%@page contentType="text/html" pageEncoding="UTF-8"%><%
    
        //do we need cross site request forgery project here? probably but it's left out due to adding additional end lines
        //its low risk here since nothing actually changes server side for these functions
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
        else if (type.equalsIgnoreCase("subscription")) {
            j = x.GetSubscriptionDetails(id);
        }
        if (j != null) {
            JAXB.marshal(j, out);
        } else {
            out.write(ResourceLoader.GetResource(session, "items.unknown"));
            response.setStatus(406);
        }
    }

    //get parameter type
    //fetch from UDDI
    //convert to string and output



%>