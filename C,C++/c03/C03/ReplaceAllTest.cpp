//: C03:ReplaceAllTest.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{-msc}
//{L} ReplaceAll
#include <iostream>
#include <cassert>
using namespace std;

string& replaceAll(string& context, const string& from,
  const string& to);

int main() {
  string text = "a man, a plan, a canal, panama";
  replaceAll(text, "an", "XXX");
  assert(text == "a mXXX, a plXXX, a cXXXal, pXXXama");
} ///:~
