


public class W1Q4 {
	public static void main(String[] args) {
		int i = 0;
		int s = 0;
		
		while (i < 100) {
			if (i % 10 == 0) s = s + i;
			i = i + 1;
		}
		System.out.println("result: " + s);
	}
}
