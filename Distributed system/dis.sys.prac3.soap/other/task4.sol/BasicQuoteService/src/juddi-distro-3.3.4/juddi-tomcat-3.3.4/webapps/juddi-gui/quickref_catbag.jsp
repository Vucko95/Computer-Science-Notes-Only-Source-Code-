<%-- 
    Document   : quickref_catbag
    Created on : Feb 9, 2014, 3:17:25 PM
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
<div class="btn-group">
        <a class="btn dropdown-toggle btn-info" data-toggle="dropdown"  href="#">WSDL/WADL/XML<span class="caret"></span></a>
        <ul class="dropdown-menu">
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:wadl:types','uddi-org:types:wadl','wadlDeployment');">WADL</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:wsdl:types','uddi-org:types:wsdl','wsdlDeployment');">WSDL Types</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:wsdl:address','uddi-org:types:wsdl','wsdlDeployment');">WSDL Address</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:wsdl:categorization:protocol','uddi-org:types:wsdl','wsdlDeployment');">WSDL Protocol</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:wsdl:categorization:transport','uddi-org:types:wsdl','wsdlDeployment');">WSDL Transport</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:wsdl:porttypereference','uddi-org:types:wsdl','wsdlDeployment');">WSDL Port Type</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:xml:localname','uddi.org:xml:localname','localName');">XML Local Name</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:xml:namespace','uddi.org:xml:namespace','urn:mynamespace');">XML Namespace</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:bpel:types','uddi.org:bpel:types','bpel');">BPEL Type</a></li>
        </ul>
</div>

<div class="btn-group">
        <a class="btn dropdown-toggle btn-info" data-toggle="dropdown"  href="#"><%=ResourceLoader.GetResource(session, "items.categorizations.uddi")%><span class="caret"></span></a>
        <ul class="dropdown-menu">
             <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:categorization:general_keywords','uddi-org:general_keywords','keyword');">Keywords</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:ubr:taxonomy:naics','uddi.org:version','1.0');">Version</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:categorization:entitykeyvalues','entityKeyValues','');">Entity Key Values</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:categorization:nodes','uddi.org:categorization:nodes','node');">UDDI Node</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:ubr:identifier:owningbusiness','uddi.org:owningbusiness','businessKey');">Owning Business</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:categorization:validatedby','uddi.org:validatedBy','');">Validated By</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:categorization:derivedfrom','uddi-org:derivedFrom','');">Derived From</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:identifier:isreplacedby','uddi-org:isReplacedBy','');">Is Replaced By</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:categorization:types','uddi-org:types:uncacheable','uncacheable');">Uncacheable</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:categorization:types','uddi-org:types:cacheable','cacheable');">Cacheable</a></li>
                
       </ul>
</div>


<div class="btn-group">
     <a class="btn dropdown-toggle btn-info" data-toggle="dropdown"  href="#"><%=ResourceLoader.GetResource(session, "items.categorizations")%><span class="caret"></span></a>
        <ul class="dropdown-menu">
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:ubr:categorization:iso3166','geoLocation:Baltimore,MD','US-MD');">ISO 3166 Location</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:ubr:categorization:naics:1997','','123456789');">NAICS 1997</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:ubr:categorization:naics:2002','','123456789');">NAICS 2002</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:ubr:categorization:naics:2007','','123456789');">NAICS 2007</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:ubr:categorization:naics:2012','','123456789');">NAICS 2012</a></li>
                <li><a href="javascript:AddCategoryKeyReferenceParam('uddi:uddi.org:ubr:categorizationgroup:wgs84','wgs84','');">World Geodetic System 1984</a></li>
       </ul>
</div>
<br><br>