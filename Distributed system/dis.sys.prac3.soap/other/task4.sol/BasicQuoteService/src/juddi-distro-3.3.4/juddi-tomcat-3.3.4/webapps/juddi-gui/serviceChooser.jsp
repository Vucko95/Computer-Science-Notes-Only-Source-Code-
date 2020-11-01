<%-- 
    Document   : serviceChooser
    Created on : Apr 28, 2013, 7:11:19 PM
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


<%@page import="org.apache.juddi.webconsole.resources.ResourceLoader"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<div class="modal hide fade container " id="serviceChooser" tabindex="102">
   <div class="modal-header">
      <a href="javascript:$('#serviceChooser').modal('hide');" class="close" data-dismiss="modal" aria-hidden="true">&times;</a>
      <h3><%=ResourceLoader.GetResource(session, "items.service.chooser")%> </h3>
   </div>
   <div class="modal-body">
      <table class="table-bordered table-condensed">
         <tr>
            <td>
               <table>
                  <tr><td><%=ResourceLoader.GetResource(session, "totals.records")%></td><td><span id="totalrecordsService"></span></td></tr>
                  <tr><td><%=ResourceLoader.GetResource(session, "totals.recordsreturned")%></td><td><span id="displayrecordsService"></span></td></tr>
                  <tr><td><%=ResourceLoader.GetResource(session, "totals.offset")%></td><td><span id="offsetService">0</span></td></tr>
               </table>
            </td>
            <td>
               <table>
                  <tr><td><%=ResourceLoader.GetResource(session, "items.name")%></td><td><input type="text" id="name_Service" value="%"></td></tr>
                  <tr><td><%=ResourceLoader.GetResource(session, "items.lang")%></td><td><input type="text" id="lang_Service" ></td></tr>
               </table>
            </td>
         </tr>
      </table>

      <a href="javascript:pagedownChooserService();"><i class="icon-circle-arrow-left disabled icon-2x" id="pageupService"></i></a>
      <a href="javascript:reloadServiceModal();"><i class="icon-refresh icon-2x"></i></a>
      <a href="javascript:pageupChooserService();"><i class="icon-circle-arrow-right disabled icon-2x" id="pagedownService"></i></a>

      <div id="servicelist">
         <img src="img/bigrollergreen.gif" title="Loading"/>
      </div>
      <script src="js/serviceChooser.js"></script>
      <script type="text/javascript">
         $("#serviceChooser").keydown(function(e) {
            if (e.which == 37) { // left
               pagedownChooserService();
            }
            else if (e.which == 39) { // right
               pageupChooserService();
            }
         });
         $('.edit').editable(function(value, settings) {
            window.console && console.log(value + this + settings);
            reloadServiceModal();
            //  RenderTmodelListBySearch('%', offset, maxrecords);
            return(value);
         }, {
            type: 'text',
            submit: i18n_ok
         });
         //only init the data when required reloadTmodelModal();
      </script>

   </div>
   <div class="modal-footer">
      <a href="#" class="btn" data-dismiss="modal"><%=ResourceLoader.GetResource(session, "actions.cancel")%></a>
      <a href="javascript:$('#serviceChooser').modal('hide');" class="btn btn-primary" data-dismiss="modal"><%=ResourceLoader.GetResource(session, "actions.select")%></a>
   </div>
</div>
<%
//<a href="javascript:tModelCancel();" class="close" class="btn btn-danger">Cancel</a>
//<a href="javascript:tModelModal();" class="btn" >Pick a tModel</a>

//<a href="javascript:$('#bindingChooser').modal();" class="btn btn-primary" data-dismiss="modal">< %=ResourceLoader.GetResource(session, "actions.select")% ></a>
%>

