<%-- 
    Document   : mbeans
    Created on : May 6, 2013, 9:07:43 PM
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
--%><%@page import="java.util.TreeMap"%><%@page import="java.util.Map"%><%@page import="javax.management.AttributeList"%><%@page import="java.util.Map.Entry"%><%@page import="java.util.Hashtable"%><%@page import="java.util.Iterator"%><%@page import="javax.management.ObjectName"%><%@page import="java.util.Set"%><%@page import="javax.management.MBeanServerFactory"%><%@page import="java.util.ArrayList"%><%@page import="javax.management.MBeanServer"%><%@page import="java.lang.management.MemoryPoolMXBean"%><%@page import="java.lang.management.ManagementFactory"%><%@page import="java.util.List"%><%@page contentType="application/json" pageEncoding="UTF-8"%><%

    TreeMap data = new TreeMap<String, String>();
    data.put("timestamp", Long.toString(System.currentTimeMillis()));
    MBeanServer mbserver = null;

    ArrayList mbservers = MBeanServerFactory.findMBeanServer(null);

    if (mbservers.size() > 0) {
        mbserver = (MBeanServer) mbservers.get(0);
    }
    if (mbserver != null) {
    } else {
        mbserver = MBeanServerFactory.createMBeanServer();
    }
    if (mbserver == null) {
        out.write("null ref<br>");
    } else {
        long totalsuccess = 0;
        long totalfailures = 0;
        String[] domains = mbserver.getDomains();
        for (int i = 0; i < domains.length; i++) {
            //              out.write(domains[i] + "<br>");
        }
        ObjectName juddi = new ObjectName("apache.juddi:counter=*");
        juddi.setMBeanServer(mbserver);
        Set<ObjectName> beans = mbserver.queryNames(juddi, null);
        Iterator<ObjectName> it = beans.iterator();
        while (it.hasNext()) {
            ObjectName n = it.next();
            //   out.write(n.getCanonicalName() + " ");
            //                out.write(n.getKeyPropertyListString() + "<Br>");
            Hashtable<String, String> props = n.getKeyPropertyList();
            Iterator<Entry<String, String>> it2 = props.entrySet().iterator();
            while (it2.hasNext()) {
                Entry<String, String> e = it2.next();
//                        out.write("key = " + e.getKey() + "<br>");
                //                      out.write("value = " + e.getValue() + "<br>");
            }
            AttributeList j = (AttributeList) mbserver.getAttributes(n, new String[]{"counter"});
            for (int k = 0; k < j.size(); k++) {
                String attr = j.get(k).toString();
                String[] kv = attr.split("=");
                //out.write("attr = " + kv[0] + " value = " + kv[1] + "<br>");
                data.put(kv[0], kv[1]);
                if (kv[0].toLowerCase().contains("success")) {
                   totalsuccess+= Long.parseLong(kv[1].trim());
                }
                  if (kv[0].toLowerCase().contains("fail")) {
                   totalfailures+= Long.parseLong(kv[1].trim());
                }
            }

            // out.write(j.getClass().getCanonicalName() + "<br>");
        }
        data.put("totalsuccess", totalsuccess);
        data.put("totalfailures", totalfailures);
    }
    //  out.write("<br>");
    //  out.write("<br>");
    //    out.write("<br>");
    //  List<MemoryPoolMXBean> memPoolBeans = ManagementFactory.getMemoryPoolMXBeans();
    // for (MemoryPoolMXBean mpb : memPoolBeans) {
    //    out.write("Memory Pool: " + mpb.getName() + "<br>");
    //}

    out.write(new org.json.JSONObject(data).toString());
%>