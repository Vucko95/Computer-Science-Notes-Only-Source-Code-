
public class Factorial {
	
	public static int iterFactorial(int i) {
		int j, answer;
		answer = 1;
		for (j=1; j<=i; j++) {
			answer = answer * j;
		}
		return answer;
	}

	public static int recursiveFactorial(int n) {	// recursive factorial function
		  if (n == 0) return 1;				// basis case
		  else return n * recursiveFactorial(n-1);	// recursive case
		}

	public static void main(String[] args) {
		int a;
		for (a=0; a< 10; a++) {
			System.out.println(a + " " + recursiveFactorial(a) +
					" " + iterFactorial(a) + " " + 
					(recursiveFactorial(a)-iterFactorial(a)));
		}
	}
}
