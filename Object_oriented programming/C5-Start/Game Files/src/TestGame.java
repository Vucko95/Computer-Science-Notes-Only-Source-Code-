
public class TestGame {
  public static void main(String[] args) {
    TestGame t = new TestGame();
    t.test();
  }
  
  public void test() {
    Game g = new Game();
    g.player.printShip();
    Bullet pB = g.player.fire();

    for (int i = 0; i < g.numberOfEnemies; i++) {
      g.enemyShips[i].printShip();
      
      if(g.enemyShips[i].isHit(pB)) {
        System.out.println("hit");
      } else {
        System.out.println("miss");
      }

      Bullet b = g.enemyShips[i].fire();
      if(b != null) {
        b.printBullet();
      }
    }
  }
}
