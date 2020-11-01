
class LinkStack {
  private LinkList theList;

  public LinkStack() {
    theList = new LinkList();
  }

  public void push(int j) {
    theList.insertFirst(j);
  }

  public double pop() {
    return theList.deleteFirst();
  }

  public boolean isEmpty() {
    return (theList.isEmpty());
  }

  public String toString() {
    return theList.toString();
  }


  public static void main(String[] args) {
    LinkStack the2Stack = new LinkStack();

    the2Stack.push(20);
    the2Stack.push(40);

    System.out.println(the2Stack);

    the2Stack.push(60);
    the2Stack.push(80);

    System.out.println(the2Stack);

    the2Stack.pop();
    the2Stack.pop();

    System.out.println(the2Stack);
  }}