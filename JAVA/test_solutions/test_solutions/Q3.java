package test_solutions;

public class Q3 {
	public static void main(String[] args) {
		// test cases...

		// the following test cases should return: true
		System.out.println(isBalanced(""));
		System.out.println(isBalanced("()"));
		System.out.println(isBalanced("()()"));
		System.out.println(isBalanced("(())"));

		// the following test cases should return: false
		System.out.println(isBalanced("("));
		System.out.println(isBalanced(")"));
		System.out.println(isBalanced("(()"));
		System.out.println(isBalanced("()(("));
	}
	
	public static boolean isBalanced(String p) {
		int counter = 0;
		
		for (int i = 0; i < p.length(); i++) {
			if (p.charAt(i) == '(')
				counter++;
			else
				counter--;
			
			if (counter < 0)
				return false;
		}
		
		return counter == 0;
	}
}
