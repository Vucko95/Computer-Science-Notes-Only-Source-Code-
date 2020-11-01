



public class W1Q10 {
	public static void main(String[] args) {
		int[] A = { 5, 7, 3, 12, 6, 11, 1, 19, 9, 4 };
		
		int j = 0;
		while (j < 10) {
			int m = j;
			for(int k=j+1; k < 10; k++) {
				if (A[m] > A[k]) m = k;
			}
			
			if (m != j) {
				int t = A[j];
				A[j] = A[m];
				A[m] = t;
			}

			j++;
		}
		
		for(j=0; j < 10; j++) {
			System.out.print(A[j] + " ");
		}
				
	}
}