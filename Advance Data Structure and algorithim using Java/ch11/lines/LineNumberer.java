import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
   This program applies line numbers to a file.
*/
public class LineNumberer
{
   public static void main(String[] args) throws FileNotFoundException
   {
      // Prompt for the input and output file names

      Scanner console = new Scanner(System.in);
      System.out.print("Input file: ");
      String inputFileName = console.next();
      System.out.print("Output file: ");
      String outputFileName = console.next();

      // Construct the Scanner and PrintWriter objects for reading and writing

      File inputFile = new File(inputFileName);
      Scanner in = new Scanner(inputFile);
      PrintWriter out = new PrintWriter(outputFileName);
      int lineNumber = 1;
      
      // Read the input and write the output

      while (in.hasNextLine())
      {
         String line = in.nextLine();
         out.println("/* " + lineNumber + " */ " + line);
         lineNumber++;
      }

      in.close();
      out.close();
   }
}
