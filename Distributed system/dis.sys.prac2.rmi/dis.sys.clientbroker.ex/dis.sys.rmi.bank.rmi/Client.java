package bank;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/** Bank */

public class Client {
  public static void main(String[] args) {
    Registry registry = LocateRegistry.getRegistry("localhost", 1099);
    BankAccount account = (BankAccount)registry.lookup("823928379");
    account.deposit(100);
    System.out.println(account.balance());
  }
}
