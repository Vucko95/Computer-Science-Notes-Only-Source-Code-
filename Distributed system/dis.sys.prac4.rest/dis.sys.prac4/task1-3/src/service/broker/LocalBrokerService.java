package service.broker;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import org.restlet.resource.ClientResource;
import org.restlet.util.NamedValue;
import org.restlet.util.Series;
import com.google.gson.Gson;
import service.core.BrokerService;
import service.core.ClientInfo;
import service.core.Quotation;

public class LocalBrokerService implements BrokerService {
  public static final String[] URLS = {"http://localhost:9000/quotations", "http://localhost:9010/quotations", "http://localhost:9020/quotations"};
  public List<Quotation> getQuotations(ClientInfo info) {
    List<Quotation> quotations = new LinkedList<Quotation>();
    Gson gson = new Gson();
    for (String URL : URLS) {
      try {
        ClientResource client = new ClientResource(URL);
        client.post(gson.toJson(info)); // is the person
        
        @SuppressWarnings("unchecked")
        String location = ((Series<NamedValue<String>>)client.getResponseAttributes().get("org.restlet.http.headers")).getFirstValue("Location");
        
        ClientResource quote = new ClientResource(location); // getting back the urls
        String Json = quote.get().getText();
        Quotation q = gson.fromJson(Json, Quotation.class);
        quotations.add(q);
      } catch (IOException e) { e.printStackTrace(); }
    }
    return quotations;
  }
}
