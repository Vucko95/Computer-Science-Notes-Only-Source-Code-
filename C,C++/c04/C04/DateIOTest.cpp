//: C04:DateIOTest.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{L} ../C02/Date
#include <iostream>
#include <sstream>
#include "../C02/Date.h"
using namespace std;

void testDate(const string& s) {
  istringstream os(s);
  Date d;
  os >> d;
  if (os)
    cout << d << endl;
  else
    cout << "input error with \"" << s << "\"\n";
}

int main() {
  testDate("08-10-2002");
  testDate("8-10-2002");
  testDate("08 - 10 - 2002");
  testDate("A-10-2002");
  testDate("08%10/2002");
} ///:~
