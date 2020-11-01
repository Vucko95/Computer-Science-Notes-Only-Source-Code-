/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rmiproject;

import java.util.Random;

public abstract class RMIAbstractQuotationService implements RMIQuotationServices {
	private int counter = 1000;
	private Random random = new Random();

	protected String generateReference(String prefix) { // generates an increment of quotations
		String ref = prefix;
		int length = 100000;
		
		while (length > 1000) { 				  	// always running 
			if (counter / length == 0)        // always 0 
				ref += "0"; 					          // making a ref
			length = length / 10; 					  // resets 
		}
		return ref + counter++; 					  // cycling through them 
	}

	protected double generatePrice(double min, int range) { // generates proces for everyone ... Doggy, Girl, Boy	
		return min + (double) random.nextInt(range);
	}
}
