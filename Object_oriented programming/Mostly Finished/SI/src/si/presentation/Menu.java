package si.presentation;

import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;

import javax.swing.JPanel;

import si.model.Game;

public class Menu extends JPanel {
	private static final long serialVersionUID = 1616386874546775416L;

	private void drawString(Graphics g, String text, Rectangle rect, int size) {
		Graphics2D g2d = (Graphics2D) g.create();

		Font font = new Font("Arial", Font.BOLD, size);
		g2d.setFont(font);
		FontMetrics metrics = g2d.getFontMetrics();
		int x = rect.x + (rect.width - metrics.stringWidth(text)) / 2;
		int y = rect.y + ((rect.height - metrics.getHeight()) / 2) + metrics.getAscent();

		g2d.setColor(Color.GREEN);
		g2d.drawString(text, x, y);
		
	}

	public void paintComponent(Graphics g) {
		g.setColor(Color.BLACK);
		g.fillRect(0, 0, Game.SCREEN_WIDTH, Game.SCREEN_HEIGHT);
		drawString(g, "Welcome to Space Invaders!!!!", new Rectangle(Game.SCREEN_WIDTH / 3, Game.SCREEN_HEIGHT / 6,
				Game.SCREEN_WIDTH / 3, Game.SCREEN_HEIGHT / 3), 24);
		drawString(g, "To play a game press N", new Rectangle(Game.SCREEN_WIDTH / 3, 2 * Game.SCREEN_HEIGHT / 6,
				Game.SCREEN_WIDTH / 3, Game.SCREEN_HEIGHT / 3), 18);
		drawString(g, "To see the High scores press H", new Rectangle(Game.SCREEN_WIDTH / 3, 3 * Game.SCREEN_HEIGHT / 6,
				Game.SCREEN_WIDTH / 3, Game.SCREEN_HEIGHT / 3), 18);
		drawString(g, "To exit press X", new Rectangle(Game.SCREEN_WIDTH / 3, 4 * Game.SCREEN_HEIGHT / 6,
				Game.SCREEN_WIDTH / 3, Game.SCREEN_HEIGHT / 3), 18);

	}
}
