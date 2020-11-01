import akka.actor.ActorRef;
import akka.actor.Props;
import akka.actor.UntypedActor;

public class Master extends UntypedActor {
	final ActorRef child =
		      getContext().actorOf(Props.create(Worker.class), "myChild");
	
	@Override
	public void onReceive(Object message) {
		if (message instanceof Init) {
			child.tell(new Content("hello"), getSelf());
		} else if (message instanceof Content) {
			Content hello = (Content) message;
			System.out.println(hello.message());
			getSender().tell(new Content("hello"), getSelf());
		} else
			unhandled(message);
	}

}
