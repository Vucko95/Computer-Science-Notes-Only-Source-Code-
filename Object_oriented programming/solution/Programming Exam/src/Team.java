import java.util.ArrayList;

public class Team {
  private String name;
  private ArrayList<Driver> drivers;

  public Team(String n) {
    name = n;
    drivers = new ArrayList<Driver>();
  }
public String getName() {
  return name;
}
  public void addDriver(Driver d) {
    drivers.add(d);
  }

  public int getPoints() {
    int sum = 0;
    for (int i = 0; i < drivers.size(); i++) {
      sum += drivers.get(i).getPoints();
    }
    return sum;
  }

  public String toString() {
    String ans = name + '\n';
    for (int i = 0; i < drivers.size(); i++) {
      ans += drivers.get(i).toString() + "\n";
    }
    return ans;
  }
}
