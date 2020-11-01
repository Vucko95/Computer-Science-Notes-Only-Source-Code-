<%-- 
    Document   : tmodel browser
    Created on : Feb 24, 2013, 9:14:01 AM
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

<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include file="header-top.jsp" %>
<div class="container">

   <!-- Main hero unit for a primary marketing message or call to action -->
   <div class="well" >
      <h2><%=ResourceLoader.GetResource(session, "items.tmodel.browser")%></h2>
   </div>

   <!-- Example row of columns -->
   <div class="row">
      <div class="span12" >
         <table class="table-striped table-bordered">
            <tr>
               <td>
                  <table>
                     <tr><td><%=ResourceLoader.GetResource(session, "totals.records")%></td><td><span id="totalrecords"></span></td></tr>
                     <tr><td><%=ResourceLoader.GetResource(session, "totals.recordsreturned")%></td><td><span id="displayrecords"></span></td></tr>
                     <tr><td><%=ResourceLoader.GetResource(session, "totals.offset")%></td><td><span id="offset">0</span></td></tr>
                  </table>
               </td>
               <td>
                  <table>
                     <tr><td><%=ResourceLoader.GetResource(session, "items.name")%></td><td><input type="text" id="name_tmodel" value="%"></td></tr>
                     <tr><td><%=ResourceLoader.GetResource(session, "items.lang")%></td><td><input type="text" id="lang_tmodel" value=""></td></tr>
                  </table>
               </td>
            </tr>

         </table>
         <a href="javascript:pagedown();"><i class="icon-circle-arrow-left icon-2x" id="pageup"></i></a>
         <a href="javascript:reload();"><i class="icon-refresh icon-2x"></i></a>
         <a href="javascript:pageup();"><i class="icon-circle-arrow-right icon-2x" id="pagedown"></i></a>

         <div id="tmodellist">
            <img src="img/bigrollergreen.gif" title="Loading"/>
         </div>
         <script src="js/tmodelsearch.js"></script>
         <script type="text/javascript">

            function reload()
            {
               RenderTmodelListBySearch('%', offset, maxrecords, false);
            }
            $('.edit').editable(function(value, settings) {
              window.console && console.log(value + this + settings);
               reload();
               //  RenderTmodelListBySearch('%', offset, maxrecords);
               return(value);
            }, {
               type: 'text',
               submit: i18n_ok
            });
            reload();
         </script>
      </div>
   </div>
   <%@include file="header-bottom.jsp" %>