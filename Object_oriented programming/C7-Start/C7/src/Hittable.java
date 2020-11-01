
public interface Hittable {
  boolean isHit(Bullet b);
  void takeDamage(Bullet b);
  boolean isDestroyed();
  int getPoints();
}