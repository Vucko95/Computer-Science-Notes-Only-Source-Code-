package si.db;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

import si.model.ScoreKeeper;

public class PersistentScoreKeeper extends ScoreKeeper {
	public PersistentScoreKeeper() {
		super();
		loadFile();
	}

	public void loadFile() {
		try (BufferedReader br = new BufferedReader(new FileReader("scores.txt"))) {
			String line = br.readLine();
			int i = 0;
			while(line != null && i < 10) {
				Scanner s = new Scanner(line);
				int score = s.nextInt();
				String name = s.nextLine().trim();
				scores[i++] = new Score(name, score);
				line = br.readLine();
				s.close();
			}
		} catch (IOException e) {
			System.err.println("Error reading score file");
		}
	}
	
	public void saveScores() {
		try (BufferedWriter bw = new BufferedWriter(new FileWriter("scores.txt"))) {
			for(int i = 0; i < scores.length; i++) {
				bw.write(scores[i].getScore() + " " + scores[i].getName()+"\n");
			}
			bw.close();
		} catch (IOException e) {
			System.err.println("Error writing score file");
		}
	}
}
