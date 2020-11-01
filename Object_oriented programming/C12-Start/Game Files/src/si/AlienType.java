package si;

public enum AlienType {
  A(10, 7, 10,
      new int[][] { { 2, 0, 1, 1 }, { 3, 1, 1, 1 }, { 7, 0, 1, 1 }, { 6, 1, 1, 1 }, { 2, 2, 6, 1 }, { 1, 3, 2, 1 }, { 4, 3, 2, 1 }, { 7, 3, 2, 1 },
          { 0, 4, 10, 1 }, { 0, 5, 1, 2 }, { 9, 5, 1, 2 }, { 2, 5, 6, 1 }, { 2, 6, 1, 1 }, { 4, 6, 2, 1 }, { 7, 6, 1, 1 } }), B(
              8, 8, 20,
              new int[][] { { 3, 0, 2, 1 }, { 2, 1, 4, 1 }, { 1, 2, 6, 1 }, { 0, 3, 2, 1 }, { 3, 3, 2, 1 }, { 6, 3, 2, 1 }, { 0, 4, 8, 1 }, { 2, 5, 1, 1 },
                  { 5, 5, 1, 1 }, { 1, 6, 1, 1 }, { 3, 6, 2, 1 }, { 6, 6, 1, 1 }, { 0, 7, 1, 1 }, { 2, 7, 1, 1 }, { 5, 7, 1, 1 }, { 7, 7, 1, 1 } }), C(10, 8,
                      15, new int[][] {{3,0,4,1}, {1,1,8,1}, {0,2,10,1}, {0,3,2,1}, {4,3,2,1}, {8,3,2,1}, {0,4,10,1}, {2,5,2,1}, {6,5,2,1}, {1,6,2,1}, {4,6,2,1}, {7,6,2,1}, {0,7,1,1}, {9,7,1,1}});
  private int width;
  private int height;
  private int score;
  private int[][] shapes;

  private AlienType(int w, int h, int s, int[][] ss) {
    width = w;
    height = h;
    score = s;
    shapes = ss;
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

  public int[][] getShapeCoefficients() {
    return shapes;
  }
}
