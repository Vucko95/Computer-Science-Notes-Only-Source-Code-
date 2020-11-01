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
import com.sun.jini.outrigger.JavaSpaceAdmin;
import com.sun.jini.proxy.BasicProxyTrustVerifier;
import com.sun.jini.start.LifeCycle;
import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.IOException;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationHandler;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.lang.reflect.Modifier;
import java.net.MalformedURLException;
import java.rmi.server.ExportException;
import java.security.AccessController;
import java.security.PrivilegedActionException;
import java.security.PrivilegedExceptionAction;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.security.auth.Subject;
import javax.security.auth.login.LoginContext;
import javax.security.auth.login.LoginException;
import javax.swing.BorderFactory;
import javax.swing.DefaultListModel;
import javax.swing.Icon;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.ListCellRenderer;
import javax.swing.SwingUtilities;
import javax.swing.border.TitledBorder;
import javax.swing.event.MenuEvent;
import javax.swing.event.MenuListener;
import javax.swing.event.PopupMenuEvent;
import javax.swing.event.PopupMenuListener;
import net.jini.admin.Administrable;
import net.jini.admin.JoinAdmin;
import net.jini.config.Configuration;
import net.jini.config.ConfigurationException;
import net.jini.config.ConfigurationProvider;
import net.jini.config.EmptyConfiguration;
import net.jini.config.NoSuchEntryException;
import net.jini.core.constraint.MethodConstraints;
import net.jini.core.discovery.LookupLocator;
import net.jini.core.entry.Entry;
import net.jini.core.event.EventRegistration;
import net.jini.core.event.RemoteEvent;
import net.jini.core.event.RemoteEventListener;
import net.jini.core.lease.Lease;
import net.jini.core.lookup.ServiceID;
import net.jini.core.lookup.ServiceItem;
import net.jini.core.lookup.ServiceMatches;
import net.jini.core.lookup.ServiceRegistrar;
import net.jini.core.lookup.ServiceTemplate;
import net.jini.discovery.Constants;
import net.jini.discovery.ConstrainableLookupLocator;
import net.jini.discovery.DiscoveryEvent;
import net.jini.discovery.DiscoveryGroupManagement;
import net.jini.discovery.DiscoveryListener;
import net.jini.discovery.DiscoveryLocatorManagement;
import net.jini.discovery.DiscoveryManagement;
import net.jini.discovery.LookupDiscoveryManager;
import net.jini.export.Exporter;
import net.jini.jeri.BasicILFactory;
import net.jini.jeri.BasicJeriExporter;
import net.jini.jeri.tcp.TcpServerEndpoint;
import net.jini.lease.LeaseListener;
import net.jini.lease.LeaseRenewalEvent;
import net.jini.lease.LeaseRenewalManager;
import net.jini.lookup.DiscoveryAdmin;
import net.jini.lookup.ui.factory.JFrameFactory;
import net.jini.lookup.entry.UIDescriptor;
import net.jini.security.BasicProxyPreparer;
import net.jini.security.ProxyPreparer;
import net.jini.security.Security;
import net.jini.security.SecurityContext;
import net.jini.security.TrustVerifier;
import net.jini.security.proxytrust.ServerProxyTrust;
import net.jini.space.JavaSpace05;
import net.jini.space.JavaSpace;

/*
 * (From the original JTSK browser class)
 * This is not great user interface design. It was a quick-and-dirty hack
 * and an experiment in on-the-fly menu construction, and it's still
 * here because we've never had time to do anything better.
 */
/**
 * Example service browser. See the package documentation for details.
 * 
 * Note: This code is part of a comprehensive tutorial - Be sure to have a look
 * at the 'README.md' file in the root of the parent 'river-examples' project
 * for instructions on how to build and view the complete tutorial.
 * 
 */
public class Browser extends JFrame {
    static final String BROWSER = Browser.class.getPackage().getName();
    static final Logger logger = Logger.getLogger(BROWSER);

    private transient SecurityContext ctx;
    private transient ClassLoader ccl;
    transient Configuration config;
    private transient DiscoveryGroupManagement disco;
    private transient ServiceRegistrar lookup = null;
    private transient Object eventSource = null;
    private transient long eventID = 0;
    private transient long seqNo = Long.MAX_VALUE;
    private transient ActionListener exiter;
    private transient ServiceTemplate tmpl;
    private transient Listener listen;
    private transient LookupListener adder;
    private transient Lease elease = null;
    transient ProxyPreparer leasePreparer;
    transient ProxyPreparer servicePreparer;
    transient ProxyPreparer adminPreparer;
    private transient MethodConstraints locatorConstraints;
    transient LeaseRenewalManager leaseMgr;
    private transient LeaseListener lnotify;
    private transient List ignoreInterfaces;
    private transient JTextArea text;
    private transient JMenu registrars;
    private transient JCheckBoxMenuItem esuper;
    private transient JCheckBoxMenuItem ssuper;
    private transient JCheckBoxMenuItem sclass;
    private transient boolean isAdmin;
    private volatile transient boolean autoConfirm;
    private transient JList list;
    private transient DefaultListModel listModel;
    private transient DefaultListModel dummyModel = new DefaultListModel();
    private transient JScrollPane listScrollPane;

    /**
     * Creates an instance with the given action listener for the Exit
     * menu item and the given configuration. The action listener defaults
     * to an instance of {@link Exit Exit}. The action listener can be
     * overridden by a configuration entry. The configuration
     * defaults to an empty configuration.
     *
     * @param exiter the action listener, or <code>null</code>
     * @param config the configuration, or <code>null</code>
     */
    public Browser(ActionListener exiter, Configuration config)
	throws ConfigurationException, IOException
    {
	if (exiter == null)
	    exiter = new Exit();
	if (config == null)
	    config = EmptyConfiguration.INSTANCE;
	init(exiter, config);
    }

    private void init(ActionListener exiter, Configuration config)
	throws ConfigurationException, IOException
    {
	exiter = wrap((ActionListener)
	    Config.getNonNullEntry(config, BROWSER, "exitActionListener",
				   ActionListener.class, exiter));
	this.exiter = exiter;
	this.config = config;
	ctx = Security.getContext();
	ccl = Thread.currentThread().getContextClassLoader();
	leaseMgr = (LeaseRenewalManager)
	    Config.getNonNullEntry(config, BROWSER, "leaseManager",
				   LeaseRenewalManager.class,
				   new LeaseRenewalManager(config));
	isAdmin = ((Boolean) config.getEntry(
				 BROWSER, "folderView",
				 boolean.class, Boolean.TRUE)).booleanValue();
	leasePreparer = (ProxyPreparer)
	    Config.getNonNullEntry(config, BROWSER, "leasePreparer",
				   ProxyPreparer.class,
				   new BasicProxyPreparer());
	servicePreparer = (ProxyPreparer)
	    Config.getNonNullEntry(config, BROWSER, "servicePreparer",
				   ProxyPreparer.class,
				   new BasicProxyPreparer());
	adminPreparer = (ProxyPreparer)
	    Config.getNonNullEntry(config, BROWSER, "adminPreparer",
				   ProxyPreparer.class,
				   new BasicProxyPreparer());
	locatorConstraints = (MethodConstraints)
	    config.getEntry(BROWSER, "locatorConstraints",
			    MethodConstraints.class, null);
	ignoreInterfaces = Arrays.asList((String[])
	    Config.getNonNullEntry(config, BROWSER, "uninterestingInterfaces",
				   String[].class,
				   new String[]{
			    "java.io.Serializable",
			    "java.rmi.Remote",
			    "net.jini.admin.Administrable",
			    "net.jini.core.constraint.RemoteMethodControl",
			    "net.jini.id.ReferentUuid",
			    "net.jini.security.proxytrust.TrustEquivalence"}));
	autoConfirm = ((Boolean) config.getEntry(
					BROWSER, "autoConfirm", boolean.class,
	    				Boolean.FALSE)).booleanValue();
	listen = new Listener();
	try {
	    DiscoveryManagement disco = (DiscoveryManagement)
		Config.getNonNullEntry(config, BROWSER, "discoveryManager",
				       DiscoveryManagement.class);
	    if (!(disco instanceof DiscoveryGroupManagement)) {
		throw new ConfigurationException(
			      "discoveryManager does not " +
			      " support DiscoveryGroupManagement");
	    } else if (!(disco instanceof DiscoveryLocatorManagement)) {
		throw new ConfigurationException(
			      "discoveryManager does not " +
			      " support DiscoveryLocatorManagement");
	    }
	    this.disco = (DiscoveryGroupManagement) disco;
	    String[] groups = this.disco.getGroups();
	    if (groups == null || groups.length > 0) {
		throw new ConfigurationException(
			      "discoveryManager cannot have initial groups");
	    }
	    if (((DiscoveryLocatorManagement) disco).getLocators().length > 0)
	    {
		throw new ConfigurationException(
			      "discoveryManager cannot have initial locators");
	    }
	} catch (NoSuchEntryException e) {
	    disco = new LookupDiscoveryManager(new String[0],
					       new LookupLocator[0], null,
					       config);
	}
	disco.setGroups((String[]) config.getEntry(BROWSER,
						   "initialLookupGroups",
						   String[].class,
						   null));
	((DiscoveryLocatorManagement) disco).setLocators((LookupLocator[])
	    Config.getNonNullEntry(config, BROWSER, "initialLookupLocators",
				   LookupLocator[].class,
				   new LookupLocator[0]));
	tmpl = new ServiceTemplate(null, new Class[0], new Entry[0]);
	setTitle("Service Browser");
	JMenuBar bar = new JMenuBar();
	JMenu file = new JMenu("File");
	JMenuItem allfind = new JMenuItem("Find All");
	allfind.addActionListener(wrap(new AllFind()));
	file.add(allfind);
	JMenuItem pubfind = new JMenuItem("Find Public");
	pubfind.addActionListener(wrap(new PubFind()));
	file.add(pubfind);
	JMenuItem multifind = new JMenuItem("Find By Group...");
	multifind.addActionListener(wrap(new MultiFind()));
	file.add(multifind);
	JMenuItem unifind = new JMenuItem("Find By Address...");
	unifind.addActionListener(wrap(new UniFind()));
	file.add(unifind);
	if(! isAdmin){
	    JMenuItem show = new JMenuItem("Show Matches");
	    show.addActionListener(wrap(new Show()));
	    file.add(show);
	}
	JMenuItem reset = new JMenuItem("Reset");
	reset.addActionListener(wrap(new Reset()));
	file.add(reset);
	JMenuItem exit = new JMenuItem("Exit");
	exit.addActionListener(exiter);
	file.add(exit);
	bar.add(file);
	addWindowListener(new Exiter());
	registrars = new JMenu("Registrar");
	addNone(registrars);
	bar.add(registrars);
	JMenu options = new JMenu("Options");
	esuper = new JCheckBoxMenuItem("Attribute supertypes", false);
	options.add(esuper);
	ssuper = new JCheckBoxMenuItem("Service supertypes", false);
	options.add(ssuper);
	sclass = new JCheckBoxMenuItem("Service classes", false);
	options.add(sclass);
	bar.add(options);
	JMenu services = new JMenu("Services");
	services.addMenuListener(wrap(new Services(services)));
	bar.add(services);
	JMenu attrs = new JMenu("Attributes");
	attrs.addMenuListener(wrap(new Entries(attrs)));
	bar.add(attrs);
	setJMenuBar(bar);

	getContentPane().setLayout(new BorderLayout());
	int textRows = 8;
	if(isAdmin){
	  textRows = 4;
	    JPanel bpanel = new JPanel();
	    bpanel.setLayout(new BorderLayout());

	    TitledBorder border = BorderFactory.createTitledBorder("Matching Services");
	    border.setTitlePosition(TitledBorder.TOP);
	    border.setTitleJustification(TitledBorder.LEFT);
	    bpanel.setBorder(border);
      
	    listModel = new DefaultListModel();
	    list = new JList(listModel);
	    list.setFixedCellHeight(20);
	    list.setCellRenderer((ListCellRenderer)
		   wrap(new ServiceItemRenderer(), ListCellRenderer.class));
	    list.addMouseListener(
			     wrap(new MouseReceiver(new ServiceListPopup())));
	    listScrollPane = new JScrollPane(list);
	    bpanel.add(listScrollPane, "Center");
	    getContentPane().add(bpanel, "South");
	}
	text = new JTextArea(genText(false), textRows, 40);
	text.setEditable(false);
	JScrollPane scroll = new JScrollPane(text);
	getContentPane().add(scroll, "Center");

	validate();
	SwingUtilities.invokeLater(wrap(new Runnable() {
	    public void run() {
		pack();
		show();
	    }
	}));
	adder = new LookupListener();
	lnotify = new LeaseNotify();
	((DiscoveryManagement) disco).addDiscoveryListener(adder);
    }

    /**
     * Creates an instance with the given command line arguments and
     * life cycle callback. See the package documentation for details
     * of the command line arguments. The default action listener for
     * the Exit menu item calls the {@link #dispose dispose} method of
     * this instance, cancels any lookup service event registration lease,
     * unexports any remote event listener, and calls the
     * {@link LifeCycle#unregister unregister} method of the life cycle
     * callback. The action listener can be overridden by a configuration
     * entry.
     *
     * @param args command line arguments
     * @param lc life cycle callback, or <code>null</code>.
     */
    public Browser(String[] args, final LifeCycle lc)
	throws ConfigurationException, LoginException, IOException
    {
	final ActionListener exiter = new ActionListener() {
		public void actionPerformed(ActionEvent ev) {
		    Browser.this.dispose();
		    cancelLease();
		    listen.unexport();
		    if (lc != null)
			lc.unregister(Browser.this);
		}
	    };
	final Configuration config =
	    ConfigurationProvider.getInstance(
				    args, Browser.class.getClassLoader());
	LoginContext login =
	    (LoginContext) config.getEntry(BROWSER, "loginContext",
					   LoginContext.class, null);
	if (login == null) {
	    init(exiter, config);
	} else {
	    login.login();
	    try {
		Subject.doAsPrivileged(
		    login.getSubject(),
		    new PrivilegedExceptionAction() {
			    public Object run()
				throws ConfigurationException, IOException
			    {
				init(exiter, config);
				return null;
			    }
			},
		    null);
	    } catch (PrivilegedActionException pae) {
		Exception e = pae.getException();
		if (e instanceof ConfigurationException)
		    throw (ConfigurationException) e;
		throw (IOException) e;
	    }
	}
    }

    private static String typeName(Class type) {
	String name = type.getName();
	int i = name.lastIndexOf('.');
	if (i >= 0)
	    name = name.substring(i + 1);
	return name;
    }

    private void setText(boolean match) {
	text.setText(genText(match));
    }

    private String genText(boolean match) {
	StringBuffer buf = new StringBuffer();
	if (tmpl.serviceTypes.length > 0) {
	    for (int i = 0; i < tmpl.serviceTypes.length; i++) {
		buf.append(tmpl.serviceTypes[i].getName());
		buf.append("\n");
	    }
	}
	if (tmpl.attributeSetTemplates.length > 0)
	    genEntries(buf, tmpl.attributeSetTemplates, false);
	genMatches(buf, match);
	return buf.toString();
    }

    private void genEntries(StringBuffer buf,
			    Entry[] entries,
			    boolean showNulls)
    {
	for (int i = 0; i < entries.length; i++) {
	    Entry ent = entries[i];
	    if (ent == null) {
		buf.append("null\n");
		continue;
	    }
	    buf.append(typeName(ent.getClass()));
	    buf.append(": ");
	    try {
		Field[] fields = ent.getClass().getFields();
		for (int j = 0; j < fields.length; j++) {
		    if (!valid(fields[j]))
			continue;
		    Object val = fields[j].get(ent);
		    if (val != null || showNulls) {
			buf.append(fields[j].getName());
			buf.append("=");
			buf.append(val);
			buf.append(" ");
		    }
		}
	    } catch (Exception e) {
	    }
	    buf.append("\n");
	}
    }

    private static boolean valid(Field f) {
	return (f.getModifiers() & (Modifier.STATIC|Modifier.FINAL)) == 0;
    }

    private void genMatches(StringBuffer buf, boolean match) {
        if(isAdmin) {
	    list.setModel(dummyModel);	// to keep away from Swing's bug
	    
	    listModel.removeAllElements();
	    list.clearSelection();
	    list.ensureIndexIsVisible(0);
	    list.repaint();
	    list.revalidate();
	    listScrollPane.validate();
	}
	if (lookup == null) {
	    String[] groups = disco.getGroups();
	    if (groups == null) {
		buf.append("Groups: <all>\n");
	    } else if (groups.length > 0) {
		buf.append("Groups:");
		for (int i = 0; i < groups.length; i++) {
		    String group = groups[i];
		    if (group.length() == 0)
			group = "public";
		    buf.append(" ");
		    buf.append(group);
		}
		buf.append("\n");
	    }
	    LookupLocator[] locators =
		((DiscoveryLocatorManagement) disco).getLocators();
	    if (locators.length > 0) {
		buf.append("Addresses:");
		for (int i = 0; i < locators.length; i++) {
		    buf.append(" ");
		    buf.append(locators[i].getHost());
		    if (locators[i].getPort() != Constants.discoveryPort) {
			buf.append(":");
			buf.append(locators[i].getPort());
		    }
		}
		buf.append("\n");
	    }
	    if (!(registrars.getMenuComponent(0) instanceof
		  JRadioButtonMenuItem))
	    {
		buf.append("No registrars to select");
		return;
	    }
	    int n = registrars.getMenuComponentCount();
	    if (n == 1) {
		buf.append("1 registrar, not selected");
	    } else {
		buf.append(n);
		buf.append(" registrars, none selected");
	    }
	    return;
	}
	ServiceMatches matches;
	try {
	    matches = lookup.lookup(tmpl, (match || isAdmin) ? 1000 : 0);
	} catch (Throwable t) {
	    logger.log(Level.INFO, "lookup failed", t);
	    return;
	}

	if (matches.items != null) {
	    for (int i = 0; i < matches.items.length; i++) {
		if (matches.items[i].service != null) {
		    try {
			matches.items[i].service =
			    servicePreparer.prepareProxy(
						     matches.items[i].service);
		    } catch (Throwable t) {
			logger.log(Level.INFO, "proxy preparation failed", t);
			matches.items[i].service = null;
		    }
		}
	    }
	}

	if(isAdmin){
	    for (int i = 0; i < matches.items.length; i++)
	        listModel.addElement(new ServiceListItem(matches.items[i]));
	    list.setModel(listModel);
	    list.clearSelection();
	    list.ensureIndexIsVisible(0);
	    list.repaint();
	    list.revalidate();
	    listScrollPane.validate();
	}

	if (!match &&
	    tmpl.serviceTypes.length == 0 &&
	    tmpl.attributeSetTemplates.length == 0)
	{
	    buf.append("Total services registered: ");
	    buf.append(matches.totalMatches);
	    return;
	}
	buf.append("\nMatching services: ");
	buf.append(matches.totalMatches);

	if(! isAdmin){
	    if (!match)
	        return;
	    buf.append("\n\n");
	    for (int i = 0; i < matches.items.length; i++) {
	        ServiceItem item = matches.items[i];
		buf.append("Service ID: ");
		buf.append(item.serviceID);
		buf.append("\n");
		buf.append("Service instance: ");
		buf.append(item.service);
		buf.append("\n");
		genEntries(buf, item.attributeSets, true);
		buf.append("\n");
	    }
	}
    }

    private static void addNone(JMenu menu) {
	JMenuItem item = new JMenuItem("(none)");
	item.setEnabled(false);
	menu.add(item);
    }

    private void addOne(ServiceRegistrar registrar) {
	LookupLocator loc;
	try {
	    loc = registrar.getLocator();
	} catch (Throwable t) {
	    logger.log(Level.INFO, "obtaining locator failed", t);
	    return;
	}
	String host = loc.getHost();
	if (loc.getPort() != Constants.discoveryPort)
	    host += ":" + loc.getPort();
	JRadioButtonMenuItem reg =
	    new RegistrarMenuItem(host, registrar.getServiceID());
	reg.addActionListener(wrap(new Lookup(registrar)));
	if (!(registrars.getMenuComponent(0)
	      instanceof JRadioButtonMenuItem))
	    registrars.removeAll();
	registrars.add(reg);
    }

    private static class RegistrarMenuItem extends JRadioButtonMenuItem {
	ServiceID id;

	RegistrarMenuItem(String host, ServiceID id) {
	    super(host);
	    this.id = id;
	}
    }

    static Class[] getInterfaces(Class c) {
	Set set = new HashSet();
	for ( ; c != null; c = c.getSuperclass()) {
	    Class[] ifs = c.getInterfaces();
	    for (int i = ifs.length; --i >= 0; )
		set.add(ifs[i]);
	}
	return (Class[]) set.toArray(new Class[set.size()]);
    }

    private class Services implements MenuListener {
	private JMenu menu;

	public Services(JMenu menu) {
	    this.menu = menu;
	}

	public void menuSelected(MenuEvent ev) {
	    if (lookup == null) {
		addNone(menu);
		return;
	    }
	    Vector all = new Vector();
	    Class[] types = tmpl.serviceTypes;
	    for (int i = 0; i < types.length; i++) {
		all.addElement(types[i]);
		JCheckBoxMenuItem item =
		    new JCheckBoxMenuItem(types[i].getName(), true);
		    item.addActionListener(wrap(new Service(types[i], i)));
		    menu.add(item);
	    }
	    try {
		types = lookup.getServiceTypes(tmpl, "");
	    } catch (Throwable t) {
		failure(t);
		return;
	    }
	    if (types == null) {
		if (all.isEmpty())
		    addNone(menu);
		return;
	    }
	    for (int i = 0; i < types.length; i++) {
		Class[] stypes;
		if (types[i] == null) {
		    all.addElement(new JMenuItem("null"));
		    continue;
		}
		if (types[i].isInterface() || sclass.getState()) {
		    stypes = new Class[]{types[i]};
		} else {
		    stypes = getInterfaces(types[i]);
		}
		for (int j = 0; j < stypes.length; j++) {
		    addType(stypes[j], all);
		}
	    }
	}

	private void addType(Class type, Vector all) {
	    if (all.contains(type))
		return;
	    all.addElement(type);
	    JCheckBoxMenuItem item =
		new JCheckBoxMenuItem(type.getName(), false);
	    item.addActionListener(wrap(new Service(type, -1)));
	    menu.add(item);
	    if (!ssuper.getState())
		return;
	    if (sclass.getState() && type.getSuperclass() != null)
		addType(type.getSuperclass(), all);
	    Class[] stypes = type.getInterfaces();
	    for (int i = 0; i < stypes.length; i++) {
		addType(stypes[i], all);
	    }
	}

	public void menuDeselected(MenuEvent ev) {
	    menu.removeAll();
	}

	public void menuCanceled(MenuEvent ev) {
	    menu.removeAll();
	}
    }

    /**
     * Indicates whether auto confirm is enabled to prevent from the user
     * having to click the 'Yes' button in the a popup window to confirm a
     * modification to the service browser pane is allowed to take place as
     * result of a service being removed, or its lookup attributes being
     * changed.
     *
     * @return <code>true</code> in case no popup is required to have the user
     *         confirm the modifications, <code>false</code> otherwise
     */
    boolean isAutoConfirm() {
	return autoConfirm;
    }

    ActionListener wrap(ActionListener l) {
	return (ActionListener) wrap((Object) l, ActionListener.class);
    }

    MenuListener wrap(MenuListener l) {
	return (MenuListener) wrap((Object) l, MenuListener.class);
    }

    MouseListener wrap(MouseListener l) {
	return (MouseListener) wrap((Object) l, MouseListener.class);
    }

    WindowListener wrap(WindowListener a) {
	return (WindowListener) wrap((Object) a, WindowListener.class);
    }

    Runnable wrap(Runnable r) {
	return (Runnable) wrap((Object) r, Runnable.class);
    }

    private Object wrap(Object obj, Class iface) {
	return Proxy.newProxyInstance(obj.getClass().getClassLoader(),
				      new Class[]{iface}, new Handler(obj));
    }

    private class Handler implements InvocationHandler {
	private final Object obj;

	Handler(Object obj) {
	    this.obj = obj;
	}

	public Object invoke(Object proxy,
			     final Method method,
			     final Object[] args)
	    throws Throwable
	{
	    if (method.getDeclaringClass() == Object.class) {
		if ("equals".equals(method.getName()))
		    return Boolean.valueOf(proxy == args[0]);
		else if ("hashCode".equals(method.getName()))
		    return new Integer(System.identityHashCode(proxy));
	    }
	    try {
		return AccessController.doPrivileged(
		    ctx.wrap(new PrivilegedExceptionAction() {
			public Object run() throws Exception {
			    Thread t = Thread.currentThread();
			    ClassLoader occl = t.getContextClassLoader();
			    try {
				t.setContextClassLoader(ccl);
				try {
				    return method.invoke(obj, args);
				} catch (InvocationTargetException e) {
				    Throwable tt = e.getCause();
				    if (tt instanceof Error)
					throw (Error) tt;
				    throw (Exception) tt;
				}
			    } finally {
				t.setContextClassLoader(occl);
			    }
			}
		    }), ctx.getAccessControlContext());
	    } catch (PrivilegedActionException e) {
		throw e.getCause();
	    }
	}
    }

    private class Show implements ActionListener {

	public void actionPerformed(ActionEvent ev) {
	    setText(true);
	}
    }

    private void resetTmpl() {
	tmpl.serviceTypes = new Class[0];
	tmpl.attributeSetTemplates = new Entry[0];
	update();
    }

    private void reset() {
	ssuper.setState(false);
	esuper.setState(false);
	sclass.setState(false);
	resetTmpl();
    }

    private class Reset implements ActionListener {

	public void actionPerformed(ActionEvent ev) {
	    reset();
	}
    }

    private class Service implements ActionListener {
	private Class type;
	private int index;

	public Service(Class type, int index) {
	    this.type = type;
	    this.index = index;
	}

	public void actionPerformed(ActionEvent ev) {
	    int z = tmpl.serviceTypes.length;
	    Class[] newTypes;
	    if (index < 0) {
		newTypes = new Class[z + 1];
		System.arraycopy(tmpl.serviceTypes, 0, newTypes, 0, z);
		newTypes[z] = type;
	    } else {
		newTypes = new Class[z - 1];
		System.arraycopy(tmpl.serviceTypes, 0,
				 newTypes, 0, index);
		System.arraycopy(tmpl.serviceTypes, index + 1,
				 newTypes, index, z - index - 1);
	    }
	    tmpl.serviceTypes = newTypes;
	    update();
	}
    }

    private class Entries implements MenuListener {
	private JMenu menu;

	public Entries(JMenu menu) {
	    this.menu = menu;
	}

	public void menuSelected(MenuEvent ev) {
	    if (lookup == null) {
		addNone(menu);
		return;
	    }
	    Entry[] attrs = tmpl.attributeSetTemplates;
	    for (int i = 0; i < attrs.length; i++) {
		Class type = attrs[i].getClass();
		JMenu item = new JMenu(typeName(type));
		item.addMenuListener(new Fields(item, i));
		menu.add(item);
	    }
	    Class[] types;
	    try {
		types = lookup.getEntryClasses(tmpl);
	    } catch (Throwable t) {
		failure(t);
		return;
	    }
	    if (types == null) {
		if (attrs.length == 0)
		    addNone(menu);
		return;
	    }
	    Vector all = new Vector();
	    for (int i = 0; i < types.length; i++) {
		if (types[i] == null)
		    menu.add(new JMenuItem("null"));
		else
		    addType(types[i], all);
	    }
	}

	private void addType(Class type, Vector all) {
	    if (all.contains(type))
		return;
	    all.addElement(type);
	    JCheckBoxMenuItem item =
		new JCheckBoxMenuItem(typeName(type), false);
	    item.addActionListener(wrap(new AttrSet(type)));
	    menu.add(item);
	    if (esuper.getState() &&
		Entry.class.isAssignableFrom(type.getSuperclass()))
		addType(type.getSuperclass(), all);
	}

	public void menuDeselected(MenuEvent ev) {
	    menu.removeAll();
	}

	public void menuCanceled(MenuEvent ev) {
	    menu.removeAll();
	}
    }

    private class AttrSet implements ActionListener {
	private Class type;

	public AttrSet(Class type) {
	    this.type = type;
	}

	public void actionPerformed(ActionEvent ev) {
	    Entry ent;
	    try {
		ent = (Entry)type.newInstance();
	    } catch (Throwable t) {
		logger.log(Level.INFO, "creating entry failed", t);
		return;
	    }
	    int z = tmpl.attributeSetTemplates.length;
	    Entry[] newSets = new Entry[z + 1];
	    System.arraycopy(tmpl.attributeSetTemplates, 0, newSets, 0, z);
	    newSets[z] = ent;
	    tmpl.attributeSetTemplates = newSets;
	    update();
	}
    }

    private class Fields implements MenuListener {
	private JMenu menu;
	private int index;

	public Fields(JMenu menu, int index) {
	    this.menu = menu;
	    this.index = index;
	}

	public void menuSelected(MenuEvent ev) {
	    JRadioButtonMenuItem match = new JRadioButtonMenuItem("(match)");
	    match.setSelected(true);
	    match.addActionListener(wrap(new Unmatch(index)));
	    menu.add(match);
	    Entry ent = tmpl.attributeSetTemplates[index];
	    Field[] fields = ent.getClass().getFields();
	    for (int i = 0; i < fields.length; i++) {
		Field field = fields[i];
		if (!valid(field))
		    continue;
		try {
		    if (field.get(ent) != null) {
			JCheckBoxMenuItem item =
			    new JCheckBoxMenuItem(field.getName(), true);
			item.addActionListener(
					wrap(new Value(index, field, null)));
			menu.add(item);
		    } else {
			JMenu item = new JMenu(field.getName());
			item.addMenuListener(
					wrap(new Values(item, index, field)));
			menu.add(item);
		    }
		} catch (Throwable t) {
		    logger.log(Level.INFO, "getting fields failed", t);
		}
	    }
	}

	public void menuDeselected(MenuEvent ev) {
	    menu.removeAll();
	}

	public void menuCanceled(MenuEvent ev) {
	    menu.removeAll();
	}
    }

    private class Unmatch implements ActionListener {
	private int index;

	public Unmatch(int index) {
	    this.index = index;
	}

	public void actionPerformed(ActionEvent ev) {
	    int z = tmpl.attributeSetTemplates.length;
	    Entry[] newSets = new Entry[z - 1];
	    System.arraycopy(tmpl.attributeSetTemplates, 0,
			     newSets, 0, index);
	    System.arraycopy(tmpl.attributeSetTemplates, index + 1,
			     newSets, index, z - index - 1);
	    tmpl.attributeSetTemplates = newSets;
	    update();
	}
    }

    private class Values implements MenuListener {
	private JMenu menu;
	private int index;
	private Field field;

	public Values(JMenu menu, int index, Field field) {
	    this.menu = menu;
	    this.index = index;
	    this.field = field;
	}

	public void menuSelected(MenuEvent ev) {
	    Object[] values;
	    try {
		values = lookup.getFieldValues(tmpl, index, field.getName());
	    } catch (Throwable t) {
		failure(t);
		return;
	    }
	    if (values == null) {
		addNone(menu);
		return;
	    }
	    for (int i = 0; i < values.length; i++) {
		JMenuItem item = new JMenuItem(values[i].toString());
		item.addActionListener(
				   wrap(new Value(index, field, values[i])));
		menu.add(item);
	    }
	}

	public void menuDeselected(MenuEvent ev) {
	    menu.removeAll();
	}

	public void menuCanceled(MenuEvent ev) {
	    menu.removeAll();
	}
    }

    private class Value implements ActionListener {
	private int index;
	private Field field;
	private Object value;

	public Value(int index, Field field, Object value) {
	    this.index = index;
	    this.field = field;
	    this.value = value;
	}

	public void actionPerformed(ActionEvent ev) {
	    try {
		field.set(tmpl.attributeSetTemplates[index], value);
	    } catch (Throwable t) {
		logger.log(Level.INFO, "setting attribute value failed", t);
	    }
	    update();
	}
    }

    private class Listener implements RemoteEventListener, ServerProxyTrust {
	private final Exporter exporter;
	final RemoteEventListener proxy;

	public Listener() throws ConfigurationException, ExportException {
	    exporter = (Exporter)
		Config.getNonNullEntry(config, BROWSER, "listenerExporter",
				       Exporter.class,
				       new BasicJeriExporter(
					     TcpServerEndpoint.getInstance(0),
					     new BasicILFactory(),
					     false, false));
	    proxy = (RemoteEventListener) exporter.export(this);
	}

	public void notify(final RemoteEvent ev) {
	    SwingUtilities.invokeLater(wrap(new Runnable() {
		public void run() {
		    if (eventID == ev.getID() &&
			seqNo < ev.getSequenceNumber() &&
			eventSource != null &&
			eventSource.equals(ev.getSource()))
		    {
			seqNo = ev.getSequenceNumber();
			setText(false);
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

    private class LookupListener implements DiscoveryListener {

	public void discovered(DiscoveryEvent e) {
	    final ServiceRegistrar[] newregs = e.getRegistrars();
	    SwingUtilities.invokeLater(wrap(new Runnable() {
		public void run() {
		    for (int i = 0; i < newregs.length; i++) {
			addOne(newregs[i]);
		    }
		    if (lookup == null)
			setText(false);
		}
	    }));
	}

	public void discarded(DiscoveryEvent e) {
	    final ServiceRegistrar[] regs = e.getRegistrars();
	    SwingUtilities.invokeLater(wrap(new Runnable() {
		public void run() {
		    for (int i = 0; i < regs.length; i++) {
			ServiceID id = regs[i].getServiceID();
			if (lookup != null &&
			    id.equals(lookup.getServiceID()))
			{
			    lookup = null;
			    seqNo = Long.MAX_VALUE;
			}
			for (int j = 0;
			     j < registrars.getMenuComponentCount();
			     j++)
			{
			    JMenuItem item =
				(JMenuItem) registrars.getMenuComponent(j);
			    if (item instanceof RegistrarMenuItem &&
				id.equals(((RegistrarMenuItem) item).id))
			    {
				item.setSelected(false);
				registrars.remove(item);
				if (registrars.getMenuComponentCount() == 0)
				    addNone(registrars);
				break;
			    }
			}
		    }
		    if (lookup == null)
			resetTmpl();
		}
	    }));
	}
    }

    private void setGroups(String[] groups) {
	((DiscoveryLocatorManagement) disco).setLocators(new LookupLocator[0]);
	try {
	    disco.setGroups(groups);
	} catch (Throwable t) {
	    logger.log(Level.INFO, "setting groups failed", t);
	}
	resetTmpl();
    }

    private class AllFind implements ActionListener {

	public void actionPerformed(ActionEvent ev) {
	    setGroups(null);
	}
    }

    private class PubFind implements ActionListener {

	public void actionPerformed(ActionEvent ev) {
	    setGroups(new String[]{""});
	}
    }

    private class MultiFind implements ActionListener {

	public void actionPerformed(ActionEvent ev) {
	    String names = JOptionPane.showInputDialog(Browser.this,
						       "Enter group names");
	    if (names == null)
		return;
	    setGroups(parseList(names, true));
	}
    }

    private class UniFind implements ActionListener {

	public void actionPerformed(ActionEvent ev) {
	    String list =
		JOptionPane.showInputDialog(Browser.this,
					    "Enter host[:port] addresses");
	    if (list == null)
		return;
	    String[] addrs = parseList(list, false);
	    LookupLocator[] locs = new LookupLocator[addrs.length];
	    for (int i = 0; i < addrs.length; i++) {
		try {
		    locs[i] = new ConstrainableLookupLocator(
				    "jini://" + addrs[i], locatorConstraints);
		} catch (MalformedURLException e) {
		    JOptionPane.showMessageDialog(Browser.this,
						  "\"" + addrs[i] + "\": " +
						  e.getMessage(),
						  "Bad Address",
						  JOptionPane.ERROR_MESSAGE);
		    return;
		}
	    }
	    try {
		disco.setGroups(new String[0]);
	    } catch (Throwable t) {
		logger.log(Levels.HANDLED, "setting groups failed", t);
	    }
	    ((DiscoveryLocatorManagement) disco).setLocators(locs);
	    resetTmpl();
	}
    }

    private class Lookup implements ActionListener {
	private ServiceRegistrar registrar;

	public Lookup(ServiceRegistrar registrar) {
	    this.registrar = registrar;
	}

	public void actionPerformed(ActionEvent ev) {
	    if (lookup == registrar) {
		lookup = null;
	    } else {
		lookup = registrar;
	    }
	    seqNo = Long.MAX_VALUE;
	    for (int i = 0; i < registrars.getMenuComponentCount(); i++) {
		JMenuItem item = (JMenuItem)registrars.getMenuComponent(i);
		if (item != ev.getSource())
		    item.setSelected(false);
	    }
	    resetTmpl();
	}
    }

    static class LeaseNotify implements LeaseListener {
	public void notify(LeaseRenewalEvent ev) {
	    if (ev.getException() != null)
		logger.log(Level.INFO, "lease renewal failed",
			   ev.getException());
	    else
		logger.log(Level.INFO, "lease renewal failed");
	}
    }

    private static String[] parseList(String names, boolean groups) {
	StringTokenizer st = new StringTokenizer(names, " \t\n\r\f,");
	String[] elts = new String[st.countTokens()];
	for (int i = 0; st.hasMoreTokens(); i++) {
	    elts[i] = st.nextToken();
	    if (groups && elts[i].equalsIgnoreCase("public"))
		elts[i] = "";
	}
	return elts;
    }

    private void cancelLease() {
	if (elease != null) {
	    try {
		leaseMgr.cancel(elease);
	    } catch (Throwable t) {
		logger.log(Levels.HANDLED, "lease cancellation failed", t);
	    }
	    elease = null;
	    eventSource = null;
	}
    }

    private void update() {
	setText(false);
	cancelLease();
	if (lookup == null)
	    return;
	try {
	    EventRegistration reg =
		lookup.notify(tmpl,
			      ServiceRegistrar.TRANSITION_MATCH_NOMATCH |
			      ServiceRegistrar.TRANSITION_NOMATCH_MATCH |
			      ServiceRegistrar.TRANSITION_MATCH_MATCH,
			      listen.proxy, null, Lease.ANY);
	    elease = (Lease) leasePreparer.prepareProxy(reg.getLease());
	    leaseMgr.renewUntil(elease, Lease.ANY, lnotify);
	    eventSource = reg.getSource();
	    eventID = reg.getID();
	    seqNo = reg.getSequenceNumber();
	} catch (Throwable t) {
	    failure(t);
	}
    }

    private void failure(Throwable t) {
	logger.log(Level.INFO, "call to lookup service failed", t);
	((DiscoveryManagement) disco).discard(lookup);
    }

    class ServiceItemRenderer implements ListCellRenderer {
        private JLabel label;

        public ServiceItemRenderer() {
	    label = new JLabel();
	    label.setOpaque(true);
	}
    
        public Component getListCellRendererComponent(JList list,
						      Object value,
						      int index,
						      boolean isSelected,
						      boolean cellHasFocus){
	    ServiceListItem item = null;
	    if(value instanceof ServiceListItem)
	        item = (ServiceListItem) value;

	    label.setFont(list.getFont());

	    if(isSelected){
	        label.setBackground(list.getSelectionBackground());
		label.setForeground(list.getSelectionForeground());
	    } else {
	        label.setBackground(list.getBackground());
		label.setForeground(list.getForeground());
	    }
	    if(item != null){
		// accessible check done in this method
	        label.setIcon(item.getIcon());
	        label.setText(item.getTitle());
	    } else
	        label.setText(value.toString());

	    return label;
	}
    }

    private static Icon[] icons = new Icon[3];
    static {
	// Administrable Service, Controllable Attribute
        icons[0] = MetalIcons.getBlueFolderIcon();
	// Non-administrable Service
	icons[1] = MetalIcons.getGrayFolderIcon();
	// "Connection Refused" Service
	icons[2] = MetalIcons.getUnusableFolderIcon();
    }

    private class ServiceListItem {
        private ServiceItem item;
        private boolean isAccessible;
	private Object admin = null;

        public ServiceListItem(ServiceItem item) {
	    this.item = item;
	    isAccessible = (item.service != null);
	}

        public String getTitle() {
	    if(item.service == null)
	        return "Unknown service";

	    HashSet set = new HashSet();
	    Class[] infs = getInterfaces(item.service.getClass());
	    for(int j = 0; j < infs.length; j++)
	        set.add(infs[j].getName());

	    // remove known interfaces
	    set.removeAll(ignoreInterfaces);

	    String title = null;
	    if(set.size() == 1) {
	        Iterator iter = set.iterator();
	        title = (String) iter.next();
	    } else {
	        title = item.service.getClass().getName();
		title += " [";
		for (Iterator iter = set.iterator(); iter.hasNext();) {
		    title += (String) iter.next();
		    if (iter.hasNext())
			title += ", ";
		}
		title += "]";
	    }
	    if(! isAccessible)
	        title += " (Stale service)";
	    return title;
	}
      
        public boolean isAccessible() {
	    getAdmin();
	    return isAccessible;
	}

	public Object getAdmin() {
	    if(admin == null &&
	       isAccessible &&
	       item.service instanceof Administrable)
	    {
		try {
		    admin = adminPreparer.prepareProxy(
				((Administrable) item.service).getAdmin());
		} catch (Throwable t) {
		    logger.log(Levels.HANDLED, "failed to get admin proxy", t);
		    isAccessible = false;
		}
	    }
	    return admin;
	}

	public boolean isAdministrable() {
	    getAdmin();
	    return (admin instanceof DestroyAdmin ||
		    admin instanceof JoinAdmin ||
		    admin instanceof DiscoveryAdmin);
	}

	public boolean isSpaceBrowsable() {
	    return (item.service instanceof JavaSpace05 ||
		    (item.service instanceof JavaSpace &&
		     getAdmin() instanceof JavaSpaceAdmin));
	}

	private boolean isUI() {
	    Entry[] attrs = item.attributeSets;
	    if ((attrs != null) && (attrs.length != 0)) {
		for (int i = 0; i < attrs.length; i++) {
		    if (attrs[i] instanceof UIDescriptor) {
			return true;
		    }
		}
	    }

	    return false;
	}

        public ServiceItem getServiceItem() {
	    return item;
	}

        public Entry[] getAttributes() {
	    return item.attributeSets;
	}

        public Icon getIcon() {
	    if(! isAccessible())
		return icons[2];
	    else if(isAdministrable())
		return icons[0];
	    else
		return icons[1];
	}

        public String toString() {
	    return isAccessible() ?
		item.service.getClass().getName() : "Unknown service";
	}
    }

    private class MouseReceiver extends MouseAdapter {
        private ServiceListPopup popup;

        public MouseReceiver(ServiceListPopup popup) {
	  this.popup = popup;
	}

        public void mouseClicked(MouseEvent ev) {
	    if(ev.getClickCount() >= 2){
		ServiceListItem listItem = getTargetListItem(ev);
		if(listItem != null) {
		    ServiceItem item = listItem.getServiceItem();
		    if(listItem.isAdministrable())
			new ServiceEditor(item, listItem.getAdmin(), lookup,
					  Browser.this).setVisible(true);
		    else if(listItem.isAccessible())
			new ServiceBrowser(item, lookup,
					   Browser.this).setVisible(true);
		}
	    }
	}

        public void mouseReleased(MouseEvent ev) {
	    if(ev.isPopupTrigger() && (getTargetListItem(ev) != null)) {
	        popup.setServiceItem(getTargetListItem(ev));
	        popup.show(ev.getComponent(), ev.getX(), ev.getY());
	    }
	}

        public void mousePressed(MouseEvent ev) {
	    if(ev.isPopupTrigger() && (getTargetListItem(ev) != null)) {
	        popup.setServiceItem(getTargetListItem(ev));
	        popup.show(ev.getComponent(), ev.getX(), ev.getY());
	    }
	}

        private ServiceListItem getTargetListItem(MouseEvent ev) {
	    int index = list.locationToIndex(ev.getPoint());
	    if(index >= 0)
	        return (ServiceListItem) listModel.getElementAt(index);
	    else
	        return null;
	}
    }

    private class ServiceListPopup
			extends JPopupMenu
			implements ActionListener, PopupMenuListener
    {
        protected JMenuItem infoItem;
        protected JMenuItem browseItem;
        protected JMenuItem adminItem;
        protected JMenuItem spaceItem;
	protected ServiceListItem listItem;
	protected JMenuItem uiItem;
        protected ServiceItem item;

        public ServiceListPopup() {
	    super();

	    ActionListener me = wrap(this);
	    infoItem = new JMenuItem("Show Info");
	    infoItem.addActionListener(me);
	    infoItem.setActionCommand("showInfo");
	    add(infoItem);

	    browseItem = new JMenuItem("Browse Service");
	    browseItem.addActionListener(me);
	    browseItem.setActionCommand("browseService");
	    add(browseItem);

	    adminItem = new JMenuItem("Admin Service");
	    adminItem.addActionListener(me);
	    adminItem.setActionCommand("adminService");
	    add(adminItem);

	    spaceItem = new JMenuItem("Browse Entries");
	    spaceItem.addActionListener(me);
	    spaceItem.setActionCommand("browseEntry");
	    add(spaceItem);

	    uiItem = new JMenuItem("Show UI");
	    uiItem.addActionListener(me);
	    uiItem.setActionCommand("showUI");
	    add(uiItem);

	    addPopupMenuListener(this);
	    setOpaque(true);
	    setLightWeightPopupEnabled(true);
	}

        public void setServiceItem(ServiceListItem listItem) {
	    this.listItem = listItem;
	    item = listItem.getServiceItem();
	    infoItem.setEnabled(listItem.isAccessible());
	    browseItem.setEnabled(listItem.isAccessible());
	    adminItem.setEnabled(listItem.isAdministrable());
	    spaceItem.setEnabled(listItem.isSpaceBrowsable());
	    uiItem.setEnabled(listItem.isUI());
	}

        public void actionPerformed(ActionEvent ev) {
	    String command = ev.getActionCommand();

	    if(command.equals("showInfo")){
	        Class[] infs = getInterfaces(item.service.getClass());
		String[] msg = new String[3 + infs.length];
		msg[0] = "ServiceID: " + item.serviceID;
		msg[1] = ("Service Instance: " +
			  item.service.getClass().getName());
		if(infs.length == 1)
		    msg[2] = "Implemented Interface:";
		else
		    msg[2] = "Implemented Interfaces:";
		for(int i = 0; i < infs.length; i++)
		    msg[3 + i] = infs[i].getName();

		JOptionPane.showMessageDialog(Browser.this,
					      msg,
					      "ServiceItem Information",
					      JOptionPane.INFORMATION_MESSAGE);
	    } else if(command.equals("browseService")){
	        new ServiceBrowser(item, lookup,
				   Browser.this).setVisible(true);
	    } else if(command.equals("adminService")){
	        new ServiceEditor(item, listItem.getAdmin(),
				  lookup, Browser.this).setVisible(true);
	    } else if(command.equals("browseEntry")){
		new SpaceBrowser(item.service instanceof JavaSpace05 ?
				 item.service : listItem.getAdmin(),
				 Browser.this).setVisible(true);
	    }
	    else if(command.equals("showUI")){
		UIDescriptor uiDescriptor = getSelectedUIDescriptor();

		if (uiDescriptor == null) {
		    return;
		}

		try {
		    JFrameFactory uiFactory = (JFrameFactory)
			uiDescriptor.getUIFactory(
			    Thread.currentThread().getContextClassLoader());
		    JFrame frame = uiFactory.getJFrame(item);

		    frame.validate();
		    frame.setVisible(true);
		}
		catch (Exception e) {
		    logger.log(Level.INFO, "show ui failed", e);
		    JOptionPane.showMessageDialog(Browser.this,
						  e.getMessage(),
						  e.getClass().getName(),
						  JOptionPane.WARNING_MESSAGE);
		    return;
		}
	    }
	}

        public void popupMenuWillBecomeVisible(PopupMenuEvent ev) {
	}

        public void popupMenuWillBecomeInvisible(PopupMenuEvent ev) {
	}

        public void popupMenuCanceled(PopupMenuEvent ev) {
	}

        private UIDescriptor getSelectedUIDescriptor() {

	    if (!(new ServiceListItem(item)).isUI()) {
		return null;
	    }

	    Entry[] attrs = item.attributeSets;
	    if ((attrs != null) && (attrs.length != 0)) {
		for (int i = 0; i < attrs.length; i++) {
		    if (attrs[i] instanceof UIDescriptor) {
			UIDescriptor desc = (UIDescriptor) attrs[i];
			if (!"javax.swing".equals(desc.toolkit)) {
				continue;
			}
			return desc;
		    }
		}
	    }
	    return null;
	}
    }

    private class Exiter extends WindowAdapter {

	public void windowClosing(WindowEvent e) {
	    Browser.this.exiter.actionPerformed(
		new ActionEvent(e.getSource(), e.getID(),
				"Exit", System.currentTimeMillis(), 0));
	}
    }

    /**
     * An action listener that cancels any lookup service event registration
     * lease and then calls {@link System#exit System.exit}.
     */
    public static class Exit implements ActionListener {

	/**
	 * Cancels any lookup service event registration lease and
	 * calls {@link System#exit System.exit}<code>(0)</code>.
	 */
	public void actionPerformed(ActionEvent ev) {
	    Object src = ev.getSource();
	    while (!(src instanceof Browser) && src instanceof Component) {
		if (src instanceof JPopupMenu)
		    src = ((JPopupMenu) src).getInvoker();
		else
		    src = ((Component) src).getParent();
	    }
	    if (src instanceof Browser) {
		((Browser) src).cancelLease();
	    }
	    System.exit(0);
	}
    }

    /**
     * Runs the service browser. See the package documentation for details.
     *
     * @param args command line arguments
     */
    public static void main (String[] args) {
	if (System.getSecurityManager() == null)
	    System.setSecurityManager(new SecurityManager());
	try {
	    final Configuration config =
		ConfigurationProvider.getInstance(
					args, Browser.class.getClassLoader());
	    LoginContext login =
		(LoginContext) config.getEntry(BROWSER, "loginContext",
					       LoginContext.class, null);
	    if (login != null) {
		login.login();
	    }
	    PrivilegedExceptionAction action =
		new PrivilegedExceptionAction() {
		    public Object run() throws Exception {
			return new Browser(null, config);
		    }
		};
	    if (login != null) {
		Subject.doAsPrivileged(login.getSubject(), action, null);
	    } else {
		action.run();
	    }
	} catch (Throwable t) {
	    if (t instanceof PrivilegedActionException)
		t = t.getCause();
	    logger.log(Level.SEVERE, "browser initialization failed", t);
	}
    }
}
