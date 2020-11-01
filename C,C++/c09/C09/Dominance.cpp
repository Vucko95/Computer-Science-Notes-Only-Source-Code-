//: C09:Dominance.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
class Top {
public:
  virtual void f() {}
};

class Left : virtual public Top {
public:
   void f(){}
};

class Right : virtual public Top {
};

class Bottom : public Left, public Right {};

int main() {
   Bottom b;
   b.f(); // calls Left::f()
} ///:~
