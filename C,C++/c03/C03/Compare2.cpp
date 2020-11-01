//: C03:Compare2.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Illustrate overloaded compare()
#include <cassert>
#include <string>
using namespace std;

int main() {
  string first("This is a day that will live in infamy");
  string second("I don't believe that this is what "
                "I signed up for");
  // Compare "his is" in both strings:
  assert(first.compare(1, 7, second, 22, 7) == 0);
  // Compare "his is a" to "his is w":
  assert(first.compare(1, 9, second, 22, 9) < 0);
} ///:~
