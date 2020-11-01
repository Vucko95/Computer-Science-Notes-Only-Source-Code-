//: C06:Removing.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// The removing algorithms
#include <algorithm>
#include <cctype>
#include <string>
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;

struct IsUpper {
  bool operator()(char c) {
    return isupper(c);
  }
};

int main() {
  string v;
  v.resize(25);
  generate(v.begin(), v.end(), CharGen());
  print(v.begin(), v.end(), "v original", "");
  // Create a set of the characters in v:
  string us(v.begin(), v.end());
  sort(us.begin(), us.end());
  string::iterator it = us.begin(), cit = v.end(),
    uend = unique(us.begin(), us.end());
  // Step through and remove everything:
  while(it != uend) {
    cit = remove(v.begin(), cit, *it);
    print(v.begin(), v.end(), "Complete v", "");
    print(v.begin(), cit, "Pseudo v ", " ");
    cout << "Removed element:\t" << *it
         << "\nPsuedo Last Element:\t"
         << *cit << endl << endl;
    it++;
  }
  generate(v.begin(), v.end(), CharGen());
  print(v.begin(), v.end(), "v", "");
  cit = remove_if(v.begin(), v.end(), IsUpper());
  print(v.begin(), cit, "v after remove_if IsUpper", " ");
  // Copying versions are not shown for remove
  // and remove_if.
  sort(v.begin(), cit);
  print(v.begin(), cit, "sorted", " ");
  string v2;
  v2.resize(cit - v.begin());                   
  unique_copy(v.begin(), cit, v2.begin());
  print(v2.begin(), v2.end(), "unique_copy", " ");
  // Same behavior:
  cit = unique(v.begin(), cit, equal_to<char>());
  print(v.begin(), cit, "unique equal_to<char>", " ");
} ///:~
