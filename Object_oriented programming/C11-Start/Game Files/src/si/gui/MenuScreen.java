package si.gui;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Rectangle;

import javax.swing.JComponent;

import si.AlienType;
import si.Bullet;
import si.Drawable;
import si.Enemy;
import si.Game;
import si.Player;

public class MenuScreen extends JComponent {
  private static final long serialVersionUID = 8486434029426170925L;
  private Drawable[] images;

  public MenuScreen() {
    images = new Drawable[5];
    images[0] = new Enemy(50, 100, 5, AlienType.A);
    images[1] = new Enemy(150, 100, 5, AlienType.B);
    images[2] = new Enemy(200, 100, 5, AlienType.C);
    images[3] = new Bullet(220, 140, true, 0);
    images[4] = new Player(200, 200, 5);
  }

  public void paintComponent(Graphics g) {
    g.setColor(Color.black);
    g.fillRect(0, 0, Game.SCREEN_WIDTH, Game.SCREEN_HEIGHT);
    g.setColor(Color.green);
    
    g.setFont(new Font("Arial", Font.PLAIN, 36));
    g.drawString("Welcome to Space Invaders!!!!", 5, 50);

    g.setFont(new Font("Arial", Font.PLAIN, 18));
    g.drawString("To play press N", Game.SCREEN_WIDTH / 4, 250);
    g.drawString("To view high scores press H", Game.SCREEN_WIDTH / 4, 300);
    g.drawString("To exit press X", Game.SCREEN_WIDTH / 4, 350);

    for (int i = 0; i < images.length; i++) {
      Rectangle[] r = images[i].getShape();
      for (int j = 0; j < r.length; j++) {
        g.fillRect(r[j].x, r[j].y, r[j].width, r[j].height);
      }
    }
  }
}
