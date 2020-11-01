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
 *
 */
/* 
 * source http://stackoverflow.com/questions/6049687/jquery-ui-dialog-box-need-to-return-value-when-user-presses-button-but-not-wor 
 * http://stackoverflow.com/questions/3560872/returning-value-from-confirmation-dialog-using-jquery-ui-dialog
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function reloadServiceModal()
{
    var name=$("#nameService").text();
    RenderServiceListBySearchModal(name, offsetService, maxrecordsService, true);
                      
}



var offsetService=0; //start at the begining
var maxrecordsService=10;  //record 20 at a time
var langService="en";  //langauge english
var totalrecordsService=0;

RenderServiceListBySearchModal('%', offsetService, maxrecordsService, true);

function pagedownChooserService()
{
    offsetService = $("#offsetService").text();
    //alert(offset);
    var newoffset = offsetService - maxrecordsService;
    if (newoffset < 0)
        return;
    //alert(newoffset);
    if (newoffset != offsetService)
        RenderServiceListBySearchModal($("#nameService").text(), newoffset, maxrecordsService, true);
}
function pageupChooserService()
{
    offsetService = $("#offsetService").text();
    //alert(offset);
    var fetch = maxrecordsService;
    if ((parseInt(offsetService) + parseInt(maxrecordsService))  > totalrecordsService)
        //fetch = maxrecords - offset;
        return;
    else 
        fetch = (parseInt(offsetService) + parseInt(maxrecordsService));    
    //alert(fetch);
    offsetService = fetch;
    RenderServiceListBySearchModal($("#nameService").text(), fetch, maxrecordsService, true);
}


var selectedItemService=null;

//offset, maxrecords, keyword
function RenderServiceListBySearchModal(keyword1, offset1, maxrecords1, isForChooser)
{
    var lang = $("#langService").text();
    $("#servicelist").html("<img src=\"img/bigrollergreen.gif\" title=\"Loading\"/>");
    var request=   $.ajax({
        url: 'ajax/servicesearch.jsp?keyword=' + keyword1 + "&offset=" + offset1 + "&maxrecords=" + maxrecords1 + "&lang=" + lang + "&chooser=" + isForChooser,
        type:"GET",
        cache: false
    });
                  
    request.done(function(msg) {
        window.console && console.log('postback done ');                
        $("#servicelist").html(msg);
        
    //refresh();
    });

    request.fail(function(jqXHR, textStatus) {
        window.console && console.log('postback failed ');                                
        $("#servicelist").html("An error occured! " + jqXHR.responseText + textStatus);
    //refresh();
    });
/*
    $.get('ajax/businesssearch.jsp?keyword=' + keyword1 + "&offset=" + offset1 + "&maxrecords=" + maxrecords1 + "&lang=" + lang, function(data) {
        $("#businesslist").html(data);
        refresh();
    });*/
}

function refreshService()
{
    var displayrecords = $("#displayrecords").text();
    if (displayrecords == totalrecordsService)
    {
        $("#pageupService").addClass("disabled");
        $("#pagedownService").addClass("disabled");
    }
    else if (offsetService + maxrecordsService > totalrecordsService)
    {
        $("#pageupService").addClass("disabled");    
    }
    else if (offsetService ==0)
    {
        $("#pagedownService").removeClass("disabled");        
    }
    else
    {
        $("#pagedownService").removeClass("disabled");        
        $("#pageupService").removeClass("disabled");        
    }
}

/**
 *This launches the tModel model div, upon return (and if not abprted), the contents of the div parameter will be replaced with the 
 *first selected tModel
 */
function serviceModal(div){
    //reset the form in case it was lanucheed more than once per page view
    reloadServiceModal();
    
    $.dialogService.confirm({
        callback: function(success, result) {
            if (!success)
            {
              //  alert("aborted!");    
            }
                
            else{
               // alert('Result: ' + result.join());
                $("#" + div).html(result[0]);
            }
       //     return false;
        }
    });
   // return false;
}
            
            
function serviceCancel()
{
    $(".modalableServiceChooser").each(function()
    {
        $(this).prop('checked', false);
    }); 
    $('#serviceChooser').modal('hide');
                
}
            
/**
 *returns an array of selected tmodel keys
 */            
$.dialogService = {
    confirm: function(options) {
        var $modal = $('#serviceChooser');
        //$modal.find('.modal-body').text(options.message);
        
        $modal.off('click.dialog', '.btn, .close')
        .off('hidden')
        .on('click.dialog', '.btn, .close', function() {
            $(this).addClass('modal-result');
        }).on('hidden', function() {
            var result = $(this).find('.modal-result').filter('.btn-primary').length > 0;
            $(this).find('.modal-result').removeClass('modal-result');
            /**
                         * find the result from the model (the selected key)
                         */
            var selectedtmodels =  new Array();
            $(".modalableServiceChooser").each(function()
            {
                var id=$(this).attr("id");
                if ($(this).is(':checked')) {
                    selectedtmodels.push(
                        id
                        );
                }
            }); 
            
            options.callback(result ,selectedtmodels);
        //  $modal.modal('hide');
        });
        //callback = options.callback;
        
        $modal.modal();
    }        
};

