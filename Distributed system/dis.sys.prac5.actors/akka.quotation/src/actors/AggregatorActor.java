package actors;

import java.util.LinkedList;
import java.util.List;

import akka.actor.ActorRef;
import akka.actor.Kill;
import akka.actor.UntypedActor;
import message.Init;
import message.Quote;
import message.Result;
import service.core.Quotation;

public class AggregatorActor extends UntypedActor {
	private int replies;
	private ActorRef client;
	private List<Quotation> quotations = new LinkedList<Quotation>();
	
	@Override
	public void onReceive(Object message) throws Exception {
		if (message instanceof Init) {
			replies = ((Init) message).replies;
			client = getSender();
		} else if (message instanceof Quote) {
			quotations.add(((Quote) message).quotation);
			if (quotations.size() == replies) {
				client.tell(new Result(quotations), getSelf());
				getSelf().tell(Kill.getInstance(), getSelf());
			}
		} else {
			unhandled(message);
		}
	}

}
