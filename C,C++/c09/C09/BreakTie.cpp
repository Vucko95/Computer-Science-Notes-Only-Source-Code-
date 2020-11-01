//: C09:BreakTie.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
class Top {};

class Left : virtual public Top {
public:
   void f(){}
};

class Right : virtual public Top {
public:
   void f(){}
};

class Bottom : public Left, public Right {
public:
  using Left::f;
};

int main() {
   Bottom b;
   b.f();     // calls Left::f()
} ///:~
