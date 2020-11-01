package service.core;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
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
import client.Main;
import service.broker.LocalBrokerService;

public class BrokerApplication extends Application {
  static Map<String, Quotation> quotations = new HashMap<String, Quotation>();
  static Gson gson = new Gson();
  public LocalBrokerService brk = new LocalBrokerService();
  List<Quotation> allQuotations = new ArrayList<Quotation>();

  public static void main(String[] args) throws Exception {
    Component component = new Component();
    component.getServers().add(Protocol.HTTP, 9004);
    component.getClients().add(Protocol.HTTP); // getting all clients from HTTP
    component.getDefaultHost().attach("", new BrokerApplication());
    component.start();
  }

  public Restlet createInboundRoot() {
    Router router = new Router(getContext());
    router.attach("/brokers", new Restlet() {
      public void handle(Request request, Response response) {
        ClientInfo in = gson.fromJson(request.getEntityAsText(), ClientInfo.class);
        List<Quotation> quotation = brk.getQuotations(in);
        if (request.getMethod().equals(Method.POST)) {
          allQuotations.addAll(quotation);
          String toJson = gson.toJson(allQuotations); // getting all quotations and setting them into toJson
          response.setEntity(toJson, MediaType.APPLICATION_JSON); // Postman
          allQuotations.clear();
          // System.out.println("source posted toJson: " + toJson);
          // System.out.println("source posted allQuotations: " + allQuotations); // will call to string
          response.setStatus(Status.SUCCESS_OK);
        } else
          response.setStatus(Status.CLIENT_ERROR_FORBIDDEN);
      }
    });
    return router;
  }
};
