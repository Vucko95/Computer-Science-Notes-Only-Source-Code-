
class Game {
  Ship player = new Ship(50, 400, 0, true);
  Ship[] enemyShips;
  int numberOfEnemies = 3;

  Game() {
    enemyShips = new Ship[numberOfEnemies];
    enemyShips[0] = new Ship(70, 50, 15, false);
    enemyShips[1] = new Ship(90, 50, 20, false);
    enemyShips[2] = new Ship(110, 50, 0, false);
  }

  void removeShip(int m) {
    if (m < numberOfEnemies && m >= 0) {
      for (int i = m; i < numberOfEnemies - 1; i++) {
        enemyShips[i] = enemyShips[i + 1];
      }
      enemyShips[numberOfEnemies - 1] = null;
      numberOfEnemies--;
    }
  }
}
