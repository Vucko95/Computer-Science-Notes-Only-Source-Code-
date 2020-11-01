



public class W1Q9 {
	public static String fn(int num, int digits) {
		String output = "";
		int mult = 1;
		for(int j=1;j<=digits; j++) {
			if (num < mult) output += "0";
			mult = mult * 10;
		}
		output += num;
		return output;
	}
	
	public static void main(String[] args) {
		System.out.println(fn(75,6));
	}
}