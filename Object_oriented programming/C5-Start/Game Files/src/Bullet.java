
class Bullet {
  int x, y;
  boolean up; // true for up, false for down
  Ship origin;

  Bullet(int x1, int y1, boolean u, Ship o) {
    x = x1;
    y = y1;
    up = u;
    origin = o;
  }
  
  void printBullet() {
    if(up) {
      System.out.println("Bullet located at ("+x+", "+y+ ") moving up");
    } else {
      System.out.println("Bullet located at ("+x+", "+y+ ") moving down");
    }
  }
}
