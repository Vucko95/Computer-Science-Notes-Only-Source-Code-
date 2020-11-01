
package rmiproject;

// ports 7777, 7780, 7778
import java.util.Random;

public abstract class RMIAbstractQuotationService implements RMIQuotationServices {
	private int counter = 1000;
	private Random random = new Random();

	// generates an increment of quotations
	protected String generateReference(String prefix) { 
		String ref = prefix;
		int length = 100000;

		// always running . always 0 . making a ref. resets 
		while (length > 1000) {
			if (counter/length == 0)
				ref += "0";
			length = length / 10;
		}
		// cycling through them 
		return ref + counter++;
	}

	// generates proces for everyone ... Doggy, Girl, Boy	
	protected double generatePrice(double min, int range) {
		return min + (double) random.nextInt(range);
	}
}
