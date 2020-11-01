package si.model;

import java.awt.Rectangle;
import java.awt.Shape;
import java.util.ArrayList;
import java.util.List;

import si.presentation.GameScreen;
import si.presentation.PlayerListener;

public class Game implements Runnable {
	private int playerLives;
	private int score;
	private boolean pause = true;
	public static final int SCREEN_WIDTH = 512;
	public static final int SCREEN_HEIGHT = 512;
	private static final Rectangle SCREEN_BOUNDS = new Rectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);;
	private List<Bullet> playerBullets;
	private List<Bullet> enemyBullets;
	private ArrayList<Hittable> targets;
	private PlayerListener listener;
	private Player player;
	private Level[] level;
	private GameScreen gameScreen;
	private final int TARGET_FPS = 30;
	private final double GAME_HERTZ = 30.0;
	private final double TARGET_TIME_BETWEEN_RENDERS = 1000000000 / TARGET_FPS;
	private final double TIME_BETWEEN_UPDATES = 1000000000 / GAME_HERTZ;
	private final int MAX_UPDATES_BEFORE_RENDER = 5;
	public static final int BUNKER_TOP = 350;
	private static final int NO_LEVELS = 3;
	private int currentLevel = 0;

	public Game(PlayerListener listener, GameScreen g) {
		this.gameScreen = g;
		g.addGame(this);
		this.listener = listener;
		targets = new ArrayList<Hittable>();
		playerLives = 3;
		score = 0;
		playerBullets = new ArrayList<Bullet>();
		enemyBullets = new ArrayList<Bullet>();
		player = new Player();
		level = new Level[3];
		level[2] = new Level(1, 3, 10);
		level[1] = new Level(2, 4, 11);
		level[0] = new Level(3, 5, 12);
	}

	public int getScore() {
		return score;
	}

	public int getLives() {
		return playerLives;
	}

	public void run() {
		double now = System.nanoTime();
		double lastUpdateTime = System.nanoTime();
		double lastRenderTime = System.nanoTime();

		while (playerLives > 0 && level[currentLevel].getShipsRemaining() > 0
				&& level[currentLevel].getBottomY() < BUNKER_TOP) {
			if (!player.isDestroyed() && !pause) {
				int updateCount = 0;
				while (now - lastUpdateTime > TIME_BETWEEN_UPDATES && updateCount < MAX_UPDATES_BEFORE_RENDER) {
					updateGame();
					lastUpdateTime += TIME_BETWEEN_UPDATES;
					updateCount++;
				}
				gameScreen.paintImmediately(SCREEN_BOUNDS);
				lastRenderTime = now;

				while (now - lastRenderTime < TARGET_TIME_BETWEEN_RENDERS) {

					try {
						Thread.sleep(1);
					} catch (Exception e) {
					}

					now = System.nanoTime();
				}
				if (listener.isPlayPause()) {
					pause = true;
				}
			} else {
				lastUpdateTime = System.nanoTime();
				if (listener.isPlayPause()) {
					if (player.isDestroyed()) {
						player.resetDestroyed();
					}
					pause = false;
				}
				try {
					Thread.sleep(5);
				} catch (InterruptedException e) {
				}
			}
		}
		if (playerLives > 0 && level[currentLevel].getShipsRemaining() == 0) {
			currentLevel++;
			if (currentLevel < NO_LEVELS) {
				run();
			} else {
				score += playerLives *100; 
			}
		} else if (playerLives == 0) {
			// show end of game stuff don't think i need to change anything
		} else if (level[currentLevel].getBottomY() >= BUNKER_TOP) {
			level[currentLevel].reset();
			playerLives--;
		}
		if (listener.isPlayPause()) {
			pause = !pause;
		}
	}

	public void updateGame() {
		player.tick();
		targets.clear();
		targets.addAll(level[currentLevel].getHittable());
		targets.add(player);
		playerBullets();
		enemyBullets();
		enemyBullets.addAll(level[currentLevel].move());
		movePlayer();
	}

	private void movePlayer() {
		if (listener.isFire()) {
			Bullet b = player.fire();
			if (b != null) {
				playerBullets.add(b);
			}
		}
		if (listener.isLeft()) {
			player.move(-6, 0);
		} else if (listener.isRight()) {
			player.move(+6, 0);
		}
	}

	private void playerBullets() {
		List<Bullet> remove = new ArrayList<Bullet>();
		for (int i = 0; i < playerBullets.size(); i++) {
			if (!playerBullets.get(i).isDestroyed() && SCREEN_BOUNDS.contains(playerBullets.get(i).getHitBox())) {
				playerBullets.get(i).move();
				for (Hittable t : targets) {
					if (t != playerBullets.get(i)) {
						if (t.isHit(playerBullets.get(i))) {
							score += t.getPoints();
							playerBullets.get(i).destroy();
						}
					}
				}
			} else {
				remove.add(playerBullets.get(i));
			}
		}
		playerBullets.removeAll(remove);
	}

	private void enemyBullets() {
		List<Bullet> remove = new ArrayList<Bullet>();
		for (int i = 0; i < enemyBullets.size(); i++) {
			Bullet b = enemyBullets.get(i);
			if (!b.isDestroyed() && SCREEN_BOUNDS.contains(b.getHitBox())) {
				b.move();
				for (Hittable t : targets) {
					if (t != b) {
						if (t.isHit(b)) {
							if (t.isPlayer()) {
								playerLives--;
							}
							b.destroy();
						}
					}
				}
			} else {
				remove.add(b);
			}
		}
		enemyBullets.removeAll(remove);
	}

	public Shape getShip() {
		return player.getShape();
	}

	public static Rectangle getScreenBounds() {
		return new Rectangle(SCREEN_BOUNDS);
	}

	public List<Drawable> getBullets() {
		ArrayList<Drawable> bullets = new ArrayList<Drawable>();
		bullets.addAll(playerBullets);
		bullets.addAll(enemyBullets);
		return bullets;
	}

	public Player getPlayer() {
		return player;
	}

	public boolean isPaused() {
		return pause;
	}

	public List<Shape> getDrawable() {
		return level[currentLevel].getShapes();
	}
}
