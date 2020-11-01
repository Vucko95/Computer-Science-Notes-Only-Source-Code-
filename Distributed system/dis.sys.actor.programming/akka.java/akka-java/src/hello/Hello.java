package hello;

import akka.actor.UntypedActor;

public class Hello extends UntypedActor {
	public Hello() {}

	@Override
	public void onReceive(Object msg) {
		if (msg instanceof String) {
			System.out.println(msg);
			getContext().stop(getSelf());
		} else
			unhandled(msg);
	}
}
