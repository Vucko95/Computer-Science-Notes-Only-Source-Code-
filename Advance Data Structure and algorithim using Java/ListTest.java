
public class ListTest {

	public static void main(String[] args) {
		List<String> list = new LinkedList<String>();
		
		Position<String> f = list.insertFirst("Rem");
		list.insertFirst("Peppa");
		list.insertAfter(f, "George");
		
		// Display the contents of the list
		Position<String> p = list.first();
		while (p != list.last()) {
			System.out.println(p.element());
			p = list.next(p);
		}
		System.out.println(p.element());
	}

}
