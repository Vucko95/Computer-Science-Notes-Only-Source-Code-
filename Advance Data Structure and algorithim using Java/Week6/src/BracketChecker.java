import java.util.Stack;

class BracketChecker {
  private String input;

  public BracketChecker(String in) {
    input = in;
  }

  public void check() {
    Stack<Character> theStack = new Stack<Character>();

    for (int j = 0; j < input.length(); j++) {
      char ch = input.charAt(j);
      switch (ch) {
      case '{': 
      case '[':
      case '(':
        theStack.push(ch);
        break;
      case '}': 
      case ']':
      case ')':
        if (!theStack.isEmpty()) {
          char chx = theStack.pop();
          if ((ch == '}' && chx != '{') || (ch == ']' && chx != '[') || (ch == ')' && chx != '('))
            System.out.println("Error: " + ch + " at " + j);
        } else

          System.out.println("Error: " + ch + " at " + j);
        break;
      default:
        break;
      }
    }
    if (!theStack.isEmpty()){
      System.out.println("Error: missing right delimiter");
    }
  }

  public static void main(String[] args) {
    String input;
    input = "a{b(c]d}e";

    BracketChecker theChecker = new BracketChecker(input);
    theChecker.check();
  }

}
//input = "[]]()()";

//1. c[d] // correct
  //   2. a{b[c]d}e // correct
    // 3. a{b(c]d}e // not correct; ] doesn't match (
  //   4. a[b{c}d]e} // not correct; nothing matches final }
   //  5. a{b(c) // not correct; Nothing matches opening {