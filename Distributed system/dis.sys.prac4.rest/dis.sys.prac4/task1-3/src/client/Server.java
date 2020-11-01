package client;

import service.auldfellas.AFApplication;
import service.broker.LocalBrokerService;
import service.core.BrokerApplication;
import service.dodgydrivers.DDQApplication;
import service.dodgydrivers.DDQService;
import service.girlpower.GPQApplication;
import service.registry.ServiceRegistry;

public class Server {
  public static void main(String[] args) throws Exception {
    // creating new objects and instances of each one of the services
    AFApplication AFApp = new AFApplication();
    DDQApplication DDQApp = new DDQApplication();
    GPQApplication GPQApp = new GPQApplication();
    BrokerApplication BRok = new BrokerApplication();

    // Starting objects
    BRok.main(null);
    AFApp.main(null);
    DDQApp.main(null);
    GPQApp.main(null);
  }
}
