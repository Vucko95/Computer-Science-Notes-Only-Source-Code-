/**
 * Used to execute the case-based recommendation algorithm
 * (MOM note - based on RS-CB-ALL)
 * 
 * @author michaelomahony
 */

package alg.cb;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import alg.cb.similarity.cases.CaseSimilarity;
import alg.cb.similarity.cases.TitleSimilarity;
import alg.cb.similarity.cases.WeightedJaccardSimilarity;
import alg.cb.recommender.Recommender;
import alg.cb.casebase.Casebase;
import alg.cb.recommender.MaxRecommender;
import alg.cb.recommender.MeanRecommender;
import alg.cb.util.DatasetReader;

public class ExecuteCB {
	public static void main(String[] args) {	
		// set the path and filename of the movie file and read in the data
		String movieFile = "dataset" + File.separator + "movies.txt";
		DatasetReader reader = new DatasetReader(movieFile);
		Casebase cb = reader.getCasebase();

		// configure the case-based recommendation algorithm - set the case similarity and recommender
		CaseSimilarity caseSimilarity = new WeightedJaccardSimilarity();
		Recommender recommender = new MeanRecommender(caseSimilarity, cb);

		// Create an instance of the Scanner class
		Scanner input = new Scanner(System.in);

		do {
			// randomly choose some target cases and display these cases
			int numberTargetMovies = 2;
			List<Integer> targetIds = getRandomTargetIds(cb, numberTargetMovies);

			System.out.println("\nTarget movies:");
			for (int id: targetIds)
				System.out.println("- " + cb.getCase(id).getTitle());

			// display the top-k recommendations based on the target cases
			List<Integer> recIds = recommender.getRecommendations(targetIds);
			int numberRecommendedMovies = 3; 

			if (recIds.size() > 0) {
				System.out.println("\nRecommended movies:");
				for (int i = 0; i < recIds.size() && i < numberRecommendedMovies; i++)
					System.out.println("- " + cb.getCase(recIds.get(i)).getTitle());
			} else
				System.out.println("\nNo recommended movies");

			// Prompt the user to enter 'y' or 'Y' to go again
			System.out.print("\nEnter 'q' to quit or any other character to go again> ");
			if (input.nextLine().toLowerCase().charAt(0) == 'q')
				break; // The user wishes to quit
		} while (true);

		// Display a final message
		System.out.println("\nGoodbye");

		// Close the Scanner
		input.close();
	}

	// returns a list containing n randomly selected unique ids
	public static List<Integer> getRandomTargetIds(Casebase cb, int n) {
		List<Integer> ids = new ArrayList<>();

		int count = 0;
		while (count < n)
			do {
				int id = (int)(Math.random() * cb.getSize());

				if (!ids.contains(id)) {
					ids.add(id);
					count++;
					break;
				}
			} while (true);

		return ids;
	}
}
