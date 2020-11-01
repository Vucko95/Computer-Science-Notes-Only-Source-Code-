//: C06:PtrFun1.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Using ptr_fun() with a unary function
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int d[] = {123, 94, 10, 314, 315};
const int DSZ = sizeof d / sizeof *d;
bool isEven(int x) {
  return x % 2 == 0;
}
int main() {
  vector<bool> vb;
  transform(d, d + DSZ, back_inserter(vb), 
    not1(ptr_fun(isEven)));
  copy(vb.begin(), vb.end(),
    ostream_iterator<bool>(cout, " "));
  cout << endl;
  // Output: 1 0 0 0 1
} ///:~
