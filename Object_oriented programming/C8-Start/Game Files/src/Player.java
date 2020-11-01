
public class Player extends Ship {
  public Player(int x1, int y1, int c) {
    super(x1, y1, c, true);
    heal(MAX_HEALTH);
  }

  public Bullet fire() {
    Bullet b = null;
    if (cooldown == 0) {
      b = new Bullet(x, y, true, 5);
      cooldown = 10;
    }
    return b;
  }

  public int getPoints() {
    return 0;
  }

  public void move() {

  }
}
