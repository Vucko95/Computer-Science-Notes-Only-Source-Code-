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
 * source http://stackoverflow.com/questions/6049687/jquery-ui-dialog-box-need-to-return-value-when-user-presses-button-but-not-wor 
 * http://stackoverflow.com/questions/3560872/returning-value-from-confirmation-dialog-using-jquery-ui-dialog
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function reloadTmodelModal()
{
    RenderTmodelListBySearch('%', offset, maxrecords, true);
                      
}


/**
 *This launches the tModel model div, upon return (and if not abprted), the contents of the div parameter will be replaced with the 
 *first selected tModel
 */
function tModelModal(div){
    $(div).focus();
    //reset the form in case it was lanucheed more than once per page view
    reloadTmodelModal();
    
    $.dialogTmodel.confirm({
        callback: function(success, result) {
            if (!success)
            {
                //alert("aborted!");    
            }
                
            else{
                //alert('Result: ' + result.join());
                $("#" + div).html(result[0]);
            }
        //    return false;
        }
    });
   // return false;
}
            
            
function tModelCancel()
{
    $(".modalableTmodel").each(function()
    {
        $(this).prop('checked', false);
    }); 
    $('#tmodelChooser').modal('hide');
                
}
            
/**
 *returns an array of selected tmodel keys
 */            
$.dialogTmodel = {
    confirm: function(options) {
        var $modal = $('#tmodelChooser');
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
            $(".modalableTmodel").each(function()
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

