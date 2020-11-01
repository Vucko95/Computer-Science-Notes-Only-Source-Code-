package practical6;

import java.util.Date;

public class Account {
	private int id; // The account id
	private double balance; // The account balance
	private Date dateCreated; // The date this account is created

	private static double annualInterestRate = 0; // The annual interest rate - applies to all accounts
	
	// Construct an account and set the date of creation
	public Account() {
		this(0, 0);
	}

	// Construct an account and set the id and balance and set the date of creation
	public Account(int id, double balance) {
		this.id = id;
		this.balance = balance;
		dateCreated = new Date();
	}

	// Return the id
	public int getId() {
		return this.id;
	}

	// Return the balance
	public double getBalance() {
		return balance;
	}

	// Return the annual interest rate
	public static double getAnnualInterestRate() {
		return annualInterestRate;
	}

	// Return the date of creation
	public Date getDateCreated() {
		return dateCreated;
	}

	// Set a new id
	public void setId(int id) {
		this.id = id;
	}

	// Set a new balance
	public void setBalance(double balance) {
		this.balance = balance;
	}

	// Set a new annual interest rate
	public static void setAnnualInterestRate(double annualInterestRate) {
		Account.annualInterestRate = annualInterestRate;
	}

	// Return the monthly interest amount
	public double getMonthlyInterest() {
		return balance * annualInterestRate / 12;
	}

	// Withdraw the amount specified
	public void withdraw(double amount) {
		balance -= amount;
	}

	// Deposit the amount specified
	public void deposit(double amount) {
		balance += amount;
	}

	// Return a String representation 
	public String toString() {
		return "id = " + id + ", balance = " + balance + ", date created = " + dateCreated;
	}
}
