//: C09:Vendor.cpp {O}
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Implementation of VENDOR.H
// This is compiled and unavailable to you
#include <iostream>
#include "Vendor.h"
using namespace std;

void Vendor::v() const {
  cout << "Vendor::v()\n";
}
void Vendor::f() const {
  cout << "Vendor::f()\n";
}
Vendor::~Vendor() {
  cout << "~Vendor()\n";
}
void Vendor1::v() const {
  cout << "Vendor1::v()\n";
}
void Vendor1::f() const {
  cout << "Vendor1::f()\n";
}
Vendor1::~Vendor1() {
  cout << "~Vendor1()\n";
}
void A(const Vendor& V) {
  // ...
  V.v();
  V.f();
  //..
}
void B(const Vendor& V) {
  // ...
  V.v();
  V.f();
  //..
} ///:~
