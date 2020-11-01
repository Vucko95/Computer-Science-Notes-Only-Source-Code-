package si.gui;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Rectangle;

import javax.swing.JComponent;

import si.Game;
import si.ScoreBoard;
import si.ScoreBoard.Score;

public class ScoreScreen extends JComponent {
  private static final long serialVersionUID = -8282302849760730222L;
  ScoreBoard board;
  public ScoreScreen(ScoreBoard b) {
    board = b;
  }
  public void paintComponent(Graphics g) {
    g.fillRect(0, 0, Game.SCREEN_WIDTH, Game.SCREEN_HEIGHT);
    g.setFont(new Font("Arial", Font.BOLD, 36));
    g.setColor(Color.GREEN);
    
    g.drawString("Space Invaders Hall of Fame", 10, 50);
    Score[] scores = board.getScores();
    g.setFont(new Font("Arial", Font.BOLD, 24));
    for (int i = 0; i < scores.length; i++) {
      Score score = scores[i];
      g.drawString(score.getName(), 2 * Game.SCREEN_WIDTH / 6, 96 + i * 32);
      g.drawString("" + score.getScore(), 4 * Game.SCREEN_WIDTH / 6, 96 + i * 32);
    }
    g.drawString("Press 'M' to return to the Main Menu", 50, 450);
  }
}