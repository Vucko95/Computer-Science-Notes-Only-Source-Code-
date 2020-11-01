package si.gui;

import java.awt.CardLayout;

import javax.swing.JFrame;
import javax.swing.JPanel;

import si.Game;

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
    w.getContentPane().add(panel);
    layout.show(panel, "Menu");
  }

  public void run() {
    game.step();
  }
}
