package si.model;

import java.awt.Rectangle;
import java.awt.Shape;
import java.util.ArrayList;
import java.util.List;

public class Bullet implements Movable, Hittable, Drawable {
  private int x, y;
  private boolean direction; // True for up, false for down
  private boolean destroyed = false;
  private Rectangle hitBox;
  private String name;
  private static int bulletCounter = 0;
  private static final int BULLET_HEIGHT = 8;
  private static final int BULLET_WIDTH = 4;
  private static final int BULLET_SPEED = 10;

  public Bullet(int x, int y, boolean direction, String name) {
    this.direction = direction;
    this.x = x;
    this.y = y;
    this.name = name + " " + bulletCounter++;
    hitBox = new Rectangle(x, y, BULLET_WIDTH, BULLET_HEIGHT);
  }

  public void move() {
    if (direction) {
      y -= BULLET_SPEED;
    } else {
      y += BULLET_SPEED;
    }
    hitBox.setLocation(x, y);
  }

  public int getX() {
    return x;
  }

  public int getY() {
    return y;
  }

  public boolean isHit(Bullet b) {
    Rectangle r = b.getHitBox();
    if (hitBox.intersects(r)) {
      destroyed = true;
    }
    return hitBox.intersects(r);
  }

  public boolean isDestroyed() {
    return destroyed;
  }

  public int getPoints() {
    return 0;
  }

  public boolean isPlayer() {
    return false;
  }

  public void destroy() {
    destroyed = true;
  }

  public List<Shape> getShapes() {
    List<Shape> ss = new ArrayList<Shape>();
    ss.add(hitBox);
    return ss;
  }

  public String getFireerName() {
    return name;
  }

  public Rectangle getHitBox() {
    return hitBox;
  }

}
