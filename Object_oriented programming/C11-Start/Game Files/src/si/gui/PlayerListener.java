package si.gui;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class PlayerListener implements KeyListener {
  private static boolean left;
  private static boolean right;
  private static boolean fire;
  private static boolean x, h, n;

  public void keyPressed(KeyEvent e) {
    if (e.getKeyCode() == KeyEvent.VK_LEFT) {
      left = true;
    } else if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
      right = true;
    } else if (e.getKeyCode() == KeyEvent.VK_SPACE) {
      fire = true;
    }
  }

  public void keyReleased(KeyEvent e) {
    if (e.getKeyCode() == KeyEvent.VK_LEFT) {
      left = false;
    } else if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
      right = false;
    } else if (e.getKeyCode() == KeyEvent.VK_SPACE) {
      fire = false;
    }
  }

  public static boolean isLeft() {
    return left;
  }

  public static boolean isRight() {
    return right;
  }

  public static boolean isFire() {
    return fire;
  }

  public static boolean newPressed() {
    return n;
  }

  public static boolean highPressed() {
    return h;
  }

  public static boolean exitPressed() {
    return x;
  }

  public void keyTyped(KeyEvent e) {
    if (e.getKeyChar() == 'n' || e.getKeyChar() == 'N') {
      n = true;
    } else if (e.getKeyChar() == 'x' || e.getKeyChar() == 'X') {
      x = true;
    } else if (e.getKeyChar() == 'h' || e.getKeyChar() == 'H') {
      h = true;
    }

  }
}