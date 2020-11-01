package map;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import akka.actor.ActorRef;
import akka.actor.Kill;
import akka.actor.Props;
import akka.actor.UntypedActor;

public class Master extends UntypedActor {
	Random random = new Random();
	ActorRef[] workers = null;
	int count;
	int sum;
	long startTime;
	
	@Override
	public void onReceive(Object message) throws Throwable {
		if (message instanceof Init) {
			Init init = (Init) message;
			
			// Create the workers
			workers = new ActorRef[init.workers];
			for (int i=0; i<init.workers; i++) {
			      workers[i] = getContext().actorOf(Props.create(Worker.class), "worker_"+i);
			}
			
			// Create the list
			int[] list = new int[init.numbers];
			for (int i=0; i<init.numbers;i++) {
				list[i]=random.nextInt(100);
			}
			
			// Local Summation
			int lsum = 0;
			long st = System.currentTimeMillis();
			for (int i=0; i<init.numbers;i++) {
				lsum+= list[i];
			}
			System.out.println("local result = " + lsum);
			System.out.println("local time = " + (System.currentTimeMillis()-st) + "ms");
			
			// Start the actor based approach
			startTime = System.currentTimeMillis();
			
			// Distribute the problems
			int segment = init.numbers / init.workers;
			for (int i=0; i<init.workers; i++) {
				int x = i*segment;
				int y = x+segment-1;
//				System.out.println("range: " + x + " to: " +y);
				workers[i].tell(new Problem(list, x, y), getSelf());
			}
			
			count = 0;
			sum = 0;
		} else if (message instanceof Result) {
			// Collate the results
			sum += ((Result) message).value;
			count++;
			if (count == workers.length) {
				// Finished...
				System.out.println("result = " + sum);
				System.out.println("duration = " + (System.currentTimeMillis()-startTime) +"ms");
				System.exit(0);
			}
		}
	}

}
