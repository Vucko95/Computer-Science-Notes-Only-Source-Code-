package service.core;

public class Quotation {
  public Quotation(String company, String reference, double price) {
    this.reference = reference;
    this.company = company;
    this.price = price;
  }

  public String reference;
  public String company;
  public double price;

  public void merge(Quotation quotation) {
    if (company == null) company = quotation.company;
    if (reference == null) reference = quotation.reference;
    if (price == 0) price = quotation.price;
  }

  public String toString() { return reference + " = { " + company + " " + reference + ", " + price + " }"; }

  public String getReference() { return reference; }

  public void setReference(String reference) { this.reference = reference; }
}
