//: C04:Datalogger.cpp {O}
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Datapoint implementations
#include "DataLogger.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

ostream& operator<<(ostream& os, const Coord& c) {
  return os << c.deg << '*' << c.min << '\''
            << c.sec << '"';
}

string Coord::toString() const {
  ostringstream os;
  os << *this;
  return os.str();
}

ostream& operator<<(ostream& os, const DataPoint& d) {
  os.setf(ios::fixed, ios::floatfield);
  char fillc = os.fill('0'); // Pad on left with '0'
  tm* tdata = localtime(&d.timestamp);
  os << setw(2) << tdata->tm_mon << '\\'
     << setw(2) << tdata->tm_mday << '\\'
     << setw(2) << tdata->tm_year+1900 << ' '
     << setw(2) << tdata->tm_hour << ':'
     << setw(2) << tdata->tm_min << ':'
     << setw(2) << tdata->tm_sec;
  os.fill(' '); // Pad on left with ' '
  streamsize prec = os.precision(4);
  os << " Lat:" << setw(9) << d.latitude.toString()
     << ", Long:" << setw(9) << d.longitude.toString()
     << ", depth:" << setw(9) << d.depth
     << ", temp:" << setw(9) << d.temperature;
  os.fill(fillc);
  os.precision(prec);
  return os;
} ///:~
