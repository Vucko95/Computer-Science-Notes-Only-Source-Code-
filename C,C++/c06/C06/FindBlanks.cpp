//: C06:FindBlanks.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Demonstrates mem_fun_ref() with string::empty()
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include "../require.h"
using namespace std;

typedef vector<string>::iterator LSI;

int main(int argc, char* argv[]) {
  char* fname = "FindBlanks.cpp";
  if(argc > 1) fname = argv[1];
  ifstream in(fname);
  assure(in, fname);
  vector<string> vs;
  string s;
  while(getline(in, s))
    vs.push_back(s);
  vector<string> cpy = vs; // For testing
  LSI lsi = find_if(vs.begin(), vs.end(),
     mem_fun_ref(&string::empty));
  while(lsi != vs.end()) {
    *lsi = "A BLANK LINE";
    lsi = find_if(vs.begin(), vs.end(),
      mem_fun_ref(&string::empty));
  }
  for(size_t i = 0; i < cpy.size(); i++)
    if(cpy[i].size() == 0)
      assert(vs[i] == "A BLANK LINE");
    else
      assert(vs[i] != "A BLANK LINE");
} ///:~
