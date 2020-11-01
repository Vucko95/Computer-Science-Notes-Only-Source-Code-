package si.gui;

import javax.swing.JFrame;

import si.Game;

public class Window {
  public static void main(String[] args) {
    JFrame window = new JFrame();
    window.setSize(Game.SCREEN_WIDTH, Game.SCREEN_HEIGHT);
    window.setResizable(false);
    window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    window.setTitle("Space Invaders");
    window.setLocationRelativeTo(null);
    ScreenController controller = new ScreenController(window);
    window.addKeyListener(new PlayerListener());
    window.setVisible(true);
    controller.run();
  }
}