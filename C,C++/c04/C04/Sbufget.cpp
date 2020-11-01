//: C04:Sbufget.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Copies a file to standard output
#include <fstream>
#include <iostream>
#include "../require.h"
using namespace std;

int main() {
  ifstream in("Sbufget.cpp");
  assure(in);
  streambuf& sb = *cout.rdbuf();
  while (!in.get(sb).eof()) {
    if (in.fail())          // Found blank line
      in.clear();
    cout << char(in.get()); // Process '\n'
  }
} ///:~
