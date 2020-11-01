<%-- 
    Document   : quickref_ident
    Created on : Feb 9, 2014, 3:18:24 PM
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

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<div class="btn-group">
        <a class="btn dropdown-toggle btn-info" data-toggle="dropdown"  href="#">Identifiers<span class="caret"></span></a>
        <ul class="dropdown-menu">
                <li><a href="javascript:AddIdentKeyReferenceParam('uddi:uddi.org:ubr:identifier:dnb.com:d-u-n-s','D-U-N-S:My Company','12-345-6789');">D-U-N-S</a></li>
                <li><a href="javascript:AddIdentKeyReferenceParam('uddi:uddi.org:ubr:identifier:owningbusiness','uddi-org:owningBusiness','key');">Owning Business</a></li>
                <li><a href="javascript:AddIdentKeyReferenceParam('uddi:uddi.org:identifier:taxid','uddi-org:taxid','');">Tax ID</a></li>
                <li><a href="javascript:AddIdentKeyReferenceParam('uddi:uddi.org:ubr:identifier:thomasregister.com:supplierid','thomasregister-com:supplierID:My Business','01234567');">Thomas Registry Supplier ID</a></li>
                <li><a href="javascript:AddIdentKeyReferenceParam('uddi:uddi.org:ubr:identifier:iso6523icd','','');">ISO 6523 ICD</a></li>
        </ul>
</div>

<br><br>


