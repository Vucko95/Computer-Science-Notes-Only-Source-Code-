package service.core;

import java.util.Random;

public abstract class AbstractQuotationService implements QuotationService {
	private int counter = 1000;
	private Random random = new Random();
	
	protected String generateReference(String prefix) {
		String ref = prefix;
		int length = 100000;
		while (length > 1000) {
			if (counter / length == 0) ref += "0";
			length = length / 10;
		}
		return ref + counter++;
	}

	protected double generatePrice(double min, int range) {
		return min + (double) random.nextInt(range);
	}
}
