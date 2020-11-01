//: C03:CompStr.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{L} ../TestSuite/Test
#include <string>
#include "../TestSuite/Test.h"
using namespace std;

class CompStrTest : public TestSuite::Test {
public:
  void run() {
    // Strings to compare
    string s1("This");
    string s2("That");
    test_(s1 == s1);
    test_(s1 != s2);
    test_(s1 > s2);
    test_(s1 >= s2);
    test_(s1 >= s1);
    test_(s2 < s1);
    test_(s2 <= s1);
    test_(s1 <= s1);
  }
};

int main() {
  CompStrTest t;
  t.run();
  return t.report();
} ///:~
