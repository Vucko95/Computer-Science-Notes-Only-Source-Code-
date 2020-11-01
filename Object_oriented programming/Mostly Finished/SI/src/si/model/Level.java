package si.model;

import java.awt.Shape;
import java.util.ArrayList;
import java.util.List;

public class Level implements Drawable {
	private Bunker[] bunkers;
	private Swarm swarm;
	private int startingSpeed;
	private int rows;
	private int cols;

	public Level(int ss, int row, int col) {
		startingSpeed = ss;
		rows = row;
		cols = col;
		reset();
		System.out.println(getShipsRemaining());
	}

	public int getShipsRemaining() {
		return swarm.getShipsRemaining();
	}

	public int getBottomY() {
		return swarm.getBottomY();
	}

	public List<Hittable> getHittable() {
		List<Hittable> targets = new ArrayList<Hittable>();
		targets.addAll(swarm.getHittable());
		for (int i = 0; i < bunkers.length; i++) {
			targets.add(bunkers[i]);
		}
		return targets;
	}

	public List<Bullet> move() {
		swarm.move();
		List<EnemyShip> ships = swarm.getBottom();
		List<Bullet> eBullets = new ArrayList<Bullet>();
		for (EnemyShip s : ships) {
			Bullet b = s.fire();
			if (b != null) {
				eBullets.add(b);
			}
		}
		return eBullets;
	}

	public List<Shape> getShapes() {
		List<Shape> shapes = new ArrayList<Shape>();

		for (Drawable ship : swarm.getShips()) {
			shapes.addAll(ship.getShapes());
		}
		for (int i = 0; i < bunkers.length; i++) {
			shapes.addAll(bunkers[i].getShapes());
		}

		return shapes;

	}

	public void reset() {
		bunkers = new Bunker[4];
		for (int i = 0; i < bunkers.length; i++) {
			bunkers[i] = new Bunker((i + 1) * Game.SCREEN_WIDTH / 5, Game.BUNKER_TOP);
		}
		swarm = new Swarm(rows, cols, startingSpeed, 1);
	}
}
