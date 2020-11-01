/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rmiproject.serverside.datamapper;

public class Quotation implements java.io.Serializable {
	public Quotation(String company, String reference, double price) {
		this.company = company;
		this.reference = reference;
		this.price = price;
	}
	
	public String company;
	public String reference;
	public double price;
}