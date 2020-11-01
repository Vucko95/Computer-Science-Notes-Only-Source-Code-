package map;
import akka.actor.ActorRef;
import akka.actor.ActorSystem;
import akka.actor.Props;

public class Main {

	public static void main(String[] args) {
		ActorSystem system = ActorSystem.create("ContentSystem");
		 
	    // create the result listener, which will print the result and shutdown the system
	    final ActorRef master = system.actorOf(Props.create(Master.class), "master");
	 
	    // start the calculation
	    master.tell(new Init(10000000,5), null);		
	}
}
