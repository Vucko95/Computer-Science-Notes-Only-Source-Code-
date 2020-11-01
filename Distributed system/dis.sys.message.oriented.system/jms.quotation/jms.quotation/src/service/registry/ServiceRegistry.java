package service.registry;

import java.util.HashMap;
import java.util.Map;

/**
 * This is a basic service registry implementation that is based on the registry used in
 * RMI systems.
 * 
 * @author Rem
 *
 */
public class ServiceRegistry {
	private static Map<String, Service> services = new HashMap<String, Service>();
	
	public static void bind(String name, Service service) {
		services.put(name, service);
	}
	
	public static void unbind(String name) {
		services.remove(name);
	}

	@SuppressWarnings("unchecked")
	public static <T extends Service> T lookup(String name, Class<T> myClass) {
		return (T) services.get(name);
	}

	public static Service lookup(String name) {
		return services.get(name);
	}

	public static String[] list() {
		return services.keySet().toArray(new String[services.size()]);
	}
}
