<%-- 
/*
 * Copyright 2001-2013 The Apache Software Foundation.
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
    Document   : index
    Created on : Mar 30, 2013, 10:05:37 PM
    Author     : Alex O'Ree

--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%
    Cookie[] cookies = request.getCookies();
    if (cookies != null && cookies.length > 0) {
        for (int i = 0; i < cookies.length; i++) {
            if (cookies[i] != null && cookies[i].getName() != null && cookies[i].getName().equalsIgnoreCase("locale")) {
                if (cookies[i].getValue() != null) {
                    session.setAttribute("locale", cookies[i].getValue());
                    response.sendRedirect("home.jsp");
                }
            }
        }
    }
    if (request.getMethod().equalsIgnoreCase("post")) {
        String lang = request.getParameter("language");
        String checked=request.getParameter("setcookie");
        if (lang != null) {
            session.setAttribute("locale", lang);
            if (checked != null && checked.equalsIgnoreCase("on")) {
                Cookie cookie = new Cookie("locale", lang);
                cookie.setMaxAge(Integer.MAX_VALUE);
                cookie.setPath("/");
                response.addCookie(cookie);
            }
            response.sendRedirect("home.jsp");
        }
    }
%>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Welcome to Apache jUDDI</title>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta name="description" content="Apache jUDDI">
        <meta name="author" content="Apache Software Foundation">

        <!-- Le styles -->
        <link href="css/bootstrap.css" rel="stylesheet">
        <link rel="shortcut icon" href="favicon.ico" />
        <link href="css/bootstrap-responsive.css" rel="stylesheet">

        <!-- HTML5 shim, for IE6-8 support of HTML5 elements -->
        <!--[if lt IE 9]>
          <script src="js/html5shiv.js"></script>
        <![endif]-->

        <!-- Fav and touch icons -->

        <link rel="shortcut icon" href="ico/favicon.png">
        <style type="text/css">
            body {
                padding: 0px 0px 0px 0px;
                margin: 0px 0px 0px 0px;
            }
        </style>

    </head>
    <body>
        <div style="width:100%; height: 100%; position:absolute; text-align: center; vertical-align: middle; padding: 0px; margin: 0px; 
             background-image: url('img/bluemarble2.jpg'); background-repeat: no-repeat; background-position-x: center;
             background-position-y: center; background-size: cover">
            <div style="color: black; background-color: whitesmoke; 
                 background: rgb(235, 235, 235); /* Fall-back for browsers that don't
                                    support rgba */
                 background: rgba(235, 235, 235, .7);width:60%; position: relative; left:20%; top:25%; height:50%; vertical-align: middle">
                <br><br>
                <h1>Welcome to jUDDI</h1>
                <form method="POST">

                    <select id="language" name="language" >
                        <option value="en" selected>English</option>
                        <option value="es" >Español</option>
                    </select>
                    <br>
                    <input type="checkbox" name="setcookie" checked> Remember my decision<br>
                    <button type="submit" value="Go" class="btn btn-primary">Go</button>

                </form><br>
                <b>We welcome help internationalizing jUDDI!</b><br>
                <script type="text/javascript">
                
                </script>
                <noscript>Your browser does not support JavaScript! Functionality will be so severely reduced, that you might as well give up, sorry!</noscript>
            </div>
        </div>
    </body>
</html>
