package si;

import java.awt.Rectangle;

public class Bunker implements Hittable, Drawable {
  private int x, y;
  private Brick[] bricks;
  public static final int BRICK_SIZE = 4;
  private int noBricks;

  private class Brick implements Hittable {
    private int x, y;
    private int width;
    private boolean destroyed;
    private Rectangle box;

    private Brick(int x1, int y1, int w) {
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

  public Bunker(int x1, int y1) {
    x = x1;
    y = y1;
    bricks = new Brick[27];
    addBricks();
  }

  private void addBricks() {
    // top row
    bricks[noBricks++] = new Brick(x + 2 * BRICK_SIZE, y + 0 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 4 * BRICK_SIZE, y + 0 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 6 * BRICK_SIZE, y + 0 * BRICK_SIZE, 2);
    // second row
    bricks[noBricks++] = new Brick(x + 1 * BRICK_SIZE, y + 1 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 3 * BRICK_SIZE, y + 1 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 5 * BRICK_SIZE, y + 1 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 7 * BRICK_SIZE, y + 1 * BRICK_SIZE, 2);
    // third row
    bricks[noBricks++] = new Brick(x + 0 * BRICK_SIZE, y + 2 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 2 * BRICK_SIZE, y + 2 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 6 * BRICK_SIZE, y + 2 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 8 * BRICK_SIZE, y + 2 * BRICK_SIZE, 2);
    // fourth row
    bricks[noBricks++] = new Brick(x + 0 * BRICK_SIZE, y + 3 * BRICK_SIZE, 1);
    bricks[noBricks++] = new Brick(x + 1 * BRICK_SIZE, y + 3 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 7 * BRICK_SIZE, y + 3 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 9 * BRICK_SIZE, y + 3 * BRICK_SIZE, 1);

    // fifth row
    bricks[noBricks++] = new Brick(x + 0 * BRICK_SIZE, y + 4 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 2 * BRICK_SIZE, y + 4 * BRICK_SIZE, 1);
    bricks[noBricks++] = new Brick(x + 7 * BRICK_SIZE, y + 4 * BRICK_SIZE, 1);
    bricks[noBricks++] = new Brick(x + 8 * BRICK_SIZE, y + 4 * BRICK_SIZE, 2);

    // sixth row
    bricks[noBricks++] = new Brick(x + 0 * BRICK_SIZE, y + 5 * BRICK_SIZE, 1);
    bricks[noBricks++] = new Brick(x + 1 * BRICK_SIZE, y + 5 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 7 * BRICK_SIZE, y + 5 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 9 * BRICK_SIZE, y + 5 * BRICK_SIZE, 1);

    // seventh row
    bricks[noBricks++] = new Brick(x + 0 * BRICK_SIZE, y + 6 * BRICK_SIZE, 2);
    bricks[noBricks++] = new Brick(x + 2 * BRICK_SIZE, y + 6 * BRICK_SIZE, 1);
    bricks[noBricks++] = new Brick(x + 7 * BRICK_SIZE, y + 6 * BRICK_SIZE, 1);
    bricks[noBricks++] = new Brick(x + 8 * BRICK_SIZE, y + 6 * BRICK_SIZE, 2);
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

  public void takeDamage(Bullet bullet) {}
}
