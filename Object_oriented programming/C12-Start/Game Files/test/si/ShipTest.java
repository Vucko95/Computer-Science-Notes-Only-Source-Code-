package si;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.fail;

import org.junit.jupiter.api.Test;

class ShipTest {

  @Test
  public void testTakeDamageHealthZero(){
    Ship shp = new Player(50, 400, 0);
    Bullet b = new Bullet(50,400,false, 25);
    shp.takeDamage(b);
    assertEquals(0, shp.getHealth());
  }
  @Test
  public void testTakeDamageNegativeParameter(){
    Ship shp = new Player(50, 400, 0);
    Bullet b = new Bullet(50,400,false, -5);
    shp.takeDamage(b);
    assertEquals(20, shp.getHealth());
  }
  @Test
  public void testTakeDamageReduction() {
    Ship shp = new Player(50, 400, 0);
    Bullet b = new Bullet(50,400,false, 5);
    shp.takeDamage(b);
    assertEquals(15, shp.getHealth());
  }
}
