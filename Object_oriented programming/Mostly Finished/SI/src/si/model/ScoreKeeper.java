package si.model;

import java.util.Arrays;
import java.util.Comparator;

public class ScoreKeeper {
	protected Score[] scores;

	public ScoreKeeper() {
		scores = new Score[10];
		for (int i = 0; i < scores.length; i++) {
			scores[i] = new Score("Player 1", 0);
		}
	}

	private void sortScores() {
		Arrays.sort(scores, new Comparator<Score>() {
			public int compare(Score a, Score b) {
				return Integer.compare(b.value, a.value);
			}
		});
	}

	public int getLowestScore() {
		sortScores();
		return scores[9].value;
	}

	public Score[] getScores() {
		Score[] scs = new Score[10];
		for (int i = 0; i < scs.length; i++) {
			scs[i] = scores[i];
		}
		return scs;
	}

	public class Score {
		private String name;
		private int value;

		public Score(String n, int s) {
			this.name = n;
			this.value = s;
		}

		public String getName() {
			return name;
		}

		public int getScore() {
			return value;
		}
	}

	public void saveScores() {
		// Just a place holder for the persistent subclass
	}

	public void addScore(String name, int s) {
		scores[9] = new Score(name, s);
		sortScores();
	}
}
