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

function reloadBusinessModal()
{
    var name=$("#nameBusiness").text();
    RenderBusinessListBySearchModal(name, offsetBusiness, maxrecordsBusiness, true);
                      
}



var offsetBusiness=0; //start at the begining
var maxrecordsBusiness=10;  //record 20 at a time
var langBusiness="en";  //langauge english
var totalrecordsBusiness=0;

RenderBusinessListBySearchModal('%', offsetBusiness, maxrecordsBusiness, true);

function pagedownChooserBusiness()
{
    offsetBusiness = $("#offsetBusiness").text();
    //alert(offset);
    var newoffset = offsetBusiness - maxrecordsBusiness;
    if (newoffset < 0)
        return;
    //alert(newoffset);
    if (newoffset != offsetBusiness)
        RenderBusinessListBySearchModal($("#nameBusiness").text(), newoffset, maxrecordsBusiness, true);
}
function pageupChooserBusiness()
{
    offsetBusiness = $("#offsetBusiness").text();
    //alert(offset);
    var fetch = maxrecordsBusiness;
    if ((parseInt(offsetBusiness) + parseInt(maxrecordsBusiness))  > totalrecordsBusiness)
        //fetch = maxrecords - offset;
        return;
    else 
        fetch = (parseInt(offsetBusiness) + parseInt(maxrecordsBusiness));    
    //alert(fetch);
    offsetBusiness = fetch;
    RenderBusinessListBySearchModal($("#nameBusiness").text(), fetch, maxrecordsBusiness, true);
}


var selectedItemBusiness=null;

//offset, maxrecords, keyword
function RenderBusinessListBySearchModal(keyword1, offset1, maxrecords1, isForChooser)
{
    var lang = $("#langBusiness").text();
    $("#businesslist").html("<img src=\"img/bigrollergreen.gif\" title=\"Loading\"/>");
    var request=   $.ajax({
        url: 'ajax/businesssearch.jsp?keyword=' + keyword1 + "&offset=" + offset1 + "&maxrecords=" + maxrecords1 + "&lang=" + lang + "&chooser=" + isForChooser,
        type:"GET",
        cache: false
    });
                  
    request.done(function(msg) {
        window.console && console.log('postback done ');                
        $("#businesslist").html(msg);
        
    //refresh();
    });

    request.fail(function(jqXHR, textStatus) {
        window.console && console.log('postback failed ');                                
        $("#businesslist").html("An error occured! " + jqXHR.responseText + textStatus);
    //refresh();
    });
/*
    $.get('ajax/businesssearch.jsp?keyword=' + keyword1 + "&offset=" + offset1 + "&maxrecords=" + maxrecords1 + "&lang=" + lang, function(data) {
        $("#businesslist").html(data);
        refresh();
    });*/
}

function refreshBusiness()
{
    var displayrecords = $("#displayrecords").text();
    if (displayrecords == totalrecordsBusiness)
    {
        $("#pageupBusiness").addClass("disabled");
        $("#pagedownBusiness").addClass("disabled");
    }
    else if (offsetBusiness + maxrecordsBusiness > totalrecordsBusiness)
    {
        $("#pageupBusiness").addClass("disabled");    
    }
    else if (offsetBusiness ==0)
    {
        $("#pagedownBusiness").removeClass("disabled");        
    }
    else
    {
        $("#pagedownBusiness").removeClass("disabled");        
        $("#pageupBusiness").removeClass("disabled");        
    }
}

/**
 *This launches the tModel model div, upon return (and if not abprted), the contents of the div parameter will be replaced with the 
 *first selected tModel
 */
function businessModal(div){
    //reset the form in case it was lanucheed more than once per page view
    reloadBusinessModal();
    
    $.dialogBusiness.confirm({
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
            
            
function businessCancel()
{
    $(".modalableBusinessChooser").each(function()
    {
        $(this).prop('checked', false);
    }); 
    $('#businessChooser').modal('hide');
                
}
            
/**
 *returns an array of selected tmodel keys
 */            
$.dialogBusiness = {
    confirm: function(options) {
        var $modal = $('#businessChooser');
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
            $(".modalableBusinessChooser").each(function()
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

