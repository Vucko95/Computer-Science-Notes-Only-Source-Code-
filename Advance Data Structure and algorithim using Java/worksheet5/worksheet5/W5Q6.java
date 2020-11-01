package worksheet5;


public class W5Q6 {
	public static boolean parenMatch(String input) {
		Stack<Character> stack = new ArrayStack<Character>();
		for (int i=0; i < input.length(); i++) {
			char ch = input.charAt(i);
			switch (ch) {
			case '(':
			case '{':
			case '[':
				stack.push(ch);
				break;
			case ')':
				if (stack.isEmpty() || ((Character) stack.pop()) != '(') return false;
				break;
			case '}':
				if (stack.isEmpty() || ((Character) stack.pop()) != '{') return false;
				break;
			case ']':
				if (stack.isEmpty() || ((Character) stack.pop()) != '[') return false;
			}
//			System.out.println(stack.toString());
		}
		
		return stack.isEmpty();
	}
	
	public static void main(String[] args) {
		System.out.println("case 0: " + parenMatch("()"));
		System.out.println("case 1: " + parenMatch("()(()){([()])}"));
		System.out.println("case 2: " + parenMatch("((()(()){([()])}))"));
		System.out.println("case 3: " + parenMatch(")(()){([()])}"));
		System.out.println("case 4: " + parenMatch("({[])}"));
		System.out.println("case 5: " + parenMatch("("));
		System.out.println("case 6: " + parenMatch("SEQ(PAR(boil kettle, wash cup), add teabag, WAIT({kettle boiled}, add water, add milk)"));
	}
}
