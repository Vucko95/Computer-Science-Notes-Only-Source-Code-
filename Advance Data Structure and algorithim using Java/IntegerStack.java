
public class IntegerStack {
	private int[] array = new int[20];
	private int top = 0;
	
	public int size() {
		return top;
	}
	
	public boolean isEmpty() {
		return top == 0;
	}
	
	public void push(int value) {
		if (top == array.length) throw new StackFullException();
		array[top++] = value;
	}
	
	public int top() {
		if (top == 0) throw new StackEmptyException(); 
		return array[top-1];
	}

	public int pop() {
		if (top == 0) throw new StackEmptyException();
		return array[--top];
	}
	
	public String toString() {
		String out = "[" + top + " / " + array.length + "]";
		for (int i=0;i<array.length; i++) {
			out += " " + array[i];
		}
		return out;
	}
	
	public static void main(String[] args) {
		IntegerStack stack = new IntegerStack();
		
		stack.push(17);
		System.out.println(stack);

		stack.push(11);
		System.out.println(stack);
		
		stack.push(12);
		System.out.println(stack);
	}
}
