package service.core;

/**
 * Class to store the quotations returned by the quotation services
 * 
 * @author Rem
 *
 */
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
