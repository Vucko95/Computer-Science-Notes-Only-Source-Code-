//: C01:Wrapped.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Safe, atomic pointers
#include <iostream>
using namespace std;

// Simplified. Yours may have other arguments.
template<class T, int SZ = 1> class PWrap {
  T* ptr;
public:
  class RangeError {}; // Exception class
  PWrap() {
    ptr = new T[SZ];
    cout << "PWrap constructor" << endl;
  }
  ~PWrap() {
    delete [] ptr;
    cout << "PWrap destructor" << endl;
  }
  T& operator[](int i) throw(RangeError) {
    if(i >= 0 && i < SZ) return ptr[i];
    throw RangeError();
  }
};

class Cat {
public:
  Cat() { cout << "Cat()" << endl; }
  ~Cat() { cout << "~Cat()" << endl; }
  void g() {}
};

class Dog {
public:
  void* operator new[](size_t) {
    cout << "Allocating a Dog" << endl;
    throw 47;
  }
  void operator delete[](void* p) {
    cout << "Deallocating a Dog" << endl;
    ::operator delete(p);
  }
};

class UseResources {
  PWrap<Cat, 3> cats;
  PWrap<Dog> dog;
public:
  UseResources() {
    cout << "UseResources()" << endl;
  }
  ~UseResources() {
    cout << "~UseResources()" << endl;
  }
  void f() { cats[1].g(); }
};

int main() {
  try {
    UseResources ur;
  } catch(int) {
    cout << "inside handler" << endl;
  } catch(...) {
    cout << "inside catch(...)" << endl;
  }
} ///:~
