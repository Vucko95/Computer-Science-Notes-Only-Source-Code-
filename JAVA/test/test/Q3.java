package test;

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

	// write this method
	public static boolean isBalanced(String p) {
		return false;
	}
}
