//: C03:StringIndexing.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
#include <cassert>
#include <string>
using namespace std;
int main(){
  string s("1234");
  assert(s[1] == '2');
  assert(s.at(1) == '2');
} ///:~
