package chapter13_examples_4;

public class TestAnimal {
	public static void main(String[] args) { 
		Animal[] animals = {new Chicken(), new Tiger()};
		
		// Iterate over the array and, for each animal, display
		// how to eat the animal and the sound the animal makes
		for (int i = 0; i < animals.length; i++) {
			System.out.println(animals[i].howToEat());
			System.out.println(animals[i].sound());
		}
	}
}

abstract class Animal {
	// Data fields, constructors, and other methods omitted here
	public abstract String howToEat();
	public abstract String sound();
}

class Chicken extends Animal { 
	@Override
	public String howToEat() {
		return "Chicken: Fry it"; 
	}
	
	@Override
	public String sound() {
		return "Chicken: cock-a-doodle-doo";
	}
}

class Tiger extends Animal { 
	@Override
	public String howToEat() {
		return "Tiger: Roast it"; 
	}
	
	@Override
	public String sound() {
		return "Tiger: RROOAARR";
	}
}
