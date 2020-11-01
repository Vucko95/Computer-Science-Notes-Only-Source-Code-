package actors;

import java.util.LinkedList;
import java.util.List;

import akka.actor.ActorRef;
import akka.actor.Props;
import akka.actor.UntypedActor;
import message.GetQuote;
import message.Init;

public class BrokerActor extends UntypedActor {
	private static int count = 0;
	List<ActorRef> services = new LinkedList<ActorRef>();
	
	@Override
	public void onReceive(Object message) throws Exception {
		if (message.equals("hello")) {
			services.add(getSender());
		} else if (message instanceof GetQuote) {
			ActorRef aggregator = getContext().actorOf(Props.create(AggregatorActor.class), "aggregator_" + (count++));
			aggregator.tell(new Init(services.size()), getSender());
			
			for(ActorRef service : services) {
				service.tell(message, aggregator);
			}
		}
	}
}
