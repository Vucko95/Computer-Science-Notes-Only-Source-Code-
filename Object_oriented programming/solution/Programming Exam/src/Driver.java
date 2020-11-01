
public class Driver implements Comparable<Driver> {
  private int points;
  private int number;
  private int laps;
  private String name;
  private String country;
  private String shortName;
  public Driver(String na, String sn, String cn, int n) {
    number = n;
    name = na;
    shortName = sn;
    country = cn;
  }
  
  public void addPoints(int p) {
    points += p;
  }
  public void addLaps(int l) {
    laps += l;
  }
  
  public String getShortName() {
    return shortName;
  }
  public int getPoints() {
    return points;
  }
  
  public String toString() {
    return number + " " + shortName + " " + name + " from " + country  + " has "+points+" points and has raced "+laps+" laps";
  }

  public int getNumber() {
    return number;
  }

  public int compareTo(Driver d) {
    return Integer.compare(d.points, points);
  }

  public String getCountry() {
    return country;
  }
}
