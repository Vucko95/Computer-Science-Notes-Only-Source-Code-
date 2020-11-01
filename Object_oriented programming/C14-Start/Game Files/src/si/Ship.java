package si;
import java.awt.Rectangle;

public abstract class Ship implements Hittable, Movable, Drawable {
  public static final int MAX_HEALTH = 20;
  protected int x;
  protected int y;
  protected int cooldown;
  private int health;
  private boolean player;
  public static final int SQUARE_SIZE = 3;
  protected Rectangle box;

  public Ship(int x1, int y1, int c, boolean p) {
    x = x1;
    y = y1;
    cooldown = c;
    player = p;
  }

  public void update() {
    if (cooldown > 0) {
      cooldown--;
    }
  }

  public int getCooldown() {
    return cooldown;
  }

  public abstract Bullet fire();

  public abstract void move();

  public abstract int getPoints();

  public void heal(int h) {
    if (h > 0) {
      if (health + h < MAX_HEALTH) {
        health = health + h;
      } else {
        health = MAX_HEALTH;
      }
    }
  }

  public void printShip() {
    if (player) {
      System.out.println("Player located at (" + x + ", " + y + ") with cooldown " + cooldown);
    } else {
      System.out.println("Enemy located at (" + x + ", " + y + ") with cooldown " + cooldown);
    }
  }

  private int randomEffect(int effect) {
    int r = Dice.roll2D6();
    if (r == 2) {
      effect = 0; // terrible attempt, no effect
    } else if (r < 6) {
      effect = (int) (effect * .4); // weak attempt, reduced effect
    } else if (r > 8 && r < 12) {
      effect = (int) (effect * 1.2); // strong attempt, increased effect
    } else if (r == 12) {
      effect = effect * 2; // perfect attempt, big effect
    }
    return effect;
  }

  public void takeDamage(Bullet bullet) {
    String message = "";
    int damage = bullet.getPower();//randomEffect(bullet.getPower());
    if (damage > 0) {
      if (health - damage > 0) {
        health = health - damage;
        message = "Ship has taken " + damage + " damage, health is now " + health;
      } else {
        health = 0;
        message = "Ship is destroyed";
      }
    } else {
      message = "Damage cannot be a negative value";
    }
    System.out.println(message);
  }

  public boolean isHit(Bullet b) {
    if (box.intersects(b.getHitBox())) {
      takeDamage(b);
      return true;
    }
    return false;
  }

  public boolean isDestroyed() {
    return health == 0;
  }

  public int getHealth() {
    return health;
  }
}