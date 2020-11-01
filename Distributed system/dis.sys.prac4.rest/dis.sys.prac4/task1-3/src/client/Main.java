package client;
import java.text.NumberFormat;
import java.util.List;
import org.restlet.resource.ClientResource;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import com.oracle.tools.packager.RelativeFileSet.Type;
import service.auldfellas.AFQService;
import service.broker.LocalBrokerService;
import service.core.BrokerService;
import service.core.ClientInfo;
import service.core.Quotation;
import service.dodgydrivers.DDQService;
import service.girlpower.GPQService;
import service.registry.ServiceRegistry;
public class Main {
  public static final String BROKER_SERVICE = "bs-BrokerService";

  static {
    ServiceRegistry.bind(BROKER_SERVICE, new LocalBrokerService());
  }

  // prints out all clints in json 
  public static void main(String[] args) throws Exception {
	  Gson gson = new Gson(); 
    for (ClientInfo info : clients)  {
    		  ClientResource client = new ClientResource("http://localhost:9004/brokers"); 
    	      java.lang.reflect.Type type = new TypeToken<List<Quotation>>(){}.getType(); 
    	      String json = (client.post(gson.toJson(info)).getText());
    		  List<Quotation> quotations = gson.fromJson(json, type); 
    	       System.out.println(json);
      		  displayProfile(info); 
    	  for(Quotation quotation: quotations) {
    		  displayQuotation(quotation); 
    	  }
          System.out.println("\n");
      }
    }

  public static void displayProfile(ClientInfo info) {
    System.out.println("|=================================================================================================================|");
    System.out.println("|                                     |                                     |                                     |");
    System.out.println(
        "| Name: " + String.format("%1$-29s", info.name) +
            " | Gender: " + String.format("%1$-27s", (info.gender == ClientInfo.MALE ? "Male" : "Female")) +
            " | Age: " + String.format("%1$-30s", info.age) + " |");
    System.out.println(
        "| License Number: " + String.format("%1$-19s", info.licenseNumber) +
            " | No Claims: " + String.format("%1$-24s", info.noClaims + " years") +
            " | Penalty Points: " + String.format("%1$-19s", info.points) + " |");
    System.out.println("|                                     |                                     |                                     |");
    System.out.println("|=================================================================================================================|");
  }

  public static void displayQuotation(Quotation quotation) {
    System.out.println(
        "| Company: " + String.format("%1$-26s", quotation.company) +
            " | Reference: " + String.format("%1$-24s", quotation.reference) +
            " | Price: " + String.format("%1$-28s", NumberFormat.getCurrencyInstance().format(quotation.price)) + " |");
    System.out.println("|=================================================================================================================|");
  }

  public static final ClientInfo[] clients = {
      new ClientInfo("Niki Collier", ClientInfo.FEMALE, 43, 0, 5, "PQR254/1"),
      new ClientInfo("Old Geeza", ClientInfo.MALE, 65, 0, 2, "ABC123/4"),
      new ClientInfo("Hannah Montana", ClientInfo.FEMALE, 16, 10, 0, "HMA304/9"),
      new ClientInfo("Rem Collier", ClientInfo.MALE, 44, 5, 3, "COL123/3"),
      new ClientInfo("Jim Quinn", ClientInfo.MALE, 55, 4, 7, "QUN987/4"),
      new ClientInfo("Donald Duck", ClientInfo.MALE, 35, 5, 2, "XYZ567/9")
  };
}
