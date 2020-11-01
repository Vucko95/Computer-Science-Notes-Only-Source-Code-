


public class W1Q6 {
	public static void main(String[] args) {
		char[] A = { 'H', 'A', 'P', 'P', 'Y' };
		
		int l = 0;
		int r = 4;
		
		while (l < r) {
			char t = A[l];
			A[l] = A[r];
			A[r] = t;
			l++;
			r--;
		}
		
		for (int j=0; j <= 4; j++) {
			System.out.print(A[j]);
		}
	}
}