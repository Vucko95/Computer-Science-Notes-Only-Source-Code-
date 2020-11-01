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
/* 
 * Copyright 2014 The Apache Software Foundation.
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


function addTransportTModelInstanceInfo()
{
      //uddi:uddi.org:wadl:types
        //uddi:uddi.org:wsdl:address
        //uddi:uddi.org:wsdl:categorization:protocol
        //uddi:uddi.org:wsdl:categorization:transport
        //uddi:uddi.org:categorization:general_keywords
        //urn:uddi:uddi.org:version
}


function AddTmodelInstanceParam(key)
{
        var div='tmodelInstance';
    currentbindingtemplatesInstance++;
    var i =  currentbindingtemplatesInstance;         
    currentOverviewDocs++;
    var k = currentOverviewDocs;
    $("<div id=\"" + div + i + "\" style=\"border-width: 2px; border-style: dashed; border-color: red\">"        
        +"<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('" + div + i + "');\"><i class=\"icon-trash icon-large\"></i></a></div><div style=\"float:left\">"
        +"<b>" + i18n_tmodelkey + "</b> (<a href=\"javascript:tModelModal('"+div + i + "KeyName\')\" ><i class=\"icon-list-alt icon-large\"></i>" + il8n_picker + "</a>): &nbsp;</div><div class=\"edit\" id=\"" + div + i + "KeyName\">" + key + "</div>"
        +"<br><div style=\"float:left\"><b>" + i18n_tmodelInstanceParams + ":</b> &nbsp;</div><div class=\"edit\" id=\"" + div + i + "instanceValue\"></div>"
        +"<br><b>" + i18n_tmodelInstanceDescription + "</b> - " + i18n_tmodelInstanceDescription2 + "<br>"
        +"<a href=\"javascript:AddDescriptionSpecific('" + div + i + "instanceDescription');\"><i class=\"icon-plus-sign icon-large\"></i></a> "
        +i18n_tmodelInstanceDescriptionAdd+"<br>"
        +"<div id=\"" + div + i + "instanceDescription\" style=\"border-width: 1px; border-style: groove;\">"
        //issue

        +"<div><br><b>" + i18n_overviewdoc + "</b> - " + i18n_overviewdocDescription + "<br>"
        +"<a href=\"javascript:AddOverviewDocumentSpecific('" + div + i + 
        "instanceoverviewDoc" + k + "Description');\"><i class=\"icon-plus-sign icon-large\"></i></a> "+ i18n_overviewdocadd + "<br>"
        +"<div id=\"" + div + i + "overviewDoc\" style=\"border-width: 1px; border-style: groove;\"></div></div></div></div></div>").appendTo("#"+div);
    Reedit();
}
