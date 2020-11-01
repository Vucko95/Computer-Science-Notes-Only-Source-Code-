package chapter13_examples_2;

public class ComparableRectangle extends Rectangle
    implements Comparable<ComparableRectangle> {

	// Construct a default comparable rectangle object
	public ComparableRectangle() {
	}

	// Construct a comparable rectangle object with the specified width and height
	public ComparableRectangle(double width, double height) {
		super(width, height);
	}
	
	// Construct a comparable rectangle object with the specified width, height, color 
	// and filled value 
	public ComparableRectangle(double width, double height, String color, boolean filled) {
		super(width, height, color, filled);
	}

	// Implement the compareTo method defined in Comparable
	@Override  
	public int compareTo(ComparableRectangle o) {
		if (getArea() > o.getArea())
			return 1;
		else if (getArea() < o.getArea())
			return -1;
		else
			return 0;
	}
}
