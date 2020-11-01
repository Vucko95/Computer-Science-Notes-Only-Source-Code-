<%-- 
    Document   : search
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

<%@page import="org.apache.juddi.v3.client.UDDIConstants"%>
<%@page import="org.apache.juddi.webconsole.hub.UddiHub"%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@include file="header-top.jsp" %>
<div class="container">

     <!-- Main hero unit for a primary marketing message or call to action -->
     <div class="well" >
          <h1><%= ResourceLoader.GetResource(session, "navbar.search")%> </h1>
     </div>

     <!-- Example row of columns -->
     <div class="row">
          <div class="span12" >


               <%
                    UddiHub x = UddiHub.getInstance(application, request.getSession());

               %>
               <div class="accordion" id="accordion2">
                    <div class="accordion-group">
                         <div class="accordion-heading">
                              <a class="accordion-toggle" data-toggle="collapse" data-parent="#accordion2" href="#collapseOne">
                                   <b><%= ResourceLoader.GetResource(session, "navbar.search")%> !</b>
                              </a>
                         </div>
                         <div id="collapseOne" class="accordion-body collapse in">
                              <div class="accordion-inner">
                                   <%= ResourceLoader.GetResource(session, "search.wrylf")%><Br>
                                   <div class="btn-group" id="searchfor" data-toggle="buttons-radio">
                                        <button type="button" class="btn active" value="business"><%= ResourceLoader.GetResource(session, "items.business")%></button>
                                        <!--<button type="button" class="btn " >Related Business</button>-->
                                        <button type="button" class="btn " value="service"><%= ResourceLoader.GetResource(session, "items.service")%></button>
                                        <button type="button" class="btn " value="bindingTemplate"><%= ResourceLoader.GetResource(session, "items.bindingtemplate")%></button>
                                        <button type="button" class="btn " value="tModel"><%= ResourceLoader.GetResource(session, "items.tmodel")%></button>
                                   </div><br><Br>
                                   <%= ResourceLoader.GetResource(session, "search.criteria")%><br>
                                   <div class="btn-group" id="searchcriteria" data-toggle="buttons-radio">
                                        <button type="button" class="btn active" value="name"><%= ResourceLoader.GetResource(session, "search.criteria.byname")%></button>
                                        <button type="button" class="btn " value="category"><%= ResourceLoader.GetResource(session, "search.criteria.bycategory")%></button>
                                        <button type="button" class="btn " value="key"><%= ResourceLoader.GetResource(session, "search.criteria.bykey")%></button>
                                        <button type="button" class="btn " value="tmodel"><%= ResourceLoader.GetResource(session, "search.criteria.bytmodel")%></button>
                                   </div><br>
                                   <%=ResourceLoader.GetResource(session, "items.findqualifiers")%><br>

                                   <div style=" float:left; padding: 2px">

                                        <div ><div  class="hide warning" id="<%=UDDIConstants.AND_ALL_KEYS%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" id="<%=UDDIConstants.AND_ALL_KEYS%>" name="<%=UDDIConstants.AND_ALL_KEYS%>" value="<%=UDDIConstants.AND_ALL_KEYS%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.AND_ALL_KEYS))%>" class="mytooltip" data-container="body"><%=UDDIConstants.AND_ALL_KEYS%></a></div>
                                        <div ><div  class="hide warning" id="<%=UDDIConstants.APPROXIMATE_MATCH%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" id="<%=UDDIConstants.APPROXIMATE_MATCH%>" name="<%=UDDIConstants.APPROXIMATE_MATCH%>" value="<%=UDDIConstants.APPROXIMATE_MATCH%>" checked="checked"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.APPROXIMATE_MATCH))%>" class="mytooltip" data-container="body"><%=UDDIConstants.APPROXIMATE_MATCH%></a></div>
                                        <div ><div  class="hide warning" id="<%=UDDIConstants.BINARY_SORT%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" id="<%=UDDIConstants.BINARY_SORT%>" name="<%=UDDIConstants.BINARY_SORT%>" value="<%=UDDIConstants.BINARY_SORT%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.BINARY_SORT))%>" class="mytooltip" data-container="body"><%=UDDIConstants.BINARY_SORT%></a></div>
                                        <div ><div  class="hide warning" id="<%=UDDIConstants.BINDING_SUBSET%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" id="<%=UDDIConstants.BINDING_SUBSET%>" name="<%=UDDIConstants.BINDING_SUBSET%>" value="<%=UDDIConstants.BINDING_SUBSET%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.BINDING_SUBSET))%>" class="mytooltip" data-container="body"><%=UDDIConstants.BINDING_SUBSET%></a></div>
                                        <div ><div  class="hide warning" id="<%=UDDIConstants.CASE_INSENSITIVE_MATCH%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" id="<%=UDDIConstants.CASE_INSENSITIVE_MATCH%>" name="<%=UDDIConstants.CASE_INSENSITIVE_MATCH%>" value="<%=UDDIConstants.CASE_INSENSITIVE_MATCH%>"  checked="checked"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.CASE_INSENSITIVE_MATCH))%>" class="mytooltip" data-container="body"><%=UDDIConstants.CASE_INSENSITIVE_MATCH%></a></div>
                                   </div>
                                   <div style=" float:left; padding: 2px">
                                        <div ><div class="hide warning" id="<%=UDDIConstants.CASE_INSENSITIVE_SORT%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.CASE_INSENSITIVE_SORT%>" value="<%=UDDIConstants.CASE_INSENSITIVE_SORT%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.CASE_INSENSITIVE_SORT))%>" class="mytooltip" data-container="body"><%=UDDIConstants.CASE_INSENSITIVE_SORT%></a></div>
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.CASE_SENSITIVE_MATCH%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.CASE_SENSITIVE_MATCH%>" value="<%=UDDIConstants.CASE_SENSITIVE_MATCH%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.CASE_SENSITIVE_MATCH))%>" class="mytooltip" data-container="body"><%=UDDIConstants.CASE_SENSITIVE_MATCH%></a></div>
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.CASE_SENSITIVE_SORT%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.CASE_SENSITIVE_SORT%>" value="<%=UDDIConstants.CASE_SENSITIVE_SORT%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.CASE_SENSITIVE_SORT))%>" class="mytooltip" data-container="body"><%=UDDIConstants.CASE_SENSITIVE_SORT%></a></div>
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.COMBINE_CATEGORY_BAGS%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.COMBINE_CATEGORY_BAGS%>" value="<%=UDDIConstants.COMBINE_CATEGORY_BAGS%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.COMBINE_CATEGORY_BAGS))%>" class="mytooltip" data-container="body"><%=UDDIConstants.COMBINE_CATEGORY_BAGS%></a></div>
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.DIACRITIC_INSENSITIVE_MATCH%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.DIACRITIC_INSENSITIVE_MATCH%>" value="<%=UDDIConstants.DIACRITIC_INSENSITIVE_MATCH%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.DIACRITIC_INSENSITIVE_MATCH))%>" class="mytooltip" data-container="body"><%=UDDIConstants.DIACRITIC_INSENSITIVE_MATCH%></a></div>
                                   </div>
                                   <div style=" float:left; padding: 2px">
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.DIACRITIC_SENSITIVE_MATCH%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.DIACRITIC_SENSITIVE_MATCH%>" value="<%=UDDIConstants.DIACRITIC_SENSITIVE_MATCH%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.DIACRITIC_SENSITIVE_MATCH))%>" class="mytooltip" data-container="body"><%=UDDIConstants.DIACRITIC_SENSITIVE_MATCH%></a></div>
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.EXACT_MATCH%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.EXACT_MATCH%>" value="<%=UDDIConstants.EXACT_MATCH%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.EXACT_MATCH))%>" class="mytooltip" data-container="body"><%=UDDIConstants.EXACT_MATCH%></a></div>
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.OR_ALL_KEYS%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.OR_ALL_KEYS%>" value="<%=UDDIConstants.OR_ALL_KEYS%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.OR_ALL_KEYS))%>" class="mytooltip" data-container="body"><%=UDDIConstants.OR_ALL_KEYS%></a></div>
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.OR_LIKE_KEYS%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.OR_LIKE_KEYS%>" value="<%=UDDIConstants.OR_LIKE_KEYS%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.OR_LIKE_KEYS))%>" class="mytooltip" data-container="body"><%=UDDIConstants.OR_LIKE_KEYS%></a></div>
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.SERVICE_SUBSET%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.SERVICE_SUBSET%>" value="<%=UDDIConstants.SERVICE_SUBSET%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.SERVICE_SUBSET))%>" class="mytooltip" data-container="body"><%=UDDIConstants.SERVICE_SUBSET%></a></div>
                                   </div>
                                   <div style=" float:left; padding: 2px">
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.SIGNATURE_PRESENT%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.SIGNATURE_PRESENT%>" value="<%=UDDIConstants.SIGNATURE_PRESENT%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.SIGNATURE_PRESENT))%>" class="mytooltip" data-container="body"><%=UDDIConstants.SIGNATURE_PRESENT%></a></div>
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.SORT_BY_DATE_ASC%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.SORT_BY_DATE_ASC%>" value="<%=UDDIConstants.SORT_BY_DATE_ASC%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.SORT_BY_DATE_ASC))%>" class="mytooltip" data-container="body"><%=UDDIConstants.SORT_BY_DATE_ASC%></a></div>
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.SORT_BY_DATE_DESC%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.SORT_BY_DATE_DESC%>" value="<%=UDDIConstants.SORT_BY_DATE_DESC%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.SORT_BY_DATE_DESC))%>" class="mytooltip" data-container="body"><%=UDDIConstants.SORT_BY_DATE_DESC%></a></div>
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.SORT_BY_NAME_ASC%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.SORT_BY_NAME_ASC%>" value="<%=UDDIConstants.SORT_BY_NAME_ASC%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.SORT_BY_NAME_ASC))%>" class="mytooltip" data-container="body"><%=UDDIConstants.SORT_BY_NAME_ASC%></a></div>
                                        <div ><div class="hide warning"  id="<%=UDDIConstants.SORT_BY_NAME_DESC%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.SORT_BY_NAME_DESC%>" value="<%=UDDIConstants.SORT_BY_NAME_DESC%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.SORT_BY_NAME_DESC))%>" class="mytooltip" data-container="body"><%=UDDIConstants.SORT_BY_NAME_DESC%></a></div>
                                   </div>
                                   <div style=" float:left; padding: 2px">
                                        <div ><div  class="hide warning" id="<%=UDDIConstants.SUPPRESS_PROJECTED_SERVICES%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.SUPPRESS_PROJECTED_SERVICES%>" value="<%=UDDIConstants.SUPPRESS_PROJECTED_SERVICES%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.SUPPRESS_PROJECTED_SERVICES))%>" class="mytooltip" data-container="body"><%=UDDIConstants.SUPPRESS_PROJECTED_SERVICES%></a></div>
                                        <div ><div  class="hide warning" id="<%=UDDIConstants.UTS_10%>w"><i class="icon-warning-sign"></i></div><input type="checkbox" name="<%=UDDIConstants.UTS_10%>" value="<%=UDDIConstants.UTS_10%>"> <a href="#" data-toggle="tooltip" title="" data-original-title="<%=StringEscapeUtils.escapeHtml(ResourceLoader.GetResource(session, UDDIConstants.UTS_10))%>" class="mytooltip" data-container="body"><%=UDDIConstants.UTS_10%></a></div>
                                   </div>
                                   <Br>
                                   <br><br><br>
                                   <div>
                                        <br><Br>
                                        <input type="text" placeholder="Type something…" id="searchcontent">
                                        <input type="text" placeholder="Language" id="lang"><br>
                                        <%= ResourceLoader.GetResource(session, "search.tip")%>
                                        <br>
                                        <a href="javascript:search();" class="btn btn-primary btn-large"><%= ResourceLoader.GetResource(session, "navbar.search")%> </a>
                                   </div>
                              </div>
                         </div>
                    </div>
                    <div class="accordion-group">
                         <div class="accordion-heading">
                              <a class="accordion-toggle" data-toggle="collapse" data-parent="#accordion2" href="#collapseTwo">
                                   <%= ResourceLoader.GetResource(session, "search.results")%>
                              </a>
                         </div>
                         <div id="collapseTwo" class="accordion-body collapse">
                              <div class="accordion-inner" id="resultdivs">
                                   <%= ResourceLoader.GetResource(session, "search.searchfirst")%>
                              </div>
                         </div>
                    </div>
               </div>

          </div>
     </div>
     <script type="text/javascript">

          $(document).ready(function() {
               $(':checkbox').click(function() {
                    checkForIllegalCombos();
                    return true;
               });
               $('.mytooltip').tooltip();
          });

          function checkForIllegalCombos() {
               var selected = new Array();
               $('.warning').hide();

               $(':checkbox').each(function(key, value) {
                    if (value.checked)
                    {
                         //alert(value.value);
                         selected.push(value.value);
                    }
               });

               var andAllKeys = indexOf.call(selected, "andAllKeys");
               var orAllKeys = indexOf.call(selected, "orAllKeys");
               var orLikeKeys = indexOf.call(selected, "orLikeKeys");

               var sortByNameAsc = indexOf.call(selected, "sortByNameAsc");
               var sortByNameDesc = indexOf.call(selected, "sortByNameDesc");

               var sortByDateAsc = indexOf.call(selected, "sortByDateAsc");
               var sortByDateDesc = indexOf.call(selected, "sortByDateDesc");

               var combineCategoryBags = indexOf.call(selected, "combineCategoryBags");
               var serviceSubset = indexOf.call(selected, "serviceSubset");
               var bindingSubset = indexOf.call(selected, "bindingSubset");

               var exactMatch = indexOf.call(selected, "exactMatch");
               var approximateMatch = indexOf.call(selected, "approximateMatch");

               //and exact
               var caseInsensitiveMatch = indexOf.call(selected, "caseInsensitiveMatch");

               var binarySort = indexOf.call(selected, "binarySort");
               var uts10 = indexOf.call(selected, "UTS-10");

               var diacriticSensitiveMatch = indexOf.call(selected, "diacriticSensitiveMatch");
               var diacriticInsensitiveMatch = indexOf.call(selected, "diacriticInsensitiveMatch");

               //exactMatch and diacriticInsensitiveMatch are mutually exclusive
               
               //  caseSensitiveSort and caseInsensitiveSort are mutually exclusive
               var caseSensitiveSort = indexOf.call(selected, "caseSensitiveSort");
               var caseInsensitiveSort = indexOf.call(selected, "caseInsensitiveSort");

               //caseSensitiveMatch and caseInsensitiveMatch are mutually exclusive
               var caseSensitiveMatch = indexOf.call(selected, "caseSensitiveMatch");
               
               if ((andAllKeys >= 0 && (orAllKeys >=0 || orLikeKeys  >=0)) ||
                       ((andAllKeys >= 0 || orAllKeys >=0) && orLikeKeys  >=0) || 
                       ((andAllKeys >= 0 ||  orLikeKeys >=0) && orAllKeys  >=0) )
               {
                    $("#andAllKeysw").show();
                    $("#orAllKeysw").show();
                    $("#orLikeKeysw").show();
               }
               if (sortByNameDesc >= 0 && sortByNameAsc >=0)
               {
                    $("#sortByNameAscw").show();
                    $("#sortByNameDescw").show();
               }
               if (sortByDateAsc >= 0 && sortByDateDesc >=0)
               {
                    $("#sortByDateAscw").show();
                    $("#sortByDateDescw").show();
               }
               if (exactMatch >= 0 && approximateMatch >=0)
               {
                    $("#exactMatchw").show();
                    $("#approximateMatchw").show();
               }
               if (exactMatch >= 0 && caseInsensitiveMatch >=0)
               {
                    $("#exactMatchw").show();
                    $("#caseInsensitiveMatchw").show();
               }
               
               if (binarySort >= 0 && uts10 >=0)
               {
                    $("#binarySortw").show();
                    $("#UTS-10w").show();
               }
               if (diacriticSensitiveMatch >= 0 && diacriticInsensitiveMatch >=0)
               {
                    $("#diacriticSensitiveMatchw").show();
                    $("#diacriticInsensitiveMatchw").show();
               }
               if (exactMatch >= 0 && diacriticInsensitiveMatch >=0)
               {
                    $("#exactMatchw").show();
                    $("#diacriticInsensitiveMatchw").show();
               }
               if (caseSensitiveMatch >= 0 && caseInsensitiveMatch >=0)
               {
                    $("#caseSensitiveMatchw").show();
                    $("#caseInsensitiveMatchw").show();
               }
               if (caseSensitiveSort >= 0 && caseInsensitiveSort >=0)
               {
                    $("#caseSensitiveSortw").show();
                    $("#caseInsensitiveSortw").show();
               }
               
               if ((combineCategoryBags >= 0 && (serviceSubset >=0 || bindingSubset  >=0)) ||
                       ((combineCategoryBags >= 0 || serviceSubset >=0) && bindingSubset  >=0) || 
                       ((combineCategoryBags >= 0 ||  serviceSubset >=0) && bindingSubset  >=0) )
               {
                    $("#combineCategoryBagsw").show();
                    $("#serviceSubsetw").show();
                    $("#bindingSubsetw").show();
               }
               
               return false;
          }

          //src = http://stackoverflow.com/questions/1181575/javascript-determine-whether-an-array-contains-a-value
          var indexOf = function(needle) {
               if (typeof Array.prototype.indexOf === 'function') {
                    indexOf = Array.prototype.indexOf;
               } else {
                    indexOf = function(needle) {
                         var i = -1, index = -1;

                         for (i = 0; i < this.length; i++) {
                              if (this[i] === needle) {
                                   index = i;
                                   break;
                              }
                         }

                         return index;
                    };
               }

               return indexOf.call(this, needle);
          };

          var offset = 0;
          var maxrecords = 20;
          function search()
          {
               /*   
                $.each($('input:checkbox'), function(index,item){
                var itemname = item.name;
                if (item.checked)
                {
                fqs+=itemname+",";
                }
                });
                */
               //var fqs = $('input:checkbox').length ? $('input:checked').val() : '';
               //alert (fqs);
               var selection = $("#searchcriteria > button.btn.active").val();
               //alert(selection);

               //var findqualifier = $("#findqualifier").val();
               //alert(findqualifier);
               var searchfor = $("#searchfor  > button.btn.active").val();
               //alert(searchfor);
               var searchcontent = $("#searchcontent").val();
               //alert(searchcontent );
               var url = 'ajax/search.jsp';

               $("#collapseTwo").collapse("show");
               $("#collapseOne").collapse("hide");

               var postbackdata = new Array();

               postbackdata.push({
                    name: "selection",
                    value: selection
               });

               postbackdata.push({
                    name: "searchcontent",
                    value: searchcontent
               });

               postbackdata.push({
                    name: "lang",
                    value: $("#lang").val()
               });


               $.each($('input:checkbox'), function(index, item) {
                    var itemname = item.name;
                    if (item.checked)
                    {
                         postbackdata.push({
                              name: "findqualifier",
                              value: itemname
                         });
                    }
               });


               postbackdata.push({
                    name: "searchfor",
                    value: searchfor
               });

               postbackdata.push({
                    name: "nonce",
                    value: $("#nonce").val()
               });

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

                    $("#resultdivs").html(msg);


               });

               request.fail(function(jqXHR, textStatus) {
                    window.console && console.log('postback failed ' + url);
                    $("#resultdivs").html(jqXHR.responseText + textStatus);
                    //$(".alert").alert();


               });

          }

     </script>

     <%@include file="tmodelChooser.jsp" %>

     <%@include file="header-bottom.jsp" %>