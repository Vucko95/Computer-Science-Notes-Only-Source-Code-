import example4.MyClass;

public class MyClassExample {
	public static void main(String[] args) {
		MyClass<String> myClass = new MyClass<String>();
		myClass.setData("rem");
		System.out.println("myclass data: " + myClass.getData());
		
		MyClass<Integer> otherMyClass = new MyClass<Integer>();
		otherMyClass.setData(10);
		System.out.println("othermyclass data: " + otherMyClass.getData());
//		if (myClass.getData() instanceof Integer) {
			otherMyClass.setData(otherMyClass.getData()*2);
//		} else if (myClass.getData() instanceof String) {
			System.out.println("it was a string: " + myClass.getData());
//		}
		
	}
}
