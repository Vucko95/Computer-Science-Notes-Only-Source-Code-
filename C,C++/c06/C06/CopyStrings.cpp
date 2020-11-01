//: C06:CopyStrings.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Copies strings
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <string>
using namespace std;

int main() {
  string a[] = {"read", "my", "lips"};
  const size_t SIZE = sizeof a / sizeof a[0];
  string b[SIZE];
  copy(a, a + SIZE, b);
  assert(equal(a, a + SIZE, b));
} ///:~
