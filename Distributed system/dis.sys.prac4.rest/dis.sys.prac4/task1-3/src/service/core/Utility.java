package service.core;

import com.google.gson.Gson;
import org.restlet.Context;
import org.restlet.Request;
import org.restlet.Response;
import org.restlet.Restlet;
import org.restlet.data.MediaType;
import org.restlet.data.Method;
import org.restlet.data.Status;
import org.restlet.routing.Router;
import java.util.HashMap;
import java.util.Map;

// for fun - not much 
public class Utility {
  static Map<String, Quotation> afpQuotationsall = new HashMap<String, Quotation>();
  static Gson gson = new Gson();

  public static Router afqEndPoints(Context context) {
    Router router = new Router(context);
    router.attach("/quotations", new Restlet() {
      public void handle(Request request, Response response) {
        String json = request.getEntityAsText();
        Quotation quotation = gson.fromJson(json, Quotation.class);
        if (request.getMethod().equals(Method.POST)) {
          if (!afpQuotationsall.containsKey(quotation.reference)) {
            afpQuotationsall.put(quotation.reference, quotation); //
            String out = "[";
            out += ",";
            String url = request.getHostRef() + "/quotations/" + quotation.reference;
            response.setLocationRef(url);
            out += "{\"reference\" : \"" + quotation.reference + "\", \"link\":\"" + url + "\"}";
            String toJson = gson.toJson(quotation);
            response.setEntity(toJson, MediaType.APPLICATION_JSON);
            System.out.println("source posted" + toJson);
            System.out.println("source posted" + quotation);
            response.setStatus(Status.SUCCESS_OK);
          }
        } else
          response.setStatus(Status.CLIENT_ERROR_FORBIDDEN);
      }
    });

    /*     
    router.attach("/quotations/{reference}", new Restlet() {
      @Override
      public void handle(Request request, Response response) {
        String id = (String) request.getAttributes().get("reference");
        if (afpQuotationsall.containsKey(id)) {
          response.setStatus(Status.SUCCESS_OK);
          if (request.getMethod().equals(Method.GET)) {
            response.setEntity(gson.toJson(afpQuotationsall.get(id)), MediaType.APPLICATION_JSON);
            response.setStatus(Status.SUCCESS_OK);
          } else if (request.getMethod().equals(Method.PUT)) {
            Quotation quotation = gson.fromJson(request.getEntityAsText(), Quotation.class);
            quotation.merge(afpQuotationsall.get(id));
            afpQuotationsall.put(quotation.reference, quotation);
            response.setStatus(Status.SUCCESS_NO_CONTENT);
          } else if (request.getMethod().equals(Method.DELETE)) {
            afpQuotationsall.remove(id);
            response.setStatus(Status.SUCCESS_NO_CONTENT);
          }
        } else {
          response.setStatus(Status.CLIENT_ERROR_NOT_FOUND);
        }
      }
    }); 
    */
    return router;
  }
}
