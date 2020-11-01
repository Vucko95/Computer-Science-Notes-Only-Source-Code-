package si.model;

public interface Hittable {
	public boolean isHit(Bullet r);
	public boolean isDestroyed();
	public int getPoints();
	public boolean isPlayer();
}

