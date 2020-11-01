package hello.server;
import org.restlet.Request;
import org.restlet.Response;
import org.restlet.Restlet;
import org.restlet.data.MediaType;
import org.restlet.data.Method;
import org.restlet.data.Status;

public class HelloRestlet extends Restlet {
    @Override
    public void handle(Request request, Response response) {
        if (request.getMethod().equals(Method.GET)) {
            response.setEntity("Hello, World", MediaType.TEXT_PLAIN);
        	response.setStatus(Status.SUCCESS_OK);
        } else {
            response.setStatus(Status.CLIENT_ERROR_FORBIDDEN);
        }
    }
}
