<%-- 
    Document   : keyHelpModal.jsp
    Created on : Nov 5, 2013, 7:29:53 AM
    Author     : Alex O'Ree
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
<script type="text/javascript">
    function ShowKeyHelp()
    {
        $("#aboutKeys").modal('show');
    }
</script>

<div class="modal hide fade container" id="aboutKeys">
    <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
        <h3><%=ResourceLoader.GetResource(session, "navbar.help")%></h3>
    </div>
    <div class="modal-body">
        <%=ResourceLoader.GetResource(session, "pages.uddikeys")%>
    </div>
    <div class="modal-footer">

        <a href="javascript:closeXmlPop('aboutKeys');" class="btn"><%=ResourceLoader.GetResource(session, "modal.close")%></a>
    </div>
</div>
