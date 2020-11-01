//: C01:FunctionTryBlock.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Function-level try blocks
//{-bor}
#include <iostream>
using namespace std;

int main() try {
  throw "main";
} catch(const char* msg) {
   cout << msg << endl;
   return 1;
} ///:~
