package worksheet5;


public class W5Q4 {

	public static void main(String[] args) {
		Stack<Integer> stack = new LinkedStack<Integer>();
		stack.push(2);
		stack.pop();
		stack.push(4);
		stack.push(3);
		stack.pop();
		stack.push(6);
		stack.push(12);
		stack.pop();
		stack.push(5);
		stack.push(9);
		stack.pop();
		stack.push(3);
		
		int total = 0;
		int count=0;
		while ( !stack.isEmpty() ) {
			total += (Integer) stack.pop();
			count++;
		}
		System.out.println("average: " + total/count);
	}

}
