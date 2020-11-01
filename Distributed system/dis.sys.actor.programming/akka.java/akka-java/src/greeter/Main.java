package greeter;

import akka.actor.ActorRef;
import akka.actor.ActorSystem;
import akka.actor.Props;

public class Main {
	public static void main(String[] args) {
		ActorSystem system = ActorSystem.create("helloakka");
		ActorRef helloActor = system.actorOf(Props.create(HelloWorld.class), "main");
		helloActor.tell(Greeter.Msg.GREET, ActorRef.noSender());

	}
}
