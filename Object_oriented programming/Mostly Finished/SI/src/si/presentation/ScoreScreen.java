package si.presentation;

import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;

import javax.swing.JPanel;

import si.model.Game;
import si.model.ScoreKeeper;
import si.model.ScoreKeeper.Score;

public class ScoreScreen extends JPanel {
	private static final long serialVersionUID = 1616386874546775416L;
	private ScoreKeeper scoreKeeper;
	private boolean menu = false;
	private PlayerListener listener;

	public ScoreScreen(ScoreKeeper sc, PlayerListener l) {
		this.scoreKeeper = sc;
		this.listener = l;
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

	public void paintComponent(Graphics g) {
		g.fillRect(0, 0, Game.SCREEN_WIDTH, Game.SCREEN_HEIGHT);
		drawString(g, "Space Invaders Hall of Fame", new Rectangle(0, 0, Game.SCREEN_WIDTH, Game.SCREEN_HEIGHT / 8),
				36);
		g.setColor(Color.GREEN);
		Score[] scores = scoreKeeper.getScores();
		g.setFont(new Font("Arial", Font.BOLD, 24));
		for (int i = 0; i < scores.length; i++) {
			Score score = scores[i];
			g.drawString(score.getName(), 2 * Game.SCREEN_WIDTH / 6, 96 + i * 32);
			g.drawString("" + score.getScore(), 4 * Game.SCREEN_WIDTH / 6, 96 + i * 32);
		}
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

}
