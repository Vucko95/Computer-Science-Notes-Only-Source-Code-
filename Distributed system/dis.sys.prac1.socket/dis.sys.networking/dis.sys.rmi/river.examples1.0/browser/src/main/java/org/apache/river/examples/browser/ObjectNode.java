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
import javax.swing.tree.TreeModel;
import javax.swing.tree.TreePath;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.Icon;

/**
 *
 * @author Sun Microsystems, Inc.
 *
 * @version 0.2 06/04/98
 *
 */
class ObjectNode extends DefaultMutableTreeNode implements java.io.Serializable {

  // "classname", "classname fieldName" or "classname fieldName=value"
  /**
   * @serial
   */
  private String name;

  /**
   * @serial
   */
  private Object obj;

  /**
   * @serial
   */
  private Class clazz;

  /**
   * @serial
   */
  private String fieldName;

  /**
   * @serial
   */
  private int arrayIndex = -1;

  /**
   * @serial
   */
  private boolean editable = false;

  /**
   * @serial
   */
  private boolean isLeaf;

  /**
   * @serial
   */
  private boolean isAdministrable;	// root level

  /**
   * @serial
   */
  private boolean isControllable;	// entry level

  /**
   * @serial
   */
  private boolean isRoot = false;

  /**
   * @serial
   */
  private boolean isEntryTop = false;

  // icons
  private static Icon[] icons = new Icon[6];
  static {
    icons[0] = MetalIcons.getBlueFolderIcon();	// Administrable Service, Controllable Attribute
    icons[1] = MetalIcons.getGrayFolderIcon();	// Non-administrable Service
    icons[2] = MetalIcons.getOrangeFolderIcon();	// Uncontrollable Attribute
    icons[3] = MetalIcons.getBlueFileIcon();	// Administrable Service, Controllable Attribute
    icons[4] = MetalIcons.getGrayFileIcon();	// Non-administrable Service
    icons[5] = MetalIcons.getOrangeFileIcon();	// Uncontrollable Attribute
  }

  /**
     Constructor for a root node.
  */
  public ObjectNode(boolean isAdministrable) {
    this("Root node", "".getClass(), null, -1, false);

    this.isAdministrable = isAdministrable;
    this.isRoot = true;
    this.isEntryTop = true;
  }

  /**
     Constructor for an entry (attribute) top nodes.
  */
  public ObjectNode(Object obj, boolean isControllable) {
    this(obj, obj.getClass(), null, -1, false);

    this.isControllable = isControllable;
    this.isEntryTop = true;
  }

  /**
     Constructor for an ordinary field.
  */
  public ObjectNode(Object obj, Class clazz, String fieldName, boolean isLeaf) {
    this(obj, clazz, fieldName, -1, isLeaf);
  }

  /**
     Constructor for an array element.
  */
  public ObjectNode(Object obj, Class clazz, String fieldName, int arrayIndex, boolean isLeaf) {
    this.obj = obj;
    this.clazz = clazz;
    this.fieldName = fieldName;
    this.arrayIndex = arrayIndex;
    this.isLeaf = isLeaf;

    super.setAllowsChildren(! isLeaf);
    setNodeName();
  }

  private void setNodeName() {
    name = Introspector.getTypename(clazz, false);
    if(fieldName != null)
      name += " " + fieldName;

    if(isLeaf) {
      //Class clazz = obj.getClass();
      String value = "";
      if(arrayIndex >= 0)
	value += ("[" + arrayIndex + "]");
      value += "=";
      if(clazz.isPrimitive()){
	value += "" + obj;
	editable = false;
      } else if(Introspector.isWrapper(clazz)){
	// Wrapper objects
	value += "" + obj;
	editable = true;
      } else if(Introspector.isString(clazz)) {
	value += "\"" + obj + "\"";
	editable = true;
      } else {
	value += (obj == null ? "null" : obj.toString());
      }
      name += value;
    } else if(obj == null) {
      name += "=null";
    }

    super.setUserObject(name);
  }

  public void add(ObjectNode child){
    child.setAdministrable(isAdministrable);
    if(! isRoot){
      child.setControllable(isControllable);
    }

    super.add(child);
  }

  public Object getEntryTop() {
    ObjectNode snode = this;
    do {
      snode = (ObjectNode) snode.getParent();
    } while(! snode.isEntryTop());

    return snode.getObject();
  }

  protected boolean isEntryTop() {
    return isEntryTop;
  }

  public void setObjectRecursive() throws NoSuchFieldException, IllegalAccessException {
    ObjectNode pnode = this;
    do {
      pnode = (ObjectNode) pnode.getParent();
      Object pobj = pnode.getObject();
      // Needs to think about array modifications
      Field f = pobj.getClass().getField(fieldName);
      f.set(pobj, obj);
    } while(! pnode.isEntryTop());
  }

  public String getTitle() {
    return name;
  }

  public Icon getIcon() {
    /*
      if(isAdministrable){
      if(isControllable){
      if(isLeaf)	    return icons[3];
      else		    return icons[0];
      } else {
      if(isLeaf)	    return icons[5];
      else		    return icons[2];
      }
      } else {
      if(isLeaf)	    return icons[4];
      else		    return icons[1];
      }
    */
    if(isAdministrable && isControllable)
      if(isLeaf)	return icons[3];
      else		return icons[0];
    else
      if(isLeaf)	return icons[4];
      else		return icons[1];
  }


  // Overwrite
  public void setUserObject(Object obj){
    if(obj instanceof String)
      name = (String) obj;

    super.setUserObject(obj);
  }

  public Object getUserObject(){
    return name;
  }

  public String toString() {
    return name;
  }

  public String getFieldName() {
    return fieldName;
  }

  public Object getObject() {
    return obj;
  }

  public boolean isEditable() {
    return editable;
  }

  public boolean isAdministrable() {
    return isAdministrable;
  }

  public void setAdministrable(boolean val) {
    isAdministrable = val;
  }

  public boolean isControllable() {
    return isControllable;
  }

  public void setControllable(boolean val) {
    isControllable = val;
  }

  public Object setValue(Object val) throws NumberFormatException {
    String clazzName = clazz.getName();
    Object newObj = null;

    if(val instanceof String || val == null) {
      String sval = (String) val;
      if(clazzName.equals("java.lang.Integer"))
	newObj = new Integer(sval);
      else if(clazzName.equals("java.lang.Boolean"))
	newObj = new Boolean(sval);
      else if(clazzName.equals("java.lang.Byte"))
	newObj = new Byte(sval);
      else if(clazzName.equals("java.lang.Character"))
	newObj = new Character(sval.charAt(0));
      else if(clazzName.equals("java.lang.Double"))
	newObj = new Double(sval);
      else if(clazzName.equals("java.lang.Float"))
	newObj = new Float(sval);
      else if(clazzName.equals("java.lang.Long"))
	newObj = new Long(sval);
      else if(clazzName.equals("java.lang.String"))
	newObj = new String(sval);	// clone 
    } else if(val.getClass().equals(obj.getClass())) {
      // same class type
      newObj = val;
    }

    Object oldObj = obj;
    obj = newObj;

    setNodeName();

    return oldObj;
  }
}
