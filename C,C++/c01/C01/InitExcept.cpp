//: C01:InitExcept.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Handles exceptions from subobjects
//{-bor}
#include <iostream>
using namespace std;

class Base {
  int i;
public:
  class BaseExcept {};

  Base(int i) : i(i) {
    throw BaseExcept();
  }
};

class Derived : public Base {
public:
  class DerivedExcept {
    const char* msg;
  public:
    DerivedExcept(const char* msg) : msg(msg) {}
    const char* what() const {
      return msg;
    }
  };
  Derived(int j)
  try 
    : Base(j) {
    // Constructor body
    cout << "This won't print\n";
  }
  catch (BaseExcept&) {
    throw DerivedExcept("Base subobject threw");;
  }
};

int main() {
  try {
    Derived d(3);
  }
  catch (Derived::DerivedExcept& d) {
    cout << d.what() << endl;  // "Base subobject threw"
  }
} ///:~
