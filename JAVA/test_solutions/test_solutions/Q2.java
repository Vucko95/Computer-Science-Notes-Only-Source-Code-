package test_solutions;

public class Q2 {
	public static void main(String[] args) {
		// test cases

		// should return: "" (i.e. a string with no characters)
		System.out.println("test case 1: " + getLCS("hello", "HELLO"));
	
		// should return: "ing"
		System.out.println("test case 2: " + getLCS("computing", "working"));
	}

	public static String getLCS(String s1, String s2) {
		String suffix = ""; 

		// Get the largest common suffix - iterate over the strings and exit
		// the loop when the corresponding characters in the strings differ
		for (int i = s1.length() - 1, j = s2.length() - 1;
				i >= 0 && j >= 0 && s1.charAt(i) == s2.charAt(j); 
				i--, j--)
			suffix = s1.charAt(i) + suffix;

		return suffix;
	}
}
