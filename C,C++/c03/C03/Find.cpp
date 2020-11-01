//: C03:Find.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{L} ../TestSuite/Test
#include <cctype>
#include <cstddef>
#include <string>
#include "../TestSuite/Test.h"
using namespace std;

// Make an uppercase copy of s
string upperCase(const string& s) {
  string upper(s);
  for(size_t i = 0; i < s.length(); ++i)
    upper[i] = toupper(upper[i]);
  return upper;
}

// Make a lowercase copy of s
string lowerCase(const string& s) {
  string lower(s);
  for(size_t i = 0; i < s.length(); ++i)
    lower[i] = tolower(lower[i]);
  return lower;
}

class FindTest : public TestSuite::Test {
  string chooseOne;
public:
  FindTest() : chooseOne("Eenie, Meenie, Miney, Mo") {}
  void testUpper() {
    string upper = upperCase(chooseOne);
    const string LOWER = "abcdefghijklmnopqrstuvwxyz";
    test_(upper.find_first_of(LOWER) == string::npos);
  }
  void testLower() {
    string lower = lowerCase(chooseOne);
    const string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    test_(lower.find_first_of(UPPER) == string::npos);
  }
  void testSearch() {
    // Case sensitive search
    size_t i = chooseOne.find("een");
    test_(i == 8);
    // Search lowercase:
    string test = lowerCase(chooseOne);
    i = test.find("een");
    test_(i == 0);
    i = test.find("een", ++i);
    test_(i == 8);
    i = test.find("een", ++i);
    test_(i == string::npos);
    // Search uppercase:
    test = upperCase(chooseOne);
    i = test.find("EEN");
    test_(i == 0);
    i = test.find("EEN", ++i);
    test_(i == 8);
    i = test.find("EEN", ++i);
    test_(i == string::npos);
  }
  void run() {
    testUpper();
    testLower();
    testSearch();
  }
};

int main() {
  FindTest t;
  t.run();
  return t.report();
} ///:~
