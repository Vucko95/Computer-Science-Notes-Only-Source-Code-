//: C09:Dominance2.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class A {
public:
   virtual void f() {cout << "A::f\n";}
};

class B : virtual public A {
public:
   void f() {cout << "B::f\n";}
};

class C : public B {};
class D : public C, virtual public A {};

int main()
{
   B* p = new D;
   p->f();  // calls B::f()
} ///:~
