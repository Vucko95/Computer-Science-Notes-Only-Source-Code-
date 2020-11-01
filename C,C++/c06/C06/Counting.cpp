//: C06:Counting.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// The counting algorithms
#include <algorithm>
#include <functional>
#include <iterator>
#include <set>
#include <vector>
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;

int main() {
  vector<char> v;
  generate_n(back_inserter(v), 50, CharGen());
  print(v.begin(), v.end(), "v", "");
  // Create a set of the characters in v:
  set<char> cs(v.begin(), v.end());
  typedef set<char>::iterator sci;
  for(sci it = cs.begin(); it != cs.end(); it++) {
    int n = count(v.begin(), v.end(), *it);
    cout << *it << ": " << n << ", ";
  }
  int lc = count_if(v.begin(), v.end(), 
    bind2nd(greater<char>(), 'a'));
  cout << "\nLowercase letters: " << lc << endl;
  sort(v.begin(), v.end());
  print(v.begin(), v.end(), "sorted", "");
} ///:~
