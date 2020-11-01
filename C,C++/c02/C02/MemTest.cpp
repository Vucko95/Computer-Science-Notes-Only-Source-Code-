//: C02:MemTest.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{L} MemCheck
// Test of MemCheck system
#include <iostream>
#include <vector>
#include <cstring>
#include "MemCheck.h"   // Must appear last!
using namespace std;

class Foo {
  char* s;
public:
  Foo(const char*s ) {
    this->s = new char[strlen(s) + 1];
    strcpy(this->s, s);
  }
  ~Foo() {
    delete [] s;
  }
};

int main() {
  MEM_ON();
  cout << "hello\n";
  int* p = new int;
  delete p;
  int* q = new int[3];
  delete [] q;
  int* r;
  delete r;
  vector<int> v;
  v.push_back(1);
  Foo s("goodbye");
  MEM_OFF();
} ///:~
