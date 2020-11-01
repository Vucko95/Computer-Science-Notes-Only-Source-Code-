
public enum AlienType {
  A(10, 7, 10), B(8, 8, 20), C(10, 8, 15);
  private int width;
  private int height;
  private int score;

  private AlienType(int w, int h, int s) {
    width = w;
    height = h;
    score = s;
  }

  public int getWidth() {
    return width;
  }

  public int getHeight() {
    return height;
  }

  public int getScore() {
    return score;
  }
}
