//: C04:Facets.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{-bor}
//{-g++}
#include <iostream>
#include <locale>
#include <string>
using namespace std;

int main() {
  // Change to French/France
  locale loc("french");
  cout.imbue(loc);

  string currency =
    use_facet<moneypunct<char> >(loc).curr_symbol();
  char point =
    use_facet<moneypunct<char> >(loc).decimal_point();
  cout << "I made " << currency << 12.34 << " today!"
       << endl;
} ///:~
