import java.awt.Rectangle;

public class Bunker implements Hittable, Drawable {
  private int x, y;
  private Brick[] bricks;
  public static final int BRICK_SIZE = 5;
  private int noBricks;

  public Bunker(int x1, int y1) {
    x = x1;
    x = y1;
    bricks = new Brick[26];
    addBricks();
  }

  private void addBricks() {
    for (int i = 0; i < 3; i++) {
      // bricks[i] = new Brick(x + 2 * (i + 1)* BRICK_SIZE, y + 0 * BRICK_SIZE, 2);
    }
  }

  private void removeDestroyed() {
    int noDestroyed = 0;
    int lastD = -1;
    for (int i = 0; i < noBricks; i++) {
      if (bricks[i].isDestroyed()) {
        noDestroyed++;
        lastD = i;
      }
    }
    if (noDestroyed > 0) {
      removeBrick(lastD);
      removeDestroyed();
    }
  }

  public void removeBrick(int b) {
    for (int i = b; i < noBricks - 1; i++) {
      bricks[i] = bricks[i + 1];
    }
    bricks[noBricks] = null;
    noBricks--;
  }

  public boolean isHit(Bullet b) {
    boolean hit = false;
    for (int i = 0; i < noBricks; i++) {
      if (bricks[i].isHit(b)) {
        bricks[i].takeDamage(b);
        hit = true;
      }
    }
    if (hit) {
      removeDestroyed();
    }
    return hit;
  }

  public boolean isDestroyed() {
    return noBricks == 0;
  }

  public int getPoints() {
    return 0;
  }

  public Rectangle[] getShape() {
    Rectangle[] shapes = new Rectangle[noBricks];
    for (int i = 0; i < noBricks; i++) {
      shapes[i] = bricks[i].getHitBox();
    }
    return shapes;
  }

  public void takeDamage(Bullet b) {}
}
