package service.core;

public class Quotation implements java.io.Serializable {
	public Quotation() {
	}
	public Quotation(String company, String reference, double price) {
		this.company = company;
		this.reference = reference;
		this.price = price;
	}
	public String company;
	public String reference;
	public double price;
}
