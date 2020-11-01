package actors;

import java.util.concurrent.TimeUnit;

import akka.actor.ActorIdentity;
import akka.actor.ActorRef;
import akka.actor.ActorSelection;
import akka.actor.Identify;
import akka.actor.UntypedActor;
import akka.pattern.AskableActorSelection;
import akka.util.Timeout;
import message.GetQuote;
import message.Quote;
import scala.concurrent.Await;
import scala.concurrent.Future;
import service.core.Quotation;
import service.core.QuotationService;

public class QuotationActor extends UntypedActor {
	private QuotationService service;
	
	public QuotationActor(QuotationService service) {
		this.service = service;
		
		ActorSelection selection = getContext().actorSelection("akka://default/user/broker");
		Timeout t = new Timeout(5, TimeUnit.SECONDS);
		AskableActorSelection asker = new AskableActorSelection(selection);
		Future<Object> fut = asker.ask(new Identify(1), t);
		try {
			ActorIdentity ident = (ActorIdentity) Await.result(fut, t.duration());
			ActorRef ref = ident.getRef();
			if (ref == null) System.out.println("No BROKER");
			ref.tell("hello", getSelf());
		} catch (Exception e) {
			e.printStackTrace();
		}		
	}
	
	@Override
	public void onReceive(Object message) throws Exception {
		if (message instanceof GetQuote) {
			GetQuote getQuote = (GetQuote) message;
			Quotation quotation = service.generateQuotation(getQuote.info);
			getSender().tell(new Quote(quotation), getSelf());
		} else {
			unhandled(message);
		}
	}
}
