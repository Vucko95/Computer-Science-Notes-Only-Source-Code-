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

function reloadBindingModal()
{
    RenderBindingListBySearch('%', offsetBinding, maxrecordsBinding, true);
                      
}



var offsetBinding=0; //start at the begining
var maxrecordsBinding=10;  //record 20 at a time
var langBinding="en";  //langauge english
var totalrecordsBinding=0;

RenderBindingListBySearch('%', offsetBinding, maxrecordsBinding, true);

function pagedownChooserBinding()
{
    offsetBinding = $("#offsetBinding").text();
    //alert(offset);
    var newoffset = offsetBinding - maxrecordsBinding;
    if (newoffset < 0)
        return;
    //alert(newoffset);
    if (newoffset != offsetBinding)
        RenderBindingListBySearch('%', newoffset, maxrecordsBinding, true);
}
function pageupChooserBinding()
{
    offsetBinding = $("#offsetBinding").text();
    //alert(offset);
    var fetch = maxrecordsBinding;
    if ((parseInt(offsetBinding) + parseInt(maxrecordsBinding))  > totalrecordsBinding)
        //fetch = maxrecords - offset;
        return;
    else 
        fetch = (parseInt(offsetBinding) + parseInt(maxrecordsBinding));    
    //alert(fetch);
    offsetBinding = fetch;
    RenderBindingListBySearch('%', fetch, maxrecordsBinding, true);
}


var selectedItemBinding=null;

//offset, maxrecords, keyword
function RenderBindingListBySearch(keyword1, offset1, maxrecords1, isForChooser)
{
    var lang = $("#langBinding").text();
    $("#bindinglist").html("<img src=\"img/bigrollergreen.gif\" title=\"Loading\"/>");
    var request=   $.ajax({
        url: 'ajax/bindingsearch.jsp?keyword=' + keyword1 + "&offset=" + offset1 + "&maxrecords=" + maxrecords1 + "&lang=" + lang + "&chooser=" + isForChooser,
        type:"GET",
        cache: false
    });
                  
    request.done(function(msg) {
        window.console && console.log('postback done ');                
        $("#bindinglist").html(msg);
       
    //refresh();
    });

    request.fail(function(jqXHR, textStatus) {
        window.console && console.log('postback failed ');                                
        $("#bindinglist").html("An error occured! " + jqXHR.responseText + textStatus);
    //refresh();
    });
/*
    $.get('ajax/businesssearch.jsp?keyword=' + keyword1 + "&offset=" + offset1 + "&maxrecords=" + maxrecords1 + "&lang=" + lang, function(data) {
        $("#businesslist").html(data);
        refresh();
    });*/
}

function refreshBinding()
{
    var displayrecords = $("#displayrecords").text();
    if (displayrecords == totalrecordsBinding)
    {
        $("#pageupBinding").addClass("disabled");
        $("#pagedownBinding").addClass("disabled");
    }
    else if (offsetBinding + maxrecordsBinding > totalrecordsBinding)
    {
        $("#pageupBinding").addClass("disabled");    
    }
    else if (offsetBinding ==0)
    {
        $("#pagedownBinding").removeClass("disabled");        
    }
    else
    {
        $("#pagedownBinding").removeClass("disabled");        
        $("#pageupBinding").removeClass("disabled");        
    }
}

/**
 *This launches the tModel model div, upon return (and if not abprted), the contents of the div parameter will be replaced with the 
 *first selected tModel
 */
function bindingModal(div, type){
    //reset the form in case it was lanucheed more than once per page view
    reloadBindingModal();
    
    $.dialogBinding.confirm({
        callback: function(success, result) {
            if (!success)
            {
            //  alert("aborted!");    
            }
                
            else{
                if (type=='val')
                    $("#" + div).val(result[0]);
                else if (type=='html')
                    $("#" + div).html(result[0]);
            }
        //     return false;
        }
    });
// return false;
}
            
            
function bindingCancel()
{
    $(".modalableBinding").each(function()
    {
        $(this).prop('checked', false);
    }); 
    $('#bindingChooser').modal('hide');
                
}
            
/**
 *returns an array of selected tmodel keys
 */            
$.dialogBinding = {
    confirm: function(options) {
        var $modal = $('#bindingChooser');
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
            $(".modalableBinding").each(function()
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

