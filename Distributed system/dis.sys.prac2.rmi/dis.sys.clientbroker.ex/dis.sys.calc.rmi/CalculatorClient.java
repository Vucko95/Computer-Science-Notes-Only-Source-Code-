import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class CalculatorClient {
	public static void main(String[] args) {
		try {
			Registry registry = LocateRegistry.getRegistry();
			Calculator c = (Calculator) registry.lookup("CalculatorService");
			System.out.println(c.sub(4, 3));
			System.out.println(c.add(4, 5));
			System.out.println(c.mul(3, 6));
			System.out.println(c.div(9, 3));
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
