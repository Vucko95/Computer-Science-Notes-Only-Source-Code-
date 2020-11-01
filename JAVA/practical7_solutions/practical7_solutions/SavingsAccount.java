package practical7_solutions;

public class SavingsAccount extends Account {
	
	// Construct a savings account
	public SavingsAccount() {
	}
	
	// Construct a savings account with the specified id and balance 
	public SavingsAccount(int id, double balance) {
		super(id, balance);
	}
	
	// Withdraw the amount specified
	@Override
	public void withdraw(double amount) {
		if (getBalance() - amount < 0)
			System.out.printf("\tYour current balance is $%.2f. " + 
					"You have attempted to withdraw $%.2f."+
					"\n\tThis transaction cannot be completed. " + 
					"Your balance is unchanged.\n", getBalance(), amount);
		else 
			super.withdraw(amount);
	}
}
