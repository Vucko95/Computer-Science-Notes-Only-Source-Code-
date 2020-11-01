package service.auldfellas;
import java.io.IOException;

import org.restlet.representation.Representation;
import org.restlet.resource.ClientResource;
import org.restlet.resource.ResourceException;
import org.restlet.util.NamedValue;
import org.restlet.util.Series;

import com.google.gson.Gson;

import service.core.Quotation;

public class TestClient {
  @SuppressWarnings("unchecked")
  public static void main(String[] args) throws ResourceException, IOException {
    Gson gson = new Gson(); // google json
    ClientResource client = new ClientResource("http://localhost:9000/quotations"); // setting the http client
    String ref = "myReffTest"; // creating a manual post reference
    Quotation quotation = new Quotation("newCompTest", ref, 22); // choosing config of the quotation url
    client.post(gson.toJson(quotation));
    client = new ClientResource("http://localhost:9000/quotations/" + ref);
    final Representation representation = client.get(); // gets the client and sets it in representation
    String location = ((Series<NamedValue<String>>)client.getResponseAttributes().get("org.restlet.http.headers")).getFirstValue("reference");
    System.out.println("URL: " + location); // find the url and puts the location from the line above
    new ClientResource(location).get().write(System.out);
  }
}