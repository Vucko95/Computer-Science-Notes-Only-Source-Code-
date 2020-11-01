<%-- 
    Document   : header-bottom
    Created on : Feb 24, 2013, 9:08:18 AM
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
 *
 */
--%>

<%@page import="org.apache.commons.lang.StringEscapeUtils"%>
<%@page import="java.io.IOException"%>
<%@page import="java.util.jar.Attributes"%>
<%@page import="java.util.jar.Manifest"%>
<%@page import="java.io.InputStream"%>
<%@page import="java.util.jar.JarFile"%>
<%@page import="java.net.URL"%>
<%@page import="java.util.Enumeration"%>
<%@page import="org.apache.juddi.adminconsole.resources.ResourceLoader"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

</div> <!-- /container -->
</form>
<div style="
     padding: 0px 0px 0px 0px; bottom: 0px; margin: 0px 0px 0px 0px; width:100%; text-align: center; position: fixed; 
     background-color: white; 
     "><center><footer>v<%
     out.write(StringEscapeUtils.escapeHtml(org.apache.juddi.v3.client.Release.getRegistryVersion()));
     %> - <a href="http://www.apache.org"><%=ResourceLoader.GetResource(session, "footer.apachecopyright")%></a></footer></center></div>
</body>
</html>

