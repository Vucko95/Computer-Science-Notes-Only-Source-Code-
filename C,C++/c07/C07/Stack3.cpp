//: C07:Stack3.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Using a vector as a stack; modified Stack1.cpp
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ifstream in("Stack3.cpp");
  vector<string> textlines;
  string line;
  while(getline(in, line)) 
    textlines.push_back(line + "\n");
  while(!textlines.empty()) {
    cout << textlines.back();
    textlines.pop_back();
  }
} ///:~
