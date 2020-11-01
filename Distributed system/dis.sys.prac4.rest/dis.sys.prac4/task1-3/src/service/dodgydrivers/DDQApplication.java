package service.dodgydrivers;

import com.google.gson.Gson;
import org.restlet.*;
import org.restlet.data.MediaType;
import org.restlet.data.Method;
import org.restlet.data.Protocol;
import org.restlet.data.Status;
import org.restlet.routing.Router;
import service.auldfellas.AFApplication;
import service.auldfellas.AFQService;
import service.core.ClientInfo;
import service.core.Quotation;
import java.util.HashMap;
import java.util.Map;

public class DDQApplication extends Application {
  static Map<String, Quotation> DDQQuotationsall = new HashMap<String, Quotation>();
  static Gson gson = new Gson();
  public DDQService ddq = new DDQService();

  public static void main(String[] args) throws Exception {
    Component component = new Component();
    component.getServers().add(Protocol.HTTP, 9010);
    component.getDefaultHost().attach("", new DDQApplication());
    component.start();
  }

  public Restlet createInboundRoot() {
    Router router = new Router(getContext());
    router.attach("/quotations", new Restlet() {
      public void handle(Request request, Response response) {
        if (request.getMethod().equals(Method.POST)) {
          ClientInfo in = gson.fromJson(request.getEntityAsText(), ClientInfo.class);
          Quotation quotation = ddq.generateQuotation(in);
          if (!DDQQuotationsall.containsKey(quotation.reference)) {
            DDQQuotationsall.put(quotation.reference, quotation); //
            String out = "[";
            out += ",";
            String url = request.getHostRef() + "/quotations/" + quotation.reference;
            response.setLocationRef(url);
            out += "{\"reference\" : \"" + quotation.reference + "\", \"link\":\"" + url + "\"}";
            String toJson = gson.toJson(quotation);
            response.setLocationRef(request.getHostRef() + "/quotations/" + quotation.reference);
            // System.out.println("source posted"+toJson);
            // System.out.println("source posted"+quotation);
            response.setStatus(Status.SUCCESS_OK);
          }
        } else
          response.setStatus(Status.CLIENT_ERROR_FORBIDDEN);
      }
    });
    
    router.attach("/quotations/{reference}", new Restlet() {
      @Override
      public void handle(Request request, Response response) {
        String id = (String) request.getAttributes().get("reference");
        if (DDQQuotationsall.containsKey(id)) {
          response.setStatus(Status.SUCCESS_OK);
          if (request.getMethod().equals(Method.GET)) {
            response.setEntity(gson.toJson(DDQQuotationsall.get(id)), MediaType.APPLICATION_JSON);
            response.setStatus(Status.SUCCESS_OK);
          } else if (request.getMethod().equals(Method.PUT)) {
            Quotation quotation = gson.fromJson(request.getEntityAsText(), Quotation.class);
            quotation.merge(DDQQuotationsall.get(id));
            DDQQuotationsall.put(quotation.reference, quotation);
            response.setStatus(Status.SUCCESS_NO_CONTENT);
          } else if (request.getMethod().equals(Method.DELETE)) {
            DDQQuotationsall.remove(id);
            response.setStatus(Status.SUCCESS_NO_CONTENT);
          }
        } else {
          response.setStatus(Status.CLIENT_ERROR_NOT_FOUND);
        }
      }
    });
    return router;
  }
}
