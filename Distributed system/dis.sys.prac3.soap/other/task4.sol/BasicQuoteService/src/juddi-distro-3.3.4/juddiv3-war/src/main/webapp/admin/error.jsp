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


    Document   : error
    Created on : Apr 28, 2013, 4:01:43 PM
    Author     : Alex O'Ree
--%>

<%@page import="org.apache.juddi.adminconsole.resources.ResourceLoader"%>
<%@page import="javax.xml.datatype.DatatypeFactory"%>
<%@page import="java.util.GregorianCalendar"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Welcome to jUDDI</title>
        <meta charset="utf-8">
        <title>Welcome to Apache jUDDI</title>
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

        <link rel="stylesheet" href="css/font-awesome.min.css">
        <link rel="stylesheet" href="css/ui-lightness/jquery-ui-1.10.2.custom.min.css">
        <!--[if IE 7]>
        <link rel="stylesheet" href="css/font-awesome-ie7.min.css">
        <![endif]-->


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
                <h1><%=ResourceLoader.GetResource(session, "error.ohno")%> <i class="icon-warning-sign icon-large"></i></h1>
                <Br>
                <b><%=ResourceLoader.GetResource(session, "error.occurred")%> </b><br><br>
                <%=ResourceLoader.GetResource(session, "error.pleasereport")%> <Br>
                <%=ResourceLoader.GetResource(session, "error.timeofevent")%>: 
                <%
                    GregorianCalendar gcal = new GregorianCalendar();
                    gcal.setTimeInMillis(System.currentTimeMillis());
                    DatatypeFactory df = DatatypeFactory.newInstance();
                    out.write(df.newXMLGregorianCalendar(gcal).toString());
                %><Br><Br>
                <%=ResourceLoader.GetResource(session, "error.reportadmin")%> <Br>
                <a class="btn btn-primary" href="https://issues.apache.org/jira/browse/JUDDI"><%=ResourceLoader.GetResource(session, "error.filereport")%> </a>.</b><br>

            </div>
        </div>
    </body>
</html>
