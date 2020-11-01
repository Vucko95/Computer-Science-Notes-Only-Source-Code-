import java.util.Random;

public class Lecture3 {

	public static void main(String[] args) {
		Random random = new Random();
		
		for (int j=10000; j < 100000; j+=10000) {
			System.out.print(j);
			// prepare the data
			int[] data = new int[j];
			for(int i=0; i<data.length; i++) {
				data[i] = random.nextInt();
			}
			
			// run algorithm 1
			long cumulativeDuration = 0;
			for (int i=0; i < 5; i++) {
				long start = System.currentTimeMillis();
				alg1(data);
				long duration = System.currentTimeMillis() - start;
				cumulativeDuration += duration;
			}
			System.out.print(", " + (cumulativeDuration/5));
			
			// run algorithm 2
			cumulativeDuration = 0;
			for (int i=0; i < 5; i++) {
				long start = System.currentTimeMillis();
				alg2(data);
				long duration = System.currentTimeMillis() - start;
				cumulativeDuration += duration;
			}
			System.out.println(", " + (cumulativeDuration/5));
		}
	}

	public static int[] alg1(int[] A) {
		int[] N = new int[A.length];
		for (int i = 0; i < A.length; i++) {
			int a = 0;
			for (int j = 0; j < i; j++) {
				a += A[j];
			}
			N[i] = a / (i + 1);
		}
		return N;
	}

	public static int[] alg2(int[] A) {
		int[] N = new int[A.length];
		int s = 0;
		for (int i = 0; i < A.length; i++) {
			s += A[i];
			N[i] = s / (i + 1);
		}
		return N;
	}

}
