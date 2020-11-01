
public class StringStack {
	private String[] array = new String[20];
	private int top = 0;
	
	public int size() {
		return top;
	}
	
	public boolean isEmpty() {
		return top == 0;
	}
	
	public void push(String value) {
		if (top == array.length) throw new StackFullException();
		array[top++] = value;
	}
	
	public String top() {
		if (top == 0) throw new StackEmptyException(); 
		return array[top-1];
	}

	public String pop() {
		if (top == 0) throw new StackEmptyException();
		
		String temp = array[--top];
		array[top] = null;
		return temp;
	}
	
	public String toString() {
		String out = "[" + top + " / " + array.length + "]";
		for (int i=0;i<array.length; i++) {
			out += " " + array[i];
		}
		return out;
	}
	
	public static void main(String[] args) {
		StringStack stack = new StringStack();
		
		stack.push("mat");
		System.out.println(stack);

		stack.push("the");
		System.out.println(stack);
		
		stack.push("the");
		System.out.println(stack);
		
		stack.pop();
		System.out.println(stack);
		
		stack.push("on");
		System.out.println(stack);

		stack.push("sat");
		System.out.println(stack);

		stack.push("pat");
		System.out.println(stack);

		stack.pop();
		System.out.println(stack);
		
		stack.push("cat");
		System.out.println(stack);

		stack.push("the");
		System.out.println(stack);

		stack.pop();
		System.out.println(stack);
		
		stack.push("The");
		System.out.println(stack);
		
		while (!stack.isEmpty()) {
			System.out.print(stack.pop() + " ");
		}
	}
}
