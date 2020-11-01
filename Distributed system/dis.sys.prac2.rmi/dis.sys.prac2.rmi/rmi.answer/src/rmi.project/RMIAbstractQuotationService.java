
package rmiproject;

import java.util.Random;

/* this file will give us the ability to callculate the updated quotations */

// this class will retrieve the calculations of Quotations service
public abstract class RMIAbstractQuotationService implements RMIQuotationServices {
	private int counter = 1000; // setting a counter
	private Random random = new Random(); // making sure we have a random object 

	// generates an increment of quotations
	protected String generateReference(String prefix) { 
		String ref = prefix;
		int length = 100000;

		// always running . always 0 . making a ref . resets 
		while (length > 1000) {
			if (counter / length == 0)
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
