package si.model;

import java.awt.Rectangle;
import java.awt.Shape;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public abstract class EnemyShip implements Hittable, Drawable {
	private String name;
	private boolean destroyed;
	protected Rectangle hitBox;
	private int x, y;
	private AlienType type;
	private Random rand;
	private List<Shape> shapes;
	protected int height = 8;

	public EnemyShip(int x, int y, AlienType type) {
		this.x = x;
		this.y = y;
		this.type = type;
		this.shapes = createShapes();
		this.rand = new Random(x*100+y);
	}

	protected abstract List<Shape> createShapes();

	public boolean isHit(Bullet b) {
		Rectangle r = b.getHitBox();
		if (hitBox.getBounds().intersects(r)) {
			destroyed = true;
		}
		return hitBox.getBounds().intersects(r);
	}

	public boolean isDestroyed() {
		return destroyed;
	}

	public int getPoints() {
		return type.getScore();
	}

	public boolean isPlayer() {
		return false;
	}

	public void move(int cX, int cY) {
		x += cX;
		y += cY;
		shapes = createShapes();
	}

	public Bullet fire() {
		Bullet bul = null;
		if (rand.nextInt() % 150 == 0) {
			int a = (x + (type.getWidth() * getScale()) / 2);
			int b = y + (getScale() * height);
			bul = new Bullet(a, b, false, name);
		}
		return bul;
	}

	protected abstract int getScale();
	
	public Rectangle getHitBox() {
		return hitBox;
	}

	public List<Shape> getShapes() {
		return new ArrayList<Shape>(shapes);
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

}
