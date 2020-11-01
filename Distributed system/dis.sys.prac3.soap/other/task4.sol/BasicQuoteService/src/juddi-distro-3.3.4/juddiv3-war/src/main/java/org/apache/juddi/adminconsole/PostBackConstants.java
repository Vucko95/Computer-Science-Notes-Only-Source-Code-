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
package org.apache.juddi.adminconsole;

/**
 * A collection of constants to use for form postbacks and parsing data from the
 * browser All fields MUST not contain any characters that could interfer with
 * the rendering of a webpage or javascript and should thus be escaped sequences
 * of characters
 *
 * @author <a href="mailto:alexoree@apache.org">Alex O'Ree</a>
 */
public class PostBackConstants {

    public static final String INSTANCE = "instance";
    public static final String ACCESSPOINT_TYPE = "accessPointType";
    public static final String ACCESSPOINT_VALUE = "accessPointValue";
    @Deprecated
    public static final String HOSTINGREDIRECTOR = "hostingRedirector";
    public static final String OVERVIEW = "overviewDoc";
    public static final String TMODELINSTANCE = "tmodelInstance";
    public static final String BINDINGTEMPLATE = "bindingTemplate";
    public static final String BINDINGKEY = "bindingKey";
    public static final String BUSINESSKEY = "businessKey";
    public static final String SERVICEKEY = "serviceKey";
    //public static final String CLICK_TO_EDIT = "Click to edit";
    public static final String DESCRIPTION = "Description";
    public static final String DISCOVERYURL = "disco";
    public static final String PHONE = "Phone";
    public static final String ADDRESS = "Address";
    public static final String ADDRESSLINE = "addressLine";
    public static final String CONTACT_PREFIX = "contact";
    public static final String NAME = "Name";
    public static final String LANG = "Lang";
    public static final String VALUE = "Value";
    public static final String TYPE = "Type";
    public static final String EMAIL = "Email";
    public static final String SORTCODE = "Sortcode";
    public static final String KEYNAME = "KeyName";
    public static final String KEYVALUE = "KeyValue";
    public static final String CATBAG_KEY_REF = "catbagkeyref";
    public static final String IDENT_KEY_REF = "identbagkeyref";
    public static final String CATBAG_KEY_REF_GRP = "catbaggrpkeyref";
    public static final String KEY_REF = "keyref";
    public static final String TMODEL_DELETED = "isDeleted";
    

}
