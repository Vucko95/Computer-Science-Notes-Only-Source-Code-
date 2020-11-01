package service.core;

/**
 * Class to store the quotations returned by the quotation services
 * @author Rem
 */

// ===========================================================================================
// this has all the infromation from quotation giving the companies, reference and price its own assignemnts
// ===========================================================================================

public class Quotation {
	public Quotation(String company, String reference, double price) {
		this.company = company;
		this.reference = reference;
		this.price = price;
	}

	public String company;
	public String reference;
	public double price;
}
