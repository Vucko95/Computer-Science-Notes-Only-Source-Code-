//: C06:InsertVector.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Appends the contents of a vector to another
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iterator>
#include <vector>
using namespace std;

int main() {
  int a[] = {10, 20, 30};
  const size_t SIZE = sizeof a / sizeof a[0];
  vector<int> v1(a, a + SIZE);
  vector<int> v2;  // v2 is empty here
  copy(v1.begin(), v1.end(), back_inserter(v2));
  assert(equal(v1.begin(), v1.end(), v2.begin()));
} ///:~
