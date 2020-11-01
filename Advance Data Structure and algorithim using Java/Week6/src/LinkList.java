
class LinkList {
  private Link first;

  public LinkList() {
    first = null;
  }

  public boolean isEmpty() {
    return (first == null);
  }

  public void insertFirst(int dd) {
    Link newLink = new Link(dd);
    newLink.next = first;
    first = newLink;
  }

  public int deleteFirst() {
    Link temp = first;
    first = first.next;
    return temp.iData;
  }

  public String toString() {
    String str="";
    Link current = first;
    while (current != null) {
      str += current.toString();
      current = current.next;
    }
    return str;
  }
}
