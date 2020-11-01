package actors;

import akka.actor.ActorRef;
import akka.actor.ActorSystem;
import akka.actor.Props;
import client.Main;
import service.auldfellas.AFQService;
import service.dodgydrivers.DDQService;
import service.girlpower.GPQService;

public class Launch {

	public static void main(String[] args) {
		ActorSystem system = ActorSystem.create();
		system.actorOf(Props.create(BrokerActor.class), "broker");
		
		system.actorOf(Props.create(QuotationActor.class, new AFQService()), AFQService.PREFIX);
		system.actorOf(Props.create(QuotationActor.class, new DDQService()), DDQService.PREFIX);
		system.actorOf(Props.create(QuotationActor.class, new GPQService()), GPQService.PREFIX);
		
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		for (int i=0; i < Main.clients.length; i++) {
			system.actorOf(Props.create(ClientActor.class,Main.clients[i]), "client"+i);
		}
	}

}
