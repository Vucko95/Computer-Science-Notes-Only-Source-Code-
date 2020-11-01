//: C03:ReplaceAll.cpp {O}
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
#include <cstddef>
#include <string>
using namespace std;

string& replaceAll(string& context, const string& from,
  const string& to) {
  size_t lookHere = 0;
  size_t foundHere;
   while ((foundHere = context.find(from, lookHere))
     != string::npos) {
    context.replace(foundHere, from.size(), to);
      lookHere = foundHere + to.size();
  }
  return context;
} ///:~
