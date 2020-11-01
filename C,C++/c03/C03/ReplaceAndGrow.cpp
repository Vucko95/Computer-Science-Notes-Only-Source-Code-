//: C03:ReplaceAndGrow.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
#include <cassert>
#include <string>
using namespace std;

int main() {
  string bigNews("I have been working the grave.");
  string replacement("yard shift.");
  // The first arg says "replace chars
  // beyond the end of the existing string":
  bigNews.replace(bigNews.size() - 1,
    replacement.size(), replacement);
  assert(bigNews == "I have been working the "
         "graveyard shift.");
} ///:~
