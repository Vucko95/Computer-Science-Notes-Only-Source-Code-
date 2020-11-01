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

import net.jini.core.lookup.ServiceItem;
import net.jini.core.lookup.ServiceRegistrar;
import net.jini.core.lookup.ServiceMatches;
import net.jini.core.lookup.ServiceTemplate;
import net.jini.core.entry.Entry;
import net.jini.lookup.ui.factory.JFrameFactory;
import net.jini.lookup.entry.UIDescriptor;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Rectangle;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.logging.Level;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPopupMenu;
import javax.swing.event.PopupMenuListener;
import javax.swing.event.PopupMenuEvent;

/**
 * A browser utility to browse entries in a specified space.
 *
 * Note: This code is part of a comprehensive tutorial - Be sure to have a look
 * at the 'README.md' file in the root of the parent 'river-examples' project
 * for instructions on how to build and view the complete tutorial.
 * 
 *
 */
class ServiceBrowser extends JFrame {
  private Browser browser;
  private AttributePanel attrPanel;
  private final static int MINIMUM_WINDOW_WIDTH = 320;

  public ServiceBrowser(ServiceItem item,
			ServiceRegistrar registrar,
			Browser browser)
  {
    super("ServiceItem Browser");

    this.browser = browser;
    // init main components
    attrPanel = new AttributePanel(item, registrar);

    // add menu and attr panel
    getContentPane().setLayout(new BorderLayout());
    getContentPane().add(new BrowserMenuBar(), "North");
    getContentPane().add(attrPanel, "Center");

    validate();
    pack();
    setSize(((getSize().width < MINIMUM_WINDOW_WIDTH) ? MINIMUM_WINDOW_WIDTH : getSize().width),
	    getSize().height);

    // center in parent frame
    Rectangle bounds = browser.getBounds();
    Dimension dialogSize = getPreferredSize();
    int xpos = bounds.x + (bounds.width - dialogSize.width)/ 2;
    int ypos = bounds.y + (bounds.height - dialogSize.height)/2;
    setLocation((xpos < 0) ? 0 : xpos,
		(ypos < 0) ? 0 : ypos);
  }


  class BrowserMenuBar extends JMenuBar {
    public BrowserMenuBar() {
      JMenuItem mitem;

      // "File" Menu
      JMenu fileMenu = (JMenu) add(new JMenu("File"));
      mitem = (JMenuItem) fileMenu.add(new JMenuItem("Refresh"));
      mitem.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  attrPanel.refreshPanel();
	}
      }));
      mitem = (JMenuItem) fileMenu.add(new JMenuItem("Close"));
      mitem.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  ServiceBrowser.this.setVisible(false);
	}
      }));
    }
  }

  class AttributePanel extends EntryTreePanel {
    private ServiceItem item;
    private ServiceRegistrar registrar;

    public AttributePanel(ServiceItem item, ServiceRegistrar registrar) {
      super(false);	// Entries are not editable.

      this.item = item;
      this.registrar = registrar;

      tree.addMouseListener(browser.wrap(new ServiceBrowser.MouseReceiver(item,
					 uiDescriptorPopup())));

      refreshPanel();
    }

    protected Entry[] getEntryArray() {
      try{
	ServiceMatches matches = registrar.lookup(new ServiceTemplate(item.serviceID,
								      new Class[] { item.service.getClass() },
								      new Entry[] {}),
						  10);
	if(matches.totalMatches != 1)
	  Browser.logger.log(Level.INFO, "unexpected lookup matches: {0}",
			     new Integer(matches.totalMatches));
	else
	  return matches.items[0].attributeSets;
      } catch (Throwable t) {
	Browser.logger.log(Level.INFO, "lookup failed", t);
      }
      return null;
    }
  }

    // provides support for ServiceUI
    public class UIDescriptorPopup extends JPopupMenu implements ActionListener,
	PopupMenuListener {

	protected transient JMenuItem showUIItem;
	protected transient ServiceItem serviceItem;

	public UIDescriptorPopup() {
	    super();

	    showUIItem = new JMenuItem("Show UI");

	    showUIItem.addActionListener(this);
	    showUIItem.setActionCommand("showUI");
	    add(showUIItem);

	    addPopupMenuListener(this);
	    setOpaque(true);
	    setLightWeightPopupEnabled(true);
	}

	public void actionPerformed(ActionEvent anEvent) {

	    UIDescriptor uiDescriptor = getSelectedUIDescriptor();

	    if (uiDescriptor == null) {
		return;
	    }

	    try {
		JFrameFactory uiFactory = (JFrameFactory)
		    uiDescriptor.getUIFactory(Thread.currentThread().getContextClassLoader());
		JFrame frame = uiFactory.getJFrame(serviceItem);

		frame.validate();
		frame.setVisible(true);
	    }
	    catch (Exception e) {
		e.printStackTrace();

		return;
	    }
	}

	public void popupMenuWillBecomeVisible(PopupMenuEvent ev) {
	}

	public void popupMenuWillBecomeInvisible(PopupMenuEvent ev) {
	}

	public void popupMenuCanceled(PopupMenuEvent ev) {
	}

	public void setServiceItem(ServiceItem anItem) {
	    serviceItem = anItem;
	}
    }

    class MouseReceiver extends MouseAdapter {

	private ServiceBrowser.UIDescriptorPopup popup;
	private ServiceItem serviceItem;

	public MouseReceiver(ServiceItem aServiceItem,
			ServiceBrowser.UIDescriptorPopup popup) {
		this.popup = popup;
		serviceItem = aServiceItem;
	}

	public void mouseReleased(MouseEvent ev) {

	    higlightSelection(ev);

	    if (!ev.isPopupTrigger()) {
		return;
	    }

	    UIDescriptor selectedDescriptor = getSelectedUIDescriptor();

	    if (selectedDescriptor == null) {
		return;
	    }

	    if (!"javax.swing".equals(selectedDescriptor.toolkit)) {
		return;
	    }

	    popup.setServiceItem(serviceItem);
	    popup.show(ev.getComponent(), ev.getX(), ev.getY());
	}

	public void mousePressed(MouseEvent ev) {

	    higlightSelection(ev);

	    if (!ev.isPopupTrigger()) {
		return;
	    }

	    UIDescriptor selectedDescriptor = getSelectedUIDescriptor();

	    if (selectedDescriptor == null) {
		return;
	    }

	    if (!"javax.swing".equals(selectedDescriptor.toolkit)) {
		return;
	    }

	    popup.setServiceItem(serviceItem);
	    popup.show(ev.getComponent(), ev.getX(), ev.getY());
	}
    }

    private UIDescriptor getSelectedUIDescriptor() {

	ObjectNode selectedNode =
		(ObjectNode) attrPanel.tree.getLastSelectedPathComponent();

	if (selectedNode == null) {
	    return null;
	}

	Object selectedObject = selectedNode.getObject();

	try {
	    return (UIDescriptor) selectedObject;
	}
	catch (ClassCastException e) {
	    return null;
	}
    }

    private void higlightSelection(MouseEvent anEvent) {
	attrPanel.tree.setSelectionPath(attrPanel.tree.getPathForLocation(
	    anEvent.getX(), anEvent.getY()));
    }

    private ServiceBrowser.UIDescriptorPopup uiDescriptorPopup() {
	return new ServiceBrowser.UIDescriptorPopup();
    }
}
