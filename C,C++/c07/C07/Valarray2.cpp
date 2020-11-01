//: C07:Valarray2.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2001 MindView, Inc.
// Available at www.BruceEckel.com.
// Illustrates slices and masks
//{-bor}
#include <valarray>
#include <iostream>
using namespace std;

template<class T>
void print(const char* lbl, const valarray<T>& a) {
  cout << lbl << ": ";
  for (size_t i = 0; i < a.size(); ++i)
    cout << a[i] << ' ';
  cout << endl;
}

int main() {
  int data[] = {1,2,3,4,5,6,7,8,9,10,11,12};
  valarray<int> v(data, 12);
  valarray<int> r1(v[slice(0, 4, 3)]);
  print("slice(0,4,3)", r1);
  // Extract conditionally
  valarray<int> r2(v[v > 6]);
  print("elements > 6", r2);
  // Square first column
  v[slice(0, 4, 3)] *= valarray<int>(v[slice(0, 4, 3)]);
  print("after squaring first row", v);
  // Restore it
  int idx[] = {1,4,7,10};
  valarray<int> save(idx, 4);
  v[slice(0, 4, 3)] = save;
  print("v restored", v);
  // Extract a 2-d subset: {{1,3,5}, {7, 9, 11}}
  valarray<size_t> siz(2);
  siz[0] = 2;
  siz[1] = 3;
  valarray<size_t> gap(2);
  gap[0] = 6;
  gap[1] = 2;
  valarray<int> r3(v[gslice(0, siz, gap)]);
  print("2-d slice", r3);
  // Extract a subset via a boolean mask (bool elements)
  valarray<bool> mask(false, 5);
  mask[1] = mask[2] = mask[4] = true;
  valarray<int> r4(v[mask]);
  print("v[mask]", r4);
  // Extract a subset via an index mask (size_t elements)
  size_t idx2[] = {2,2,3,6};
  valarray<size_t> mask2(idx2, 4);
  valarray<int> r5(v[mask2]);
  print("v[mask2]", r5);
  // Use an index mask in assignment
  valarray<char> text("now is the time", 15);
  valarray<char> caps("NITT", 4);
  valarray<size_t> idx3(4);
  idx3[0] = 0;
  idx3[1] = 4;
  idx3[2] = 7;
  idx3[3] = 11;
  text[idx3] = caps;
  print("capitalized", text);
} ///:~
