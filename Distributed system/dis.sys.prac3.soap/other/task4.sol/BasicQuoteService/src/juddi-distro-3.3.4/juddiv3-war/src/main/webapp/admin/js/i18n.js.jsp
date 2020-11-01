
<%@page import="org.apache.juddi.adminconsole.resources.ResourceLoader"%>
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
    Document   : i18n.js
    Created on : Apr 6, 2013, 11:42:48 AM
    Author     : Alex O'Ree
--%>

<%@page contentType="application/javascript" pageEncoding="UTF-8"%>
//<script type="text/javascript">
    var i18n_clicktoedit="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.clicktoedit"))%>";
    var i18n_loading="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.loading"))%>";
    var i18n_login="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "navbar.login.button"))%>";
    var il8n_picker="<%= org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.picker"))%>";
    var i18n_name="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.name"))%>";
    var i18n_value="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.value"))%>";
    var i18n_key="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.key"))%>";
    var i18n_lang="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.lang"))%>";
    var i18n_email="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.email"))%>";
    var i18n_type="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.type"))%>";
    
    var i18n_descriptionAdd="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.description.add"))%>";
    var i18n_description="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.description"))%>";
    var i18n_contactPrimary="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.contact.primary"))%>";
    var i18n_contactType="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.contact.type"))%>";
    var i18n_contactTypeDefault="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.contact.default"))%>";
    var i18n_address="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.address"))%>";
    var i18n_addressValue="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.addressvalue"))%>";
    var i18n_addressDefaultType="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.addresstype.default"))%>";
    var i18n_addressLineAdd="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.addressline.add"))%>";
    
    var i18n_keyname_optional="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.keyname.optional"))%>";
    var i18n_keyvalue_optional="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.keyvalue.optional"))%>";
    
    var i18n_addrefcat="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.keyrefcat.add"))%>"; 
    
    var i18n_addressSortCode="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.sortcode"))%>";
    var i18n_phone="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.phone"))%>";
    
    var i18n_phoneType="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.phone.types"))%>";
    
    
    var i18n_bindingTemplateKey="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.bindingtemplate.key"))%>";
    var i18n_bindingTemplateDescriptionAdd="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.bindingtemplate.description.add"))%>";
    var i18n_accesspoint="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.accesspoint"))%>";
    var i18n_accesspointType="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.accesspoint.type"))%>";
    var i18n_accesspointValue="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.accesspoint.value"))%>";
    
    var i18n_tmodelinstanceinfo="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.tmodelinstance.info"))%>";
    var i18n_tmodelinstanceinfoDescription="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.tmodelinstance.info.desc"))%>";
    var i18n_tmodelinstanceinfoAdd="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.tmodelinstance.add"))%>";
    var i18n_bindingTemplateKeyRefCat="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.bindingtemplate.keyrefcat"))%>";
    var i18n_bindingTemplateKeyRefCatGrp="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.bindingtemplate.keyrefgrp"))%>";
    
    var i18n_keyRefGrpAdd="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.keyrefgroup.add"))%>";
    var i18n_accesspointDescription="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.accesspoint.description"))%>";
    var i18n_tmodelkey="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.tmodel.key"))%>";
    var i18n_tmodelInstanceParams="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.tmodelinstance.parameters"))%>";
    var i18n_tmodelInstanceDescription="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.tmodelinstance.description"))%>"; 
    var i18n_tmodelInstanceDescription2="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.tmodelinstance.description2"))%>"; 
    var i18n_tmodelInstanceDescriptionAdd="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.tmodelinstance.description.add"))%>"; 
    
    var i18n_overviewdoc="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.overviewurl"))%>"; 
    var i18n_overviewdocDescription="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.overviewurl.description"))%>"; 
    var i18n_overviewdocadd="<%=org.apache.commons.lang.StringEscapeUtils.escapeJavaScript(ResourceLoader.GetResource(session, "items.overviewurl.add"))%>"; 
    //items.overviewurl.description.add
    //items.name.add
    //items.overviewurl.description.add
    //items.bindingtemplate.add
    //items.bindingtemplate.description.add
//</script>