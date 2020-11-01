package si.model;

import java.awt.Rectangle;
import java.awt.Shape;
import java.util.ArrayList;
import java.util.List;

public class Bunker implements Drawable, Hittable {
  private int brickScale = 5;
  private ArrayList<Brick> bricks;
  private int x, y;

  private class Brick implements Hittable {
    private boolean destroyed;
    private Rectangle hitBox;

    public Brick(int x, int y) {
      destroyed = false;
      hitBox = new Rectangle(x, y, brickScale, brickScale);
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

    public Shape getShape() {
      return new Rectangle(hitBox);
    }
  }


  public Bunker(int x1, int y1) {
    this.x = x1;
    this.y = y1;
    bricks = new ArrayList<Brick>();

    for (int i = 0; i < 6; i++) { // Top row
      bricks.add(new Brick(x + 2 * brickScale + i * brickScale, y + 0 * brickScale));
    }
    for (int i = 0; i < 8; i++) { // Second row
      bricks.add(new Brick(x + 1 * brickScale + i * brickScale, y + 1 * brickScale));
    }
    for (int i = 0; i < 10; i++) { // Third row
      bricks.add(new Brick(x + 0 * brickScale + i * brickScale, y + 2 * brickScale));
    }
    for (int i = 0; i < 4; i++) { // fourth row
      bricks.add(new Brick(x + 0 * brickScale + i * brickScale, y + 3 * brickScale));
      bricks.add(new Brick(x + 6 * brickScale + i * brickScale, y + 3 * brickScale));
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        bricks.add(new Brick(x + 0 * brickScale + i * brickScale, y + (j + 3) * brickScale));
        bricks.add(new Brick(x + 7 * brickScale + i * brickScale, y + (j + 3) * brickScale));
      }
    }
  }

  public boolean isHit(Bullet b) {
    boolean hit = false;
    Brick remove = null;
    for (Brick br : bricks) {
      if (br.isHit(b)) {
        remove = br;
        hit = true;
      }
    }
    bricks.remove(remove);
    return hit;
  }

  public boolean isDestroyed() {
    return bricks.size() == 0;
  }

  public int getPoints() {
    return 0;
  }

  public boolean isPlayer() {
    return false;
  }

  public List<Shape> getShapes() {
    List<Shape> ss = new ArrayList<Shape>();
    for (Brick b : bricks) {
      ss.add(b.getShape());
    }

    return ss;
  }

}
