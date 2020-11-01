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

var offseServicet=0; //start at the begining
var maxrecordsService=20;  //record 20 at a time
var totalrecordsService=0;

function refreshServiceList()
{
    RenderServiceListBySearch('%', offsetService, maxrecordsService);    
}
RenderServiceListBySearch('%', offsetService, maxrecordsService);
//offset += maxrecords;
function pagedownService()
{                                            
    offsetService = $("#offsetService").text();
    //alert(offset);
    var newoffset = offsetService - maxrecordsService;
    if (newoffset < 0)
        return;
    //alert(newoffset);
    if (newoffset != offsetService)
        RenderServiceListBySearch('%', newoffset, maxrecordsService);
}
function pageupService()
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
    RenderServiceListBySearch('%', fetch, maxrecordsService);
}

function RenderServiceListBySearch(keyword, offset, maxrecords)
{
    var    keyword2 = $("#name_service_search").val();
   
    var lang = $("#lang_service_search").val();
    if (lang==undefined)
       lang="";
     if (keyword2==undefined)
       keyword2="";
    lang = encodeURIComponent(lang);
    offset = encodeURIComponent(offset);
    maxrecords = encodeURIComponent(maxrecords);
    keyword2 = encodeURIComponent(keyword2);
    $("#serviceBrowserListing").html("<img src=\"img/bigrollergreen.gif\" title=\"Loading\"/>");
    var request=   $.ajax({
        url: 'ajax/servicesearch.jsp?keyword=' + keyword2 + "&offset=" + offset + "&maxrecords=" + maxrecords + "&lang=" + lang,
        type:"GET",
        cache: false
    });
                  
    request.done(function(msg) {
        window.console && console.log('postback done ');                
        $("#serviceBrowserListings").html(msg);
    });

    request.fail(function(jqXHR, textStatus) {
        window.console && console.log('postback failed ');                                
        $("#serviceBrowserListings").html("An error occured! " + jqXHR.responseText + textStatus);
    });
}

function refresh()
{
    var displayrecords = $("#displayrecordsService").text();
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