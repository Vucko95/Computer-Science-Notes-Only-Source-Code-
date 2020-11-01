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

import net.jini.core.entry.Entry;
import java.lang.reflect.Field;
import java.lang.reflect.Array;
import java.awt.Component;
import java.awt.BorderLayout;
import java.util.logging.Level;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.JLabel;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreeCellRenderer;
import javax.swing.plaf.metal.MetalLookAndFeel;

/**
 *
 * @author Sun Microsystems, Inc.
 *
 * @version 0.2 06/04/98
 *
 */
abstract class EntryTreePanel extends JPanel {
  /**
   * running mode. 
   *
   * @serial
   */
  private boolean isControllable;


  /**
   * @serial
   */

  private JScrollPane scrollPane;

  /**
   * @serial
   */
  protected JTree tree;

  /**
   * @serial
   */
  protected ObjectNode root;

  /**
   * @serial
   */
  protected DefaultTreeModel model;

  /**
   * @serial
   */
  private boolean showModifier = false;

  /**
   * @serial
   */
  private boolean showPackage = false;


  public EntryTreePanel(boolean isControllable) {
    this.isControllable = isControllable;

    // Init this panel
    setLayout(new BorderLayout());

    // Init tree node and model (attribute tree nodes)
    root = new ObjectNode(isControllable);
    //initTree();
    model = new DefaultTreeModel(root);

    // Init tree view
    tree = new JTree(model);
    //tree.addMouseListener(new DoubleClicker(this));
    tree.setRootVisible(false);
    ObjectNodeRenderer renderer = new ObjectNodeRenderer();
    tree.setCellRenderer(renderer);
    tree.setRowHeight(0);	// let the renderer handle it
    scrollPane = new JScrollPane(tree);
    add(scrollPane, "Center");

    tree.validate();
    scrollPane.validate();
  }

  protected abstract Entry[] getEntryArray();


  protected void initTree() {
    Entry[] entries = getEntryArray();
    if(entries == null)
      entries = new Entry[0];

    for(int i = 0; i < entries.length; i++){
      // check controllability
      boolean nodeControllable = false;
      if(isControllable && ! (entries[i] instanceof net.jini.lookup.entry.ServiceControlled)) {
	nodeControllable = true;
      }

      ObjectNode node = new ObjectNode(entries[i], nodeControllable);
      root.add(node);
      try {
	recursiveObjectTree(node);
      } catch(IllegalAccessException e){
	Browser.logger.log(Level.INFO, "entry access failed", e);
      }
    }
  }

  public void refreshPanel() {
    // reconstruct nodes
    root.removeAllChildren();
    initTree();
    
    model.nodeStructureChanged(root);

    tree.validate();
    scrollPane.validate();
  }

  protected void recursiveObjectTree(ObjectNode node)
    throws IllegalArgumentException, IllegalAccessException {

    Object obj = node.getObject();
    if(obj == null)
      return;
    //Field[] fields = obj.getClass().getDeclaredFields();
    Field[] fields = obj.getClass().getFields();

    for(int i = 0; i < fields.length; i++){
      Field f = fields[i];

      if(Introspector.isHidden(f))
	continue;

      Class clazz = f.getType();
      ObjectNode child = null;
      String fname = f.getName();
      if(clazz.isPrimitive()){
	String clazzName = clazz.toString();
	Object fobj = null;
	if("int".equals(clazzName)){
	  fobj = new Integer(f.getInt(obj));
	} else if("boolean".equals(clazzName)){
	  fobj = new Boolean(f.getBoolean(obj));
	} else if("byte".equals(clazzName)){
	  fobj = new Byte(f.getByte(obj));
	} else if("char".equals(clazzName)){
	  fobj = new Character(f.getChar(obj));
	} else if("double".equals(clazzName)){
	  fobj = new Double(f.getDouble(obj));
	} else if("float".equals(clazzName)){
	  fobj = new Float(f.getFloat(obj));
	} else if("long".equals(clazzName)){
	  fobj = new Long(f.getLong(obj));
	}

	child = new ObjectNode(fobj, clazz, fname, true);
      } else if(Introspector.isWrapper(clazz) || Introspector.isString(clazz)) {
	child = new ObjectNode(f.get(obj), clazz, fname, true);
      } else if(clazz.isArray()){
	child = new ObjectNode(f.get(obj), clazz, fname, false);
	child.setAdministrable(node.isAdministrable());
	child.setControllable(node.isControllable());
	recursiveArrayTree(child, f);
      } else {
	// unknown type
	Object subobj = f.get(obj);

	// check if sub object has a viewable members.
	if(countViewableFields(clazz) > 0){
	  child = new ObjectNode(subobj, clazz, fname, false);
	  child.setAdministrable(node.isAdministrable());
	  child.setControllable(node.isControllable());
	  recursiveObjectTree(child);
	} else {
	  child = new ObjectNode(subobj, clazz, fname, true);
	}
      }
      node.add(child);
    }
  }

  private int countViewableFields(Class clazz) {

    int count = 0;
    //Field[] fields = obj.getClass().getDeclaredFields();
    //Field[] fields = obj.getClass().getFields();
    Field[] fields = clazz.getFields();
    for(int i = 0; i < fields.length; i++){
      Field f = fields[i];

      if(Introspector.isHidden(f))
	continue;

      count++;
    }

    return count;
  }

  private void recursiveArrayTree(ObjectNode node, Field f)
    throws IllegalArgumentException, IllegalAccessException {

    String name = node.getFieldName();
    Object aobj = node.getObject();

    int length = Array.getLength(aobj);

    Class clazz = f.getType().getComponentType();

    if(clazz.isPrimitive() || Introspector.isWrapper(clazz) || Introspector.isString(clazz)){
      // primitive, wrapper objects, string array
      for(int i = 0; i < length; i++){
	Object elem = Array.get(aobj, i);
	//String fname = name + "[" + i + "]"; 
	ObjectNode child = new ObjectNode(elem, clazz, name, i, true);
	node.add(child);
      }
    } else {
      // Object or Array (*sigh*)
      for(int i = 0; i < length; i++){
	Object elem = Array.get(aobj, i);
	//String fname = name + "[" + i + "]"; 
	ObjectNode child = new ObjectNode(elem, clazz, name, i, false);
	recursiveObjectTree(child);
	child.setAdministrable(node.isAdministrable());
	child.setControllable(node.isControllable());

	node.add(child);
      }
    }
  }


  class ObjectNodeRenderer implements TreeCellRenderer {
    private JLabel label;

    public ObjectNodeRenderer() {
      label = new JLabel();
      label.setOpaque(true);
    }
    
    public Component getTreeCellRendererComponent(JTree tree,
						  Object value,
						  boolean isSelected,
						  boolean isExpanded,
						  boolean isLeaf,
						  int row,
						  boolean cellHasFocus){

      //label.setFont(tree.getFont());
      label.setForeground(tree.getForeground());
      if(isSelected){
	//label.setBackground(UIManager.getColor("Tree.backgroundSelectionColor"));
	//label.setForeground(UIManager.getColor("Tree.textSelectionColor"));
	label.setBackground(MetalLookAndFeel.getPrimaryControl());
      } else {
	//label.setBackground(UIManager.getColor("Tree.backgroundNonSelectionColor"));
	//label.setForeground(UIManager.getColor("Tree.textNonSelectionColor"));
	label.setBackground(tree.getBackground());
      }

      ObjectNode node = (ObjectNode) value;
      label.setText(node.getTitle());
      label.setIcon(node.getIcon());
      return label;
    }
  }
}
