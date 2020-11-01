package map;

import akka.actor.Kill;
import akka.actor.UntypedActor;

public class Worker extends UntypedActor {

	@Override
	public void onReceive(Object message) throws Throwable {
		if (message instanceof Problem) {
			Problem problem = (Problem) message;
			int sum = 0;
			for (int i=problem.start; i<problem.end; i++) {
				sum += problem.list[i];
			}
			getSender().tell(new Result(sum), getSelf());
			getSelf().tell(Kill.getInstance(), getSelf());
		}
	}

}
