
public class W4Q3 {

	public static void main(String[] args) {
		Stack stack = new ArrayStack();
		stack.push(13.2);
		stack.push(4.2);
		stack.push(3.0);
		stack.push(2.6);
		stack.pop();
		stack.pop();
		stack.push(1.2);
		stack.pop();
		stack.pop();
		stack.push(5.4);
		stack.push(6.9);
		
		double total = 0.0;
		while ( !stack.isEmpty() ) {
			total += (Double) stack.pop();
		}
		System.out.println("remaining total: " + total);
	}

}
