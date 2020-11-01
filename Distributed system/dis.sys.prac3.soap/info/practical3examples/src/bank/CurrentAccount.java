package bank;

public class CurrentAccount implements BankAccount {
	private double balance;
	
	public CurrentAccount() {
		balance = 0;
	}
	
	@Override
	public void deposit(double amount) {
		balance += amount;
	}

	@Override
	public boolean withdraw(double amount) {
		if (balance > amount) {
			balance -= amount;
			return true;
		}
		return false;
	}

	@Override
	public double balance() {
		return balance;
	}

}
