package service.auldfellas;

import java.util.HashMap;
import java.util.Map;
import org.restlet.Application;
import org.restlet.Component;
import org.restlet.Request;
import org.restlet.Response;
import org.restlet.Restlet;
import org.restlet.data.MediaType;
import org.restlet.data.Method;
import org.restlet.data.Protocol;
import org.restlet.data.Status;
import org.restlet.routing.Router;
import com.google.gson.Gson;
import service.core.ClientInfo;
import service.core.Quotation;

public class AFApplication extends Application {
  static Map<String, Quotation> afpQuotationsall = new HashMap<String, Quotation>();
  static Gson gson = new Gson();
  public AFQService afq = new AFQService();

  // Start()
  public static void main(String[] args) throws Exception {
    Component component = new Component();
    component.getServers().add(Protocol.HTTP, 9000);
    component.getDefaultHost().attach("", new AFApplication());
    component.start();
  }

  // post method
  public Restlet createInboundRoot() {
    Router router = new Router(getContext()); // create router
    router.attach("/quotations", new Restlet() { // attach router to quotations
      public void handle(Request request, Response response) { // start handle with res and req
        if (request.getMethod().equals(Method.POST)) { // starting post method with request param 
          // generates quotation 
          ClientInfo in = gson.fromJson(request.getEntityAsText(), ClientInfo.class);
          Quotation quotation = afq.generateQuotation(in);
          // System.out.println("all" + quotation);
          // System.out.println("in" + in);
          if (!afpQuotationsall.containsKey(quotation.reference)) { // if this service contains quotation ref
            afpQuotationsall.put(quotation.reference, quotation);
            String out = "["; // manual json
            out += ",";
            String url = request.getHostRef() + "/quotations/" + quotation.reference; // adds quotation ref to url 
            response.setLocationRef(url); //
            out += "{\"reference\" : \"" + quotation.reference + "\", \"link\":\"" + url + "\"}"; // adds to url
            String toJson = gson.toJson(quotation);
            response.setLocationRef(request.getHostRef() + "/quotations/" + quotation.reference);
            // System.out.println("source posted toJson" + toJson);
            // System.out.println("source posted quotation" + quotation); 
            response.setStatus(Status.SUCCESS_OK); // making sure it works 
          } else
            response.setStatus(Status.CLIENT_ERROR_FORBIDDEN);
        } else
          response.setStatus(Status.CLIENT_ERROR_FORBIDDEN);
      }
    });

    // get method
    router.attach("/quotations/{reference}", new Restlet() { // attaching reference as get
      @Override
      public void handle(Request request, Response response) {
        String id = (String) request.getAttributes().get("reference"); // getting the attributes reference attaching them as string 
        if (afpQuotationsall.containsKey(id)) { // asking if quotation contains id then do this:
          response.setStatus(Status.SUCCESS_OK); // tells us ok
          if (request.getMethod().equals(Method.GET)) {
            response.setEntity(gson.toJson(afpQuotationsall.get(id)), MediaType.APPLICATION_JSON); //sets the entity  
            response.setStatus(Status.SUCCESS_OK);
          } else if (request.getMethod().equals(Method.PUT)) {
            Quotation quotation = gson.fromJson(request.getEntityAsText(), Quotation.class); // creates quotation from quotation class 
            quotation.merge(afpQuotationsall.get(id)); // merges the id to quotation 
            afpQuotationsall.put(quotation.reference, quotation); // puts the quotation reference
            response.setStatus(Status.SUCCESS_NO_CONTENT);
          } else if (request.getMethod().equals(Method.DELETE)) {
            afpQuotationsall.remove(id); // if id doesnt work remove it 
            response.setStatus(Status.SUCCESS_NO_CONTENT);
          }
        } else {
          response.setStatus(Status.CLIENT_ERROR_NOT_FOUND);
        }
      }
    });
    return router; // returns the router
  }
}
