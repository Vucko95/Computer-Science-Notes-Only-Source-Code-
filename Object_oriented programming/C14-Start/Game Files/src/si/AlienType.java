package si;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public enum AlienType {
  A("A.dat"), B("B.dat"), C("C.dat");
  private int width;
  private int height;
  private int score;
  private int[][] shapes;

  private AlienType(String n) {
    try (DataInputStream dis = new DataInputStream(new FileInputStream(n))) {
      width = dis.readInt();
      height = dis.readInt();
      score = dis.readInt();
      int nShapes = dis.readInt();
      shapes = new int[nShapes][4];

      for (int i = 0; i < nShapes; i++) {
        for (int j = 0; j < 4; j++) {
          shapes[i][j] = dis.readInt();
        }
      }

    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

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
