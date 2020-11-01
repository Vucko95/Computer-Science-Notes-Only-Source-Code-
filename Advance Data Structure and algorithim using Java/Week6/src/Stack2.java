class Stack2 {
  private int maxSize;

  private char[] stackArray;

  private int top;

  public Stack2(int s) {
    maxSize = s;
    stackArray = new char[maxSize];
    top = -1; 
  }

  public void push(char j) {
    stackArray[++top] = j;
  }

  public char pop() {
    return stackArray[top--];
  }

  public char peek() {
    return stackArray[top];
  }

  public boolean isEmpty() {
    return (top == -1);
  }

  public boolean isFull() {
    return (top == maxSize - 1);
  }


  public static void main(String[] args) {
    String input = "input";
    int stackSize = input.length();

    Stack2 theStack = new Stack2(stackSize);

    for (int j = 0; j < input.length(); j++) {
      char ch = input.charAt(j);
      theStack.push(ch);
    }

    while (!theStack.isEmpty()) {
      char ch = theStack.pop();
      System.out.println(ch);
    }
  }
}