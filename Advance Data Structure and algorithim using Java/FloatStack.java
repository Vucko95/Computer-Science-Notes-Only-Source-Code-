
public class FloatStack {
	private float[] array = new float[20];
	private int top = 0;
	
	public int size() {
		return top;
	}
	
	public boolean isEmpty() {
		return top == 0;
	}
	
	public void push(float value) {
		if (top == array.length) throw new StackFullException();
		array[top++] = value;
	}
	
	public float top() {
		if (top == 0) throw new StackEmptyException(); 
		return array[top-1];
	}

	public float pop() {
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
		FloatStack stack = new FloatStack();
		
		stack.push(13.2f);
		System.out.println(stack);

		stack.push(4.2f);
		System.out.println(stack);
		
		stack.push(3.0f);
		System.out.println(stack);

		stack.push(2.6f);
		System.out.println(stack);

		stack.pop();
		System.out.println(stack);
		
		stack.pop();
		System.out.println(stack);
		
		stack.push(1.2f);
		System.out.println(stack);

		stack.pop();
		System.out.println(stack);
		
		stack.pop();
		System.out.println(stack);
		
		stack.push(5.4f);
		System.out.println(stack);

		stack.push(6.9f);
		System.out.println(stack);
		
		float total = 0.0f;
		while (!stack.isEmpty()) {
			total += stack.pop();
		}
		System.out.println("total: " + total);
	}
}
