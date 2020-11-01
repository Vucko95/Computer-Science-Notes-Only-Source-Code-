//: C09:VirtInit.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Illustrates initialization order with virtual bases
#include <iostream>
#include <string>
using namespace std;

class M {
public:
  M(const string& s) {
    cout << "M " << s << endl;
  }
};

class A{
  M m;
public:
  A(const string& s) : m("in A") {
     cout << "A " << s << endl;
  }
};

class B
{
  M m;
public:
  B(const string& s) : m("in B")  {
    cout << "B " << s << endl;
  }
};

class C
{
  M m;
public:
  C(const string& s) : m("in C")  {
    cout << "C " << s << endl;
  }
};

class D
{
  M m;
public:
  D(const string& s) : m("in D") {
    cout << "D " << s << endl;
  }
};

class E : public A, virtual public B, virtual public C
{
  M m;
public:
  E(const string& s)
  : A("from E"), B("from E"), C("from E"), m("in E") {
    cout << "E " << s << endl;
  }
};

class F : virtual public B, virtual public C, public D
{
  M m;
public:
  F(const string& s)
  : B("from F"), C("from F"), D("from F"), m("in F") {
    cout << "F " << s << endl;
  }
};

class G : public E, public F
{
  M m;
public:
  G(const string& s)
  : B("from G"), C("from G"), E("from G"),
    F("from G"), m("in G") {
    cout << "G " << s << endl;
  }
};

int main() {
  G g("from main");
} ///:~
