/**
   Describes a product with a description and a price.
*/
public class Product
{  
   private String description;
   private double price;

   /**
      Constructs a product from a description and a price.
      @param aDescription the product description
      @param aPrice the product price
   */
   public Product(String aDescription, double aPrice)
   {  
      description = aDescription;
      price = aPrice;
   }
   
   /**
      Gets the product description.
      @return the description
   */
   public String getDescription()
   {  
      return description;
   }

   /**
      Gets the product price.
      @return the unit price
   */
   public double getPrice()
   {
      return price;
   }
}

