package si.model;

public enum AlienType {
	A(9, 20), B(8, 15), C(12, 10);
	private int width;
	private int score;

	private AlienType(int w, int s) {
		width = w;
		score = s;
	}

	public int getWidth() {
		return width;
	}

	public int getScore() {
		return score;
	}
}
