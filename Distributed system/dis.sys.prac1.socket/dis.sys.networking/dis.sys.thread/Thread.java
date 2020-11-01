/**
 * Thread
 */
public class Thread implements Runnable{
	private String name; 
	public MyThread(String name) {
		this.name = name; 
	}
	public void run(){
		for(int i = 0; i < 2; i++) {
			// System.out.println(name + "="+i);
			Thread t = new Thread(new MyThread("rem")); 
			t.start(); 
		}
	}
}
