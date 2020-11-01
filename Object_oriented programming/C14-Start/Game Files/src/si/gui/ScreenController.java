package si.gui;

import java.awt.CardLayout;

import javax.swing.JFrame;
import javax.swing.JPanel;

import si.Game;
import si.ScoreBoard;

public class ScreenController {
  private Game game;
  private JPanel panel;
  private CardLayout layout;

  public ScreenController(JFrame w) {
    game = new Game();
    layout = new CardLayout();
    panel = new JPanel(layout);
    panel.add(new GameScreen(game), "Game");
    panel.add(new MenuScreen(), "Menu");
    panel.add(new ScoreScreen(new ScoreBoard()), "Scores");
    w.getContentPane().add(panel);
    layout.show(panel, "Scores");
  }

  public void run() {
    // while() {
    // game.step();
    // }

  }
}
