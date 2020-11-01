//: C02:SimpleDateTest2.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{L} Date
#include <iostream>
#include "Date.h"
using namespace std;

// Test machinery
int nPass = 0, nFail = 0;
void test(bool t) {
  if(t) nPass++; else nFail++;
}

int main() {
  Date mybday(1951, 10, 1);
  Date today;
   Date myevebday("19510930");
  
  // Test the operators
  test(mybday < today);
  test(mybday <= today);
  test(mybday != today);
  test(mybday == mybday);
  test(mybday >= mybday);
  test(mybday <= mybday);
  test(myevebday < mybday);
  test(mybday > myevebday);
  test(mybday >= myevebday);
  test(mybday != myevebday);

  // Test the functions
  test(mybday.getYear() == 1951);
  test(mybday.getMonth() == 10);
  test(mybday.getDay() == 1);
  test(myevebday.getYear() == 1951);
  test(myevebday.getMonth() == 9);
  test(myevebday.getDay() == 30);
  test(mybday.toString() == "19511001");
  test(myevebday.toString() == "19510930");

  // Test duration
  Date d2(2002, 7, 4);
  Date::Duration dur = duration(mybday, d2);
  test(dur.years == 50);
  test(dur.months == 9);
  test(dur.days == 3);

  // Report results:
  cout << "Passed: " << nPass << ", Failed: "
       << nFail << endl;
} ///:~
