<%-- 
    Document   : demp
    Created on : Jan 14, 2014, 6:08:15 PM
    Author     : Alex O'Ree

This is used for the jUDDI demo instance
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
--%>

<%@page import="org.apache.juddi.webconsole.resources.ResourceLoader"%>
<div class="modal hide fade container " id="banner">
        <div class="modal-header">
                <a href="javascript:$('#banner').modal('hide');" class="close" data-dismiss="modal" aria-hidden="true">&times;</a>
                <h3>Welcome</h3>
        </div>
        <div class="modal-body" align="center">
		
                <i class="icon-thumbs-up icon-4x"></i><br>
                Hi there! Thank's for checking out jUDDI's cloud instance. You are free to do whatever you want here.<br>
				
				<br>
				<i class="icon-warning-sign icon-4x"></i><br>
                As such, do not rely on any information provided here. It's probably all made up by people just like you.<br><br>
                In order to create, update or delete content, you'll need to <b>sign in</b>. Just make up a username and stick with it. Passwords are not validated.<br><br>
                If you run into a problem, please file a <a href="http://juddi.apache.org/issue-tracking.html" target="_newtab">bug report</a> so that we can fix it.



        </div>
        <div class="modal-footer">
                <a href="javascript:$('#banner').modal('hide');" class="btn btn-primary" data-dismiss="modal"><%=ResourceLoader.GetResource(session, "modal.close")%></a>
        </div>
</div>

<script type="text/javascript">
        function setCookieBanner(cname, cvalue, exdays)
        {
                var d = new Date();
                d.setTime(d.getTime() + (exdays * 24 * 60 * 60 * 1000));
                var expires = "expires=" + d.toGMTString();
                document.cookie = cname + "=" + cvalue + "; " + expires;
        }
        function getCookieBanner(cname)
        {
                var name = cname + "=";
                var ca = document.cookie.split(';');
                for (var i = 0; i < ca.length; i++)
                {
                        var c = ca[i].trim();
                        if (c.indexOf(name) == 0)
                                return c.substring(name.length, c.length);
                }
                return "";
        }
        function checkCookieBanner()
        {
                var username = getCookieBanner("bannerseen");
                if (username != "")
                {
                        //alert("Welcome again " + username);
                }
                else
                {
                        $('#banner').modal();

                        setCookieBanner("bannerseen", "true", 1);

                }
        }

        $(document).ready(function() {
                checkCookieBanner();
        });
        
</script>