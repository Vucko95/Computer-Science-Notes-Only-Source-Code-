//: C07:VectorCoreDump.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Invalidating an iterator
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vi(10, 0);
  ostream_iterator<int> out(cout, " ");
  vector<int>::iterator i = vi.begin();
  *i = 47;
  copy(vi.begin(), vi.end(), out);
  cout << endl;
  // Force it to move memory (could also just add
  // enough objects):
  vi.resize(vi.capacity() + 1);
  // Now i points to wrong memory:
  *i = 48;  // Access violation
  copy(vi.begin(), vi.end(), out); // No change to vi[0]
} ///:~
