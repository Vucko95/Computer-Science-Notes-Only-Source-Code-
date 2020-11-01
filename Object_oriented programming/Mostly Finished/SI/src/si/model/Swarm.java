package si.model;

import java.util.ArrayList;
import java.util.List;

public class Swarm implements Movable {
	private List<EnemyShip> ships;
	private boolean direction = true; // true for moving right false for left
	private int x = 50, y = 40;
	private int space = 30;
	private EnemyShip[][] shipGrid;
	private int rows, cols;
	private int count = 0;
	private int moveX;
	private int moveY;

	public Swarm(int r, int c, int sX, int sY) {
		rows = r;
		cols = c;
		moveX = sX;
		moveY = sY;
		shipGrid = new EnemyShip[r][c];
		ships = new ArrayList<EnemyShip>();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				EnemyShip a;
				if (i % 5 == 0) {
					a = new AlienTypeA(x + (1 + space) * j, y + i * space);
				} else if (i % 5 == 1 || i % 5 == 2) {
					a = new AlienTypeB(x + (1 + space) * j, y + i * space);
				} else {
					a = new AlienTypeC(x + (1 + space) * j, y + i * space);
				}
				ships.add(a);
				shipGrid[i][j] = a;
			}
		}
	}

	public void move() {
		List<EnemyShip> remove = new ArrayList<EnemyShip>();
		for (EnemyShip s : ships) {
			if (s.isDestroyed()) {
				remove.add(s);
			}
		}
		ships.removeAll(remove);

		if (count % 25 == 0) {
			int cX = ((direction) ? moveX : -moveX);
			int cY = 0;
			if (x + getWidth() + cX > Game.SCREEN_WIDTH - 20 || getAdjustedX() + cX < 20) {
				direction = !direction;
				cY = moveY * 5;
				cX = ((direction) ? moveX : -moveX);
				if (direction) {
					moveX++;
				}
			} else {
				y = y + cY;
				x = x + cX;
			}
			for (EnemyShip s : ships) {
				s.move(cX, cY);
			}

		}
	}

	private int getAdjustedX() {
		int w = 0;
		for (int i = 0; i < cols; i++) {
			int c = 0;
			for (int j = 0; j < rows; j++) {
				if (shipGrid[j][i].isDestroyed()) {
					c++;
				}
			}
			if (c == rows) {
				w++;
			} else {
				break;
			}
		}
		return x + w * space;
	}

	public int getBottomY() {
		int b = 0;
		for (EnemyShip e : getBottom()) {
			if (e.getY() + e.getHitBox().height > b) {
				b = e.getY() + e.getHitBox().height;
			}
		}
		return b;
	}

	private int getWidth() {
		int w = cols;
		for (int i = cols - 1; i >= 0; i--) {
			int c = 0;
			for (int j = 0; j < rows; j++) {
				if (shipGrid[j][i].isDestroyed()) {
					c++;
				}
			}
			if (c == rows) {
				w--;
			} else {
				break;
			}
		}
		return w * space;
	}

	public void tick() {
		count++;
	}

	public List<Hittable> getHittable() {
		return new ArrayList<Hittable>(ships);
	}

	public List<EnemyShip> getBottom() {
		List<EnemyShip> bottomShips = new ArrayList<EnemyShip>();

		for (int i = 0; i < cols; i++) {
			boolean found = false;
			for (int j = rows - 1; j >= 0 && !found; j--) {
				if (!shipGrid[j][i].isDestroyed()) {
					found = true;
					bottomShips.add(shipGrid[j][i]);
				}
			}
		}
		return bottomShips;
	}

	public List<Drawable> getShips() {
		return new ArrayList<Drawable>(ships);
	}

	public int getShipsRemaining() {
		return ships.size();
	}
}
