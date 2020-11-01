import java.awt.Rectangle;

public class Bullet implements Hittable, Movable {
  private int x, y;
  private boolean up; // true for up, false for down
  private int damage;
  public static final int BULLET_WIDTH = 5;
  private Rectangle box;
  private boolean hit;

  public Bullet(int x1, int y1, boolean u, int d) {
    x = x1;
    y = y1;
    up = u;
    damage = d;
    box = new Rectangle(x, y, BULLET_WIDTH, BULLET_WIDTH);
    hit = false;
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
    box.y = y;
  }

  public boolean isHit(Bullet r) {
    if (this != r) {
      if (box.intersects(r.box)) {
        return true;
      }
    }
    return false;
  }

  public boolean isDestroyed() {
    return hit;
  }

  public int getPoints() {
    return 0;
  }

  public Rectangle getShape() {
    return box;
  }

  public void takeDamage(Bullet b) {
    hit = true;
    b.hit = true;
  }
}
