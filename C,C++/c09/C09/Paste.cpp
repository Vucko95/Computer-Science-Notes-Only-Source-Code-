//: C09:Paste.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{L} Vendor
// Fixing a mess with MI
#include <iostream>
#include "Vendor.h"
using namespace std;

class MyBase { // Repair Vendor interface
public:
  virtual void v() const = 0;
  virtual void f() const = 0;
  // New interface function:
  virtual void g() const = 0;
  virtual ~MyBase() { cout << "~MyBase()\n"; }
};

class Paste1 : public MyBase, public Vendor1 {
public:
  void v() const {
    cout << "Paste1::v()\n";
    Vendor1::v();
  }
  void f() const {
    cout << "Paste1::f()\n";
    Vendor1::f();
  }
  void g() const {
    cout << "Paste1::g()\n";
  }
  ~Paste1() { cout << "~Paste1()\n"; }
};

int main() {
  Paste1& p1p = *new Paste1;
  MyBase& mp = p1p; // Upcast
  cout << "calling f()\n";
  mp.f();  // Right behavior
  cout << "calling g()\n";
  mp.g(); // New behavior
  cout << "calling A(p1p)\n";
  A(p1p); // Same old behavior
  cout << "calling B(p1p)\n";
  B(p1p);  // Same old behavior
  cout << "delete mp\n";
  // Deleting a reference to a heap object:
  delete &mp; // Right behavior
} ///:~
