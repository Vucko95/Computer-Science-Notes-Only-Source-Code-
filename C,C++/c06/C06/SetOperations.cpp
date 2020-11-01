//: C06:SetOperations.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Set operations on sorted ranges
#include <vector>
#include <algorithm>
#include "PrintSequence.h"
#include "Generators.h"
using namespace std;

int main() {
  const int sz = 30;
  char v[sz + 1], v2[sz + 1];
  CharGen g;
  generate(v, v + sz, g);
  generate(v2, v2 + sz, g);
  sort(v, v + sz);
  sort(v2, v2 + sz);
  print(v, v + sz, "v", "");
  print(v2, v2 + sz, "v2", "");
  bool b = includes(v, v + sz, v + sz/2, v + sz);
  cout.setf(ios::boolalpha);
  cout << "includes: " << b << endl;
  char v3[sz*2 + 1], *end;
  end = set_union(v, v + sz, v2, v2 + sz, v3);
  print(v3, end, "set_union", "");
  end = set_intersection(v, v + sz,
    v2, v2 + sz, v3);
  print(v3, end, "set_intersection", "");
  end = set_difference(v, v + sz, v2, v2 + sz, v3);
  print(v3, end, "set_difference", "");
  end = set_symmetric_difference(v, v + sz,
    v2, v2 + sz, v3);
  print(v3, end, "set_symmetric_difference","");
} ///:~
