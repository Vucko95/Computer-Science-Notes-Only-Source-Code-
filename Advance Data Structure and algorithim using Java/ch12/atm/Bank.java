import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
   A bank contains customers with bank accounts.
*/
public class Bank
{  
   private ArrayList<Customer> customers;

   /**
      Constructs a bank with no customers.
   */
   public Bank()
   {  
      customers = new ArrayList<Customer>();
   }
   
   /**
      Reads the customer numbers and pins 
      and initializes the bank accounts.
      @param filename the name of the customer file
   */
   public void readCustomers(String filename) 
         throws IOException
   {  
      Scanner in = new Scanner(new File(filename));
      while (in.hasNext())
      {  
         int number = in.nextInt();
         int pin = in.nextInt();
         Customer c = new Customer(number, pin);
         addCustomer(c);
      }
      in.close();
   }
   
   /**
      Adds a customer to the bank.
      @param c the customer to add
   */
   public void addCustomer(Customer c)
   {  
      customers.add(c);
   }
   
   /** 
      Finds a customer in the bank.
      @param aNumber a customer number
      @param aPin a personal identification number
      @return the matching customer, or null if no customer 
      matches
   */
   public Customer findCustomer(int aNumber, int aPin)
   {  
      for (Customer c : customers)
      {  
         if (c.match(aNumber, aPin))
            return c;
      }
      return null;
   }
}


