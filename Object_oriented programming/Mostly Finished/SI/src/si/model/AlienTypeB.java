package si.model;

import java.awt.Rectangle;
import java.awt.Shape;
import java.util.ArrayList;
import java.util.List;

public class AlienTypeB extends EnemyShip {
	private int shipScale = 2;

	public AlienTypeB(int x, int y) {
		super(x, y, AlienType.B);
	}

	protected List<Shape> createShapes() {
		hitBox = new Rectangle(getX(), getY(), shipScale * AlienType.B.getWidth(), shipScale * height);
		List<Shape> shapes = new ArrayList<Shape>();
		shapes.add(new Rectangle(getX() + shipScale * 3, getY() + shipScale * 0, shipScale * 2, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 2, getY() + shipScale * 1, shipScale * 4, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 1, getY() + shipScale * 2, shipScale * 6, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 0, getY() + shipScale * 3, shipScale * 2, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 3, getY() + shipScale * 3, shipScale * 2, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 6, getY() + shipScale * 3, shipScale * 2, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 0, getY() + shipScale * 4, shipScale * 8, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 2, getY() + shipScale * 5, shipScale * 1, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 5, getY() + shipScale * 5, shipScale * 1, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 1, getY() + shipScale * 6, shipScale * 1, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 3, getY() + shipScale * 6, shipScale * 2, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 6, getY() + shipScale * 6, shipScale * 1, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 0, getY() + shipScale * 7, shipScale * 1, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 2, getY() + shipScale * 7, shipScale * 1, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 5, getY() + shipScale * 7, shipScale * 1, shipScale * 1));
		shapes.add(new Rectangle(getX() + shipScale * 7, getY() + shipScale * 7, shipScale * 1, shipScale * 1));

		return shapes;
	}
	
	@Override
	protected int getScale() {
		return shipScale;
	}

}