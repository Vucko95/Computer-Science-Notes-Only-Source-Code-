package chapter13_examples_5;

public class TestEdible {
	public static void main(String[] args) {
		// Declare, create and initialise an array of animal and fruit objects
		Object[] objects = {new Tiger(), new Chicken(), new Apple(), new Orange()};
		
		// Iterate over the array and, for each object, display (if applicable)
		// how to eat the object and (if applicable) the sound the object makes
		for (int i = 0; i < objects.length; i++) {
			if (objects[i] instanceof Edible)
				System.out.println(((Edible)objects[i]).howToEat());

			if (objects[i] instanceof Animal) 
				System.out.println(((Animal)objects[i]).sound());
		}
	}
}

interface Edible {
	// Describe how to eat
	public abstract String howToEat();
}

abstract class Animal {
	// Data fields, constructors, and other methods omitted here
	public abstract String sound();
}

class Tiger extends Animal {
	@Override
	public String sound() {
		return "Tiger: RROOAARR";
	}
}

class Chicken extends Animal implements Edible {
	@Override
	public String sound() {
		return "Chicken: cock-a-doodle-doo";
	}
	
	@Override
	public String howToEat() {
		return "Chicken: Fry it";
	}
}

abstract class Fruit implements Edible {
	// Data fields, constructors, and methods omitted here
}

class Apple extends Fruit {
	@Override
	public String howToEat() {
		return "Apple: Make apple cider";
	}
}

class Orange extends Fruit {
	@Override
	public String howToEat() {
		return "Orange: Make orange juice";
	}
}
