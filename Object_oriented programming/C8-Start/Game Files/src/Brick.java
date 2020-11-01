import java.awt.Rectangle;

public class Brick implements Hittable {
  private int x, y;
  private int width;
  private boolean destroyed;
  private Rectangle box;

  public Brick(int x1, int y1, int w) {
    x = x1;
    y = y1;
    width = w;
    destroyed = false;
    box = new Rectangle(x, y, width * Bunker.BRICK_SIZE, Bunker.BRICK_SIZE);
  }

  public boolean isHit(Bullet b) {
    if (box.intersects(b.getHitBox())) {
      return true;
    }
    return false;
  }

  public boolean isDestroyed() {
    return destroyed;
  }

  public int getPoints() {
    return 0;
  }

  public Rectangle getHitBox() {
    return new Rectangle(box);
  }

  public void takeDamage(Bullet bullet) {
    destroyed = true;
  }
}
