import java.util.Random;

public class Dice {
  private static Random rng = new Random();

  public static int roll1D6() {// name means roll 1 6 sided dice
    int d = rng.nextInt(6); // generate a number between 0 and 5
    return 1 + d; // add one to the value so the range is between 1 and 6
  }

  public static int roll2D6() { // roll 2 six 6 dice and add the values
    int d = roll1D6() + roll1D6(); // call the method and add the results
    return d; // return the calculated answer
  }
}
