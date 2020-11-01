public class Enemy extends Ship {
  private AlienType type;

  public Enemy(int x1, int y1, int c, AlienType a) {
    super(x1, y1, c, false);
    type = a;
    heal(5);
  }

  public Bullet fire() {
    Bullet b = null;
    if (cooldown == 0) {
      // TODO calculate correct location for bullet
      b = new Bullet(x, y, true, 5);
      cooldown = 10;
    }
    return b;
  }

  public int getPoints() {
    return type.getScore();
  }
  
  public void move() {
    // TODO calculate how to move ship
  }
}