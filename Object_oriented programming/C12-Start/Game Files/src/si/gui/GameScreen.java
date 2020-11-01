package si.gui;

import si.Drawable;
import si.Game;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;

import javax.swing.JComponent;

public class GameScreen extends JComponent {
  private static final long serialVersionUID = -8282302849760730222L;
  private Game game;
  public GameScreen(Game g) {
    game = g;
  }
  protected void paintComponent(Graphics g) {
    g.setColor(Color.black);
    g.fillRect(0, 0, Game.SCREEN_WIDTH, Game.SCREEN_HEIGHT);
    g.setColor(Color.green);
    for (Drawable d : game.getDrawable()) {
      for (Rectangle s : d.getShape()) {
        g.fillRect(s.x, s.y, s.width, s.height);
      }
    }
  }
}