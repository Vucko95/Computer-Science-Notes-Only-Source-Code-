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


var offsetBusiness=0; //start at the begining
var maxrecordsBusiness=20;  //record 20 at a time
var totalrecordsBusiness=0;

RenderBusinessListBySearch('%', offsetBusiness, maxrecordsBusiness);

function pagedownBusiness()
{
    offset = $("#offsetBusiness").text();
    //alert(offset);
    var newoffset = offsetBusiness - maxrecordsBusiness;
    if (newoffset < 0)
        return;
    //alert(newoffset);
    if (newoffset != offsetBusiness)
    {
        offsetBusiness = newoffset;
        RenderBusinessListBySearch('%', newoffset, maxrecordsBusiness);
    }
}
function refreshBusinessList()
{
    RenderBusinessListBySearch('%', offsetBusiness, maxrecordsBusiness);
}
function pageupBusiness()
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
    RenderBusinessListBySearch('%', fetch, maxrecordsBusiness);
}

//offset, maxrecords, keyword
function RenderBusinessListBySearch(keyword1, offset1, maxrecords1)
{
   var    keyword =$("#name_business").val();
    var lang = $("#lang_business").text();
    if (lang==undefined)
       lang = "";
    if (keyword==undefined)
       keyword = "";
    lang = encodeURIComponent(lang);
    keyword = encodeURIComponent(keyword);
    offset1 = encodeURIComponent(offset1);
    maxrecords1 = encodeURIComponent(maxrecords1);
    
    $("#businesslist").html("<img src=\"img/bigrollergreen.gif\" title=\"Loading\"/>");
    var request=   $.ajax({
        url: 'ajax/businesssearch.jsp?keyword=' + keyword + "&offset=" + offset1 + "&maxrecords=" + maxrecords1 + "&lang=" + lang,
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



function refresh()
{
    var displayrecords = $("#displayrecordsBusiness").text();
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