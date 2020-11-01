//: C06:CopyIntsToFile.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Uses an output file stream iterator
#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iterator>
using namespace std;
bool gt15(int x) {
  return 15 < x;
}
int main() {
  int a[] = {10, 20, 30};
  const size_t SIZE = sizeof a / sizeof a[0];
  ofstream outf("ints.out");
  remove_copy_if(a, a + SIZE,
                 ostream_iterator<int>(outf, "\n"), gt15);
} ///:~
