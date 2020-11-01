
public class Lecture1 {
	public static int min(int a, int b) {
		if (a < b) return a;
		else return b;
	}
	
	public static int factorial(int a) {
		if (a == 0) return 1;

		int f = 1;
		for (int i=2; i <= a; i++) {
			f = f * i;
		}
		return f;
	}
	
	public static void main(String[] args) {
		System.out.println("Min: " + min(5, 7));
		System.out.println("Factorial 5 = " + factorial(5));
	}
}
