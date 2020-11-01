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

var loggedin=false;

var tagsToReplace = {
    '&': '&amp;',
    '<': '&lt;',
    '>': '&gt;'
};

function replaceTag(tag) {
    return tagsToReplace[tag] || tag;
}

function safe_tags_replace(str) {
    return str.replace(/[&<>]/g, replaceTag);
}

function escapeJquerySelector(str)
{
    if (str)
        return str.replace(/([ #;?&,.+*~\':"!^$[\]()=<>|\/@])/g,'\\$1');
    return str;
}

  
function Reedit()
{
    window.console && console.log('Reedit');                
    $('.edit').editable(function(value, settings) { 
                
        window.console && console.log(this);
        window.console && console.log(value);
        window.console && console.log(settings);
        //replace tags with escaped characters to prevent XSS
        return(safe_tags_replace(value));
    }, { 
        type    : 'text',
        submit  : 'OK'
    });
 
}

Reedit();


function Login()
{
    
    $("#loginbutton").addClass("disabled");
    $("#loginbutton").text(i18n_loading);
    
    var form = $("#uddiform");
    var d = form.serializeArray();
    var request=   $.ajax({
        url: 'ajax/loginpost.jsp',
        type:"POST",
        //  dataType: "html", 
        cache: false, 
        //  processData: false,f
        data: d
    });
                  
    request.done(function(msg) {
        window.console && console.log('postback done ');                
        $("#loginbutton").text(i18n_login);
        RefreshLoginPage();
    });

    request.fail(function(jqXHR, textStatus) {
        window.console && console.log('postback failed ');                                
        //TODO handle expired nonce values?
        RefreshLoginPage();
        $("#loginbutton").text(i18n_login);
        $("#loginfailuredetails").text("Login failed: " + textStatus + " " + jqXHR.responseText);
        $("#loginfailure").modal();
    });
}

function logout()
{
    
    $.get('logout.jsp', function(data) {
        window.location = "index.jsp";
    });
}

function RefreshLoginPage()
{
    $.get('login.jsp', function(data) {
        $('#loginfield').html(data);
    });
}

// Escapes special characters and returns a valid jQuery selector
//source http://totaldev.com/content/escaping-characters-get-valid-jquery-id
function jqSelector(str)
{
    return str.replace(/([;&,\.\+\*\~':"\!\^#$%@\[\]\(\)=>\|])/g, '\\$1');
}

function ShowServicesByBusinessKey(bizid)
{
    window.console && console.log('fetching service list for business ' + bizid);                
    var request=   $.ajax({
        url: 'ajax/servicelist.jsp?id=' + bizid,
        type:"GET",
        cache: false
    });
                  
    request.done(function(msg) {
        window.console && console.log(msg);                
        window.console && console.log('postback done to div ' + bizid);                
        $("#" + jqSelector(bizid)).html(msg);
    //refresh();
    });

    request.fail(function(jqXHR, textStatus) {
        window.console && console.log('postback failed ');                                
        $("#" + jqSelector(bizid)).html("An error occured! " + jqXHR.responseText + textStatus);
    //refresh();
    });

}

function ShowBusinssDetails(bizid)
{
    $.get('ajax/businessdetails.jsp?id=' + bizid, function(data) {
        $('#servicelist').html(data);
    });
}

function GetServiceDetails(svcid)
{
    $.get('ajax/servicedetails.jsp?id=' + svcid, function(data) {
        $('#servicelist').html(data);
        $('.editable').editable('ajax/saveservicedetails.jsp');
    });
}


function hideAlert()
{
    $("#resultBar").hide();
}