
class Ship {
  int x, y, cooldown, health;
  boolean player;

  Ship(int x1, int y1, int c, boolean p) {
    x = x1;
    y = y1;
    cooldown = c;
    player = p;
  }

  Bullet fire() {
    Bullet b = null;
    if (cooldown == 0) {
      b = new Bullet(x, y, player, this);
    }
    return b;
  }

  boolean isHit(Bullet b) {
    if (b.x >= x && b.x <= x + 10 && b.y >= y && b.y <= y + 10) {
      return true;
    }
    return false;
  }

  void printShip() {
    if (player) {
      System.out.println("Player located at (" + x + ", " + y + ") with cooldown " + cooldown);
    } else {
      System.out.println("Enemy located at (" + x + ", " + y + ") with cooldown " + cooldown);
    }
  }
}