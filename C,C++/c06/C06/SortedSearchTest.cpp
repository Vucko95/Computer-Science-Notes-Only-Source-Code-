//: C06:SortedSearchTest.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Test searching in sorted ranges
#include <algorithm>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include "NString.h"
#include "PrintSequence.h" 
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
  typedef vector<NString>::iterator sit;
  char* fname = "test.txt";
  if(argc > 1) fname = argv[1];
  ifstream in(fname);
  assure(in, fname);
  srand(time(0));
  cout.setf(ios::boolalpha);
  vector<NString> original;
  copy(istream_iterator<string>(in), 
    istream_iterator<string>(), back_inserter(original));
  require(original.size() >= 4, "Must have four elements");
  vector<NString> v(original.begin(), original.end()), 
    w(original.size() / 2);
  sort(v.begin(), v.end());
  print(v.begin(), v.end(), "sort");
  v = original;
  stable_sort(v.begin(), v.end());
  print(v.begin(), v.end(), "stable_sort");
  v = original;
  sit it = v.begin(), it2;
  // Move iterator to middle
  for(size_t i = 0; i < v.size() / 2; i++)
    it++;
  partial_sort(v.begin(), it, v.end());
  cout << "middle = " << *it << endl;
  print(v.begin(), v.end(), "partial_sort");
  v = original;
  // Move iterator to a quarter position
  it = v.begin();
  for(size_t i = 0; i < v.size() / 4; i++)
    it++;
  // Less elements to copy from than to the destination
  partial_sort_copy(v.begin(), it, w.begin(), w.end());
  print(w.begin(), w.end(), "partial_sort_copy");
  // Not enough room in destination
  partial_sort_copy(v.begin(), v.end(), w.begin(), 
    w.end());
  print(w.begin(), w.end(), "w partial_sort_copy");
  // v remains the same through all this process
  assert(v == original);
  nth_element(v.begin(), it, v.end());
  cout << "The nth_element = " << *it << endl;
  print(v.begin(), v.end(), "nth_element");   
  string f = original[rand() % original.size()];
  cout << "binary search: "
    << binary_search(v.begin(), v.end(), f)
    << endl;
  sort(v.begin(), v.end());
  it = lower_bound(v.begin(), v.end(), f);
  it2 = upper_bound(v.begin(), v.end(), f);
  print(it, it2, "found range");
  pair<sit, sit> ip =
    equal_range(v.begin(), v.end(), f);
  print(ip.first, ip.second,
    "equal_range");
} ///:~
