<%-- 
    Document   : csrf Provides basic Cross site request forgery protection
    Created on : Feb 27, 2013, 8:42:07 PM
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

<%@page import="org.apache.juddi.adminconsole.hub.UddiAdminHub"%>
<%@page import="org.apache.juddi.adminconsole.CrossSiteRequestForgeryException"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%
    //this is to catch someone that bookmarked a page after selecting a language
    Cookie[] cookies3 = request.getCookies();
    if (cookies3 != null && cookies3.length > 0) {
        for (int i = 0; i < cookies3.length; i++) {
            if (cookies3[i] != null && cookies3[i].getName() != null && cookies3[i].getName().equalsIgnoreCase("locale")) {
                if (cookies3[i].getValue() != null) {
                    session.setAttribute("locale", cookies3[i].getValue());
                }
            }
        }
    }
    if (session.getAttribute("locale")==null){
        //last change, default to english
        session.setAttribute("locale", "en");
    }
    String currentNonce = null;

    if (request.getMethod().equalsIgnoreCase("post")) {

        if ((request.getParameter("nonce") == null || request.getParameter("nonce").isEmpty())) {
            //reject it
            session.removeAttribute("nonce");
            response.sendRedirect("index.jsp");
            UddiAdminHub.log.warn( "CSRF Test failed, no nonce guid." + request.getRemoteAddr() + request.getRemoteUser());
            //throw new CrossSiteRequestForgeryException();
            response.sendRedirect("index.jsp");
                
                return;
        } else {

            String noncestr = (String) session.getAttribute("nonce");
            if (noncestr == null) {
                //no session variable to test against, reject it
                UddiAdminHub.log.warn( "CSRF Test failed, no session guid." + request.getRemoteAddr() + request.getRemoteUser());
                session.removeAttribute("nonce");
                //throw new CrossSiteRequestForgeryException("Cross Site Request Forgery");
                response.sendRedirect("index.jsp");
                
                return;
            }
            String postedstr = request.getParameter("nonce");

            //check session against existing nonce, if match
            //generate new one, add to page and session
            //else redirect to index page
            if (noncestr.equals(postedstr)) {
                currentNonce = noncestr;
                //OK
                // current = UUID.randomUUID();
                //session.removeAttribute("nonce");
                // session.setAttribute("nonce", current.toString());
                UddiAdminHub.log.info( "CSRF Test passed.");
            } else {
                //mismatch, reject it
                UddiAdminHub.log.warn( "CSRF Test failed, session did not match nonce guid." + request.getRemoteAddr() + request.getRemoteUser());
                session.removeAttribute("nonce");
                //throw new CrossSiteRequestForgeryException("Cross Site Request Forgery");
                response.sendRedirect("index.jsp");
                
                return;
            }
        }
    } else {
        //HTTP GET or otherwise message
        if ((currentNonce == null) || currentNonce.isEmpty()) {
            currentNonce = (String)session.getAttribute("nonce");
            if (currentNonce == null) {
                currentNonce = java.util.UUID.randomUUID().toString();
            }
            session.setAttribute("nonce", currentNonce);
        }

    }

%>
