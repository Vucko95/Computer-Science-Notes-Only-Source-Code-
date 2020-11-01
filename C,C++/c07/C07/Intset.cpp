//: C07:Intset.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Simple use of STL set
#include <cassert>
#include <set>
using namespace std;

int main() {
  set<int> intset;
    for(int i = 0; i < 25; i++)
      for(int j = 0; j < 10; j++)
        // Try to insert duplicates:
        intset.insert(j);
  assert(intset.size() == 10);
} ///:~
