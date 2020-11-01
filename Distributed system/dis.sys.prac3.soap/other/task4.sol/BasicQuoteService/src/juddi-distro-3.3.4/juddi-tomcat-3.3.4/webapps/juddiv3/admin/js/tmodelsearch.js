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
var offset=0; //start at the begining
var maxrecords=10;  //record 20 at a time
var lang="en";  //langauge english
var totalrecords=0;

RenderTmodelListBySearch('%', offset, maxrecords);

function pagedownChooserTmodel()
{
    offset = $("#offset").text();
    //alert(offset);
    var newoffset = offset - maxrecords;
    if (newoffset < 0)
        return;
    //alert(newoffset);
    if (newoffset != offset)
        RenderTmodelListBySearch('%', newoffset, maxrecords, true);
}
function pageupChooserTmodel()
{
    offset = $("#offset").text();
    //alert(offset);
    var fetch = maxrecords;
    if ((parseInt(offset) + parseInt(maxrecords))  > totalrecords)
        //fetch = maxrecords - offset;
        return;
    else 
        fetch = (parseInt(offset) + parseInt(maxrecords));    
    //alert(fetch);
    offset = fetch;
    RenderTmodelListBySearch('%', fetch, maxrecords, true);
}


function pagedown()
{
    offset = $("#offset").text();
    //alert(offset);
    var newoffset = offset - maxrecords;
    if (newoffset < 0)
        return;
    //alert(newoffset);
    if (newoffset != offset)
        RenderTmodelListBySearch('%', newoffset, maxrecords, false);
}
function pageup()
{
    offset = $("#offset").text();
    //alert(offset);
    var fetch = maxrecords;
    if ((parseInt(offset) + parseInt(maxrecords))  > totalrecords)
        //fetch = maxrecords - offset;
        return;
    else 
        fetch = (parseInt(offset) + parseInt(maxrecords));    
    //alert(fetch);
    offset = fetch;
    RenderTmodelListBySearch('%', fetch, maxrecords, false);
}
var selectedItem=null;

//offset, maxrecords, keyword
function RenderTmodelListBySearch(keyword1, offset1, maxrecords1, isForChooser)
{
    var lang = $("#lang").text();
    $("#tmodellist").html("<img src=\"img/bigrollergreen.gif\" title=\"Loading\"/>");
    var request=   $.ajax({
        url: 'ajax/tmodelsearch.jsp?keyword=' + keyword1 + "&offset=" + offset1 + "&maxrecords=" + maxrecords1 + "&lang=" + lang + "&chooser=" + isForChooser,
        type:"GET",
        cache: false
    });
                  
    request.done(function(msg) {
        window.console && console.log('postback done ');                
        $("#tmodellist").html(msg);
        $('.modalable').click(function(){
            selectedItem =$(this).attr("id");
        });
    //refresh();
    });

    request.fail(function(jqXHR, textStatus) {
        window.console && console.log('postback failed ');                                
        $("#tmodellist").html("An error occured! " + jqXHR.responseText + textStatus);
    //refresh();
    });
/*
    $.get('ajax/businesssearch.jsp?keyword=' + keyword1 + "&offset=" + offset1 + "&maxrecords=" + maxrecords1 + "&lang=" + lang, function(data) {
        $("#businesslist").html(data);
        refresh();
    });*/
}

function refresh()
{
    var displayrecords = $("#displayrecords").text();
    if (displayrecords == totalrecords)
    {
        $("#pageup").addClass("disabled");
        $("#pagedown").addClass("disabled");
    }
    else if (offset + maxrecords > totalrecords)
    {
        $("#pageup").addClass("disabled");    
    }
    else if (offset ==0)
    {
        $("#pagedown").removeClass("disabled");        
    }
    else
    {
        $("#pagedown").removeClass("disabled");        
        $("#pageup").removeClass("disabled");        
    }
}