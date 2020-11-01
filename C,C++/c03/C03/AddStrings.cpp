//: C03:AddStrings.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
#include <string>
#include <cassert>
using namespace std;

int main() {
  string s1("This ");
  string s2("That ");
  string s3("The other ");
  // operator+ concatenates strings
  s1 = s1 + s2;
  assert(s1 == "This That ");
  // Another way to concatenates strings
  s1 += s3;
  assert(s1 == "This That The other ");
  // You can index the string on the right
  s1 += s3 + s3[4] + "ooh lala";
  assert(s1 == "This That The other The other "
        "ooh lala");
} ///:~
