
class Bullet {
  int x, y;
  boolean up; // true for up, false for down
  int damage;

  Bullet(int x1, int y1, boolean u, int d) {
    x = x1;
    y = y1;
    up = u;
    damage = d;
  }
  
  void printBullet() {
    if(up) {
      System.out.println("Bullet located at ("+x+", "+y+ ") moving up");
    } else {
      System.out.println("Bullet located at ("+x+", "+y+ ") moving down");
    }
  }
}
