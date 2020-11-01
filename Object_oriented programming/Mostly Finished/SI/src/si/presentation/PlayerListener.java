package si.presentation;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class PlayerListener implements KeyListener {
	private boolean left;
	private boolean right;
	private boolean fire;
	private boolean start;
	private boolean newGame;
	private boolean high;
	private boolean exit;
	private boolean menu;
	private boolean pause;
	private boolean about;

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

	public void keyTyped(KeyEvent e) {
		if (e.getExtendedKeyCode() == KeyEvent.VK_S) {
			start = true;
		} else if (e.getExtendedKeyCode() == KeyEvent.VK_H) {
			high = true;
		} else if (e.getExtendedKeyCode() == KeyEvent.VK_X) {
			exit = true;
		} else if (e.getExtendedKeyCode() == KeyEvent.VK_M) {
			menu = true;
		} else if (e.getExtendedKeyCode() == KeyEvent.VK_N) {
			newGame = true;
		} else if (e.getExtendedKeyCode() == KeyEvent.VK_P) {
			pause = true;
		}else if (e.getExtendedKeyCode() == KeyEvent.VK_A) {
			about = true;
		}
	}

	public boolean isLeft() {
		return left;
	}

	public boolean isRight() {
		return right;
	}

	public boolean isFire() {
		return fire;
	}

	public boolean isStart() {
		if (start) {
			start = false;
			return true;
		}
		return false;
	}

	public boolean isHigh() {
		if (high) {
			high = false;
			return true;
		}
		return false;
	}

	public boolean isExit() {
		if (exit) {
			exit = false;
			return true;
		}
		return false;
	}

	public boolean isMenu() {
		if (menu) {
			menu = false;
			return true;
		}
		return false;
	}

	public boolean isNew() {
		if (newGame) {
			newGame = false;
			return true;
		}
		return false;
	}

	public void reset() {
		left = false;
		right = false;
		fire = false;
		start = false;
		high = false;
		exit = false;
		menu = false;
		newGame = false;
	}

	public boolean isPlayPause() {
		if (pause) {
			pause = false;
			return true;
		}
		return false;
	}

	public boolean isAbout() {
		if (about) {
			about = false;
			return true;
		}
		return false;
	}
}
