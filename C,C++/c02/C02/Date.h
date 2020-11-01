//: C02:Date.h
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
#ifndef DATE_H
#define DATE_H
#include <string>
#include <stdexcept>
#include <iosfwd>

class Date {
public:
  // A class for date calculations
  struct Duration {
    int years, months, days;
    Duration(int y, int m, int d)
    : years(y), months(m) ,days(d) {}
  };
  // An exception class
  struct DateError : public std::logic_error {
      DateError(const std::string& msg = "")
        : std::logic_error(msg) {}
  };
  Date();
  Date(int, int, int) throw(DateError);
  Date(const std::string&) throw(DateError);
  int getYear() const;
  int getMonth() const;
  int getDay() const;
  std::string toString() const;
  friend Duration duration(const Date&, const Date&);
  friend bool operator<(const Date&, const Date&);
  friend bool operator<=(const Date&, const Date&);
  friend bool operator>(const Date&, const Date&);
  friend bool operator>=(const Date&, const Date&);
  friend bool operator==(const Date&, const Date&);
  friend bool operator!=(const Date&, const Date&);
  friend std::ostream& operator<<(std::ostream&,
                                  const Date&);
  friend std::istream& operator>>(std::istream&, 
                                  Date&);
private:
  int year, month, day;
  int compare(const Date&) const;
  static int daysInPrevMonth(int year, int mon);
};

#endif ///:~
