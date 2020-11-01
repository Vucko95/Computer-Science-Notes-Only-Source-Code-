package practical6;

public class TestAccount {
	public static void main (String[] args) {
		// Create a new account with the specified id and balance
		Account account = new Account(1122, 20000);
		// Set the annual interest rate
		Account.setAnnualInterestRate(0.045);
		// Withdraw the specified amount
		account.withdraw(2500);
		// Deposit the specified amount
		account.deposit(3000);
		
		// Display account information
		System.out.printf("Balance is %.2f\n", account.getBalance());
		System.out.printf("Monthly interest amount is %.2f\n", account.getMonthlyInterest());
		System.out.println("This account was created on " + account.getDateCreated().toString());
	}
}
