package hello.server;
import org.restlet.Application;
import org.restlet.Restlet;
import org.restlet.routing.Router;

public class HelloApplication extends Application {
    public Restlet createInboundRoot() {
        Router router = new Router(getContext());
        router.attach("/hello", new HelloRestlet());
        return router;
    }
}
