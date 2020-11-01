
public class Bullet {
  private int x, y;
  private boolean up; // true for up, false for down
  private int damage;

  public Bullet(int x1, int y1, boolean u, int d) {
    x = x1;
    y = y1;
    up = u;
    damage = d;
  }

  public void printBullet() {
    if (up) {
      System.out.println("Bullet located at (" + x + ", " + y + ") moving up");
    } else {
      System.out.println("Bullet located at (" + x + ", " + y + ") moving down");
    }
  }

  public int getPower() {
    return damage;
  }

  public int getX() {
    return x;
  }

  public int getY() {
    return y;
  }

  public void move() {
    if (up) {
      y = y - 2;
    } else {
      y = y + 2;
    }
  }
}
