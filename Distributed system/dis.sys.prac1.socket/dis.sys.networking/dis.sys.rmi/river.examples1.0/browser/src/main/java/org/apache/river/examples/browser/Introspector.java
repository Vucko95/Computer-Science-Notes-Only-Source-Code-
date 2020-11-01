/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.apache.river.examples.browser;

import java.lang.reflect.Field;
import java.lang.reflect.Array;
import java.lang.reflect.Modifier;

/**
 * Introspection related methods
 *
 * @author Sun Microsystems, Inc.
 *
 * @version 0.2 06/04/98
 *
 */

class Introspector {

  public static boolean isHidden(Field f){
    int m = f.getModifiers();

    if(Modifier.isPrivate(m) || Modifier.isStatic(m))
      return true;

    return false;
  }

  public static boolean isString(Class clazz){
    if("java.lang.String".equals(clazz.getName()))
      return true;
    return false;
  }

  public static boolean isWrapper(Class clazz){
    String name = clazz.getName();

    if("java.lang.Integer".equals(name) ||
       "java.lang.Boolean".equals(name) ||
       "java.lang.Byte".equals(name) ||
       "java.lang.Char".equals(name) ||
       "java.lang.Double".equals(name) ||
       "java.lang.Float".equals(name) ||
       "java.lang.Long".equals(name)){
      return true;
    }
    return false;
  }

  /** Return the name of an interface or primitive type, handling arrays. */
  public static String getTypename(Class t, boolean showPackage) {
    String brackets = "";
    while(t.isArray()) {
      brackets += "[]";
      t = t.getComponentType();
    }

    if(showPackage)
      return t.getName() + brackets;
    else
      return extractClassName(t.getName()) + brackets;
  }

  /** Return a string version of modifiers, handling spaces nicely. */
  public static String getModifierString(int m) {
    if(m == 0)
      return "";
    else
      return Modifier.toString(m) + " ";
  }

  /** Print the modifiers, type, and name of a field. */
  public static String getFieldString(Field f, boolean showModifier, boolean showPackage) {
    String fstring = "";
    
    if(showModifier)
      fstring += getModifierString(f.getModifiers());

    fstring += getTypename(f.getType(), showPackage);
    fstring += " ";
    fstring += f.getName();

    return fstring;
  }

  public static String extractClassName(String fullName){
    int index = fullName.lastIndexOf(".");
    
    return fullName.substring(index + 1);
  }
}
