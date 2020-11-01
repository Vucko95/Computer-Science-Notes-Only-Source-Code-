//: C06:CopyIntsFromFile.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Uses an input stream iterator
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include "../require.h"
using namespace std;
bool gt15(int x) {
  return 15 < x;
}
int main() {
  ifstream inf("someInts.dat");
  assure(inf, "someInts.dat");
  remove_copy_if(istream_iterator<int>(inf),   
                 istream_iterator<int>(),
                 ostream_iterator<int>(cout, "\n"), gt15);
} ///:~
