/**
   A bank customer with a checking and a savings account.
*/
public class Customer
{  
   private int customerNumber;
   private int pin;
   private BankAccount checkingAccount;
   private BankAccount savingsAccount;

   /**
      Constructs a customer with a given number and PIN.
      @param aNumber the customer number
      @param aPin the personal identification number
   */
   public Customer(int aNumber, int aPin)
   {  
      customerNumber = aNumber;
      pin = aPin;
      checkingAccount = new BankAccount();
      savingsAccount = new BankAccount();
   }
   
   /** 
      Tests if this customer matches a customer number 
      and PIN.
      @param aNumber a customer number
      @param aPin a personal identification number
      @return true if the customer number and PIN match
   */
   public boolean match(int aNumber, int aPin)
   {  
      return customerNumber == aNumber && pin == aPin;
   }
   
   /** 
      Gets the checking account of this customer.
      @return the checking account
   */
   public BankAccount getCheckingAccount()
   {  
      return checkingAccount;
   }
   
   /** 
      Gets the savings account of this customer.
      @return the checking account
   */
   public BankAccount getSavingsAccount()
   {  
      return savingsAccount;
   }
}
