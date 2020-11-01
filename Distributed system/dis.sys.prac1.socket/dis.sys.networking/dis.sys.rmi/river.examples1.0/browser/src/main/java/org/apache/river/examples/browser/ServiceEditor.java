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

import com.sun.jini.admin.DestroyAdmin;
import com.sun.jini.config.Config;
import com.sun.jini.logging.Levels;
import com.sun.jini.proxy.BasicProxyTrustVerifier;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.net.MalformedURLException;
import java.rmi.server.ExportException;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.SwingUtilities;
import javax.swing.event.PopupMenuEvent;
import javax.swing.event.PopupMenuListener;
import javax.swing.tree.TreePath;
import net.jini.admin.JoinAdmin;
import net.jini.config.ConfigurationException;
import net.jini.core.discovery.LookupLocator;
import net.jini.core.entry.Entry;
import net.jini.core.event.EventRegistration;
import net.jini.core.event.RemoteEvent;
import net.jini.core.event.RemoteEventListener;
import net.jini.core.lease.Lease;
import net.jini.core.lookup.ServiceEvent;
import net.jini.core.lookup.ServiceItem;
import net.jini.core.lookup.ServiceMatches;
import net.jini.core.lookup.ServiceRegistrar;
import net.jini.core.lookup.ServiceTemplate;
import net.jini.export.Exporter;
import net.jini.jeri.BasicILFactory;
import net.jini.jeri.BasicJeriExporter;
import net.jini.jeri.tcp.TcpServerEndpoint;
import net.jini.lookup.DiscoveryAdmin;
import net.jini.lookup.entry.UIDescriptor;
import net.jini.lookup.ui.factory.JFrameFactory;
import net.jini.security.TrustVerifier;
import net.jini.security.proxytrust.ServerProxyTrust;

/**
 * ServiceEditor is a gui-based utility to add/modify
 * attributes, groups and lookup locators.
 * And also supports some well known admin interfaces.
 * (DestroyAdmin, DiscoveryAdmin)
 *
 * <p>
 * current issues<br>
 * <ul>
 *   <li> can't operate(add/remove/modify) array elements in an entry.
 *   <li> does not support EntryBean.
 *   <li> field modification is not based on EditableTree
 * </ul>
 *
 * @author Sun Microsystems, Inc.
 */
class ServiceEditor extends JFrame {
  private static final Logger logger = Browser.logger;

  private Browser browser;
  private ServiceItem item;
  private ServiceRegistrar registrar;
  protected Object admin;
  private ServiceTemplate stmpl;
  private NotifyReceiver receiver;
  private Lease elease = null;
  private long eventID = 0;
  private long seqNo = Long.MAX_VALUE;
  private AttributeTreePanel attrPanel;

  private final static int MINIMUM_WINDOW_WIDTH = 320;

  public ServiceEditor(ServiceItem item,
		       Object admin,
		       ServiceRegistrar registrar,
		       Browser browser)
    {
    super("ServiceItem Editor");
    
    this.item = item;
    this.admin = admin;
    this.registrar = registrar;
    this.browser = browser;

    // init main components
    attrPanel = new AttributeTreePanel();

    // setup notify
    try {
      stmpl = new ServiceTemplate(item.serviceID,
				  new Class[] { item.service.getClass() },
				  new Entry[] {});
      receiver = new NotifyReceiver();

      setupNotify();
    } catch (Throwable t) {
      logger.log(Level.INFO, "event registration failed", t);
      cancelNotify();
    }

    addWindowListener(browser.wrap(new WindowAdapter() {
	public void windowClosing(WindowEvent e) {
	  cleanup();
	}
      }));
    // add menu and attr panel
    getContentPane().setLayout(new BorderLayout());
    getContentPane().add(new JoinMenuBar(), "North");
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

  void cleanup() {
    // cancel lease
    cancelNotify();
    // release resources and close all child frames
    dispose();
    receiver.unexport();
  }

  protected void cancelNotify() {
    if(elease != null) {
      try {
	browser.leaseMgr.cancel(elease);
      } catch (Throwable t) {
	logger.log(Levels.HANDLED, "event cancellation failed", t);
      }
      elease = null;
      seqNo = Long.MAX_VALUE;
    }
  }

  protected void setupNotify() {
    if(registrar != null) {
      try {
	EventRegistration reg =
	    registrar.notify(stmpl,
			     ServiceRegistrar.TRANSITION_MATCH_NOMATCH |
			     ServiceRegistrar.TRANSITION_NOMATCH_MATCH |
			     ServiceRegistrar.TRANSITION_MATCH_MATCH,
			     receiver.proxy,
			     null,
			     Lease.ANY);
	elease = (Lease) browser.leasePreparer.prepareProxy(reg.getLease());
	browser.leaseMgr.renewUntil(elease, Lease.ANY,
				    new Browser.LeaseNotify());
	eventID = reg.getID();
	seqNo = reg.getSequenceNumber();
      } catch (Throwable t) {
	logger.log(Level.INFO, "event registration failed", t);
      }
    }
  }

  private class NotifyReceiver implements RemoteEventListener, ServerProxyTrust
  {
    private final Exporter exporter;
    final RemoteEventListener proxy;

    public NotifyReceiver() throws ConfigurationException, ExportException {
      exporter = (Exporter)
	  Config.getNonNullEntry(browser.config, Browser.BROWSER,
				 "listenerExporter", Exporter.class,
				 new BasicJeriExporter(
					     TcpServerEndpoint.getInstance(0),
					     new BasicILFactory(),
					     false, false));
      proxy = (RemoteEventListener) exporter.export(this);
    }

    public void notify(final RemoteEvent ev) {
      SwingUtilities.invokeLater(browser.wrap(new Runnable() {
	public void run() {
	  if (eventID == ev.getID() && seqNo < ev.getSequenceNumber()) {
	    seqNo = ev.getSequenceNumber();
	    attrPanel.receiveNotify(((ServiceEvent) ev).getTransition());
	  }
	}
      }));
    }

    public TrustVerifier getProxyVerifier() {
      return new BasicProxyTrustVerifier(proxy);
    }

    void unexport() {
	exporter.unexport(true);
    }
  }

  class JoinMenuBar extends JMenuBar {
    public JoinMenuBar() {
      JMenuItem mitem;

      // "File" Menu
      JMenu fileMenu = (JMenu) add(new JMenu("File"));
      mitem = (JMenuItem) fileMenu.add(new JMenuItem("Show Info"));
      mitem.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  Class[] infs = Browser.getInterfaces(item.service.getClass());
	  String[] msg = new String[3 + infs.length];
	  msg[0] = "ServiceID: " + item.serviceID;
	  msg[1] = "Service Instance: " + item.service.getClass().getName();
	  if(infs.length == 1)
	    msg[2] = "Implemented Interface:";
	  else
	    msg[2] = "Implemented Interfaces:";
	  for(int i = 0; i < infs.length; i++)
	    msg[3 + i] = "    " + infs[i].getName();

	  JOptionPane.showMessageDialog(ServiceEditor.this,
					msg,
					"ServiceItem Information",
					JOptionPane.INFORMATION_MESSAGE);
	}
      }));
      mitem = (JMenuItem) fileMenu.add(new JMenuItem("Refresh"));
      mitem.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  attrPanel.refreshPanel();
	}
      }));
      mitem = (JMenuItem) fileMenu.add(new JMenuItem("Close"));
      mitem.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  cleanup();
	}
      }));

      // "Edit" Menu
      JMenu editMenu = (JMenu) add(new JMenu("Edit"));
      mitem = (JMenuItem) editMenu.add(new JMenuItem("Add Attribute..."));
      mitem.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  attrPanel.addAttr();
	}
      }));
      if(! (admin instanceof JoinAdmin))
	mitem.setEnabled(false);
      mitem = (JMenuItem) editMenu.add(new JMenuItem("Remove Attribute"));
      mitem.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  attrPanel.removeAttr();
	}
      }));
      if(! (admin instanceof JoinAdmin))
	mitem.setEnabled(false);

      // "Admin" Menu
      JMenu adminMenu = (JMenu) add(new JMenu("Admin"));

      // Group (JoinAdmin)
      mitem = (JMenuItem) adminMenu.add(new JMenuItem("Joining groups..."));
      mitem.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  new GroupLister("Joining Groups").showFrame();
	}
      }));
      if(! (admin instanceof JoinAdmin))
	mitem.setEnabled(false);

      // Locator (JoinAdmin)
      mitem = (JMenuItem) adminMenu.add(new JMenuItem("Joining locators..."));
      mitem.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  new LocatorLister("Joining Locators").showFrame();
	}
      }));
      if(! (admin instanceof JoinAdmin))
	mitem.setEnabled(false);

      // separator
      adminMenu.addSeparator();

      // Group (DiscoveryAdmin)
      mitem = (JMenuItem) adminMenu.add(new JMenuItem("Member groups..."));
      mitem.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  new MemberGroupLister("Member Groups").showFrame();
	}
      }));
      if(! (admin instanceof DiscoveryAdmin))
	mitem.setEnabled(false);

      // Unicast port (DiscoveryAdmin)
      mitem = (JMenuItem) adminMenu.add(new JMenuItem("Unicast port..."));
      mitem.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  try {
	    String[] msg = { "Current port is " + ((DiscoveryAdmin) admin).getUnicastPort(),
			     "Input a new value" };
	    String result = JOptionPane.showInputDialog(ServiceEditor.this,
							msg,
							"Unicast Port",
							JOptionPane.QUESTION_MESSAGE);

	    if(result == null)
	      return;

	    try {
	      int port = Integer.parseInt(result);
	      ((DiscoveryAdmin) admin).setUnicastPort(port);
	    } catch (NumberFormatException e) {
	      JOptionPane.showMessageDialog(ServiceEditor.this,
					    result + " is not acceptable.",
					    "Error",
					    JOptionPane.ERROR_MESSAGE);
	    } catch (Throwable t) {
	      logger.log(Level.INFO, "setting unicast port failed", t);
	      JOptionPane.showMessageDialog(ServiceEditor.this,
					    t.getMessage(),
					    t.getClass().getName(),
					    JOptionPane.ERROR_MESSAGE);
	    }
	  } catch (Throwable t) {
	    logger.log(Level.INFO, "getting unicast port failed", t);
	    JOptionPane.showMessageDialog(ServiceEditor.this,
					  t.getMessage(),
					  t.getClass().getName(),
					  JOptionPane.ERROR_MESSAGE);
	  }
	}
      }));
      if(! (admin instanceof DiscoveryAdmin))
	mitem.setEnabled(false);

      // separator
      adminMenu.addSeparator();

      // DestroyAdmin
      mitem = (JMenuItem) adminMenu.add(new JMenuItem("Destroy"));
      mitem.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  if(JOptionPane.showConfirmDialog(ServiceEditor.this,
					   "Are you sure to destroy this service?",
					   "Query",
					   JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION)
	    try {
	      ((DestroyAdmin) admin).destroy();
	      cleanup();
	    } catch (Throwable t) {
	      logger.log(Level.INFO, "service destroy failed", t);
	      JOptionPane.showMessageDialog(ServiceEditor.this,
					    t.getMessage(),
					    t.getClass().getName(),
					    JOptionPane.ERROR_MESSAGE);
	    }
	}
      }));
      if(! (admin instanceof DestroyAdmin))
	mitem.setEnabled(false);
    }
  }

  class AttributeTreePanel extends EntryTreePanel {

    public AttributeTreePanel() {
      super(admin instanceof JoinAdmin);

      if(admin instanceof JoinAdmin) {
	tree.addMouseListener(browser.wrap(new DoubleClicker(this)));
      }
      tree.addMouseListener(browser.wrap(new MouseReceiver(item, uiDescriptorPopup())));

      refreshPanel();
    }

    protected Entry[] getEntryArray() {
      if(admin instanceof JoinAdmin) {
	try {
	  item.attributeSets = ((JoinAdmin) admin).getLookupAttributes();
	} catch (Throwable t) {
	  logger.log(Level.INFO, "obtaining attributes failed", t);
	}
      } else {
	try{
	  ServiceMatches matches = registrar.lookup(stmpl, 1);
	  if(matches.totalMatches != 1)
	    Browser.logger.log(Level.INFO, "unexpected lookup matches: {0}",
			       new Integer(matches.totalMatches));
	  else
	    item.attributeSets = matches.items[0].attributeSets;
	} catch (Throwable t) {
	  Browser.logger.log(Level.INFO, "lookup failed", t);
	}
      }
      return item.attributeSets;
    }

    protected void receiveNotify(int transition) {

      if (browser.isAutoConfirm()) {
        if (transition == ServiceRegistrar.TRANSITION_MATCH_NOMATCH)
          cleanup();
        else
          refreshPanel();

        return;
      }

	String[] msg =
	    (transition == ServiceRegistrar.TRANSITION_MATCH_NOMATCH) ?
	    new String[]{
		"Service has been removed from lookup service.",
		"Do you want to close the service editor window ?"} :
	    new String[]{
		"Attributes have been modified by another client or the service itself.",
		"Do you want to refresh the attributes ?"};
      int result = JOptionPane.showConfirmDialog(AttributeTreePanel.this,
						 msg,
						 "Query",
						 JOptionPane.YES_NO_OPTION);
	
      if(result == JOptionPane.YES_OPTION) {
	  if (transition == ServiceRegistrar.TRANSITION_MATCH_NOMATCH)
	      cleanup();
	  else
	      refreshPanel();
      }
    }

    public void editField(ObjectNode node) {

      String result = JOptionPane.showInputDialog(this,
						  "Input a new value",
						  "Modify a field",
						  JOptionPane.QUESTION_MESSAGE);

      if(result == null){
      } else {
	// Save current value as template
	Entry template = cloneEntry((Entry) node.getEntryTop());
	Object oldVal = null;

	if(result.length() == 0){
	  oldVal = node.setValue(null);
	} else {
	  oldVal = node.setValue(result);
	}
	// modifyAttribute
	try {
	  node.setObjectRecursive();
	  Entry attr = (Entry) node.getEntryTop();
	  //Entry template = (Entry) generateTemplate(attr);

	  // cancel notify while adding an attribute
	  cancelNotify();

	  ((JoinAdmin) admin).modifyLookupAttributes(
			      new Entry[] { template }, new Entry[] { attr });

	  setupNotify();

	  // Redraw node value
	  model.nodeChanged(node);
	} catch (Throwable t) {
	  logger.log(Level.INFO, "attribute modification failed", t);
	  // recover tree node
	  try {
	    node.setValue(oldVal);
	    node.setObjectRecursive();
	  } catch (Throwable tt) {
	    logger.log(Levels.HANDLED, "node reset failed", tt);
	  }
	  model.nodeChanged(node);
	  //model.nodeStructureChanged(node);

	  // show dialog
	  JOptionPane.showMessageDialog(AttributeTreePanel.this,
					t.getMessage(),
					t.getClass().getName(),
					JOptionPane.ERROR_MESSAGE);
	}
      }
    }

    public void addAttr() {

      String result = JOptionPane.showInputDialog(this,
						  "Input an entry class name",
						  "Add an attribute",
						  JOptionPane.QUESTION_MESSAGE);

      if(result == null || result.length() == 0){
      } else {
	try {
	  Class clazz = Class.forName(result);
	  Object attr = clazz.newInstance();

	  if(! (attr instanceof Entry)){
	    JOptionPane.showMessageDialog(AttributeTreePanel.this,
					  "Does not implement Entry interface",
					  "Unacceptable Class",
					  JOptionPane.WARNING_MESSAGE);

	  } else if(attr instanceof net.jini.lookup.entry.ServiceControlled){
	    JOptionPane.showMessageDialog(AttributeTreePanel.this,
					  "Implements ServiceControlled interface",
					  "Unacceptable Class",
					  JOptionPane.WARNING_MESSAGE);
	  } else {
	    // cancel notify while adding an attribute
	    cancelNotify();

	    ((JoinAdmin) admin).addLookupAttributes(
						new Entry[] { (Entry) attr });
	    // add node of this attribute
	    ObjectNode node = new ObjectNode(attr, true);
	    root.add(node);
	    recursiveObjectTree(node);

	    // 
	    setupNotify();

	    // refresh view
	    model.nodesWereInserted(root,
				    new int[] { model.getIndexOfChild(root, node) });
	  }
	} catch (ClassNotFoundException e) {
	  JOptionPane.showMessageDialog(AttributeTreePanel.this,
					e.getMessage(),
					"Class Not Found",
					JOptionPane.WARNING_MESSAGE);
	} catch (Throwable t) {
	  logger.log(Level.INFO, "adding attribute failed", t);
	  JOptionPane.showMessageDialog(AttributeTreePanel.this,
					t.getMessage(),
					t.getClass().getName(),
					JOptionPane.WARNING_MESSAGE);
	}
      }
    }

    public void removeAttr() {

      ObjectNode node = (ObjectNode) tree.getLastSelectedPathComponent();
      if(node == null){
	JOptionPane.showMessageDialog(AttributeTreePanel.this,
				      "Select an attribute folder to remove.",
				      "Warning",
				      JOptionPane.WARNING_MESSAGE);
	
	return;
      } else if(! node.isControllable()){
	JOptionPane.showMessageDialog(AttributeTreePanel.this,
				      "This attribute is under service provider's control.",
				      "Warning",
				      JOptionPane.WARNING_MESSAGE);
	
	return;
      } else if(! node.isEntryTop()){
	JOptionPane.showMessageDialog(AttributeTreePanel.this,
				      "Select a top of attribute folder.",
				      "Warning",
				      JOptionPane.WARNING_MESSAGE);
	
	return;
      }

      Entry target = (Entry) node.getObject();
      int result = JOptionPane.showConfirmDialog(AttributeTreePanel.this,
						 new String[] {"Remove attribute:",
								 target.toString() },
						 "Query",
						 JOptionPane.YES_NO_OPTION);
	
      if(result == JOptionPane.YES_OPTION){
	// Remote Attribute
	try {

	  // cancel notify while adding an attribute
	  cancelNotify();

	  ((JoinAdmin) admin).modifyLookupAttributes(
				new Entry[] { target }, new Entry[] { null });

	  // 
	  setupNotify();

	  int index = root.getIndex(node);
	  root.remove(node);
	  model.nodesWereRemoved(root, new int[] {index}, new Object[] {node});
	  node = null;
	} catch (Throwable t) {
	  logger.log(Level.INFO, "attribute removal failed", t);
	  JOptionPane.showMessageDialog(AttributeTreePanel.this,
					t.getMessage(),
					t.getClass().getName(),
					JOptionPane.ERROR_MESSAGE);
	}
      }
    }

    private Entry cloneEntry(Entry attr) {
      try {
	Class realClass = attr.getClass();
	Entry template = (Entry) realClass.newInstance();

	Field[] f = realClass.getFields();
	for(int i = 0; i < f.length; i++) {
	  if(! usableField(f[i]))
	    continue;
	  f[i].set(template, f[i].get(attr));
	}

	return template;
      } catch (Throwable t) {
	logger.log(Level.INFO, "duplicating entry failed", t);
      }
      return null;
    }

    // from EntryRep
    private boolean usableField(Field field) {
      Class desc = field.getDeclaringClass();

      if(desc.isPrimitive()) {
	throw new IllegalArgumentException("primitive types not allowed in an Entry");
      }

      // skip anything that isn't a public per-object mutable field
      int mods = field.getModifiers();
      return (0 == (mods & (Modifier.TRANSIENT | Modifier.STATIC | Modifier.FINAL)));
    }

    private Entry generateTemplate(Entry attr) {
      try {
	Class realClass = attr.getClass();
	Entry template = (Entry) realClass.newInstance();

	Field[] f = realClass.getFields();
	for(int i = 0; i < f.length; i++)
	  f[i].set(template, null);

	return template;
      } catch (Throwable t) {
	logger.log(Level.INFO, "instantiating template failed", t);
      }
      return null;
    }

    class DoubleClicker extends MouseAdapter {
      AttributeTreePanel parent;

      public DoubleClicker(AttributeTreePanel parent){
	this.parent = parent;
      }

      public void mouseClicked(MouseEvent ev){
	if(ev.getClickCount() >= 2){
	  JTree tree = (JTree) ev.getSource();
	  TreePath path = tree.getPathForLocation(ev.getX(), ev.getY());
	  if(path == null)
	    return;
	  ObjectNode node = (ObjectNode) path.getLastPathComponent();

	  if(node.isLeaf()){
	    if(! node.isControllable()){
	      JOptionPane.showMessageDialog(AttributeTreePanel.this,
					    "This attribute is under service provider's control.",
					    "Warning",
					    JOptionPane.WARNING_MESSAGE);
	    } else if(node.isEditable() &&
		      ((ObjectNode) node.getParent()).isEntryTop())
	    {
	      parent.editField(node);
	    } else {
	      JOptionPane.showMessageDialog(AttributeTreePanel.this,
					    "This field is not editable.",
					    "Warning",
					    JOptionPane.WARNING_MESSAGE);
	    }
	  }

	  tree.scrollPathToVisible(path);
	}
      }
    }
  }

  abstract class ListerFrame extends JFrame {

    private JList listBox;
    private JScrollPane scrollPane;
    protected DefaultListModel model = new DefaultListModel();
    private DefaultListModel dummyModel = new DefaultListModel();	// to keep away from Swing's bug

    private JButton addButton;
    private JButton removeButton;
    private JButton closeButton;

    public ListerFrame(String title) {
      super(title);

      getContentPane().setLayout(new BorderLayout());

      // create the initial list
      listBox = new JList(model);
      listBox.setFixedCellHeight(20);
      scrollPane = new JScrollPane(listBox);
      getContentPane().add(scrollPane, "Center");
      //resetListModel();

      // Create the controls 
      JPanel buttonPanel = new JPanel();
      addButton = new JButton("Add");
      addButton.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  String result = JOptionPane.showInputDialog(ListerFrame.this, getAddMessage());

	  if(result != null){
	    StringTokenizer st = new StringTokenizer(result);
	    String[] tokens = new String[st.countTokens()];
	    for(int i = 0; i < tokens.length; i++)
	      tokens[i] = st.nextToken().trim();

	    addItems(tokens);
	    resetListModel();
	    scrollPane.validate();
	  }
	}
      }));
      buttonPanel.add(addButton);

      removeButton = new JButton("Remove");
      removeButton.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  Object[] selected = listBox.getSelectedValues();

	  if(selected == null || selected.length == 0){
	    // no items are selected
	    JOptionPane.showMessageDialog(ListerFrame.this,
					  "No items are selected",
					  "Warning",
					  JOptionPane.WARNING_MESSAGE);
	    return;
	  }

	  int result = JOptionPane.showConfirmDialog(ListerFrame.this,
						     getRemoveMessage(selected),
						     "Query",
						     JOptionPane.YES_NO_OPTION);
	
	  if(result == JOptionPane.YES_OPTION){
	    removeItems(selected);
	    resetListModel();
	    scrollPane.validate();
	  }
	}
      }));
      buttonPanel.add(removeButton);

      closeButton = new JButton("Close");
      closeButton.addActionListener(browser.wrap(new ActionListener() {
	public void actionPerformed(ActionEvent ev) {
	  setVisible(false);
	}
      }));
      buttonPanel.add(closeButton);
      getContentPane().add(buttonPanel, "South");

      pack();
    }

    public void showFrame() {
      // init list data
      resetListModel();

      // center in parent frame
      Rectangle bounds = ServiceEditor.this.getBounds();
      Dimension dialogSize = getPreferredSize();

      setLocation(bounds.x + (bounds.width - dialogSize.width)/ 2,
		  bounds.y + (bounds.height - dialogSize.height)/2);

      setVisible(true);
    }

    private void resetListModel() {
      //listBox.setModel(null);
      listBox.setModel(dummyModel);	// to keep away from NullException (Swing's bug)

      model.removeAllElements();
      initListModel();

      listBox.setModel(model);
      listBox.clearSelection();
      listBox.ensureIndexIsVisible(0);
      listBox.repaint();
      listBox.revalidate();
    }

    protected abstract void initListModel();

    protected abstract String getAddMessage();

    protected abstract String getRemoveMessage(Object[] items);

    protected abstract void addItems(String[] items);

    protected abstract void removeItems(Object[] items);
  }

  class GroupLister extends ListerFrame {

    public GroupLister(String title) {
      super(title);
    }

    protected void initListModel() {
	if (!(admin instanceof JoinAdmin)) {
	    return;
	}

      try {
	String[] groups = ((JoinAdmin) admin).getLookupGroups();
	for(int i = 0; i < groups.length; i++) {
	  model.addElement(new GroupItem(groups[i]));
	}
      } catch (Throwable t) {
	logger.log(Level.INFO, "obtaining groups failed", t);
      }
    }

    protected String getAddMessage() {
      return "Enter adding group(s)";
    }

    protected String getRemoveMessage(Object[] items) {
      StringBuffer msg = new StringBuffer();
      if(items.length > 1)
	msg.append("Remove these groups : ");
      else
	msg.append("Remove a group : ");
      for(int i = 0; i < items.length; i++) {
	if(i != 0)
	  msg.append(", ");
	msg.append(((GroupItem) items[i]).toString());
      }
      return msg.toString();
    }

    protected void addItems(String[] items) {
      // check "public"
      String[] grps = new String[items.length];
      for(int i = 0; i < items.length; i++)
	grps[i] = new GroupItem(items[i]).group;

      try {
	((JoinAdmin) admin).addLookupGroups(grps);
      } catch (Throwable t) {
	logger.log(Level.INFO, "adding groups failed", t);
      }
    }

    protected void removeItems(Object[] items) {
      String[] grps = new String[items.length];
      for(int i = 0; i < items.length; i++)
	grps[i] = ((GroupItem) items[i]).group;

      try {
	((JoinAdmin) admin).removeLookupGroups(grps);
      } catch (Throwable t) {
	logger.log(Level.INFO, "removing groups failed", t);
      }
    }
  }

  class MemberGroupLister extends ListerFrame {

    public MemberGroupLister(String title) {
      super(title);
    }

    protected void initListModel() {
      try {
	String[] groups = ((DiscoveryAdmin) admin).getMemberGroups();
	for(int i = 0; i < groups.length; i++) {
	  model.addElement(new GroupItem(groups[i]));
	}
      } catch (Throwable t) {
	logger.log(Level.INFO, "obtaining groups failed", t);
      }
    }

    protected String getAddMessage() {
      return "Enter adding group(s)";
    }

    protected String getRemoveMessage(Object[] items) {
      StringBuffer msg = new StringBuffer();
      if(items.length > 1)
	msg.append("Remove these groups : ");
      else
	msg.append("Remove a group : ");
      for(int i = 0; i < items.length; i++) {
	if(i != 0)
	  msg.append(", ");
	msg.append(((GroupItem) items[i]).toString());
      }
      return msg.toString();
    }

    protected void addItems(String[] items) {
      // check "public"
      String[] grps = new String[items.length];
      for(int i = 0; i < items.length; i++)
	grps[i] = new GroupItem(items[i]).group;

      try {
	((DiscoveryAdmin) admin).addMemberGroups(grps);
      } catch (Throwable t) {
	logger.log(Level.INFO, "adding groups failed", t);
      }
    }

    protected void removeItems(Object[] items) {
      String[] grps = new String[items.length];
      for(int i = 0; i < items.length; i++)
	grps[i] = ((GroupItem) items[i]).group;

      try {
	((DiscoveryAdmin) admin).removeMemberGroups(grps);
      } catch (Throwable t){
	logger.log(Level.INFO, "removing groups failed", t);
      }
    }
  }

  class GroupItem {
    public String group;

    public GroupItem(String group) {
      if(group.equals("public"))
	this.group = "";
      else
	this.group = group;
    }

    public String toString() {
      if("".equals(group))
	return "public";
      else
	return group;
    }
  }

  class LocatorLister extends ListerFrame {

    public LocatorLister(String title) {
      super(title);
    }

    protected void initListModel() {
	if (!(admin instanceof JoinAdmin)) {
	    return;
	}

      try {
	LookupLocator[] locators = ((JoinAdmin) admin).getLookupLocators();
	for(int i = 0; i < locators.length; i++) {
	  model.addElement(locators[i]);
	}
      } catch (Throwable t) {
	logger.log(Level.INFO, "obtaining locators failed", t);
      }
    }

    protected String getAddMessage() {
      return "Enter a new locator's URL";
    }

    protected String getRemoveMessage(Object[] items) {
      StringBuffer msg = new StringBuffer();
      if(items.length > 1)
	msg.append("Remove these locators : ");
      else
	msg.append("Remove a locator : ");
      for(int i = 0; i < items.length; i++) {
	if(i != 0)
	  msg.append(", ");
	msg.append(items[i].toString());
      }
      return msg.toString();
    }

    protected void addItems(String[] items) {
      LookupLocator[] locs = new LookupLocator[items.length];
      for(int i = 0; i < items.length; i++) {
	try {
	  locs[i] = new LookupLocator(items[i]);
	} catch (MalformedURLException e) {
	  JOptionPane.showMessageDialog(LocatorLister.this,
					"\"" + items[i] + "\": " +
					e.getMessage(),
					"Bad Locator",
					JOptionPane.WARNING_MESSAGE);
	  return;
	}
      }

      try {
	((JoinAdmin) admin).addLookupLocators(locs);
      } catch (Throwable t){
	logger.log(Level.INFO, "adding locators failed", t);
      }
    }

    protected void removeItems(Object[] items) {
      LookupLocator[] locs = new LookupLocator[items.length];
      for(int i = 0; i < items.length; i++)
	locs[i] = (LookupLocator) items[i];

      try {
	((JoinAdmin) admin).removeLookupLocators(locs);
      } catch (Throwable t) {
	logger.log(Level.INFO, "removing locators failed", t);
      }
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

	private ServiceEditor.UIDescriptorPopup popup;
	private ServiceItem serviceItem;

	public MouseReceiver(ServiceItem aServiceItem,
			ServiceEditor.UIDescriptorPopup popup) {
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

    private void higlightSelection(MouseEvent event) {
	attrPanel.tree.setSelectionPath(attrPanel.tree.getPathForLocation(
	    event.getX(), event.getY()));
    }

    private ServiceEditor.UIDescriptorPopup uiDescriptorPopup() {
	return new ServiceEditor.UIDescriptorPopup();
    }
}
