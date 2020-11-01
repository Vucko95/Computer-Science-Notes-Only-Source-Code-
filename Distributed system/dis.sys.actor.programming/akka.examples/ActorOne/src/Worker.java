import akka.actor.UntypedActor;

public class Worker extends UntypedActor {
	@Override
	public void onReceive(Object message) {
		if (message instanceof Content) {
			Content hello = (Content) message;
			System.out.println(hello.message());
			getSender().tell(new Content("goodbye"), getSelf());
		} else
			unhandled(message);
	}
}
