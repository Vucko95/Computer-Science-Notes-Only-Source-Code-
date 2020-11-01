package si;

import java.awt.Rectangle;

import si.gui.PlayerListener;

public class Player extends Ship implements Drawable {
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
    if (PlayerListener.isLeft()) {
      move(-2);
    } else if (PlayerListener.isRight()) {
      move(2);
    }
  }

  private void move(int x1) {
    Rectangle newBox = new Rectangle(this.x + x1, this.y, 9 * SQUARE_SIZE, 5 * SQUARE_SIZE);
    if (Game.getScreenBounds().contains(newBox.getBounds())) {
      box = newBox;
      this.x += x1;
    }
  }

  public Rectangle[] getShape() {
    return new Rectangle[] { new Rectangle(x + 4 * SQUARE_SIZE, y + 0 * SQUARE_SIZE, 1 * SQUARE_SIZE, 1 * SQUARE_SIZE),
        new Rectangle(x + 3 * SQUARE_SIZE, y + 1 * SQUARE_SIZE, 3 * SQUARE_SIZE, 1 * SQUARE_SIZE),
        new Rectangle(x + 1 * SQUARE_SIZE, y + 2 * SQUARE_SIZE, 7 * SQUARE_SIZE, 1 * SQUARE_SIZE),
        new Rectangle(x + 0 * SQUARE_SIZE, y + 3 * SQUARE_SIZE, 9 * SQUARE_SIZE, 1 * SQUARE_SIZE),
        new Rectangle(x + 0 * SQUARE_SIZE, y + 4 * SQUARE_SIZE, 9 * SQUARE_SIZE, 1 * SQUARE_SIZE) };
  }
}
