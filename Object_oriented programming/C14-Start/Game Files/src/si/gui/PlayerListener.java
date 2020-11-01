package si.gui;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class PlayerListener implements KeyListener {
  private static boolean left, right, fire;
  private static boolean x, h, n, m;

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
    if(n) {
      n = false;
      return true;
    }
    return false;
  }

  public static boolean highPressed() {
    if(h) {
      h = false;
      return true;
    }
    return false;
  }

  public static boolean exitPressed() {
    if(x) {
      x = false;
      return true;
    }
    return false;
  }
  
  public static boolean menuPressed() {
    if(m) {
      m = false;
      return true;
    }
    return false;
  }

  public void keyTyped(KeyEvent e) {
    if (e.getKeyChar() == 'n' || e.getKeyChar() == 'N') {
      n = true;
    } else if (e.getKeyChar() == 'x' || e.getKeyChar() == 'X') {
      x = true;
    } else if (e.getKeyChar() == 'h' || e.getKeyChar() == 'H') {
      h = true;
    }else if (e.getKeyChar() == 'm' || e.getKeyChar() == 'M') {
      m = true;
    }

  }
}