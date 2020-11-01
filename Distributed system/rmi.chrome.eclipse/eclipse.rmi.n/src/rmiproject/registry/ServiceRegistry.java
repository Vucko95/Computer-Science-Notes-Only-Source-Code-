/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rmiproject.registry;

import java.util.HashMap;
import java.util.Map;
import rmiproject.RMIQuotationServices;

public class ServiceRegistry {
	private static Map<String, Service> services = new HashMap<String, Service>();
	
	public static void bind(String name, Service service) {
		services.put(name, service);
	}
	
	public static void unbind(String name) {
		services.remove(name);
	}

	public static Service lookup(String name) {
		return services.get(name);
	}

	public static String[] list() {
		return services.keySet().toArray(new String[services.size()]);
	}

    public static RMIQuotationServices lookup(String name, Class<RMIQuotationServices> aClass) {
        return (RMIQuotationServices) services.get(name);
    }
}
