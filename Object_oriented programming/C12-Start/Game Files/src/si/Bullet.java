package si;
import java.awt.Rectangle;

public class Bullet implements Hittable, Movable, Drawable {
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

  public String toString() {
    String s = "Bullet located at (" + x + ", " + y + ") the bullet is travelling ";
    if (up) {
      s += "up";
    } else {
      s += "down";
    }
    s += " and has power " + damage;
    return s;
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
        hit = true;
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

  public Rectangle getHitBox() {
    return box;
  }

  public boolean equals(Object o) {
    if (o instanceof Bullet) {
      Bullet b = (Bullet) o;
      if (this.x == b.x && this.y == b.y && this.damage == b.damage && this.up == b.up) {
        return true;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }

  public void takeDamage(Bullet bullet) {
    hit = true;
    bullet.hit = true;
  }

  public Rectangle[] getShape() {
    return new Rectangle[] { new Rectangle(box) };
  }
}
