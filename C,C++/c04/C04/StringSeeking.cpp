//: C04:StringSeeking.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Reads and writes a string stream
//{-bor}
#include <cassert>
#include <sstream>
#include <string>
using namespace std;

int main() {
  string text = "We will sell no wine";
  stringstream ss(text);
  ss.seekp(0, ios::end);
  ss << " before its time.";
  assert(ss.str() ==
    "We will sell no wine before its time.");
  // Change "sell" to "ship"
  ss.seekg(9, ios::beg);
  string word;
  ss >> word;
  assert(word == "ell");
  ss.seekp(9, ios::beg);
  ss << "hip";
  // Change "wine" to "code"
  ss.seekg(16, ios::beg);
  ss >> word;
  assert(word == "wine");
  ss.seekp(16, ios::beg);
  ss << "code";
  assert(ss.str() ==
    "We will ship no code before its time.");
  ss.str("A horse of a different color.");
  assert(ss.str() == "A horse of a different color.");
} ///:~
