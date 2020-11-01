package chapter11_examples;

public class TestCircleRectangle {
	public static void main(String[] args) {
		// Create a circle object
		Circle c1 = new Circle(5.0);
		System.out.println("circle: c1");
		System.out.println("The color is: " + c1.getColor());
		System.out.println("Is filled: " + c1.isFilled());
		System.out.println("The date of creation is: " + c1.getDateCreated());
		System.out.println("The radius is: " + c1.getRadius());
		System.out.printf("The area is: %.2f\n", c1.getArea());
		System.out.println();

		// Create another circle object
		Circle c2 = new Circle(10.0, "red", true);
		System.out.println("circle: c2");
		System.out.println("The color is: " + c2.getColor());
		System.out.println("Is filled: " + c2.isFilled());
		System.out.println("The date of creation is: " + c2.getDateCreated());
		System.out.println("The radius is: " + c2.getRadius());
		System.out.printf("The area is: %.2f\n", c2.getArea());
		System.out.println();
		
		// Create a rectangle object
		Rectangle r = new Rectangle(2.0, 4.0, "blue", false);
		System.out.println("rectangle: r");
		System.out.println("The color is: " + r.getColor());
		System.out.println("Is filled: " + r.isFilled());
		System.out.println("The date of creation is: " + r.getDateCreated());
		System.out.println("The width is: " + r.getWidth());
		System.out.println("The height is: " + r.getHeight());
		System.out.println("The area is: " + r.getArea());
		System.out.println("The perimeter is: " + r.getPerimeter());
	}	
}