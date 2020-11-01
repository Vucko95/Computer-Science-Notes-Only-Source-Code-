package student.server;

import org.restlet.Component;
import org.restlet.data.Protocol;

public class StudentServer {
    public static void main(String[] args) throws Exception {
        Component component = new Component();
        component.getServers().add(Protocol.HTTP, 8182);
        component.getDefaultHost().
            attach("", new StudentApplication());
        component.start();
    }

}
