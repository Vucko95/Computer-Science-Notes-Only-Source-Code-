package si;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class ScoreBoard {
  protected Score[] scores;

  public class Score {
    private String name;
    private int value;

    public Score(String n, int s) {
      this.name = n;
      this.value = s;
    }

    public String getName() {
      return name;
    }

    public int getScore() {
      return value;
    }
  }

  public ScoreBoard() {
    scores = new Score[10];
    for (int i = 0; i < scores.length; i++) {
      scores[i] = new Score("Player 1", 0);
    }
    loadScores();
    sortScores();
  }

  private void sortScores() {
    Arrays.sort(scores, new Comparator<Score>() {
      public int compare(Score o1, Score o2) {
        return Integer.compare(o1.value, o2.value);
      }
    });
  }

  private void loadScores() {
    try (BufferedReader br = new BufferedReader(new FileReader("scores.txt"))) {
      String line = br.readLine();
      int i = 0;
      while (line != null && i < 10) {
        Scanner s = new Scanner(line);
        int score = s.nextInt();
        String name = s.nextLine().trim();
        scores[i++] = new Score(name, score);
        line = br.readLine();
        s.close();
      }
    } catch (IOException e) {
      System.err.println("Error reading score file");
    }
  }

  public Score[] getScores() {
    Score[] scs = new Score[10];
    for (int i = 0; i < scs.length; i++) {
      scs[i] = scores[i];
    }
    return scs;
  }

  public void saveScores() {
    try (BufferedWriter bw = new BufferedWriter(new FileWriter("scores.txt"))) {
      for (int i = 0; i < scores.length; i++) {
        bw.write(scores[i].getScore() + " " + scores[i].getName() + "\n");
      }
      bw.close();
    } catch (IOException e) {
      System.err.println("Error writing score file");
    }

  }

  public void addScore(Score s) {
    sortScores();
    if (scores[9].value < s.value) {
      scores[9] = s;
      sortScores();
    }
  }
}