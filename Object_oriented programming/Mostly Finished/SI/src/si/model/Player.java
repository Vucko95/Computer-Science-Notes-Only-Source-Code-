package si.model;

import java.awt.Polygon;
import java.awt.Rectangle;
import java.awt.Shape;
import java.util.ArrayList;
import java.util.List;

public class Player implements Hittable, Drawable {
	private int x;
	private int y;
	private Shape hitBox;
	private int weaponCooldown;
	private boolean destroyed = true;
	private int shipScale = 4;
	private int width = shipScale * 8;

	public Player() {
		x = 400 - width;
		y = 450;
		hitBox = creatPolygon(x, y);
	}

	private Polygon creatPolygon(int x, int y) {
		Polygon p = new Polygon();
		p.addPoint(x + 0 * shipScale, y + 2 * shipScale);
		p.addPoint(x + 2 * shipScale, y + 2 * shipScale);
		p.addPoint(x + 2 * shipScale, y + 1 * shipScale);
		p.addPoint(x + 3 * shipScale, y + 1 * shipScale);
		p.addPoint(x + 3 * shipScale, y + 0 * shipScale);
		p.addPoint(x + 4 * shipScale, y + 0 * shipScale);
		p.addPoint(x + 4 * shipScale, y + 1 * shipScale);
		p.addPoint(x + 5 * shipScale, y + 1 * shipScale);
		p.addPoint(x + 5 * shipScale, y + 2 * shipScale);
		p.addPoint(x + 7 * shipScale, y + 2 * shipScale);
		p.addPoint(x + 7 * shipScale, y + 4 * shipScale);
		p.addPoint(x + 0 * shipScale, y + 4 * shipScale);
		p.addPoint(x + 0 * shipScale, y + 2 * shipScale);
		return p;
	}

	public boolean isHit(Bullet b) {
		Rectangle r = b.getHitBox();
		if (hitBox.intersects(r)) {
			destroyed = true;
		}
		return hitBox.intersects(r);
	}

	public void tick() {
		if (weaponCooldown > 0) {
			weaponCooldown--;
		} else {
			weaponCooldown = 10;
		}
	}

	public boolean isDestroyed() {
		return destroyed;
	}
	
	public void resetDestroyed() {
		destroyed = false;
	}

	public int getPoints() {
		return -100;
	}

	public boolean isPlayer() {
		return true;
	}

	public Bullet fire() {
		Bullet b = null;
		if (weaponCooldown == 0) {
			b = new Bullet(x + 3 * shipScale, y + 0 * shipScale, true, "Player");
		}
		return b;
	}

	public void move(int x, int y) {
		Polygon newBox = creatPolygon(this.x + x, this.y + y);
		if (Game.getScreenBounds().contains(newBox.getBounds())) {
			hitBox = newBox;
			this.x += x;
			this.y += y;
		}
	}

	public Shape getShape() {
		return hitBox;
	}

	@Override
	public List<Shape> getShapes() {
		List<Shape> ss = new ArrayList<Shape>();
		ss.add(hitBox);
		return ss;
	}

}
