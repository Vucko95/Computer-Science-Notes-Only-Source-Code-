//: C06:FBinder.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Binders aren't limited to producing predicates
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include "Generators.h"
using namespace std;

int main() {
  ostream_iterator<int> out(cout," ");
  vector<int> v(15);
  generate(v.begin(), v.end(), URandGen(20));
  copy(v.begin(), v.end(), out);
  transform(v.begin(), v.end(), v.begin(),
            bind2nd(multiplies<int>(), 10));
  copy(v.begin(), v.end(), out);
} ///:~
