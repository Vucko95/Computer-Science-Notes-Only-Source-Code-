package dsaii.collections;

public class Main {
    public static void main(String[] args) {
        Stack<Character> stack = new ArrayStack<Character>();
        String word = "reverse";
        for (int i=0; i < word.length(); i++) {
            stack.push(word.charAt(i));
        }

        StringBuffer buf = new StringBuffer();
        while (!stack.isEmpty()) {
            buf.append(stack.pop());
        }
        System.out.println("reversed: " + buf.toString());
    }
}
