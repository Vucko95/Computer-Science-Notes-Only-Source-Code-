/**
   Describes a mailing address.
*/
public class Address
{  
   private String name;
   private String street;
   private String city;
   private String state;
   private String zip;

   /**
      Constructs a mailing address. 
      @param aName the recipient name
      @param aStreet the street
      @param aCity the city
      @param aState the two-letter state code
      @param aZip the ZIP postal code
   */
   public Address(String aName, String aStreet,
         String aCity, String aState, String aZip)
   {  
      name = aName;
      street = aStreet;
      city = aCity;
      state = aState;
      zip = aZip;
   }   

   /**
      Formats the address.
      @return the address as a string with three lines
   */
   public String format()
   {  
      return name + "\n" + street + "\n"
            + city + ", " + state + " " + zip;
   }
}

