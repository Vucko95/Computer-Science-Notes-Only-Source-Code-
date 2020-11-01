//: C06:NString.h
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// A "numbered string" that indicates which
// occurrence this is of a particular word
#ifndef NSTRING_H
#define NSTRING_H
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
typedef std::pair<std::string, int> psi;

// Only compare on the first element
bool operator==(const psi& l, const psi& r) {
  return l.first == r.first;
}

class NString {
  std::string s;
  int thisOccurrence;
  // Keep track of the number of occurrences:
  typedef std::vector<psi> vp;
  typedef vp::iterator vpit;
  static vp words;
  void addString(const std::string& x) {
    psi p(x, 0);
    vpit it = std::find(words.begin(), words.end(), p);
    if(it != words.end())
      thisOccurrence = ++it->second;
    else {
      thisOccurrence = 0;
      words.push_back(p);
    }
  }
public:
  NString() : thisOccurrence(0) {}
  NString(const std::string& x) : s(x) {
    addString(x);
  }
  NString(const char* x) : s(x) {
    addString(x);
  }
  // The implicit operator= and
  // copy-constructor are OK here
  friend std::ostream& operator<<(
    std::ostream& os, const NString& ns) {
    return os << ns.s << " ["
      << ns.thisOccurrence << "]";
  }
  // Need this for sorting. Notice it only
  // compares strings, not occurrences:
  friend bool
  operator<(const NString& l, const NString& r) {
    return l.s < r.s;
  }
  friend
  bool operator==(const NString& l, const NString& r) {
    return l.s == r.s;
  }
  // For sorting with greater<NString>:
  friend bool
  operator>(const NString& l, const NString& r) {
    return l.s > r.s;
  }
  // To get at the string directly:
  operator const std::string&() const {return s;}
};

// Allocate static member object. Done here for
// brevity, but should normally be done in a
// separate cpp file:
NString::vp NString::words;
#endif // NSTRING_H ///:~
