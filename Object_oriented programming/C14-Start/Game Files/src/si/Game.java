package si;

import java.awt.Rectangle;

public class Game {
  public static final int SCREEN_WIDTH = 512;
  public static final int SCREEN_HEIGHT = 512;
  Ship player;
  private int playerScore = 0;
  Ship[] enemyShips;
  int numberOfEnemies = 3;
  private Bunker[] bunkers;
  private Bullet[] bullets;
  private int noBullets;
  private Hittable[] targets;
  private Movable[] movers;
  private Drawable[] drawables;
  private int noDraw;
  private int noMovers;
  private int noTargets;

  public Game() {
    player = new Player(50, 400, 0);
    targets = new Hittable[1000];
    movers = new Movable[1000];
    drawables = new Drawable[1000];
    bunkers = new Bunker[4];
    bunkers[0] = new Bunker(100, 350);
    bunkers[1] = new Bunker(200, 350);
    bunkers[2] = new Bunker(300, 350);
    bunkers[3] = new Bunker(400, 350);
    targets[noTargets++] = player;
    movers[noMovers++] = player;
    drawables[noDraw++] = player;
    for (int i = 0; i < bunkers.length; i++) {
      targets[noTargets++] = bunkers[i];
      drawables[noDraw++] = bunkers[i];
    }
    enemyShips = new Ship[numberOfEnemies];
    enemyShips[0] = new Enemy(70, 50, 15, AlienType.A);
    enemyShips[1] = new Enemy(170, 50, 20, AlienType.B);
    enemyShips[2] = new Enemy(270, 50, 0, AlienType.C);
    for (int i = 0; i < numberOfEnemies; i++) {
      targets[noTargets++] = enemyShips[i];
      movers[noMovers++] = enemyShips[i];
      drawables[noDraw++] = enemyShips[i];
    }
    bullets = new Bullet[100];
  }

  public void removeShip(int m) {
    if (m < numberOfEnemies && m >= 0) {
      for (int i = m; i < numberOfEnemies - 1; i++) {
        enemyShips[i] = enemyShips[i + 1];
      }
      enemyShips[numberOfEnemies - 1] = null;
      numberOfEnemies--;
    }
  }

  public void step() {
    // update the player
    player.update();
    // update the enemies
    for (int i = 0; i < numberOfEnemies; i++) {
      enemyShips[i].update();
    }
    // move the movable objects
    for (int i = 0; i < noMovers; i++) {
      movers[i].move();
    }

    Bullet b = player.fire();
    if (b != null) {
      bullets[noBullets++] = b;
      targets[noTargets++] = b;
      movers[noMovers++] = b;
      drawables[noDraw++] = b;
    }
    // attempt to fire enemy ships
    for (int i = 0; i < numberOfEnemies; i++) {
      b = enemyShips[i].fire();
      if (b != null) {
        bullets[noBullets++] = b;
        targets[noTargets++] = b;
        movers[noMovers++] = b;
        drawables[noDraw++] = b;
      }
    }

    for (int i = 0; i < noBullets; i++) {
      if (bullets[i] != null && !bullets[i].isDestroyed()) {
        for (int j = 0; j < noTargets; j++) {
          if (!targets[j].isDestroyed() && targets[j].isHit(bullets[i])) {
            targets[j].takeDamage(bullets[j]);
            if (targets[j].isDestroyed()) {
              playerScore += targets[j].getPoints();
            }
          }
        }
      }
    }
  }

  public int getScore() {
    return playerScore;
  }

  public Drawable[] getDrawable() {
    Drawable[] d = new Drawable[noDraw];
    for (int i = 0; i < d.length; i++) {
      d[i] = drawables[i];
    }
    return d;
  }

  public static Rectangle getScreenBounds() {
    return new Rectangle(0 , 0 , SCREEN_WIDTH, SCREEN_HEIGHT);
  }
}
