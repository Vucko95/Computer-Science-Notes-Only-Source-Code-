//: C06:BinderValue.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// The bound argument can vary
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

int boundedRand() { return rand() % 100; }

int main() {
  const int SZ = 20;
  int a[SZ], b[SZ] = {0};
  generate(a, a + SZ, boundedRand);
  int val = boundedRand();
  int* end = remove_copy_if(a, a + SZ, b,
                            bind2nd(greater<int>(), val));
  // Sort for easier viewing:
  sort(a, a + SZ);
  sort(b, end);
  ostream_iterator<int> out(cout, " ");
  cout << "Original Sequence:\n";
  copy(a, a + SZ, out); cout << endl;
  cout << "Values less <= " << val << endl;
  copy(b, end, out); cout << endl;
} ///:~
