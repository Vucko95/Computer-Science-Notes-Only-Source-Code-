//: C09:Interfaces.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Multiple interface inheritance
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Printable {
public:
  virtual ~Printable() {}
  virtual void print(ostream&) const = 0;
};

class Intable {
public:
  virtual ~Intable() {}
  virtual int toInt() const = 0;
};

class Stringable {
public:
  virtual ~Stringable() {}
  virtual string toString() const = 0;
};

class Able : public Printable,
             public Intable,
             public Stringable {
  int myData;
public:
  Able(int x) {
    myData = x;
  }
  void print(ostream& os) const {
    os << myData;
  }
  int toInt() const {
    return myData;
  }
  string toString() const {
    ostringstream os;
    os << myData;
    return os.str();
  }
};

void testPrintable(const Printable& p) {
  p.print(cout);
  cout << endl;
}
void testIntable(const Intable& n) {
  int i = n.toInt() + 1;
  cout << i << endl;
}
void testStringable(const Stringable& s) {
  string buf = s.toString() + "th";
  cout << buf << endl;
}

int main() {
  Able a(7);
  testPrintable(a);
  testIntable(a);
  testStringable(a);
} ///:~
