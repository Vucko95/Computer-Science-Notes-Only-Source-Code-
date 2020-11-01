package practical7_solutions;

public class CheckingAccount extends Account{
	private double overdraftLimit;

	// Construct a savings account and set the date of creation
	public CheckingAccount() {
		this(0, 0);
	}

	// Construct a savings account and set the id, balance and date of creation
	public CheckingAccount(int id, double balance) {
		super(id, balance);
		overdraftLimit = 1000;
	}
	
	// Return the overdraft limit
	public double getOverdraftLimit() {
		return overdraftLimit;
	}

	// Set a new overdraft limit
	public void setOverdraftLimit(double overdraftLimit) {
		this.overdraftLimit = overdraftLimit;
	}

	// Return the monthly interest amount
	@Override
	public double getMonthlyInterest() {
		return (getBalance() > 0) ? super.getMonthlyInterest() : 0;
	}
	
	// Withdraw the amount specified
	@Override
	public void withdraw(double amount) {
		if (getBalance() - amount < -1 * overdraftLimit)
			System.out.printf("\tYour current balance is $%.2f. " + 
					"Your overdraft limit is $%.2f." +
					"\n\tYou have attempted to withdraw $%.2f."+
					"\n\tThis transaction cannot be completed. " + 
					"Your balance is unchanged.\n", getBalance(), overdraftLimit, amount);
		else 
			super.withdraw(amount);
	}
	
	// Return a String representation 
	@Override
	public String toString() {
		return super.toString() + ", overdraft limit = " + overdraftLimit;
	}
}
