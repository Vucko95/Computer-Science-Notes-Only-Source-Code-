//: C03:HTMLStripper.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{L} ReplaceAll
// Filter to remove html tags and markers
#include <cassert>
#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include "../require.h"
using namespace std;

string& replaceAll(string& context, const string& from,
  const string& to);

string& stripHTMLTags(string& s) {
  static bool inTag = false;
  bool done = false;
  while (!done) {
    if (inTag) {
      // The previous line started an HTML tag
      // but didn't finish. Must search for '>'.
      size_t rightPos = s.find('>');
      if (rightPos != string::npos) {
        inTag = false;
        s.erase(0, rightPos + 1);
      }
      else {
        done = true;
        s.erase();
      }
    }
    else {
      // Look for start of tag:
      size_t leftPos = s.find('<');
      if (leftPos != string::npos) {
        // See if tag close is in this line
        size_t rightPos = s.find('>');
        if (rightPos == string::npos) {
          inTag = done = true;
          s.erase(leftPos);
        }
        else
          s.erase(leftPos, rightPos - leftPos + 1);
      }
      else
        done = true;
    }
  }
  // Remove all special HTML characters
  replaceAll(s, "&lt;", "<");
  replaceAll(s, "&gt;", ">");
  replaceAll(s, "&amp;", "&");
  replaceAll(s, "&nbsp;", " ");
  // Etc...
  return s;
}

int main(int argc, char* argv[]) {
  requireArgs(argc, 1, 
    "usage: HTMLStripper InputFile");
  ifstream in(argv[1]);
  assure(in, argv[1]);
  string s;
  while(getline(in, s))
    if (!stripHTMLTags(s).empty())
      cout << s << endl;
} ///:~
