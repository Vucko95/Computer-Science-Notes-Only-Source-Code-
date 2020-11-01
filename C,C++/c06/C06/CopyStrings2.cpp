//: C06:CopyStrings2.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Replaces strings that satisfy a predicate
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;
// The predicate
bool contains_e(const string& s) {
  return s.find('e') != string::npos;
}
int main() {
  string a[] = {"read", "my", "lips"};
  const size_t SIZE = sizeof a / sizeof a[0];
  string b[SIZE];
  string* endb =
    replace_copy_if(a, a + SIZE, b, contains_e, 
                    string("kiss"));
  string* beginb = b;
  while (beginb != endb)
    cout << *beginb++ << endl;
} ///:~
