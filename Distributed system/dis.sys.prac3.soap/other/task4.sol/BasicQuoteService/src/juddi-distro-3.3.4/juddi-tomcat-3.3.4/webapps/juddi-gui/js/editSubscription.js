/* 
 * Copyright 2013 The Apache Software Foundation.
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

$(document).ready(function() {
    toggleType1(true);
    toggleTransport1();

    Reedit();
    $("#pubassertcontainer").hide();
    $("#keylist").resizable();
    $("#bindingKey").resizable();

});

function selectPublisherAssertionStatus()
{
    $("#assertionStatusChooser").modal('show');
}

function toggleTransport1()
{
    //window.console && console.log('hi  ' + $("#btn-specificitem").hasClass("active"));   
    setTimeout(function() {
        if ($("#btn-manual").hasClass("active"))
        {
            $("#bindingKeyDiv").hide();
            //$("#specific").show();
        }
        else
        {
            $("#bindingKeyDiv").show();
            // $("#specific").hide();
        }

    }, 100);


    // $("#bindingKeyDiv").show();
    return false;
}


function publisherAssertionPicker()
{
    $("#keylistcontainer").hide();
    $("#pubassertcontainer").show();
    selectPublisherAssertionStatus();
}
function clearbox()
{
    $("#keylist option").remove();
    $("#keylistcontainer").show();
    $("#pubassertcontainer").hide();
    return false;
}
function additem()
{
    var alertCriteraSingleItem = $("#alertCriteraSingleItem > button.btn.active").val();
    if (alertCriteraSingleItem === "binding")
    {
        reloadBindingModal();
        $.dialogBinding.confirm({
            callback: function(success, result) {
                if (success)
                {
                    for (var i = 0; i < result.length; i++)
                        if ($("#keylist option[value='" + result[i] + "']").length == 0)
                            $("#keylist").append("<option value=\"" + result[i] + "\">" + result[i] + "</option>");
                }
            }
        });
    }
    if (alertCriteraSingleItem === "business") {
        reloadBusinessModal();
        $.dialogBusiness.confirm({
            callback: function(success, result) {
                if (success)
                {
                    for (var i = 0; i < result.length; i++)
                        if ($("#keylist option[value='" + result[i] + "']").length == 0)
                            $("#keylist").append("<option value=\"" + result[i] + "\">" + result[i] + "</option>");
                }
            }
        });
    }
    if (alertCriteraSingleItem === "service") {
        reloadServiceModal();

        $.dialogService.confirm({
            callback: function(success, result) {
                if (success)
                {
                    for (var i = 0; i < result.length; i++)
                        if ($("#keylist option[value='" + result[i] + "']").length == 0)
                            $("#keylist").append("<option value=\"" + result[i] + "\">" + result[i] + "</option>");
                }
            }
        });

    }
    if (alertCriteraSingleItem === "tmodel") {
        reloadTmodelModal();
        $.dialogTmodel.confirm({
            callback: function(success, result) {
                if (success)
                {
                    for (var i = 0; i < result.length; i++)
                        if ($("#keylist option[value='" + result[i] + "']").length === 0)
                            $("#keylist").append("<option value=\"" + result[i] + "\">" + result[i] + "</option>");
                }
            }
        });
    }
}
function removeitem()
{
    $("#keylist option:selected").remove();
}


function toggleType1(firstLoad)
{
    //window.console && console.log('hi  ' + $("#btn-specificitem").hasClass("active"));   
    setTimeout(function() {
        if ($("#btn-specificitem").hasClass("active"))
        {
            $("#basedonresults").hide();
            $("#specific").show();
        }
        else
        {
            $("#basedonresults").show();
            $("#specific").hide();
        }
        if (firstLoad != true) {
            $('#collapseOne').collapse('hide');
            $('#collapseTwo').collapse('show');
        }
    }, 100);

    return false;
}




function selectPublisherAssertionStatus()
{
    $("#assertionStatusChooser").modal('show');
}

function toggleTransport1()
{
    //window.console && console.log('hi  ' + $("#btn-specificitem").hasClass("active"));   
    setTimeout(function() {
        if ($("#btn-manual").hasClass("active"))
        {
            $("#bindingKeyDiv").hide();
            //$("#specific").show();
        }
        else
        {
            $("#bindingKeyDiv").show();
            // $("#specific").hide();
        }

    }, 100);


    // $("#bindingKeyDiv").show();
    return false;
}


function saveSubscription()
{

    var interval = $("#timepicker2").val();
    var maxRecords = $("#maxRecords").val();
    var brief = $("#brief").val();
    var expires = $("#datetimepicker2").val();

   // alert(interval + expires);
    var subkey = $("#subkey").html();

    var alertCriteraSingleItem = $("#alertCriteraSingleItem > button.btn.active").val();
    var alertTransport = $("#alertTransport > button.btn.active").val();
    var itemKey = $("#keylist option");
    var keys = "";
    var first = true;
    $.each(itemKey, function(idx, value) {
        if (first)
            keys = value.value;
        else
            keys = keys + "," + value.value;
        first = false;
    });
    var bindingKey = $("#bindingKey").val();
    var alertType = $("#alertType > button.btn.active").val();

    var alertCriteraMultipleItem = $("#alertCriteraMultipleItem > button.btn.active").val();
    var searchcontent = $("#searchcontent").val();
    var searchlang = $("#searchlang").val();

    var postbackdata = new Array();
    var url = 'ajax/subscription.jsp';
    itemKey = $("#itemKey").html();

    //  var tqs = new Array();
    //$("div.edit").each(function()
    $('.fq').each(function(index, item) {
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
        name: "alertCriteraMultipleItem",
        value: alertCriteraMultipleItem
    });
    postbackdata.push({
        name: "searchcontent",
        value: searchcontent
    });

    postbackdata.push({
        name: "searchlang",
        value: searchlang
    });


    postbackdata.push({
        name: "subkey",
        value: subkey
    });

    postbackdata.push({
        name: "expires",
        value: expires
    });

    postbackdata.push({
        name: "interval",
        value: interval
    });

    postbackdata.push({
        name: "brief",
        value: brief
    });

    postbackdata.push({
        name: "maxRecords",
        value: maxRecords
    });


    postbackdata.push({
        name: "alertType",
        value: alertType
    });
    postbackdata.push({
        name: "itemKey",
        value: keys
    });

    postbackdata.push({
        name: "assertionStatus",
        value: itemKey
    });
    postbackdata.push({
        name: "alertCriteraSingleItem",
        value: alertCriteraSingleItem
    });
    postbackdata.push({
        name: "bindingKey",
        value: bindingKey
    });
    postbackdata.push({
        name: "alertTransport",
        value: alertTransport
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
        window.console && console.log('postback done '  + url);                
        
        $("#alert_results").html('<i class="icon-2x icon-thumbs-up"></i><br>'  + msg);
        $("#alert").modal();
        
    });

    request.fail(function(jqXHR, textStatus) {
        window.console && console.log('postback failed ' + url);                                
        $("#alert_results").html('<i class="icon-2x icon-thumbs-down"></i><br>'  + jqXHR.responseText + textStatus);
        $("#alert").modal();
    });
}
