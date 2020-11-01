import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    ArrayList<Driver> drvrs = readDriverData();
    Championship champ = new Championship();
    for (int i = 0; i < drvrs.size(); i++) {
//      System.out.println(drvrs.get(i));
      champ.addDriver(drvrs.get(i));
    }
    
    ArrayList<Team> teams = readTeamData(drvrs);
    for (int i = 0; i < teams.size(); i++) {
//      System.out.println(teams.get(i));
      champ.addTeam(teams.get(i));
    }
    System.out.println(champ);
    
    for(int i = 1; i < 21; i++) {
      String name = i + ".txt";
      champ.readRaceData(name);
      System.out.println(champ);
    }
  }

  public static ArrayList<Driver> readDriverData() {
    ArrayList<Driver> drivers = new ArrayList<Driver>();
    try (BufferedReader br = new BufferedReader(new FileReader("d.txt"))) {
      String line = br.readLine();
      while (line != null) {
        Scanner in = new Scanner(line);
        String firName = in.next();
        String famName = in.next();
        String name = firName + " " + famName;
        String shName = in.next();
        int num = in.nextInt();
        String cntry = in.next();
        Driver d = new Driver(name, shName, cntry, num);
        drivers.add(d);

        in.close();

        line = br.readLine();
      }

    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }

    return drivers;
  }

  public static ArrayList<Team> readTeamData(ArrayList<Driver> drivers) {
    ArrayList<Team> teams = new ArrayList<Team>();
    try (BufferedReader br = new BufferedReader(new FileReader("t.txt"))) {
      String line = br.readLine();
      while (line != null) {
        Scanner in = new Scanner(line);
        String name = in.next();
        while (!in.hasNextInt()) {
          name += " " + in.next();
        }
        Team t = new Team(name);
        while (in.hasNextInt()) {
          int num = in.nextInt();
          for (int i = 0; i < drivers.size(); i++) {
            if (drivers.get(i).getNumber() == num) {
              t.addDriver(drivers.get(i));
            }
          }
        }
        teams.add(t);

        line = br.readLine();
      }

    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }

    return teams;
  }
}
