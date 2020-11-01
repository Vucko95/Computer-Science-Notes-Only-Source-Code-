



public class W1Q8 {
	public static void main(String[] args) {
		int[] A = { 5, 7, 3, 12, 6, 11, 1, 19, 9, 4 };
		
		int j = 1;
		int t = A[0];
		while (j < 10) {
			A[j-1] = A[j];
			j++;
		}
		A[j-1] = t;
		
		for(j=0; j < 10; j++) {
			System.out.print(A[j] + " ");
		}
				
	}
}