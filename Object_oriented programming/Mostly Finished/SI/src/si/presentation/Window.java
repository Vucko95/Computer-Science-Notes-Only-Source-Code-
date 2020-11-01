package si.presentation;

import javax.swing.JFrame;

import si.model.Game;

public class Window {
	public static void main(String[] args) {
		JFrame window = new JFrame();
		window.setSize(Game.SCREEN_WIDTH, Game.SCREEN_HEIGHT);
		window.setResizable(false);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.setTitle("Space Invaders");
		window.setLocationRelativeTo(null);
		PlayerListener listener = new PlayerListener();
		window.addKeyListener(listener);
		MainMenu menu = new MainMenu(window, listener);
//		window.add(menu);
		window.setVisible(true);
		menu.run();
	}

}
