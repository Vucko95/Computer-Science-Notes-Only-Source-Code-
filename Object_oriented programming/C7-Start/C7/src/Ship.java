import java.awt.Rectangle;

public class Ship implements Hittable, Movable {
  public static final int MAX_HEALTH = 20;
  private int x, y, cooldown, health;
  private boolean player;
  public static final int SHIP_WIDTH = 10;
  private Rectangle box;

  public Ship(int x1, int y1, int c, boolean p) {
    x = x1;
    y = y1;
    cooldown = c;
    player = p;
    box = new Rectangle(x, y, SHIP_WIDTH, SHIP_WIDTH);
  }

  public Bullet fire() {
    Bullet b = null;
    if (cooldown == 0) {
      b = new Bullet(x, y, player, 5);
    }
    return b;
  }

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
    int damage = randomEffect(bullet.getPower());
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
    if (box.intersects(b.getShape())) {
      takeDamage(b);
      return true;
    }
    return false;
  }

  public boolean isDestroyed() {
    return health == 0;
  }

  public int getPoints() {
    if (player) {
      return 0;
    }
    return 5;
  }

  public void move() {
    
  }
}