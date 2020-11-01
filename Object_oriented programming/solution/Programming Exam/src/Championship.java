import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Championship {
  private ArrayList<Team> teams;
  private ArrayList<Driver> drivers;

  public Championship() {
    teams = new ArrayList<Team>();
    drivers = new ArrayList<Driver>();
  }

  public void addTeam(Team t) {
    teams.add(t);
  }

  public void addDriver(Driver d) {
    drivers.add(d);
  }

  public String toString() {
    String answer = "Current Driver Championship Table\n";
    answer += "Position Number Name Country Points\n";

    Collections.sort(drivers);
    int pos = 1;
    for (Driver d : drivers) {
      answer += pos++ + "     " + d.getNumber() + "     " + d.getShortName() + "    " + d.getCountry() + "   "
          + d.getPoints() + "\n";
    }
    answer += "Current Team Championship \nTable Position Name Points\n";
    Collections.sort(teams, new Comparator<Team>() {
      public int compare(Team o1, Team o2) {
        return Integer.compare(o2.getPoints(), o1.getPoints());
      }
    });
    pos = 1;
    for (Team t : teams) {
      answer += pos++ + "     " + t.getName() + "     " + t.getPoints() + "\n";
    }

    return answer;
  }

  public void readRaceData(String file) {
    try (BufferedReader br = new BufferedReader(new FileReader(file))) {
      String line = br.readLine();
      
      while(line !=  null) {
        String[] spl = line.split(" ");
        String pos = spl[0];
        int dNum = Integer.parseInt(spl[1]);
        int lap = Integer.parseInt(spl[2]);
        int pnt = Integer.parseInt(spl[3]);
        for(Driver d: drivers) {
          if(d.getNumber() == dNum) {
            d.addLaps(lap);
            d.addPoints(pnt);
          }
        }
        line = br.readLine();
      }
      
      
      
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }

  }
}
