//: C06:GreaterThanN.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;
class gt_n {
  int value;
public:
  gt_n(int val) : value(val) {}
  bool operator()(int n) {
    return n > value;
  }
};
int main() {
  gt_n f(4);
  cout << f(3) << endl;  // Prints 0 (for false)
  cout << f(5) << endl;  // Prints 1 (for true)
} ///:~
