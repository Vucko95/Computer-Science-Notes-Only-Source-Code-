package si.presentation;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Shape;

import javax.swing.JComponent;

import si.model.Drawable;
import si.model.Game;

public class GameScreen extends JComponent {
	private static final long serialVersionUID = -8282302849760730222L;
	private Game game;

	protected void paintComponent(Graphics g) {
		if (game != null) {
			Graphics2D g2 = (Graphics2D) g;
			g.setColor(Color.black);
			g.fillRect(0, 0, Game.SCREEN_WIDTH, Game.SCREEN_HEIGHT);
			g.setColor(Color.green);
			g.drawString("Lives: " + game.getLives(), 0, 20);
			g.drawString("Score: " + game.getScore(), Game.SCREEN_WIDTH / 2, 20);

			g2.fill(game.getShip());
			for (Drawable bullet : game.getBullets()) {
				for (Shape s : bullet.getShapes()) {
					g2.fill(s);
				}
			}
			for (Shape s : game.getDrawable()) {
					g2.fill(s);
			}

			if ((game.isPaused() || game.getPlayer().isDestroyed() )&& game.getLives() > 0) {
				g.drawString("Press 'p' to continue ", 256, 256);
			} else if (game.getPlayer().isDestroyed() && game.getLives() == 0) {
				g.drawString("Game over ", 480, 256);
			}
		}
	}

	public void addGame(Game g) {
		System.out.println("here");
		this.game = g;
	}
}
