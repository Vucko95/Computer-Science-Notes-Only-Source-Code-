//: C06:CountNotEqual.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Count elements not equal to 20
#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
using namespace std;
int main() {
  int a[] = {10, 20, 30};
  const size_t SIZE = sizeof a / sizeof a[0];
  cout << count_if(a, a + SIZE,
                   not1(bind1st(equal_to<int>(), 20)));// 2
} ///:~
