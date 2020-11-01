package practical7_solutions;

import java.util.Scanner;

public class Q2_Solution {

	public static void main(String[] args) {
		// Create an instance of the Scanner class
		Scanner input = new Scanner(System.in);

		// Prompt the user to create a savings or a checking account
		//*** Start #1 ***//
		Account account = createAccount(input);
		//*** End #1 ***//

		do {
			// Display options to users
			//*** Start #2 ***//
			if (!processOption(input, account))
				break;
			//*** End #2 ***//
		} while (true);

		// Display a final message
		System.out.println("\nGoodbye");

		// Close the Scanner
		input.close();
	}

	// Create an account
	public static Account createAccount(Scanner input) {
		int type = 0;
		do {
			System.out.println("What kind of account do you wish to create?");
			System.out.print("Enter 1 for savings and 2 for checking: ");
			type = input.nextInt();
		}
		while (type != 1 && type != 2);

		Account account;
		if (type == 1) account = new SavingsAccount();
		else account = new CheckingAccount();

		// Prompt the user to enter the account id, balance, and annual interest rate
		System.out.print("\nEnter the account id (int): ");
		int id = input.nextInt();
		account.setId(id);

		System.out.print("Enter the account balance (double): ");
		double balance = input.nextDouble();
		account.setBalance(balance);

		System.out.print("Enter the annual interest rate (double): ");
		double annualInterestRate = input.nextDouble();
		Account.setAnnualInterestRate(annualInterestRate);

		return account;
	}

	// Display options to users. Returns false if user chooses to exit; true otherwise
	public static boolean processOption(Scanner input, Account account) {
		// Display options to users 
		System.out.println(getOptions(account));

		int option = input.nextInt();
		if (option == 0)
			return false; 
		
		switch (option) {
		case 1: 
			System.out.println("\tThe id is: " + account.getId());
			System.out.println("\tThe account was created on: " + account.getDateCreated());
			break;
		case 2:
			System.out.printf("\tThe balance is: %.2f\n", account.getBalance());
			break;
		case 3:
			System.out.printf("\tThe monthly interest is: %.2f\n", account.getMonthlyInterest());
			break;
		case 4:
			System.out.print("\tEnter the amount to withdraw: ");
			double withdrawAmount = input.nextDouble();
			account.withdraw(withdrawAmount);
			break;
		case 5:
			System.out.print("\tEnter the amount to deposit: ");
			double depositAmount = input.nextDouble();
			account.deposit(depositAmount);
			break;	
		case 6:
			if (account instanceof CheckingAccount)
				System.out.printf("\tThe overdraft limit is: %.2f\n", ((CheckingAccount)account).getOverdraftLimit());
			else
				System.out.println("\tOption not available");
			break;
		case 7:
			if (account instanceof CheckingAccount) {
				System.out.print("\tEnter the new  overdraft limit: ");
				double limit = input.nextDouble();
				((CheckingAccount)account).setOverdraftLimit(limit);
			} else
				System.out.println("\tOption not available");
			break;	
		default: 
			System.out.println("\tInvalid option. Try again.");
		};
		
		return true;
	}

	// Return the user options
	public static String getOptions(Account account) {
		StringBuilder options = new StringBuilder();

		options.append("\nOptions:\n");
		options.append("1. Display account details\n");
		options.append("2. Display account balance\n");
		options.append("3. Display monthly interest\n");
		options.append("4. Make a withdrawal\n");
		options.append("5. Make a deposit\n");

		if (account instanceof CheckingAccount) {
			options.append("6. Display overdraft limit\n");
			options.append("7. Change overdraft limit\n");
		}

		options.append("0. To exit\n");
		options.append("Select an option (int): ");

		return options.toString();
	}
}
