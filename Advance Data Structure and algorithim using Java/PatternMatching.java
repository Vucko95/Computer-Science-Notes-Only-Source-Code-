


public class PatternMatching {
	public static int bruteForceSearch(String T, String P) {
		int i = 0;
		while (i < T.length() - P.length()) {
			int j =0;
			while (j < P.length() && T.charAt(i+j) == P.charAt(j)) {
				j++;
			}
			if (j == P.length()) return i;
			i++;
		}
		return -1;
	}
	
}
