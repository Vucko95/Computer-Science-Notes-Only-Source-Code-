package hello;

import akka.actor.ActorRef;
import akka.actor.ActorSystem;
import akka.actor.Props;

public class Main {
	public static void main(String[] args) {
		ActorSystem system = ActorSystem.create("helloakka");
		ActorRef helloActor = system.actorOf(Props.create(Hello.class), "greeter");
		helloActor.tell("Isn't this cool!", ActorRef.noSender());

	}
}
