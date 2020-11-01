//: C09:Countable.h
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// A "mixin" class
#ifndef COUNTABLE_H
#define COUNTABLE_H
#include <cassert>

class Countable {
public:
  long attach() { return ++count; }
  long detach() {
    return (--count > 0) ? count : (delete this, 0);
  }
  long refCount() const { return count; }
protected:
  Countable() { count = 0; }
  virtual ~Countable() { assert(count == 0); }
private:
  long count;
};
#endif ///:~
