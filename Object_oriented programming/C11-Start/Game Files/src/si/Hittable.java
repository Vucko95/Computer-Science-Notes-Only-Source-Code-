package si;

public interface Hittable {
  boolean isHit(Bullet b);
  boolean isDestroyed();
  int getPoints();
  void takeDamage(Bullet bullet);
}