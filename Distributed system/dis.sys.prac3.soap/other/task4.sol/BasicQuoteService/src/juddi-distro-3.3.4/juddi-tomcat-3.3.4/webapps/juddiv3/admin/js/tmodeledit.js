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


function AddOverviewDocument()
{
    currentOverviewDocs++;
    var i = currentOverviewDocs;
    $("<div id=\"overviewDoc" + i + "\" style=\"border-width:1px; border-style:solid\" >" 
        +"<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('overviewDoc" + i 
        +"');\"><i class=\"icon-trash\"></i></a></div>"
        +"<div style=\"float:left\">" + i18n_value + ": &nbsp;</div>"
        +"<div class=\"edit\" id=\"overviewDoc" + i + "Value\"></div>"
        +"<div style=\"float:left\">" + i18n_type + ": &nbsp;</div>"
        +"<div class=\"edit\" id=\"overviewDoc" + i + "Type\"></div>"
        //descriptions
        +"<a href=\"javascript:AddDescriptionSpecific('overviewDoc" + i + "Description');\">"
        +"<i class=\"icon-plus-sign\"></i></a> " + i18n_descriptionAdd
        + ("<div id=\"overviewDoc" + i + "Description\" style=\"border-width:1px; border-style:dotted\"></div>")
    
        +"</div>").prependTo("#overviewDoc");
    Reedit();
}


function AddDescriptionOverviewSpecific(div)
{
    //javascript:Remove('bindingTemplate0Description0'); 
    currentDescriptionSpecific++;
    var i = currentDescriptionSpecific;
    $("<div id=\""+ div + i + "\" style=\"border-width:1px; border-style:solid\" >" 
        +"<div style=\"float:left;height:100%\"><a href=\"javascript:Remove('" + div + i 
        +"');\"><i class=\"icon-trash\"></i></a></div>"
        +"<div style=\"float:left\">" + i18n_value + ": &nbsp;</div>"
        +"<div class=\"edit\" id=\"" + div + "Description" + i + "Value\"></div>"
        +"<div style=\"float:left\">" + i18n_lang + ": &nbsp;</div>"
        +"<div class=\"edit\" id=\"" + div + "Description" + i + "Lang\"></div>"
        +"</div>").appendTo("#" + div);
    Reedit();
}


function savetModel()
{
    var url='ajax/savetmodel.jsp';
    var postbackdata = new Array();
    $("div.edit").each(function()
    {
        //TODO filter out (click to edit) values
        var id=$(this).attr("id");
        var value=$(this).text();
        postbackdata.push({
            name: id, 
            value: value
        });
    }); 
    
    $("#isDeleted")
    if ($('#isDeleted').is(':checked')) {
         postbackdata.push({
            name: "isDeleted", 
            value: "checked"
        });
    } else {
       
    } 
    postbackdata.push({
        name:"nonce", 
        value: $("#nonce").val()
    });
    $("div.noedit").each(function()
    {
        var id=$(this).attr("id");
        var value=$(this).text();
        postbackdata.push({
            name: id, 
            value: value
        });
    }); 
    
    
    var request=   $.ajax({
        url: url,
        type:"POST",
        //  data" + i18n_type + ": "html", 
        cache: false, 
        //  processData: false,f
        data: postbackdata
    });
                
                
    request.done(function(msg) {
        window.console && console.log('postback done '  + url);                
        
        $("#resultBar").html('<a class="close" data-dismiss="alert" href="javascript:hideAlert();">&times;'  + '</a>' + msg);
        $("#resultBar").show();
        
    });

    request.fail(function(jqXHR, textStatus) {
        window.console && console.log('postback failed ' + url);                                
        $("#resultBar").html('<a class="close" data-dismiss="alert" href="javascript:hideAlert();">&times;' + '</a>' +jqXHR.responseText + textStatus );
        //$(".alert").alert();
        $("#resultBar").show();
        
    });
}

function deletetModel()
{
    //businessKey
    var bizid=$("#serviceKey").text();
    var url='ajax/deletetmodel.jsp?id=' + bizid;
    var postbackdata = new Array();
    postbackdata.push({
        name:"nonce", 
        value: $("#nonce").val()
    });
    var request=   $.ajax({
        url: url,
        type:"POST",
        //  data" + i18n_type + ": "html", 
        cache: false, 
        //  processData: false,f
        data: postbackdata
    });

    request.done(function(msg) {
        window.console && console.log('postback done '  + url);                
        
        $("#resultBar").html('<a class="close" data-dismiss="alert" href="javascript:hideAlert();">&times;'  + '</a>' + msg);
        $("#resultBar").show();
        
    });

    request.fail(function(jqXHR, textStatus) {
        window.console && console.log('postback failed ' + url);                                
        $("#resultBar").html('<a class="close" data-dismiss="alert" href="javascript:hideAlert();">&times;' + '</a>' + jqXHR.responseText + textStatus);
        //$(".alert").alert();
        $("#resultBar").show();
        
    });
}