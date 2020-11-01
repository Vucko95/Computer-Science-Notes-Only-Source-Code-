package actors;

import java.util.concurrent.TimeUnit;

import akka.actor.ActorIdentity;
import akka.actor.ActorRef;
import akka.actor.ActorSelection;
import akka.actor.Identify;
import akka.actor.UntypedActor;
import akka.pattern.AskableActorSelection;
import akka.util.Timeout;
import client.Main;
import message.GetQuote;
import message.Result;
import scala.concurrent.Await;
import scala.concurrent.Future;
import service.core.ClientInfo;
import service.core.Quotation;

public class ClientActor extends UntypedActor {
	private ClientInfo info;
	
	public ClientActor(ClientInfo info) {
		this.info = info;
		
		ActorSelection selection = getContext().actorSelection("akka://default/user/broker");
		Timeout t = new Timeout(5, TimeUnit.SECONDS);
		AskableActorSelection asker = new AskableActorSelection(selection);
		Future<Object> fut = asker.ask(new Identify(1), t);
		try {
			ActorIdentity ident = (ActorIdentity) Await.result(fut, t.duration());
			ActorRef ref = ident.getRef();
			if (ref == null) System.out.println("No BROKER");
			ref.tell(new GetQuote(info), getSelf());
		} catch (Exception e) {
			e.printStackTrace();
		}		
	}
	
	@Override
	public void onReceive(Object message) throws Exception {
		if (message instanceof Result) {
			Main.displayProfile(info);
			
			// Retrieve quotations from the broker and display them...
			for(Quotation quotation : ((Result) message).quotations) {
				Main.displayQuotation(quotation);
			}
			
			// Print a couple of lines between each client
			System.out.println("\n");
		}
		
	}

}
