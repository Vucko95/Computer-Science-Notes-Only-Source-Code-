package si.presentation;

import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;

import javax.swing.JPanel;

import si.model.Game;

public class AboutScreen extends JPanel {
	private static final long serialVersionUID = -1264717778772722118L;
	private boolean menu = false;
	private PlayerListener listener;

	public AboutScreen(PlayerListener pl) {
		listener = pl;
	}

	public void paintComponent(Graphics g) {
		g.setColor(Color.BLACK);
		g.fillRect(0, 0, Game.SCREEN_WIDTH, Game.SCREEN_HEIGHT);
		g.setColor(Color.green);
		drawString(g, "Space Invader Controlls", new Rectangle(0, 0, Game.SCREEN_WIDTH, 64), 36);
		g.drawString("Move Left", 1 * Game.SCREEN_WIDTH / 6, 96 + 0 * 32);
		g.drawString("left arrow", 4 * Game.SCREEN_WIDTH / 6, 96 + 0 * 32);
		g.drawString("Move Right", 1 * Game.SCREEN_WIDTH / 6, 96 + 1 * 32);
		g.drawString("right arrow", 4 * Game.SCREEN_WIDTH / 6, 96 + 1 * 32);
		g.drawString("Fire", 1 * Game.SCREEN_WIDTH / 6, 96 + 2 * 32);
		g.drawString("space bar", 4 * Game.SCREEN_WIDTH / 6, 96 + 2 * 32);
		g.drawString("Play/Pause", 1 * Game.SCREEN_WIDTH / 6, 96 + 3 * 32);
		g.drawString("p", 4 * Game.SCREEN_WIDTH / 6, 96 + 3 * 32);
		drawString(g, "Press 'M' to return to the Main Menu", new Rectangle(0, 416, Game.SCREEN_WIDTH, 96), 24);
	}

	public void run() {
		while (!menu) {
			if (listener.isMenu()) {
				menu = true;
			}
			try {
				Thread.sleep(5);
			} catch (InterruptedException e) {
			}
		}
		listener.reset();
		menu = false;
	}

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
}
